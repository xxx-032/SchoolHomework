#include<atomic>
#include<thread>
#include<mutex>
#include<iostream>
#include<time.h>
#include <windows.h>
#include<math.h>

#define maxLenth 1000

HANDLE hMutex;  //���廥�������

long long countNum = 0;
int Aflag = 1;
int Bflag = 1;
int distrubFlag = 0;


enum{����,����,æ��,�ȴ�,���ͳɹ�,����ʧ��,��ͻʮ��,����֡�������};
enum{ͨ������,ͨ����æ};


class computer {
private:
	int flag;		//�ж�����λ��
	int times;		//Я������֡�ݶ�10��
	int last;		//����ʱ��256����ʱ��
	int listen;		//�ݶ�96������ʱ��
	int countFlagTimes;	//��ͻ����
	int disturb;
	int speed;
	char *name;
	int cur;
	int wait;
public:
	int num = 96;
	int prenum = num;
	computer(char *n,int wait ,int times = 10, int last = 256, int listen = 96, int cft = 0,int flag = ����,int cur = 1, int disturb = 48) {
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

	//��������ʾ��Ϣ��
	void printMessage() {
		switch (flag) {
		case ����:
			std::cout << name << "���������ŵ���.\n";
			break;
		case æ��:
			std::cout << name << "���ڴ��͵�" << cur << "������֡��.\n";
			break;
		case �ȴ�:
			std::cout << name << "����ִ���˱��㷨��.\n";
			break;
		case ���ͳɹ�:
			std::cout << name << "�����" << cur <<"������֡�ɹ�.\n";
			countFlagTimes = 0;
			cur++;
			break;
		case ����ʧ��:
			countFlagTimes++;
			std::cout << name << "�����" << cur << "������֡ʧ��,�ȴ��ٴ��ش������͸����ź�.\n";
			break;
		case ��ͻʮ��:
			std::cout << name << "�����" << cur << "������֡ʧ��,����������֡.\n";
			countFlagTimes = 0;
			cur++;
			break;
		case ����֡�������:
			std::cout << name << "����֡�������.\n";
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
	//������������������ͻ����ͻ�������Ϊ10�Σ�����ʮ�ζ�����֡�����������10�Σ�����48���ص�ӵ���źţ�֮���ӳ�һ�����ʱ�䣨��ʱ������ָ�������㷨�ó��������·�������֡
	//rand()%(pow(2,countflagtimes)-1)*2*last(2*lastΪ������);
	int getDelayTime() {
		return (wait * 2 * last) > 256 + 48 ? (wait * 2 * last) : 256 + 48;
	}
	int getCur() { return cur; }
}A("����A",0), B("����B",1);


int getNext(computer *src,computer *dst) {
	switch (src->getFlag()) {
	case ����:
		if (dst->getFlag() == æ��) {
			if (dst->num - countNum <= 96) {
				src->setFlag(����);
				return src->getListen();
			}
			distrubFlag = 1;
		}
		src->setFlag(æ��);
		return src->getLast();
		break;
	case æ��:
		if (dst->getFlag() == ����ʧ�� || dst->getFlag() == æ��) {
			src->setFlag(����ʧ��);
			return 0;
		}
		if (distrubFlag) {
			distrubFlag = 0;
			src->setFlag(����ʧ��);
			return 0;
		}
		src->setFlag(���ͳɹ�);
		return 0;
		break;
	case �ȴ�:case ���ͳɹ�:
		src->setFlag(����);
		return src->getListen();
		break;
	case ����ʧ��:case ��ͻʮ��:
		if (src->getcountFlagTimes() >= 10) {
			src->setFlag(��ͻʮ��);
			return 0;
		}
		src->setFlag(�ȴ�);
		return src->getDelayTime() > src->getDisturb() ? src->getDelayTime() : src->getDisturb();
		break;
	}
}

int getOneNext(computer *src) {
	switch (src->getFlag()) {
	case ����:
		src->setFlag(æ��);
		return src->getLast();
		break;
	case æ��:
		src->setFlag(���ͳɹ�);
		return 0;
		break;
	case �ȴ�:case ���ͳɹ�:
		src->setFlag(����);
		return src->getListen();
		break;
	case ����ʧ��:case ��ͻʮ��:
		if (src->getcountFlagTimes() >= 10) {
			src->setFlag(��ͻʮ��);
			return 0;
		}
		src->setFlag(�ȴ�);
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
		A.setFlag(����֡�������);
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
		B.setFlag(����֡�������);
	}
	return 0;
}




int main(void) {
	hMutex = CreateMutex(NULL, false, nullptr);     //�����������
	HANDLE hThread1=CreateThread(NULL, 0, ThreadProcA, NULL, 0, NULL);		//����A�ȴ��߳�
	HANDLE hThread2=CreateThread(NULL, 0, ThreadProcB, NULL, 0, NULL);		//����B�ȴ��߳�
	/*
	WaitForSingleObjects(MAX_THREADS, hThread1, TRUE, INFINITE);
	WaitForSingleObjects(MAX_THREADS, hThread2, TRUE, INFINITE);
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	*/
	Sleep(9223372036854775807);


}
