#ifndef PUBLIC_H
#define PUBLIC_H


/*
	让他选择导入的部门和时间(月份)
*/


//宏定义
#define MAXCOL 80		
#define MAXROW 40
#define tab	"◢"
#define SHOWDATA 5   //一页显示时间日期总数
#define SHOWLIST 9	 //一页显示员工人数 
#define MODE0 100    //鼠标判断事件0 sample::welcome
#define	MODE1 101    //鼠标判断1 sample::boundary
#define	MODE2 102	 //鼠标判断2 loadin:loadin
#define	MODE3 103	 //鼠标判断3 loadin:boundary
#define MODE4 104	 //鼠标判断4 samples:qtime
#define MODE5 105	 //鼠标判断4 samples:qdepartment
#define MODE6 106	 //鼠标判断4 samples:qpos
#define MODE7 107	 //鼠标判断4 samples:qcount
#define MODE8 108	 //鼠标判断8 sample::backgound12
#define MODE9 109	 //鼠标判断9 sample::导入数据
#define MODE10 110	 //鼠标判断10 sample::qhelp
#define MODE11 111	 
#define MODE12 112	 
#define MODE13 113	 
#define MODE14 114	 
#define MODE15 115	 
#define MODE16 116
#define MODE17 117	 
#define MODE18 118	 
#define MODE19 119	 
#define MODE20 120	 
#define MODE21 121	
#define MODE22 122	 
#define MODE23 123

//全局变量声明
extern int mode;
extern int qdep;
extern int page14;
extern int page17;
extern int page4;
extern int page5;
extern int page8;
extern int page88;
extern int fltell;
extern int xxxnum;
extern int xxxdata;
enum workpost { SALESMAN=1, TECHNICIAN, SALESMANAGER, MANAGER };
typedef struct { int year; int month; int day; } birthday;

//头文件
#include<stdlib.h>
#include<iostream>
#include<windows.h>     //mouse.h鼠标输入头文件
#include<fstream>		//文件输入输出头文件
#include<conio.h>		//getch()头文件
#include<atlimage.h>	//用于图片添加头文件
#include <time.h>		//延迟函数头文件
#include<vector>
#include<memory>
#include<string>
#include<algorithm>
#include<io.h>
#include<map>


//函数声明

//loadin.cpp
void loadin(void);		//默认游客员工登陆栏
void loadprocess(void);//登陆过程操作


//PrintChar.cpp
void PrintChar(char *ch, UINT count, UINT x, UINT y);	//按所需打印字符

//mouse.cpp
int input(int X,int Y);			//定义鼠标宏值
void HideCursor();		//隐藏控制台的光标
void ShowCursor();		//显示控制台光标
void mouse(char* argv[]);			//调用鼠标

//1~5为读取判断输入个人信息word[5];
std::string mouseprocess1();
std::string mouseprocess2();
std::string mouseprocess3();
std::string mouseprocess4();
std::string mouseprocess5();

//用于添加新部门
std::string mouseprocess6();
bool mouseprocess7(std::string newdepartment);
//用于添加新月份
bool mouseprocess8(std::string newdepartment);
bool mouseprocess9(void);

//samples.cpp

