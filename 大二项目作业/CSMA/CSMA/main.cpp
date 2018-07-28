#include<atomic>
#include<thread>
#include<mutex>
#include<iostream>
#include<time.h>
#include <windows.h>
#include<math.h>

#define maxLenth 1000

HANDLE hMutex;  //定义互斥对象句柄

long long countNum = 0;
int Aflag = 1;
int Bflag = 1;
int distrubFlag = 0;


enum{空闲,侦听,忙传,等待,传送成功,传送失败,冲突十次,所有帧传送完毕};
enum{通道空闲,通道繁忙};


class computer {
private:
	int flag;		//判断所处位置
	int times;		//携带数据帧暂定10个
	int last;		//传播时延256比特时间
	int listen;		//暂定96个比特时间
	int countFlagTimes;	//冲突次数
	int disturb;
	int speed;
	char *name;
	int cur;
	int wait;
public:
	int num = 96;
	int prenum = num;
	computer(char *n,int wait ,int times = 10, int last = 256, int listen = 96, int cft = 0,int flag = 侦听,int cur = 1, int disturb = 48) {
		name = (char *)malloc(sizeof(n));
		strcpy(name, n);
		this->times = times;
		this->last = last;
		this->listen = listen;
		this->countFlagTimes = cft;
		this->flag = flag;
		this->cur = cur;
		this->disturb = disturb;
		this->wait = wait;
	}
	~computer() {};

	//输出相关提示信息。
	void printMessage() {
		switch (flag) {
		case 侦听:
			std::cout << name << "正在侦听信道中.\n";
			break;
		case 忙传:
			std::cout << name << "正在传送第" << cur << "个数据帧中.\n";
			break;
		case 等待:
			std::cout << name << "正在执行退避算法中.\n";
			break;
		case 传送成功:
			std::cout << name << "传输第" << cur <<"个数据帧成功.\n";
			countFlagTimes = 0;
			cur++;
			break;
		case 传送失败:
			countFlagTimes++;
			std::cout << name << "传输第" << cur << "个数据帧失败,等待再次重传并发送干扰信号.\n";
			break;
		case 冲突十次:
			std::cout << name << "传输第" << cur << "个数据帧失败,丢弃该数据帧.\n";
			countFlagTimes = 0;
			cur++;
			break;
		case 所有帧传送完毕:
			std::cout << name << "所有帧传送完毕.\n";
			break;
		}
	}
	void setFlag(int f) {
		this->flag = f; 
	}
	int getFlag() { return flag; }
	int getcountFlagTimes() { return countFlagTimes; }
	int getTimes() { return times; }
	int getListen() {return listen;}
	int getLast() { return last; }
	int getDisturb() { return disturb + last; }
	//传输过程中如果发生冲突，冲突次数最多为10次，超过十次丢弃该帧，如果不超过10次，则发送48比特的拥塞信号，之后延迟一个随机时间（该时间利用指数后退算法得出），重新发送数据帧
	//rand()%(pow(2,countflagtimes)-1)*2*last(2*last为争用期);
	int getDelayTime() {
		return (wait * 2 * last) > 256 + 48 ? (wait * 2 * last) : 256 + 48;
	}
	int getCur() { return cur; }
}A("主机A",0), B("主机B",1);


int getNext(computer *src,computer *dst) {
	switch (src->getFlag()) {
	case 侦听:
		if (dst->getFlag() == 忙传) {
			if (dst->num - countNum <= 96) {
				src->setFlag(侦听);
				return src->getListen();
			}
			distrubFlag = 1;
		}
		src->setFlag(忙传);
		return src->getLast();
		break;
	case 忙传:
		if (dst->getFlag() == 传送失败 || dst->getFlag() == 忙传) {
			src->setFlag(传送失败);
			return 0;
		}
		if (distrubFlag) {
			distrubFlag = 0;
			src->setFlag(传送失败);
			return 0;
		}
		src->setFlag(传送成功);
		return 0;
		break;
	case 等待:case 传送成功:
		src->setFlag(侦听);
		return src->getListen();
		break;
	case 传送失败:case 冲突十次:
		if (src->getcountFlagTimes() >= 10) {
			src->setFlag(冲突十次);
			return 0;
		}
		src->setFlag(等待);
		return src->getDelayTime() > src->getDisturb() ? src->getDelayTime() : src->getDisturb();
		break;
	}
}

int getOneNext(computer *src) {
	switch (src->getFlag()) {
	case 侦听:
		src->setFlag(忙传);
		return src->getLast();
		break;
	case 忙传:
		src->setFlag(传送成功);
		return 0;
		break;
	case 等待:case 传送成功:
		src->setFlag(侦听);
		return src->getListen();
		break;
	case 传送失败:case 冲突十次:
		if (src->getcountFlagTimes() >= 10) {
			src->setFlag(冲突十次);
			return 0;
		}
		src->setFlag(等待);
		return src->getDelayTime() > src->getDisturb() ? src->getDelayTime() : src->getDisturb();
		break;
	}
}


unsigned long __stdcall ThreadProcA(void* lp)
{
	A.printMessage();
	while (countNum < A.num)
	{
		WaitForSingleObject(hMutex, INFINITE);
		countNum++;
		_sleep(15);
		ReleaseMutex(hMutex);
	}
	if (B.getCur() <= B.getTimes()) {
		if (A.num <= B.num && countNum >= A.num && Aflag) {
			A.num = getNext(&A, &B) + countNum;
			CreateThread(NULL, 0, ThreadProcA, NULL, 0, NULL);
		}
	}
	else {
		if (countNum >= A.num && Aflag) {
			A.num = getOneNext(&A) + countNum;
			CreateThread(NULL, 0, ThreadProcA, NULL, 0, NULL);
		}
	}
	if (A.getCur() == A.getTimes() + 1) {
		Aflag = 0;
	}
	if (!Aflag) {
		A.setFlag(所有帧传送完毕);
	}
	return 0;
}

unsigned long __stdcall ThreadProcB(void* lp)
{
	B.printMessage();
	while (countNum < B.num)
	{
		WaitForSingleObject(hMutex, INFINITE);
		countNum++;
		_sleep(15);
		ReleaseMutex(hMutex);
	}
	if (A.getCur() <= A.getTimes()) {
		if (B.num <= A.num && countNum >= B.num && Bflag) {
			B.num = getNext(&B, &A) + countNum;
			CreateThread(NULL, 0, ThreadProcB, NULL, 0, NULL);
		}
	}
	else {
		if (countNum >= B.num && Bflag) {
			B.num = getOneNext(&B) + countNum;
			CreateThread(NULL, 0, ThreadProcB, NULL, 0, NULL);
		}
	}

	if (B.getCur() == B.getTimes() + 1) {
		Bflag = 0;
	}
	if (!Bflag) {
		B.setFlag(所有帧传送完毕);
	}
	return 0;
}




int main(void) {
	hMutex = CreateMutex(NULL, false, nullptr);     //创建互斥对象
	HANDLE hThread1=CreateThread(NULL, 0, ThreadProcA, NULL, 0, NULL);		//创建A等待线程
	HANDLE hThread2=CreateThread(NULL, 0, ThreadProcB, NULL, 0, NULL);		//创建B等待线程
	/*
	WaitForSingleObjects(MAX_THREADS, hThread1, TRUE, INFINITE);
	WaitForSingleObjects(MAX_THREADS, hThread2, TRUE, INFINITE);
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	*/
	Sleep(9223372036854775807);


}
