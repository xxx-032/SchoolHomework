#include"public.h"
using namespace std;


void loadin(void) {
	int i;
	int temp = 0;
	int zzz = 0;
	char secret[7];
	char c;
	ClearScreen();
	for (i = 0; i < MAXCOL; i++)								//�߿�
		cout<<"*";
	cout << "\n\n\t\t    ��������������������������������������������\n";
	cout << "\t\t    ��               �û���¼                 ��\n";
	cout << "\t\t    ��   ����������������������������������   ��\n";
	cout << "\t\t    ��   ��  �˻�����dgut                ��   ��\n";
	cout << "\t\t    ��   ����������������������������������   ��\n";
	cout << "\t\t    ��   ����������������������������������   ��\n";
	cout << "\t\t    ��   ��  ���룺                      ��   ��\n";
	cout << "\t\t    ��   ����������������������������������   ��\n";
	cout << "\t\t    ��                                        ��\n";
	cout << "\t\t    ��                                        ��\n";
	cout << "\t\t    ��                                        ��\n";
	cout << "\t\t    ��                                        ��\n";
	cout << "\t\t    ��                    ��ʼ���룺123456    ��\n";
	cout << "\t\t    ��������������������������������������������\n\n";
	cout << "                                                        ������س�������ϵͳ.\n";
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
			for (i = 0; i < MAXCOL; i++)								//�߿�
				cout << "*";
			cout << "\n\n\t\t    ��������������������������������������������\n";
			cout << "\t\t    ��               �û���¼                 ��\n";
			cout << "\t\t    ��   ����������������������������������   ��\n";
			cout << "\t\t    ��   ��  �˻�����dgut                ��   ��\n";
			cout << "\t\t    ��   ����������������������������������   ��\n";
			cout << "\t\t    ��   ����������������������������������   ��\n";
			cout << "\t\t    ��   ��  ���룺";
			for (i = 0; i < temp; i++)
				cout << "*";
			for (i = 0; i < 6 - temp; i++)
				cout << " ";
			cout << "                ��   ��\n";
			cout << "\t\t    ��   ����������������������������������   ��\n";
			cout << "\t\t    ��                                        ��\n";
			cout << "\t\t    ��                                        ��\n";
			cout << "\t\t    ��                                        ��\n";
			cout << "\t\t    ��                                        ��\n";
			cout << "\t\t    ��                    ��ʼ���룺123456    ��\n";
			cout << "\t\t    ��������������������������������������������\n\n";
			cout << "                                                        ������س�������ϵͳ.\n";
			for (i = 0; i < MAXCOL; i++)
				cout << "*";
			break;



		case '\n':case '\r':
			secret[temp] = '\0';
			if (strcmp(secret, "123456") == 0) {
				cout << "��½�ɹ�.";
				delay(1);
				ClearScreen();
				background(2);
				PrintChar("��ӭʹ�ñ�Ա������ϵͳ.", sizeof("��ӭʹ�ñ�Ա������ϵͳ."), 25,  1);
				flag = 1;
			}
			else {
				cout << "�����������������.";
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
			for (i = 0; i < MAXCOL; i++)								//�߿�
				cout << "*";
			cout << "\n\n\t\t    ��������������������������������������������\n";
			cout << "\t\t    ��               �û���¼                 ��\n";
			cout << "\t\t    ��   ����������������������������������   ��\n";
			cout << "\t\t    ��   ��  �˻�����dgut                ��   ��\n";
			cout << "\t\t    ��   ����������������������������������   ��\n";
			cout << "\t\t    ��   ����������������������������������   ��\n";
			cout << "\t\t    ��   ��  ���룺";
			for (i = 0; i < temp; i++)
				cout << "*";
			for (i = 0; i < 6 - temp; i++)
				cout << " ";
			cout << "                ��   ��\n";
			cout << "\t\t    ��   ����������������������������������   ��\n";
			cout << "\t\t    ��                                        ��\n";
			cout << "\t\t    ��                                        ��\n";
			cout << "\t\t    ��                                        ��\n";
			cout << "\t\t    ��                                        ��\n";
			cout << "\t\t    ��                    ��ʼ���룺123456    ��\n";
			cout << "\t\t    ��������������������������������������������\n\n";
			cout << "                                                        ������س�������ϵͳ.\n";
			for (i = 0; i < MAXCOL; i++)
				cout << "*";
			break;
		}
		if (flag == 1)
			break;
	}
}