void boundary();		//登陆菜单
void welcome();			//欢迎界面
void exitsys();			//退出系统
void payrule();			//工资细则
void delay(int set);	//延迟函数用于闪烁问题
void ClearScreen(void); //清屏函数
void background(int);		//背景1(常用设置)
void background2(int);		//背景2(查询设置)
void background3(int);		//背景3(服务索引)
void background4(int);		//背景4(导入数据)
void background5(int);		//背景5(岗位管理)
void background6(int);		//背景6(分组管理)
void background7(int);		//背景7(个人信息表)
void background8(int);		//背景8(个人信息表2)
void background9(void);		//背景9(个人信息表右键属性)
void background10(int);		//背景10(添加成员用)
void background11(int);		//背景11(温馨提示)
void background12(int);		//背景12添加部门
void background13(int);		//背景13添加月份
void background22(int);		//背景22
void sss(int page);			
void qtime(int page);			//查询年月
void qdepartment(int page);		//查询部门
void qpos(void);			//查询岗位
void qcount(void);			//统计结果
void qhelp(void);			//服务索引
void getFiles(std::string path, std::vector<std::string>& files);	//获取目录.txt文件
void renew(char* argv[]);	//更新档案
void idsort(int dep);				//按id排序
void namesort(int dep);			//按名字排序	
void possort(int dep);				//按岗位排序
void wagessort(int dep);			//按工资排序
void departmentsort(int dep);		//按部门排序
void findname(const std::string&b);	//查询名字
void findid(const int id);			//查询id
bool fn(const std::string&b);		
bool fi(const int id);
void datapageup();					//月份上一页
void datapagedown();				//月份下一页
void savedepartment();				//用于保存部门
bool qdepartmentup(int page);		//用于部门翻上一页
bool qdepartmentdown(int page);		//用于部门翻下一页
bool makedepartmentsure(int f);				//确认删除
bool makedatasure(int f);				//确认删除
void renewdepartment();				//获取部门
void renew(char* argv[]);				//获取时间
bool qdataup(int page);		//用于月份翻上一页
bool qdatadown(int page);		//用于月份翻下一页
void adddata(const std::string&c);	//添加新月份
void deletedata(const std::string&c);//删除月份
void qtimetrue(int page);				//月份信息
void openfile(int i);					//获取员工信息
void savefile(int i);					//保存员工信息
bool showlistup(int page);				//展露个人信息上一页
bool showlistdown(int page);			//展露个人信息下一页
void showlist(int page);				//展露个人信息
void getlist(int dep);
bool showlistup(int page,int dep);				//展露个人信息上一页
bool showlistdown(int page, int dep);			//展露个人信息下一页
void showlist(int page, int dep);				//展露个人信息
void deleteone(int num, int open, char* argv[]);	//删除用
void departmentwages(const std::string &department);	//统计
void allmenwages();										//统计


class worker
{
protected:
	long id;
	std::string name;
	std::string sex;
	std::string department;
	std::string pos;
	birthday birth;
	double curwages;
	const double wages = 8000;
	const double basewages = 5000;
	int worktime;
	double salesmoney;
public:
	static int datapage;
	static int allmen;
	static long long allmoney;
	static int highestmoney;
	static int lowestmoney;
	static std::map<std::string, int>departmentmoney;//每个部门的销售额
	static std::map<std::string, int>departmentpeople;
	static std::map<std::string, int>departmentallmoney;
	static std::map<std::string, int>departmentlowestmoney;
	static std::map<std::string, int>departmenthighestmoney;
	static std::vector<std::string>dep;
	static std::vector<std::string>post;
	static std::vector<std::shared_ptr<worker>>people;
	static std::vector<std::shared_ptr<worker>>deppeople;
	static std::map<std::string, int>departmentsalesmanager;
	static std::vector<std::string>readfile;
	static std::vector<std::string>data;
	static std::vector<std::shared_ptr<worker>>FINDNAME;
	static std::vector<std::shared_ptr<worker>>FINDID;
	static int salesmangernum;


	void setworker(long i=0, std::string n=nullptr, std::string s=nullptr, std::string d = nullptr, std::string p=0, double c=0, int dd=0, int m=0, int y=0){
		id = i+m*1000+dd*100; name = n; sex = s; department = d; pos = p; curwages = c; birth.day = dd; birth.month = m; birth.year = y;
	};
	virtual ~worker() = default;

	virtual void setname(const std::string &n) { name = n; };
	virtual const std::string &getname()const { return name; };

	virtual void setsex(const std::string &s) { sex = s; };
	virtual const std::string &getsex()const { return sex; };

