#include"public.h"
using namespace std;


void loadin(void) {
	int i;
	int temp = 0;
	int zzz = 0;
	char secret[7];
	char c;
	ClearScreen();
	for (i = 0; i < MAXCOL; i++)								//边框
		cout<<"*";
	cout << "\n\n\t\t    ┌────────────────────┐\n";
	cout << "\t\t    │               用户登录                 │\n";
	cout << "\t\t    │   ┌───────────────┐   │\n";
	cout << "\t\t    │   │  账户名：dgut                │   │\n";
	cout << "\t\t    │   └───────────────┘   │\n";
	cout << "\t\t    │   ┌───────────────┐   │\n";
	cout << "\t\t    │   │  密码：                      │   │\n";
	cout << "\t\t    │   └───────────────┘   │\n";
	cout << "\t\t    │                                        │\n";
	cout << "\t\t    │                                        │\n";
	cout << "\t\t    │                                        │\n";
	cout << "\t\t    │                                        │\n";
	cout << "\t\t    │                    初始密码：123456    │\n";
	cout << "\t\t    └────────────────────┘\n\n";
	cout << "                                                        请输入回车键进入系统.\n";
	for (i = 0; i < MAXCOL; i++)
		cout << "*";
}

void loadprocess(void) {
	int i;
	int flag = 0;
	int temp = 0;
	char secret[9];
	char c;
	while (1) {
		c = getch();
		if (temp < 6)
			secret[temp] = c;
		switch (c) {
		case 27:case 8:
			if (temp == 0)
				continue;
			temp--;
			ClearScreen();
			for (i = 0; i < MAXCOL; i++)								//边框
				cout << "*";
			cout << "\n\n\t\t    ┌────────────────────┐\n";
			cout << "\t\t    │               用户登录                 │\n";
			cout << "\t\t    │   ┌───────────────┐   │\n";
			cout << "\t\t    │   │  账户名：dgut                │   │\n";
			cout << "\t\t    │   └───────────────┘   │\n";
			cout << "\t\t    │   ┌───────────────┐   │\n";
			cout << "\t\t    │   │  密码：";
			for (i = 0; i < temp; i++)
				cout << "*";
			for (i = 0; i < 6 - temp; i++)
				cout << " ";
			cout << "                │   │\n";
			cout << "\t\t    │   └───────────────┘   │\n";
			cout << "\t\t    │                                        │\n";
			cout << "\t\t    │                                        │\n";
			cout << "\t\t    │                                        │\n";
			cout << "\t\t    │                                        │\n";
			cout << "\t\t    │                    初始密码：123456    │\n";
			cout << "\t\t    └────────────────────┘\n\n";
			cout << "                                                        请输入回车键进入系统.\n";
			for (i = 0; i < MAXCOL; i++)
				cout << "*";
			break;



		case '\n':case '\r':
			secret[temp] = '\0';
			if (strcmp(secret, "123456") == 0) {
				cout << "登陆成功.";
				delay(1);
				ClearScreen();
				background(2);
				PrintChar("欢迎使用本员工工资系统.", sizeof("欢迎使用本员工工资系统."), 25,  1);
				flag = 1;
			}
			else {
				cout << "密码错误，请重新输入.";
				temp = 0;
				cout << endl;
				getchar();
				for (i = 0; i < 6; i++)
					secret[i] = '0';
				secret[i] = '\0';
				loadprocess();
			}
			break;



		default:
			if (temp < 6)
				temp++;
			ClearScreen();
			for (i = 0; i < MAXCOL; i++)								//边框
				cout << "*";
			cout << "\n\n\t\t    ┌────────────────────┐\n";
			cout << "\t\t    │               用户登录                 │\n";
			cout << "\t\t    │   ┌───────────────┐   │\n";
			cout << "\t\t    │   │  账户名：dgut                │   │\n";
			cout << "\t\t    │   └───────────────┘   │\n";
			cout << "\t\t    │   ┌───────────────┐   │\n";
			cout << "\t\t    │   │  密码：";
			for (i = 0; i < temp; i++)
				cout << "*";
			for (i = 0; i < 6 - temp; i++)
				cout << " ";
			cout << "                │   │\n";
			cout << "\t\t    │   └───────────────┘   │\n";
			cout << "\t\t    │                                        │\n";
			cout << "\t\t    │                                        │\n";
			cout << "\t\t    │                                        │\n";
			cout << "\t\t    │                                        │\n";
			cout << "\t\t    │                    初始密码：123456    │\n";
			cout << "\t\t    └────────────────────┘\n\n";
			cout << "                                                        请输入回车键进入系统.\n";
			for (i = 0; i < MAXCOL; i++)
				cout << "*";
			break;
		}
		if (flag == 1)
			break;
	}
}