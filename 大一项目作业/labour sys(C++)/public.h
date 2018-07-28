#ifndef PUBLIC_H
#define PUBLIC_H


/*
	����ѡ����Ĳ��ź�ʱ��(�·�)
*/


//�궨��
#define MAXCOL 80		
#define MAXROW 40
#define tab	"��"
#define SHOWDATA 5   //һҳ��ʾʱ����������
#define SHOWLIST 9	 //һҳ��ʾԱ������ 
#define MODE0 100    //����ж��¼�0 sample::welcome
#define	MODE1 101    //����ж�1 sample::boundary
#define	MODE2 102	 //����ж�2 loadin:loadin
#define	MODE3 103	 //����ж�3 loadin:boundary
#define MODE4 104	 //����ж�4 samples:qtime
#define MODE5 105	 //����ж�4 samples:qdepartment
#define MODE6 106	 //����ж�4 samples:qpos
#define MODE7 107	 //����ж�4 samples:qcount
#define MODE8 108	 //����ж�8 sample::backgound12
#define MODE9 109	 //����ж�9 sample::��������
#define MODE10 110	 //����ж�10 sample::qhelp
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

//ȫ�ֱ�������
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

//ͷ�ļ�
#include<stdlib.h>
#include<iostream>
#include<windows.h>     //mouse.h�������ͷ�ļ�
#include<fstream>		//�ļ��������ͷ�ļ�
#include<conio.h>		//getch()ͷ�ļ�
#include<atlimage.h>	//����ͼƬ���ͷ�ļ�
#include <time.h>		//�ӳٺ���ͷ�ļ�
#include<vector>
#include<memory>
#include<string>
#include<algorithm>
#include<io.h>
#include<map>


//��������

//loadin.cpp
void loadin(void);		//Ĭ���ο�Ա����½��
void loadprocess(void);//��½���̲���


//PrintChar.cpp
void PrintChar(char *ch, UINT count, UINT x, UINT y);	//�������ӡ�ַ�

//mouse.cpp
int input(int X,int Y);			//��������ֵ
void HideCursor();		//���ؿ���̨�Ĺ��
void ShowCursor();		//��ʾ����̨���
void mouse(char* argv[]);			//�������

//1~5Ϊ��ȡ�ж����������Ϣword[5];
std::string mouseprocess1();
std::string mouseprocess2();
std::string mouseprocess3();
std::string mouseprocess4();
std::string mouseprocess5();

//��������²���
std::string mouseprocess6();
bool mouseprocess7(std::string newdepartment);
//����������·�
bool mouseprocess8(std::string newdepartment);
bool mouseprocess9(void);

//samples.cpp

void boundary();		//��½�˵�
void welcome();			//��ӭ����
void exitsys();			//�˳�ϵͳ
void payrule();			//����ϸ��
void delay(int set);	//�ӳٺ���������˸����
void ClearScreen(void); //��������
void background(int);		//����1(��������)
void background2(int);		//����2(��ѯ����)
void background3(int);		//����3(��������)
void background4(int);		//����4(��������)
void background5(int);		//����5(��λ����)
void background6(int);		//����6(�������)
void background7(int);		//����7(������Ϣ��)
void background8(int);		//����8(������Ϣ��2)
void background9(void);		//����9(������Ϣ���Ҽ�����)
void background10(int);		//����10(��ӳ�Ա��)
void background11(int);		//����11(��ܰ��ʾ)
void background12(int);		//����12��Ӳ���
void background13(int);		//����13����·�
void background22(int);		//����22
void sss(int page);			
void qtime(int page);			//��ѯ����
void qdepartment(int page);		//��ѯ����
void qpos(void);			//��ѯ��λ
void qcount(void);			//ͳ�ƽ��
void qhelp(void);			//��������
void getFiles(std::string path, std::vector<std::string>& files);	//��ȡĿ¼.txt�ļ�
void renew(char* argv[]);	//���µ���
void idsort(int dep);				//��id����
void namesort(int dep);			//����������	
void possort(int dep);				//����λ����
void wagessort(int dep);			//����������
void departmentsort(int dep);		//����������
void findname(const std::string&b);	//��ѯ����
void findid(const int id);			//��ѯid
bool fn(const std::string&b);		
bool fi(const int id);
void datapageup();					//�·���һҳ
void datapagedown();				//�·���һҳ
void savedepartment();				//���ڱ��沿��
bool qdepartmentup(int page);		//���ڲ��ŷ���һҳ
bool qdepartmentdown(int page);		//���ڲ��ŷ���һҳ
bool makedepartmentsure(int f);				//ȷ��ɾ��
bool makedatasure(int f);				//ȷ��ɾ��
void renewdepartment();				//��ȡ����
void renew(char* argv[]);				//��ȡʱ��
bool qdataup(int page);		//�����·ݷ���һҳ
bool qdatadown(int page);		//�����·ݷ���һҳ
void adddata(const std::string&c);	//������·�
void deletedata(const std::string&c);//ɾ���·�
void qtimetrue(int page);				//�·���Ϣ
void openfile(int i);					//��ȡԱ����Ϣ
void savefile(int i);					//����Ա����Ϣ
bool showlistup(int page);				//չ¶������Ϣ��һҳ
bool showlistdown(int page);			//չ¶������Ϣ��һҳ
void showlist(int page);				//չ¶������Ϣ
void getlist(int dep);
bool showlistup(int page,int dep);				//չ¶������Ϣ��һҳ
bool showlistdown(int page, int dep);			//չ¶������Ϣ��һҳ
void showlist(int page, int dep);				//չ¶������Ϣ
void deleteone(int num, int open, char* argv[]);	//ɾ����
void departmentwages(const std::string &department);	//ͳ��
void allmenwages();										//ͳ��


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
	static std::map<std::string, int>departmentmoney;//ÿ�����ŵ����۶�
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
	manager(long i, std::string n, std::string s, std::string d, int dd, int m, int y, std::string p={ "����" }) {
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
	techman(long i, std::string n, std::string s, std::string d, int dd, int m, int y, int w, std::string p = { "����Ա" }) {
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
	salesman(long i, std::string n, std::string s, std::string d,int dd, int m, int y, double sm, std::string p = { "����Ա" }){
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
	salesmanager(long i, std::string n, std::string s, std::string d, int dd, int m, int y, std::string p = { "���۾���" }) {
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