	virtual void setdepartment(const std::string &d) { department = d; };
	virtual const std::string &getdepartment()const { return department; };

	virtual void setpos(const std::string &p) { pos = p; };
	virtual const std::string &getpos()const { return pos; };

	virtual void setid(const long &i) { id = i; };
	virtual const long &getid()const { return id; };

	virtual void setbirth(const birthday&b) { birth = b; };
	virtual const birthday &getbirth() { return birth; };

	virtual const double &getcurwages()const { return curwages; };


	virtual const int &getworktime()const { return worktime; };

	virtual const double &getsalesmoney()const { return salesmoney; };

	virtual void coo(void) = 0;

	virtual void print(int y)=0;
	virtual void save(std::ofstream&out) = 0;
	void renewsalesmanager(void) {};
	virtual void privateprint(int y) = 0;
};


class manager : public worker
{

public:
	static std::vector<manager>managernum;
	manager() = default;
	manager(long i, std::string n, std::string s, std::string d, int dd, int m, int y, std::string p={ "经理" }) {
		setworker(i, n, s, d, p, wages, dd, m, y);
		++allmen; allmoney += curwages;
		departmentallmoney[d] += curwages;
		departmentpeople[d]++;
		if (lowestmoney == 0)
			lowestmoney = curwages;
		if (departmentlowestmoney[d] == 0)
			departmentlowestmoney[d] = curwages;
		if (departmentlowestmoney[d] > curwages)
			departmentlowestmoney[d] = curwages;
		if (departmenthighestmoney[d] < curwages)
			departmenthighestmoney[d] = curwages;
		if (lowestmoney > curwages)
			lowestmoney = curwages;
		if (highestmoney < curwages)
			highestmoney = curwages;
	};
	~manager() { --allmen; allmoney -= wages; };
	virtual void print(int y) {
		char a[20], c[20];
		int size = 0;
		itoa(id, a, 10);
		while (a[size++] != '\0');
		PrintChar(a, size, 24, y);
		size = 0;
		PrintChar(const_cast<char *>(name.c_str()), name.size(), 36, y);
		PrintChar(const_cast<char *>(department.c_str()), department.size(), 48, y);
		PrintChar(const_cast<char *>(pos.c_str()), pos.size(), 60, y);
		itoa(curwages, c, 10);
		while (c[size++] != '\0');
		PrintChar(c, size, 72, y);
	};

	virtual void coo(void) {
		char a[20];
		int size = 0;
		itoa(birth.year * 10000 + birth.month * 100 + birth.day, a, 10);
		while (a[size++] != '\0');
		PrintChar(const_cast<char *>(name.c_str()), name.size(), 38, 8);
		PrintChar(const_cast<char *>(sex.c_str()), sex.size(), 38, 11);
		PrintChar(const_cast<char *>(pos.c_str()), pos.size(), 38, 14);
		PrintChar(a, size, 63, 8);
	};

	virtual void privateprint(int y) {
		char a[20], b[20],c[20];
		int size = 0, size1 = 0, size2 = 0,size3=0,size4=0;
		worktime = 0;
		itoa(id, a, 10);
		itoa(birth.year*10000+birth.month*100+birth.day, b, 10);
		itoa(worktime, c, 10);
		
		while (a[size++] != '\0');
		while (b[size1++] != '\0');
		while (c[size2++] != '\0');

		if (y == 0) {
			PrintChar(const_cast<char *>(name.c_str()),name.size(), 38, 8);
			PrintChar(const_cast<char *>(sex.c_str()), sex.size(), 38, 11);
			PrintChar(const_cast<char *>(department.c_str()),department.size(), 38, 14);
			PrintChar(const_cast<char *>(pos.c_str()), pos.size(), 38, 17);

			PrintChar(a, size, 63, 8);
			PrintChar(b, size1, 61, 11);
			PrintChar("0", sizeof("0"), 65, 14);
			PrintChar("0", sizeof("0"), 65, 17);
		}
		if (y == 1) {
			PrintChar("0", sizeof("0"), 40, 8);
			PrintChar("8000", sizeof("8000"), 42, 11);
		}
	};

	virtual void save(std::ofstream&out) { out << pos << " "<< id << " " << name << " " << sex << " " << department << " " << birth.day << " " << birth.month << " " << birth.year ; };
};

class techman : public worker
{

public:
	static std::vector<techman>techmannum;
	techman() = default;
	techman(long i, std::string n, std::string s, std::string d, int dd, int m, int y, int w, std::string p = { "技术员" }) {
		setworker(i, n, s, d, p, 0, dd, m, y);
		worktime = w;
		setcurwages();
		++allmen; allmoney += curwages;
		departmentallmoney[d] += curwages;
		departmentpeople[d]++;
		if (lowestmoney == 0)
			lowestmoney = curwages;
		if (departmentlowestmoney[d] == 0)
			departmentlowestmoney[d] = curwages;
		if (departmentlowestmoney[d] > curwages)
			departmentlowestmoney[d] = curwages;
		if (departmenthighestmoney[d] < curwages)
			departmenthighestmoney[d] = curwages;
		if (lowestmoney > curwages)
			lowestmoney = curwages;
		if (highestmoney < curwages)
			highestmoney = curwages;
	};
	void setcurwages(void) { curwages = worktime*100; };
	~techman() { --allmen; allmoney -= curwages; };
	virtual void print(int y) {
		char a[20], c[20];
		int size = 0;
		itoa(id, a, 10);
		while (a[size++] != '\0');
		PrintChar(a, size, 24, y);
		size = 0;
		PrintChar(const_cast<char *>(name.c_str()), name.size(), 36, y);
		PrintChar(const_cast<char *>(department.c_str()), department.size(), 48, y);
		PrintChar(const_cast<char *>(pos.c_str()), pos.size(), 60, y);
		itoa(curwages, c, 10);
		while (c[size++] != '\0');
		PrintChar(c, size, 72, y);
	};

	virtual void save(std::ofstream&out) { out << pos << " " << id << " " << name << " " << sex << " " << department << " " << birth.day << " " << birth.month << " " << birth.year << " " << worktime << " " ; };

	virtual void coo(void) {
		char a[20];
		int size = 0;
		itoa(birth.year * 10000 + birth.month * 100 + birth.day, a, 10);
		while (a[size++] != '\0');
		PrintChar(const_cast<char *>(name.c_str()), name.size(), 38, 8);
		PrintChar(const_cast<char *>(sex.c_str()), sex.size(), 38, 11);
		PrintChar(const_cast<char *>(pos.c_str()), pos.size(), 38, 14);
		PrintChar(a, size, 63, 8);
	};

	virtual void privateprint(int y) {
		char a[20], b[20], c[20], d[20];
		int size = 0, size1 = 0, size2 = 0, size3 = 0;
		worktime = 0;
		itoa(id, a, 10);
		itoa(birth.year * 10000 + birth.month * 100 + birth.day, b, 10);
		itoa(worktime, c, 10);
		itoa(curwages, d, 10);

		while (a[size++] != '\0');
		while (b[size1++] != '\0');
		while (c[size2++] != '\0');
		while (d[size3++] != '\0');

		if (y == 0) {
			PrintChar(const_cast<char *>(name.c_str()), name.size(), 38, 8);
			PrintChar(const_cast<char *>(sex.c_str()), sex.size(), 38, 11);
			PrintChar(const_cast<char *>(department.c_str()), department.size(), 38, 14);
			PrintChar(const_cast<char *>(pos.c_str()), pos.size(), 38, 17);
			PrintChar(a, size, 63, 8);
			PrintChar(b, size1, 61, 11);
			PrintChar(c, size2, 65, 14);
			PrintChar("0", sizeof("0"), 65, 17);
		}
		if (y == 1) {
			PrintChar("0", sizeof("0"), 40, 8);
			PrintChar(d, size3, 42, 11);
		};
	}
};

class salesman : public worker
{
public:
	static std::vector<salesman>salesmannum;
	salesman() = default;
	salesman(long i, std::string n, std::string s, std::string d,int dd, int m, int y, double sm, std::string p = { "销售员" }){
		setworker(i, n, s, d, p, 0, dd, m, y);
		salesmoney = sm; departmentmoney[department] += sm;
		setcurwages();
		++allmen; allmoney += curwages;
		departmentallmoney[d] += curwages;
		departmentpeople[d]++;
		if (lowestmoney == 0)
			lowestmoney = curwages;
		if (departmentlowestmoney[d] == 0)
			departmentlowestmoney[d] = curwages;
		if (departmentlowestmoney[d] > curwages)
			departmentlowestmoney[d] = curwages;
		if (departmenthighestmoney[d] < curwages)
			departmenthighestmoney[d] = curwages;
		if (lowestmoney > curwages)
			lowestmoney = curwages;
		if (highestmoney < curwages)
			highestmoney = curwages;
	};
	void setcurwages(void) { curwages = salesmoney*0.04; };
	~salesman() { --allmen; allmoney -= curwages; };
	virtual void print(int y) {
		char a[20], c[20];
		int size = 0;
		itoa(id, a, 10);
		while (a[size++] != '\0');
		PrintChar(a, size, 24, y);
		size = 0;
		PrintChar(const_cast<char *>(name.c_str()), name.size(), 36, y);
		PrintChar(const_cast<char *>(department.c_str()), department.size(), 48, y);
		PrintChar(const_cast<char *>(pos.c_str()), pos.size(), 60, y);
		itoa(curwages, c, 10);
		while (c[size++] != '\0');
		PrintChar(c, size, 72, y);
	};

	virtual void save(std::ofstream&out) { out << pos << " " << id << " " << name << " " << sex << " " << department << " " << birth.day << " " << birth.month << " " << birth.year << " " << salesmoney << " " ; };

	virtual void coo(void) {
		char a[20];
		int size = 0;
		itoa(birth.year * 10000 + birth.month * 100 + birth.day, a, 10);
		while (a[size++] != '\0');
		PrintChar(const_cast<char *>(name.c_str()), name.size(), 38, 8);
		PrintChar(const_cast<char *>(sex.c_str()), sex.size(), 38, 11);
		PrintChar(const_cast<char *>(pos.c_str()), pos.size(), 38, 14);
		PrintChar(a, size, 63, 8);
	};

	virtual void privateprint(int y) {
		char a[20], b[20], c[20], d[20];
		int size = 0, size1 = 0, size2 = 0, size3 = 0;
		worktime = 0;
		itoa(id, a, 10);
		itoa(birth.year * 10000 + birth.month * 100 + birth.day, b, 10);
		itoa(salesmoney, c, 10);
		itoa(curwages, d, 10);

		while (a[size++] != '\0');
		while (b[size1++] != '\0');
		while (c[size2++] != '\0');
		while (d[size3++] != '\0');

		if (y == 0) {
			
			PrintChar(const_cast<char *>(name.c_str()), name.size(), 38, 8);
			PrintChar(const_cast<char *>(sex.c_str()), sex.size(), 38, 11);
			PrintChar(const_cast<char *>(department.c_str()), department.size(), 38, 14);
			PrintChar(const_cast<char *>(pos.c_str()), pos.size(), 38, 17);
			PrintChar(a, size, 63, 8);
			PrintChar(b, size1, 61, 11);
			PrintChar("0", sizeof("0"), 65, 14);
			PrintChar("0", sizeof("0"), 65, 17);
		}
		if (y == 1) {
			PrintChar(c, size2, 40, 8);
			PrintChar(d, size3, 42, 11);
		};
	};
};

class salesmanager : public worker
{
public:
	static std::vector<salesmanager>salesmanagernum;
	salesmanager() = default;
	salesmanager(long i, std::string n, std::string s, std::string d, int dd, int m, int y, std::string p = { "销售经理" }) {
		setworker(i, n, s, d, p, 0, dd, m, y);
		departmentsalesmanager[department]++;
		departmentpeople[d]++;
		if (lowestmoney == 0)
			lowestmoney = curwages;
		if (departmentlowestmoney[d] == 0)
			departmentlowestmoney[d] = curwages;
	};
	~salesmanager() { --allmen; allmoney -= curwages; };
	bool hassalesmanager(void) { return departmentsalesmanager[department] ? true : false; };
	virtual void print(int y) {
		char a[20], c[20];
		int size = 0;
		itoa(id, a, 10);
		while (a[size++] != '\0');
		PrintChar(a, size, 24, y);
		size = 0;
		PrintChar(const_cast<char *>(name.c_str()), name.size(), 36, y);
		PrintChar(const_cast<char *>(department.c_str()), department.size(), 48, y);
		PrintChar(const_cast<char *>(pos.c_str()), pos.size(), 60, y);
		itoa(curwages, c, 10);
		while (c[size++] != '\0');
		PrintChar(c, size, 72, y);
	};

	virtual void save(std::ofstream&out) { out << pos << " " << id << " " << name << " " << sex << " " << department << " " << birth.day << " " << birth.month << " " << birth.year << " " ; };

	virtual void coo(void) {
		char a[20];
		int size = 0;
		itoa(birth.year * 10000 + birth.month * 100 + birth.day, a, 10);
		while (a[size++] != '\0');
		PrintChar(const_cast<char *>(name.c_str()), name.size(), 38, 8);
		PrintChar(const_cast<char *>(sex.c_str()), sex.size(), 38, 11);
		PrintChar(const_cast<char *>(pos.c_str()), pos.size(), 38, 14);
		PrintChar(a, size, 63, 8);
	}

	virtual void privateprint(int y) {
		char a[20], b[20], c[20], d[20];
		int size = 0, size1 = 0, size2 = 0, size3 = 0;
		worktime = 0;
		itoa(id, a, 10);
		itoa(birth.year * 10000 + birth.month * 100 + birth.day, b, 10);
		itoa(salesmoney, c, 10);
		itoa(curwages, d, 10);

		while (a[size++] != '\0');
		while (b[size1++] != '\0');
		while (c[size2++] != '\0');
		while (d[size3++] != '\0');

		if (y == 0) {
			
			PrintChar(const_cast<char *>(name.c_str()), name.size(), 38, 8);
			PrintChar(const_cast<char *>(sex.c_str()), sex.size(), 38, 11);
			PrintChar(const_cast<char *>(department.c_str()), department.size(), 38, 14);
			PrintChar(const_cast<char *>(pos.c_str()), pos.size(), 38, 17);
			PrintChar(a, size, 63, 8);
			PrintChar(b, size1, 61, 11);
			PrintChar("0", sizeof("0"), 65, 14);
			PrintChar("5000", sizeof("5000"), 65, 17);
		}
		if (y == 1) {
			PrintChar("0", sizeof("0"), 40, 8);
			PrintChar(d, size3, 42, 11);
		};
	};


	void renewsalesmanager(void) { 
	curwages = basewages + departmentmoney[department] * 0.005; 
	++allmen; allmoney += curwages;		
	departmentallmoney[department] += curwages;
	if (departmentlowestmoney[department] > curwages)
		departmentlowestmoney[department] = curwages;
	if (departmenthighestmoney[department] < curwages)
		departmenthighestmoney[department] = curwages;
	if (lowestmoney > curwages)
		lowestmoney = curwages;
	if (highestmoney < curwages)
		highestmoney = curwages;
	};
};




#endif