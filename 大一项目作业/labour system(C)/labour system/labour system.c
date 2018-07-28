#include<stdio.h>;
#include<stdlib.h>;

enum department { ���۲� = 1, ������ = 2, ���²� = 3 };
enum POST { ���۾��� = 1, ����Ա = 2, ����Ա = 3, ���� = 4 };
#define MAXCOL 80		
#define MAXROW 40

/*
1)	����Ա����Ϣ�����¹��ʴӸߵ���������ʾ��
2)	ĳ����λ��Ա����Ϣ�����¹��ʴӸߵ���������ʾ��
6.	ͳ�ƣ�
1)	ͳ�Ʋ���ʾĳ�����ŵ�ƽ�����ʡ���͹��ʡ���߹��ʡ�
2)	ͳ�Ʋ���ʾĳ�����ų���ƽ�����ʵ�������Ա����Ϣ��
3)	ͳ�Ʋ���ʾ����Ա���е���͹��ʺ���߹���Ա������Ϣ��
4)	ͳ�Ʋ���ʾ����Ա������ƽ�����ʵ�������Ա����Ϣ��

*/

struct labour {
	int num;
	int file;
	int department;
	int post;
	char name[20];
	char sex[10];
	int age;
	double worktime;
	double salesmoney;
	double basemoney;
	double wages;
	struct labour *next;
}*head = NULL, *rhead = NULL;
char document[25] = "Ա����Ա����";
int Ap = 0, Pt = 0, sum = 0;
char Pfilenum = '\0';
int jihao = 1;
int biaozhi = 1;
int permonth[50] = { 0 };
int per = 0;

void main(void)
{
	/*
	����
	��ӭ����
	ѡ������
	ʵ�ֹ��ܣ�1.	�������  2.	�޸�����  3.	ɾ������  4.	��ѯ���� ��

	*/
	system("cls");
	void loadin(void);
	void add(void);
	int inquirAp(void);
	int inquirPt(void);
	void home(void);
	void payrule(void);
	void End(void);
	void Menu(void);
	int i;
	system("mode con cols=80 lines=40");						//������ʾ��������С
	for (i = 0; i < MAXCOL; i++)								//�߿�
		printf("*");
	printf("\n\n\n\n");
	for (i = 0; i < MAXCOL / 4; i++)								//����
		printf(" ");
	printf("��ӭʹ�ñ�Ա�����ʹ���ϵͳ.\n\n\n\n\n");
	for (i = 0; i < MAXCOL * 5 / 8; i++)								//����
		printf(" ");
	printf("������س�������ϵͳ.\n");
	for (i = 0; i < MAXCOL; i++)
		printf("*");
	getchar();
	loadin();
}


void Menu(void) {
	int i, choice;
	system("cls");
	printf("\t\t\t��ӭʹ��Ա�����ʹ���ϵͳ.\n");
	for (i = 0; i < MAXCOL; i++)								//�߿�
		printf("*");
	printf("\n\n");
	printf("\t\t\t  1.��ѯ����.\n");
	printf("\n\n");
	printf("\t\t\t  2.����ϸ��.\n");
	printf("\n\n");
	printf("\t\t\t  3.�˳���ϵͳ.\n");
	printf("\n\n");
	printf("\t\t\t\t\t\t��������:\n");
	printf("\t\t\t\t\t\t\t      ��������\n");
	printf("\t\t\t\t\t\t��\t      ��    ��\n");
	printf("\t\t\t\t\t\t \t��������    ��\n");
	printf("\t\t\t\t\t  ��    ��   �� ��   �س�   ��\n");
	printf("\t\t\t\t\t\t\t��������������\n");

	printf("\t\t\t\t\t����������������\n");
	printf("\t\t\t\t\t��    �ո�    ��\n");
	printf("\t\t\t\t\t����������������\n");
	for (i = 0; i < MAXCOL; i++)
		printf("*");
	while (1) {
		printf("���������ѡ��,�����س�ȷ�����ѡ��:");
		scanf("%d", &choice);
		getchar();
		switch (choice) {
		case 1:
			home();
			break;
		case 2:
			payrule();
			Menu();
			break;
		case 3:
			End();
		default:
			printf("�������,������˵�����Ӧ������.\n");
		}
	}
}


//�޸��������������ˡ��ǵø�
void add(void) {
	FILE *fp;
	int file;
	char name[30];
	int flen;
	int k = 0;
	int i;
	int temp;
	int member[50] = { 0 };
	int hh[50] = { 0 };
	int filenum = 0;
	int allsalesmoney = 0;					//û��ɵģ������Ҹ�λ�ö���ȥ.��add
	struct labour  *p = NULL, *p0 = NULL, *p1 = NULL, *p2 = NULL, *p3 = NULL, *zz = NULL,*zzz=NULL;			//*p�����û�����


	p1 = (struct labour*)malloc(sizeof(struct labour));

	if ((fp = fopen(document, "rb")) != NULL) {
		fseek(fp, -8, SEEK_END);
		flen = ftell(fp);
		fseek(fp, 0, SEEK_SET);
		if (flen == ftell(fp)) {
		}
		else {
			while (ftell(fp) != flen) {
				fread(p1, sizeof(struct labour), 1, fp);
				temp = p1->file;
				if (p1->file == (p1->num % 100))
					member[k]++;
			

				if (temp != hh[per]) {
					hh[k] = temp;
					k++;
					permonth[k] = p1->file;
				}
				p1 = (struct labour*)malloc(sizeof(struct labour));
			}
		}
	}

	free(p1);

	p = (struct labour*)malloc(sizeof(struct labour));


	printf("�������Ա����ְ������ݺ��·�(eg:201608):");
	scanf("%d", &file);
	while (getchar() != '\n') continue;
	for (i = 0; i < 50; i++) {
		if (hh[i] == file) {
			k = i;
			break;
		}
		else if (hh[i] == 0) {
			k = i;
			break;
		}
		else
			k++;
	}

	printf("������Ա��������");
	scanf("%s", p->name);
	while (getchar() != '\n') continue;

	p->file = file;

	zzz = head;
	if(zzz==NULL) {
		filenum = member[k];
		p->num = file * 100 + filenum + 1;
	}
	else {
		while (zzz != NULL) {
			if (strcmp(p->name, zzz->name) == 0) {

				p->num = zzz->num;
				break;
			}
			else {
				filenum = member[k];
				p->num = file * 100 + filenum + 1;
			}
			zzz = zzz->next;
		}
	}
	printf("������Ա���Ա�");
	scanf("%s", p->sex);
	while (getchar() != '\n') continue;
	printf("������Ա�����䣺");
	scanf("%d", &p->age);
	while (getchar() != '\n') continue;
	enum department b;
	enum POST a;
	printf("		1.���۲�	2.������	3.���²�\n");
	do {
		printf("�밴������ʾȷ��Ա����������,�����س�ȷ�����ѡ��:");
		scanf("%d", &b);
		while (getchar() != '\n') continue;
		switch (b) {
		case ���۲�:
			p->department = ���۲�;
			break;
		case ������:
			p->department = ������;
			break;
		case ���²�:
			p->department = ���²�;
			break;
		default:
			printf("�������,�����벿�Ŷ�Ӧ������.\n");
			getchar();
			break;
		}
	} while (b < 1 && b > 3);

	printf("		1.���۾���	2.����Ա	3.����Ա	4.����\n");
	do {

		printf("�밴������ʾȷ��Ա������ְ��,�����س�ȷ�����ѡ��:");
		scanf("%d", &a);
		while (getchar() != '\n') continue;
		switch (a) {
		case ���۾���:
			p1 = head;
			while (p1 != NULL) {
				if (p->file == p1->file)
					if (p1->post == ���۾���&&p1->department == b) {
						printf("ÿ������ֻ����һ�����۾���,����ʧ��.\n");
						printf("��������ص�������.");
						getchar();
						home();
					}
				p1 = p1->next;
			}
			p->post = ���۾���;
			p->worktime = 0;
			p->salesmoney = 0;
			p->basemoney = 5000;
			p->wages = p->basemoney + allsalesmoney*0.05;
			break;
		case ����Ա:
			p->post = ����Ա;
			p->worktime = 0;
			printf("�������Ա���������Ÿ������۶");
			scanf("%lf", &p->salesmoney);
			allsalesmoney += p->salesmoney;
			p->basemoney = 0;
			p->wages = p->salesmoney*0.4;
			break;
		case ����Ա:
			p->post = ����Ա;
			printf("�������Ա�����¹���ʱ��(�ۼ�Сʱ����)��");
			scanf("%lf", &p->worktime);
			p->basemoney = 0;
			p->wages = (p->worktime) * 100;
			break;
		case ����:
			p->post = ����;
			p->worktime = 0;
			p->basemoney = 0;
			p->wages = 8000;
			break;
		default:
			printf("�������,������ְ���Ӧ������.\n");
			getchar();
		}
	} while (a < 1 && a > 4);



	p0 = p;
	p1 = head;

	if (head == NULL) {
		head = p0;
		p0->next = NULL;
	}
	else {
		//���Ӹ��ж�file�·ݵ�
		if (p->file > head->file) {
			p0->next = head;
			head = p0;
		}
		else {
			while ((p0->file < p1->file) && (p1->next != NULL)) {
				p3 = p1;
				p1 = p1->next;
			}
			if (p1->file == p0->file) {
				while ((p0->wages <= p1->wages) && (p1->next != NULL)) {
					p2 = p1;
					p1 = p1->next;
				}
				if (p0->wages > p1->wages) {
					p0->next = p1;
					p3->next = p0;
				}

				else if (p1->next == NULL) {
					p1->next = p0;
					p0->next = NULL;
				}
				else {
					p2->next = p0;
					p0->next = p1;
				}
			}
			else if (p1->next == NULL) {
				p1->next = p0;
				p0->next = NULL;
			}
			else {
				p3->next = p0;
				p0->next = p1;
			}
		}
	}

	p1 = head;

	fp = fopen(document, "wb");
	while (p1 != NULL) {
		fwrite(p1, sizeof(struct labour), 1, fp);
		p1 = p1->next;
	}

	filenum += 1;

	fwrite(&filenum, sizeof(int), 1, fp);
	fwrite(&allsalesmoney, sizeof(int), 1, fp);

	fclose(fp);
	per = 0;
	printf("��ӳɹ�,�ٴ�����س����ص�ϵͳ.");
	getchar();
}


int inquirAp(void) {			//������ʾ��Ϣ		һҳһ�����������ӡ������ǲ��ţ�
	int b;
	printf("		1.���۲�		2.������		3.���²�\n\n");						//ѡ���Ӧ���ֱ߿��Ա����Ϣ.
	do {
		printf("�밴������ʾȷ����ѯ�Ĳ�����Ϣ,�����س�ȷ�����ѡ��:");
		scanf("%d", &b);
		getchar();
		switch (b) {
		case ���۲�:

			break;
		case ������:

			break;
		case ���²�:

			break;
		default:
			printf("�������,�����벿�Ŷ�Ӧ������.\n");
			getchar();
			break;
		}
	} while (b < 1 && b > 3);


	return b;

}	   //�߿�ûŪ�õ�



int inquirPt(void) {			//ְλ��ʾ��Ϣ
	int a;

	printf("		1.���۾���	2.����Ա	3.����Ա	4.����\n\n");
	do {

		printf("�밴������ʾȷ��Ա������ְ��,�����س�ȷ�����ѡ��:");
		scanf("%d", &a);
		while (getchar() != '\n') continue;
		switch (a) {
		case ���۾���:

			break;
		case ����Ա:

			break;
		case ����Ա:

			break;
		case ����:

			break;
		default:
			printf("�������,�������ѯְ���Ӧ������.\n");
			getchar();
		}
	} while (a < 1 && a > 4);

	return a;

}



void End(void) {
	int i;
	system("cls");
	for (i = 0; i < MAXCOL; i++)
		printf("*");
	printf("\n\n");
	printf("\n\n\t��лʹ�ñ�ϵͳ�����������뼰ʱ������Ա����...\n\n\n");
	printf("\n\n");
	for (i = 0; i < MAXCOL; i++)
		printf("*");
	exit(0);
}



void home(void) {
	int choices, i, k = 0;
	int flen = 0, len = 0, choice, psum = 0, rsum = 0;
	int filenum = 0;
	int allsalesmoney = 0;			//������ȫ��ƽ������
	int xswages = 0, rswages = 0, jswages = 0;			//ÿ���Ź���
	int xssalesmoney = 0, rssalesmoney = 0, jssalesmoney = 0;		//ÿ�������۹���
	int flag = 0;			//Ap,Pt
	int allsum = 0;			//ƽ����������
	double allwages = 0;		//ÿ��ȫ������.
	int asum = 0, rpsum = 0;
	int Apwages = 0;
	int temp;
	int time = 0;
	int ca, ca1, ca2;
	FILE *fp;
	char c;
	struct labour *b = NULL;
	struct labour *tempp = NULL, *hey = NULL;
	struct labour *p = NULL, *p0 = NULL, *p1 = NULL, *p2 = NULL, *zz = NULL, *Aphead = NULL, *Ap2 = NULL, *Ap1 = NULL, *zz2 = NULL, *Aptemp = NULL, *Aptemp1 = NULL;
	system("cls");
	if (Ap == 0) {
		per = 0;
		for (i = 0; i < 50; i++)
			permonth[i] = 0;
	}
	if ((fp = fopen(document, "rb")) != NULL) {
		fseek(fp, -8, SEEK_END);
		flen = ftell(fp);
		fseek(fp, 0, SEEK_SET);
		if (flen == ftell(fp)) {
		}
		else {
			sum = 0;
			p = (struct labour*)malloc(sizeof(struct labour));
			Ap1 = (struct labour*)malloc(sizeof(struct labour));
			head = p;
			while (ftell(fp) != flen) {
				asum++;
				if (Ap != 0) {
					{
						flag = 1;
						fread(Ap1, sizeof(struct labour), 1, fp);
						if( permonth[per] == Ap1->file )
						if (Ap1->department == Ap) {
							if (Aphead == NULL) {
								Aphead = Ap1;
								Ap1->next = NULL;
							}
							temp = Ap1->file;
							if (permonth[k] == 0) {
								permonth[k] = temp;
							}
							else if (temp != permonth[per]) {
								k++;
								permonth[k] = Ap1->file;
							}
							if (Ap1->file == permonth[per]) {
								switch (Ap1->department) {
								case ���۲�:
									xssalesmoney += Ap1->salesmoney;
									break;
								case ������:
									jssalesmoney += Ap1->salesmoney;
									break;
								case ���²�:
									rssalesmoney += Ap1->salesmoney;
									break;
								}
							}
							Ap2 = (struct labour*)malloc(sizeof(struct labour));
							zz2 = Ap1;
							Ap1->next = Ap2;
							Ap1 = Ap2;
						}
					}
				}
				else {
					fread(p, sizeof(struct labour), 1, fp);
					temp = p->file;
					if (permonth[k] == 0)
						permonth[k] = temp;
					else if (temp != permonth[per]) {
						k++;
						permonth[k] = p->file;
					}
					if (p->file == permonth[per]) {
						switch (p->department) {
						case ���۲�:
							xssalesmoney += p->salesmoney;
							break;
						case ������:
							jssalesmoney += p->salesmoney;
							break;
						case ���²�:
							rssalesmoney += p->salesmoney;
							break;
						}
					}
					p0 = (struct labour*)malloc(sizeof(struct labour));
					zz = p;
					p->next = p0;
					p = p0;

				}
			}
		}
	}
	else {
		fp = fopen(document, "wb");
	}
	if (Ap != 0) {
		if (Aphead != NULL) {
			if (zz2 != NULL)
				zz2->next = NULL;
			fread(&filenum, sizeof(int), 1, fp);
			fread(&allsalesmoney, sizeof(int), 1, fp);
			fclose(fp);
		}
	}
	else {
		if (head != NULL) {
			zz->next = NULL;
			fread(&filenum, sizeof(int), 1, fp);
			fread(&allsalesmoney, sizeof(int), 1, fp);
			fclose(fp);
		}
	}

	if (Pt != 0) {
		flag = 2;
	}

	if (Ap != 0)
		p0 = Aphead;
	else
		p0 = head;


	allwages = 0; Apwages = 0;
	while (p0 != NULL&&p0->file == permonth[per]) {
		switch (p0->department) {
		case ���۲�:
			if (p0->post == ���۾���) {
				p0->wages = xssalesmoney*0.05 + p0->basemoney;
			}
			Apwages += p0->wages;
			break;
		case ������:
			if (p0->post == ���۾���) {
				p0->wages = jssalesmoney*0.05 + p0->basemoney;
			}
			Apwages += p0->wages;
			break;
		case ���²�:
			if (p0->post == ���۾���) {
				p0->wages = rssalesmoney*0.05 + p0->basemoney;
			}
			Apwages += p0->wages;
			break;
		}
		psum++;
		allwages += p0->wages;
		p0 = p0->next;
	}

	if (Ap != 0)
		p0 = Aphead;
	else
		p0 = head;


	for (i = 0; i < 3 * MAXCOL / 7; i++)
		printf(" ");
	printf("%d", permonth[per]);
	printf("\n");
	for (i = 0; i < MAXCOL; i++)
		printf("*");
	printf("  \tְ����    ����  �Ա�   ����     ��λ  ����            ���¹���  \n");	//Ա����Ա������ڿ���ѡ�񿴾����Ա��֮���
	printf("\t\t\t\t\t\t   ��ʱ �����۶� ��н �ϼƹ���\n");

	i = 0;
	if (p0 == NULL)
		printf("\n\n\t\t\t       ����Ա����Ϣ.\n\n\n");
	while (p0 != NULL) {
		if (p0->file == permonth[per]) {
			while (p0 != NULL) {
				if (p0->file == permonth[per]) {
					rsum++;
					sum++;
					rpsum++;
					time++;

					if (i<jihao - 1) {
						i++;
						if (b == NULL)
							b = head;
						else
							b = b->next;
					}
					printf("  ");
					if (flag == 0) {
						if (jihao == time) {
							printf("��");
						}
					}
					else
						printf("  ");
					if (flag == 1)
						if (p0->department != Ap) {
							p0 = p0->next;
							continue;
						}
					if (flag == 2)
						if (p0->post != Pt) {
							p0 = p0->next;
							continue;
						}

					printf("  ");
					printf("%d", p0->num);
					printf("%8s", p0->name);
					printf("%5s", p0->sex);
					switch (p0->department) {
					case ���۲�:
						printf("%8s", "���۲�");
						break;
					case ������:
						printf("%8s", "������");
						break;
					case ���²�:
						printf("%8s", "���²�");
						break;
					}


					switch (p0->post) {
					case ���۾���:
						printf("%10s", "���۾���");
						break;
					case ����Ա:
						printf("%10s", "����Ա");
						break;
					case ����Ա:
						printf("%10s", "����Ա");
						break;
					case ����:
						printf("%10s", "����");
						break;
					}
					if (p0->post == ���۾���) {
						printf("%4d", p0->age);
						printf("%5.1f%8.1f%7.0f%9.1f", p0->worktime, p0->salesmoney, p0->basemoney, p0->wages);
						printf("\n");
						printf("\n");
					}
					else {
						printf("%4d", p0->age);
						printf("%5.1f%8.1f%7.0f%9.1f", p0->worktime, p0->salesmoney, p0->basemoney, p0->wages);
						printf("\n");
						printf("\n");
					}
					if (p0->wages >= allwages / psum)
						allsum++;
					if (rsum % 10 == 0)
						break;
				}
				p0 = p0->next;
			}
			break;
		}
		b = p0;
		p0 = p0->next;
	}


	printf("\n");
	for (i = 0; i < MAXCOL; i++)
		printf("*");
	printf("        ��һҳ                   ��   ��                  ��һҳ\n");
	printf("\t\t\t\t   %d/%d", sum / 10 + 1, asum / 10 + 1);
	printf("\n");
	if (flag == 0 || flag == 1) {
		printf("\t\t\t    �س��������˵���.    \tƽ������:%.2lf", allwages / psum);
		printf("\n\t\t\t\t\t\t\tƽ��������������Ϊ:%d\n", allsum);
	}
	else
		printf("\t\t\t    �س��������˵���. ");

	if (Ap != 0|| Pt != 0) {
		Ap = 0;
		Pt = 0;
		printf("���س�������ϵͳ��ҳ...");
		while (getchar() != '\n') continue;
		home();
	}
	while (1) {
		time = 0;
		c = getch();

		switch (c) {
		case -32:
			c = getch();
			if (flag == 0) {
				switch (c) {
				case 75:
					jihao = 1;
					if (per == 0)
						printf("�Ѿ��ǵ�һҳ��.");
					else {

						rsum = 0;
						if (rpsum - 10 >= 0) {
							system("cls");
							for (i = 0; i < 3 * MAXCOL / 7; i++)
								printf(" ");
							printf("%d", permonth[per]);
							printf("\n");
							for (i = 0; i < MAXCOL; i++)
								printf("*");
							printf("  \tְ����    ����  �Ա�   ����     ��λ  ����            ���¹���  \n");	//Ա����Ա������ڿ���ѡ�񿴾����Ա��֮���
							printf("\t\t\t\t\t\t   ��ʱ �����۶� ��н �ϼƹ���\n");
							sum -= 10;
							rpsum -= 10;
							i = 0;
							allwages = 0; Apwages = 0;
							while (p0 != NULL&&p0->file == permonth[per]) {
								switch (p0->department) {
								case ���۲�:
									if (p0->post == ���۾���) {
										p0->wages = xssalesmoney*0.05 + p0->basemoney;
									}
									Apwages += p0->wages;
									break;
								case ������:
									if (p0->post == ���۾���) {
										p0->wages = jssalesmoney*0.05 + p0->basemoney;
									}
									Apwages += p0->wages;
									break;
								case ���²�:
									if (p0->post == ���۾���) {
										p0->wages = rssalesmoney*0.05 + p0->basemoney;
									}
									Apwages += p0->wages;
									break;
								}
								psum++;
								allwages += p0->wages;
								p0 = p0->next;
							}
							p0 = head;
							while (p0 != NULL) {
								if (rsum == sum) {
									while (p0 != NULL) {
										if (p0->file == permonth[per]) {
											sum++;
											rpsum++;
											rsum++;
											time++;
											if (i < jihao - 1) {
												i++;
												if (b == NULL)
													b = head;
												else
													b = b->next;
											}
											//if(jihao==1&&sum-1=0)
											printf("  ");
											if (jihao == time) {
												printf("��");
											}
											if (flag == 1)
												if (p0->department != Ap) {
													p0 = p0->next;
													continue;
												}
											if (flag == 2)
												if (p0->post != Pt) {
													p0 = p0->next;
													continue;
												}

											printf("  ");
											printf("%d", p0->num);
											printf("%8s", p0->name);
											printf("%5s", p0->sex);
											switch (p0->department) {
											case ���۲�:
												printf("%8s", "���۲�");
												break;
											case ������:
												printf("%8s", "������");
												break;
											case ���²�:
												printf("%8s", "���²�");
												break;
											}


											switch (p0->post) {
											case ���۾���:
												printf("%10s", "���۾���");
												break;
											case ����Ա:
												printf("%10s", "����Ա");
												break;
											case ����Ա:
												printf("%10s", "����Ա");
												break;
											case ����:
												printf("%10s", "����");
												break;
											}
											if (p0->post == ���۾���) {
												printf("%4d", p0->age);
												printf("%5.1f%8.1f%7.0f%9.1f", p0->worktime, p0->salesmoney, p0->basemoney, p0->wages);
												printf("\n");
												printf("\n");
											}
											else {
												printf("%4d", p0->age);
												printf("%5.1f%8.1f%7.0f%9.1f", p0->worktime, p0->salesmoney, p0->basemoney, p0->wages);
												printf("\n");
												printf("\n");
											}
											if (p0->wages >= allwages / psum)
												allsum++;
											if (sum % 10 == 0)
												break;
										}
										p0 = p0->next;
									}
									break;

								}
								rsum++;
								b = p0;
								p0 = p0->next;
							}
						}
						else {
							sum -= rpsum;
							per--;
							allwages = 0; Apwages = 0;
							psum = 0; rpsum = 0;
							allsum = 0;
							tempp = p0;
							p0 = head;
							system("cls");
							for (i = 0; i < 3 * MAXCOL / 7; i++)
								printf(" ");
							printf("%d", permonth[per]);
							printf("\n");
							for (i = 0; i < MAXCOL; i++)
								printf("*");
							printf("  \tְ����    ����  �Ա�   ����     ��λ  ����            ���¹���  \n");	//Ա����Ա������ڿ���ѡ�񿴾����Ա��֮���
							printf("\t\t\t\t\t\t   ��ʱ �����۶� ��н �ϼƹ���\n");

							while (p0 != NULL) {
								if (p0->file == permonth[per]) {
									switch (p0->department) {
									case ���۲�:
										if (p0->post == ���۾���) {
											p0->wages = xssalesmoney*0.05 + p0->basemoney;
										}
										Apwages += p0->wages;
										break;
									case ������:
										if (p0->post == ���۾���) {
											p0->wages = jssalesmoney*0.05 + p0->basemoney;
										}
										Apwages += p0->wages;
										break;
									case ���²�:
										if (p0->post == ���۾���) {
											p0->wages = rssalesmoney*0.05 + p0->basemoney;
										}
										Apwages += p0->wages;
										break;
									}
									psum++;
									allwages += p0->wages;
								}
								p0 = p0->next;
							}
							p0 = head;
							sum -= psum;
							i = 0;
							while (p0 != NULL) {
								if (rsum == sum) {
									while (p0 != NULL) {
										if (p0->file == permonth[per]) {
											rsum++;
											sum++;
											rpsum++;
											time++;
											if (i < jihao - 1) {
												i++;
												if (b == NULL)
													b = head;
												else
													b = b->next;
											}
											printf("  ");
											if (jihao == time) {
												printf("��");
											}
											if (flag == 1)
												if (p0->department != Ap) {
													p0 = p0->next;
													continue;
												}
											if (flag == 2)
												if (p0->post != Pt) {
													p0 = p0->next;
													continue;
												}

											printf("  ");
											printf("%d", p0->num);
											printf("%8s", p0->name);
											printf("%5s", p0->sex);
											switch (p0->department) {
											case ���۲�:
												printf("%8s", "���۲�");
												break;
											case ������:
												printf("%8s", "������");
												break;
											case ���²�:
												printf("%8s", "���²�");
												break;
											}


											switch (p0->post) {
											case ���۾���:
												printf("%10s", "���۾���");
												break;
											case ����Ա:
												printf("%10s", "����Ա");
												break;
											case ����Ա:
												printf("%10s", "����Ա");
												break;
											case ����:
												printf("%10s", "����");
												break;
											}
											if (p0->post == ���۾���) {
												printf("%4d", p0->age);
												printf("%5.1f%8.1f%7.0f%9.1f", p0->worktime, p0->salesmoney, p0->basemoney, p0->wages);
												printf("\n");
												printf("\n");
											}
											else {
												printf("%4d", p0->age);
												printf("%5.1f%8.1f%7.0f%9.1f", p0->worktime, p0->salesmoney, p0->basemoney, p0->wages);
												printf("\n");
												printf("\n");
											}
											if (p0->wages >= allwages / psum)
												allsum++;
											if (sum % 10 == 0)
												break;
										}
										p0 = p0->next;
									}
									break;
								}
								b = p0;
								rsum++;
								p0 = p0->next;
							}
						}

						for (i = 0; i < MAXCOL; i++)
							printf("*");
						printf("        ��һҳ                   ��   ��                  ��һҳ\n");
						printf("\t\t\t\t   %d/%d", sum / 10 + 1, psum / 10 + 1);
						printf("\n");
						if (flag == 0 || flag == 1) {
							printf("\t\t\t    �س��������˵���.    \tƽ������:%.2lf", allwages / psum);
							printf("\n\t\t\t\t\t\t\tƽ��������������Ϊ:%d\n", allsum);
						}
						break;
					}
					break;
				case 77:
					if (sum == asum) {
						printf("�ѵ����һҳ,�볢����������.");
					}
					else {
						jihao = 1;
						system("cls");

						if (rpsum != psum) {
							for (i = 0; i < 3 * MAXCOL / 7; i++)
								printf(" ");
							printf("%d", permonth[per]);
							printf("\n");
							for (i = 0; i < MAXCOL; i++)
								printf("*");
							printf("  \tְ����    ����  �Ա�   ����     ��λ  ����            ���¹���  \n");	//Ա����Ա������ڿ���ѡ�񿴾����Ա��֮���
							printf("\t\t\t\t\t\t   ��ʱ �����۶� ��н �ϼƹ���\n");
							allwages = 0; Apwages = 0;
							while (p0 != NULL&&p0->file == permonth[per]) {
								switch (p0->department) {
								case ���۲�:
									if (p0->post == ���۾���) {
										p0->wages = xssalesmoney*0.05 + p0->basemoney;
									}
									Apwages += p0->wages;
									break;
								case ������:
									if (p0->post == ���۾���) {
										p0->wages = jssalesmoney*0.05 + p0->basemoney;
									}
									Apwages += p0->wages;
									break;
								case ���²�:
									if (p0->post == ���۾���) {
										p0->wages = rssalesmoney*0.05 + p0->basemoney;
									}
									Apwages += p0->wages;
									break;
								}
								psum++;
								allwages += p0->wages;
								p0 = p0->next;
							}
							i = 0;
							while (p0 != NULL) {
								if (p0->file == permonth[per]) {
									while (p0 != NULL) {
										if (p0->file == permonth[per]) {
											rsum++;
											sum++;
											rpsum++;
											time++;
											if (i < jihao - 1) {
												i++;
												if (b == NULL)
													b = head;
												else
													b = b->next;
											}
											printf("  ");
											if (jihao == time) {
												printf("��");
											}
											if (flag == 1)
												if (p0->department != Ap) {
													p0 = p0->next;
													continue;
												}
											if (flag == 2)
												if (p0->post != Pt) {
													p0 = p0->next;
													continue;
												}

											printf("  ");
											printf("%d", p0->num);
											printf("%8s", p0->name);
											printf("%5s", p0->sex);
											switch (p0->department) {
											case ���۲�:
												printf("%8s", "���۲�");
												break;
											case ������:
												printf("%8s", "������");
												break;
											case ���²�:
												printf("%8s", "���²�");
												break;
											}


											switch (p0->post) {
											case ���۾���:
												printf("%10s", "���۾���");
												break;
											case ����Ա:
												printf("%10s", "����Ա");
												break;
											case ����Ա:
												printf("%10s", "����Ա");
												break;
											case ����:
												printf("%10s", "����");
												break;
											}
											if (p0->post == ���۾���) {
												printf("%4d", p0->age);
												printf("%5.1f%8.1f%7.0f%9.1f", p0->worktime, p0->salesmoney, p0->basemoney, p0->wages);
												printf("\n");
												printf("\n");
											}
											else {
												printf("%4d", p0->age);
												printf("%5.1f%8.1f%7.0f%9.1f", p0->worktime, p0->salesmoney, p0->basemoney, p0->wages);
												printf("\n");
												printf("\n");
											}
											if (p0->wages >= allwages / psum)
												allsum++;
											if (rsum % 10 == 0)
												break;
										}
										p0 = p0->next;
									}
									break;
								}
								if (i == 0)
									b = p0;
								p0 = p0->next;
							}
						}
						else {
							per++;
							for (i = 0; i < 3 * MAXCOL / 7; i++)
								printf(" ");
							printf("%d", permonth[per]);
							printf("\n");
							for (i = 0; i < MAXCOL; i++)
								printf("*");
							printf("  \tְ����    ����  �Ա�   ����     ��λ  ����            ���¹���  \n");	//Ա����Ա������ڿ���ѡ�񿴾����Ա��֮���
							printf("\t\t\t\t\t\t   ��ʱ �����۶� ��н �ϼƹ���\n");


							if (p0 == NULL) {
								p0 = head;
							}
							allwages = 0; Apwages = 0;
							psum = 0; rpsum = 0;
							allsum = 0;
							tempp = p0;
							while (p0 != NULL) {
								if (p0->file == permonth[per]) {
									switch (p0->department) {
									case ���۲�:
										if (p0->post == ���۾���) {
											p0->wages = xssalesmoney*0.05 + p0->basemoney;
										}
										Apwages += p0->wages;
										break;
									case ������:
										if (p0->post == ���۾���) {
											p0->wages = jssalesmoney*0.05 + p0->basemoney;
										}
										Apwages += p0->wages;
										break;
									case ���²�:
										if (p0->post == ���۾���) {
											p0->wages = rssalesmoney*0.05 + p0->basemoney;
										}
										Apwages += p0->wages;
										break;
									}
									psum++;
									allwages += p0->wages;
								}
								p0 = p0->next;
							}
							p0 = tempp;
							i = 0;
							while (p0 != NULL) {
								if (p0->file == permonth[per]) {
									while (p0 != NULL) {
										if (p0->file == permonth[per]) {
											rsum++;
											sum++;
											rpsum++;
											time++;
											if (i < jihao - 1) {
												i++;
												if (b == NULL)
													b = head;
												else
													b = b->next;
											}
											printf("  ");
											if (jihao == time) {
												printf("��");
											}
											if (flag == 1)
												if (p0->department != Ap) {
													p0 = p0->next;
													continue;
												}
											if (flag == 2)
												if (p0->post != Pt) {
													p0 = p0->next;
													continue;
												}

											printf("  ");
											printf("%d", p0->num);
											printf("%8s", p0->name);
											printf("%5s", p0->sex);
											switch (p0->department) {
											case ���۲�:
												printf("%8s", "���۲�");
												break;
											case ������:
												printf("%8s", "������");
												break;
											case ���²�:
												printf("%8s", "���²�");
												break;
											}


											switch (p0->post) {
											case ���۾���:
												printf("%10s", "���۾���");
												break;
											case ����Ա:
												printf("%10s", "����Ա");
												break;
											case ����Ա:
												printf("%10s", "����Ա");
												break;
											case ����:
												printf("%10s", "����");
												break;
											}
											if (p0->post == ���۾���) {
												printf("%4d", p0->age);
												printf("%5.1f%8.1f%7.0f%9.1f", p0->worktime, p0->salesmoney, p0->basemoney, p0->wages);
												printf("\n");
												printf("\n");
											}
											else {
												printf("%4d", p0->age);
												printf("%5.1f%8.1f%7.0f%9.1f", p0->worktime, p0->salesmoney, p0->basemoney, p0->wages);
												printf("\n");
												printf("\n");
											}
											if (p0->wages >= allwages / psum)
												allsum++;
											if (rsum % 10 == 0)
												break;
										}
										p0 = p0->next;
									}
									break;
								}
								if (i == 0)
									b = p0;
								p0 = p0->next;
							}
						}

						for (i = 0; i < MAXCOL; i++)
							printf("*");
						printf("        ��һҳ                   ��   ��                  ��һҳ\n");
						printf("\t\t\t\t   %d/%d", sum / 10 + 1, psum / 10 + 1);
						printf("\n");
						if (flag == 0 || flag == 1) {
							printf("\t\t\t    �س��������˵���.    \tƽ������:%.2lf", allwages / psum);
							printf("\n\t\t\t\t\t\t\tƽ��������������Ϊ:%d\n", allsum);
						}
						break;
					}
					break;

				case 72:
					if (flag == 0 || flag == 1) {
						jihao--;
						temp = rsum - rpsum;
						if (jihao == 0)
							jihao = rpsum;
						if (Ap != 0)
							p0 = Aphead;
						else
							p0 = head;
						system("cls");
						for (i = 0; i < 3 * MAXCOL / 7; i++)
							printf(" ");
						printf("%d", permonth[per]);
						printf("\n");
						for (i = 0; i < MAXCOL; i++)
							printf("*");
						printf("  \tְ����    ����  �Ա�   ����     ��λ  ����            ���¹���  \n");	//Ա����Ա������ڿ���ѡ�񿴾����Ա��֮���
						printf("\t\t\t\t\t\t   ��ʱ �����۶� ��н �ϼƹ���\n");
						rsum = 0;
						time = 0;
						i = 0;
						while (p0 != NULL) {
							if (rsum == temp) {
								while (p0 != NULL) {
									if (p0->file == permonth[per]) {
										rsum++;
										time++;
										if (i < jihao - 1) {
											i++;
											if (b == NULL)
												b = head;
											else
												b = b->next;
										}
										printf("  ");
										if (jihao == time) {
											printf("��");
										}
										if (flag == 1)
											if (p0->department != Ap) {
												p0 = p0->next;
												continue;
											}
										if (flag == 2)
											if (p0->post != Pt) {
												p0 = p0->next;
												continue;
											}

										printf("  ");
										printf("%d", p0->num);
										printf("%8s", p0->name);
										printf("%5s", p0->sex);
										switch (p0->department) {
										case ���۲�:
											printf("%8s", "���۲�");
											break;
										case ������:
											printf("%8s", "������");
											break;
										case ���²�:
											printf("%8s", "���²�");
											break;
										}


										switch (p0->post) {
										case ���۾���:
											printf("%10s", "���۾���");
											break;
										case ����Ա:
											printf("%10s", "����Ա");
											break;
										case ����Ա:
											printf("%10s", "����Ա");
											break;
										case ����:
											printf("%10s", "����");
											break;
										}
										if (p0->post == ���۾���) {
											printf("%4d", p0->age);
											printf("%5.1f%8.1f%7.0f%9.1f", p0->worktime, p0->salesmoney, p0->basemoney, p0->wages);
											printf("\n");
											printf("\n");
										}
										else {
											printf("%4d", p0->age);
											printf("%5.1f%8.1f%7.0f%9.1f", p0->worktime, p0->salesmoney, p0->basemoney, p0->wages);
											printf("\n");
											printf("\n");
										}
										if (psum % 10 == 0)
											break;
									}
									p0 = p0->next;
								}
								break;
							}
							rsum++;
							b = p0;
							p0 = p0->next;
						}


						for (i = 0; i < MAXCOL; i++)
							printf("*");
						printf("        ��һҳ                   ��   ��                  ��һҳ\n");
						printf("\t\t\t\t   %d/%d", sum / 10 + 1, asum / 10 + 1);
						printf("\n");
						if (flag == 0 || flag == 1) {
							printf("\t\t\t    �س��������˵���.    \tƽ������:%.2lf", allwages / psum);
							printf("\n\t\t\t\t\t\t\tƽ��������������Ϊ:%d\n", allsum);
						}
						break;
					}
					break;

				case 80:
					if (flag == 0 || flag == 1) {
						jihao++;
						if (jihao == rpsum % 10 + 1)
							jihao = 1;
						temp = rsum - rpsum;
						if (Ap != 0)
							p0 = Aphead;
						else
							p0 = head;
						system("cls");
						for (i = 0; i < 3 * MAXCOL / 7; i++)
							printf(" ");
						printf("%d", permonth[per]);
						printf("\n");
						for (i = 0; i < MAXCOL; i++)
							printf("*");
						printf("  \tְ����    ����  �Ա�   ����     ��λ  ����            ���¹���  \n");	//Ա����Ա������ڿ���ѡ�񿴾����Ա��֮���
						printf("\t\t\t\t\t\t   ��ʱ �����۶� ��н �ϼƹ���\n");
						rsum = 0;
						time = 0;
						i = 0;
						while (p0 != NULL) {
							if (rsum == temp) {
								while (p0 != NULL) {
									if (p0->file == permonth[per]) {
										rsum++;
										time++;
										if (i < jihao - 1) {
											i++;
											if (b == NULL)
												b = head;
											else
												b = b->next;
										}
										printf("  ");
										if (jihao == time) {
											printf("��");
										}
										if (flag == 1)
											if (p0->department != Ap) {
												p0 = p0->next;
												continue;
											}
										if (flag == 2)
											if (p0->post != Pt) {
												p0 = p0->next;
												continue;
											}

										printf("  ");
										printf("%d", p0->num);
										printf("%8s", p0->name);
										printf("%5s", p0->sex);
										switch (p0->department) {
										case ���۲�:
											printf("%8s", "���۲�");
											break;
										case ������:
											printf("%8s", "������");
											break;
										case ���²�:
											printf("%8s", "���²�");
											break;
										}


										switch (p0->post) {
										case ���۾���:
											printf("%10s", "���۾���");
											break;
										case ����Ա:
											printf("%10s", "����Ա");
											break;
										case ����Ա:
											printf("%10s", "����Ա");
											break;
										case ����:
											printf("%10s", "����");
											break;
										}
										if (p0->post == ���۾���) {
											printf("%4d", p0->age);
											printf("%5.1f%8.1f%7.0f%9.1f", p0->worktime, p0->salesmoney, p0->basemoney, p0->wages);
											printf("\n");
											printf("\n");
										}
										else {
											printf("%4d", p0->age);
											printf("%5.1f%8.1f%7.0f%9.1f", p0->worktime, p0->salesmoney, p0->basemoney, p0->wages);
											printf("\n");
											printf("\n");
										}
										if (psum % 10 == 0)
											break;
									}
									p0 = p0->next;
								}
								break;
							}
							rsum++;
							b = p0;
							p0 = p0->next;
						}


						for (i = 0; i < MAXCOL; i++)
							printf("*");
						printf("        ��һҳ                   ��   ��                  ��һҳ\n");
						printf("\t\t\t\t   %d/%d", sum / 10 + 1, asum / 10 + 1);
						printf("\n");
						if (flag == 0 || flag == 1) {
							printf("\t\t\t    �س��������˵���.    \tƽ������:%.2lf", allwages / psum);
							printf("\n\t\t\t\t\t\t\tƽ��������������Ϊ:%d\n", allsum);
						}
						break;
					}
					break;
				}
			}
			break;
		case ' ':
			if (flag == 0 || flag == 1) {
				printf("����Դ�Ա����Ϣ�����޸�:\n");
				printf("1.�޸���Ϣ.	2.ɾ����Ϣ.	3.�鿴��Ա��������Ϣ.	4.���ز���. :");
				scanf("%d", &ca);
				switch (ca) {
				case 1:
					printf("��Ҫ�޸ĸ�ְ��ʲô��Ϣ��\n");
					printf("1.����	2.����	3.ְ��	4.�Ա�	5.����	\n");
					scanf("%d", &ca1);
					if (b == NULL) {
						b = head;
						switch (ca1) {
						case 1:
							if (b == NULL) {
								head = head->next;
							}
							else if (b != NULL) {
								b->next = b->next->next;
							}

							add();
							break;
						case 2:
							printf("		1.���۲�	2.������	3.���²�\n");
							do {
								printf("��ְ���޸ĺ�Ĳ���Ϊ:");
								scanf("%d", &ca2);
								while (getchar() != '\n') continue;
								switch (ca2) {
								case ���۲�:
									b->department = ���۲�;
									break;
								case ������:
									b->department = ������;

									break;
								case ���²�:
									b->department = ���²�;


									break;
								default:
									printf("�������,�����벿�Ŷ�Ӧ������.\n");
									getchar();
									break;
								}
							} while (ca2 < 1 && ca2 > 3);

							break;
						case 3:
							printf("		1.���۾���	2.����Ա	3.����Ա	4.����\n");

							do {
								printf("��ְ���޸ĺ��ְ��Ϊ:");
								scanf("%d", &ca2);
								while (getchar() != '\n') continue;
								switch (ca2) {
								case ���۾���:
									b->post = ���۾���;
									b->worktime = 0;
									b->basemoney = 5000;
									b->wages = b->basemoney + allsalesmoney*0.05;
									break;
								case ����Ա:
									b->post = ����Ա;
									b->worktime = 0;
									printf("�������Ա���������Ÿ������۶");
									scanf("%lf", &b->salesmoney);
									b->basemoney = 0;
									allsalesmoney += b->salesmoney;
									b->wages = b->salesmoney*0.4;
									break;
								case ����Ա:
									b->post = ����Ա;
									printf("�������Ա�����¹���ʱ��(�ۼ�Сʱ����)��");
									scanf("%lf", &b->worktime);
									b->basemoney = 0;
									b->wages = (b->worktime) * 100;
									break;
								case ����:
									b->post = ����;
									b->worktime = 0;
									b->basemoney = 0;
									b->wages = 8000;
									break;
								default:
									printf("�������,������ְ���Ӧ������.\n");
									getchar();
								}
							} while (ca2 < 1 && ca2 > 4);
							break;
						case 4:
							printf("��ְ���޸ĺ���Ա�Ϊ:");
							scanf("%s", b->sex);
							while (getchar() != '\n') continue;
							break;
						case 5:
							printf("��ְ���޸ĺ������Ϊ:");
							scanf("%s", b->sex);
							while (getchar() != '\n') continue;
							break;
						}
					}
					else {
						switch (ca1) {
						case 1:
							if (b == NULL) {
								head = head->next;
							}
							else if (b != NULL) {
								b->next = b->next->next;
							}

							add();
							break;
						case 2:
							printf("		1.���۲�	2.������	3.���²�\n");
							do {
								printf("��ְ���޸ĺ�Ĳ���Ϊ:");
								scanf("%d", &ca2);
								while (getchar() != '\n') continue;
								switch (ca2) {
								case ���۲�:
									b->next->department = ���۲�;
									hey = head;
									while (hey != NULL) {
										if (p->file == hey->file)
											if (p1->post == ���۾���&&hey->department == b) {
												printf("ÿ������ֻ����һ�����۾���,����ʧ��.\n");
												printf("��������ص�������.");
												getchar();
												home();
											}
										p1 = p1->next;
									}
									break;
								case ������:
									b->next->department = ������;
									hey = head;
									while (hey != NULL) {
										if (p->file == hey->file)
											if (p1->post == ���۾���&&hey->department == b) {
												printf("ÿ������ֻ����һ�����۾���,����ʧ��.\n");
												printf("��������ص�������.");
												getchar();
												home();
											}
										p1 = p1->next;
									}
									break;
								case ���²�:
									b->next->department = ���²�;
									hey = head;
									while (hey != NULL) {
										if (p->file == hey->file)
											if (p1->post == ���۾���&&hey->department == b) {
												printf("ÿ������ֻ����һ�����۾���,����ʧ��.\n");
												printf("��������ص�������.");
												getchar();
												home();
											}
										p1 = p1->next;
									}
									break;
								default:
									printf("�������,�����벿�Ŷ�Ӧ������.\n");
									getchar();
									break;
								}
							} while (ca2 < 1 && ca2 > 3);

							break;
						case 3:
							printf("		1.���۾���	2.����Ա	3.����Ա	4.����\n");

							do {
								printf("��ְ���޸ĺ��ְ��Ϊ:");
								scanf("%d", &ca2);
								while (getchar() != '\n') continue;
								switch (ca2) {
								case ���۾���:
									b->next->post = ���۾���;
									b->next->worktime = 0;
									b->next->basemoney = 5000;
									b->next->wages = b->next->basemoney + allsalesmoney*0.05;
									break;
								case ����Ա:
									b->next->post = ����Ա;
									b->next->worktime = 0;
									printf("�������Ա���������Ÿ������۶");
									scanf("%lf", &b->next->salesmoney);
									b->next->basemoney = 0;
									allsalesmoney += b->next->salesmoney;
									b->next->wages = b->next->salesmoney*0.4;
									break;
								case ����Ա:
									b->next->post = ����Ա;
									printf("�������Ա�����¹���ʱ��(�ۼ�Сʱ����)��");
									scanf("%lf", &b->next->worktime);
									b->next->basemoney = 0;
									b->next->wages = (b->next->worktime) * 100;
									break;
								case ����:
									b->next->post = ����;
									b->next->worktime = 0;
									b->next->basemoney = 0;
									b->next->wages = 8000;
									break;
								default:
									printf("�������,������ְ���Ӧ������.\n");
									getchar();
								}
							} while (ca2 < 1 && ca2 > 4);
							break;
						case 4:
							printf("��ְ���޸ĺ���Ա�Ϊ:");
							scanf("%s", b->next->sex);
							while (getchar() != '\n') continue;
							break;
						case 5:
							printf("��ְ���޸ĺ������Ϊ:");
							scanf("%s", b->next->sex);
							while (getchar() != '\n') continue;
							break;
						}
					}
					if (ca1 != 1) {
						printf("�޸ĳɹ�.�س�������ҳ��.");
						while (getchar() != '\n') continue;
						getchar();
					}
					break;
				case 2:
					if (b == NULL) {
						head = head->next;
					}
					else if (b != NULL) {
						b->next = b->next->next;
					}
					printf("ɾ���ɹ�.�س�������ҳ��.");
					while (getchar() != '\n') continue;
					getchar();
					break;
				case 3:
					system("cls");
					p0 = head;
					for (i = 0; i < 3 * MAXCOL / 7; i++)
						printf(" ");
					if (b == NULL) {
						printf("ְ����:%d", head->num);
					}
					else
						printf("ְ����:%d", b->next->num);
					printf("\n");
					for (i = 0; i < MAXCOL; i++)
						printf("*");
					printf("  \t�����·�    ����  �Ա�   ����     ��λ  ����            ���¹���  \n");	//Ա����Ա������ڿ���ѡ�񿴾����Ա��֮���
					printf("\t\t\t\t\t\t     ��ʱ �����۶� ��н �ϼƹ���\n");

					if (b == NULL) {
						b = head;
						while (p0 != NULL) {
							if (strcmp(b->name, p0->name) == 0) {
								printf("  ");
								printf("  ");
								printf("%10d", p0->file);
								printf("%10s", p0->name);
								printf("%5s", p0->sex);
								switch (p0->department) {
								case ���۲�:
									printf("%8s", "���۲�");
									break;
								case ������:
									printf("%8s", "������");
									break;
								case ���²�:
									printf("%8s", "���²�");
									break;
								}


								switch (p0->post) {
								case ���۾���:
									printf("%10s", "���۾���");
									break;
								case ����Ա:
									printf("%10s", "����Ա");
									break;
								case ����Ա:
									printf("%10s", "����Ա");
									break;
								case ����:
									printf("%10s", "����");
									break;
								}
								if (p0->post == ���۾���) {
									printf("%4d", p0->age);
									printf("%5.1f%8.1f%7.0f%9.1f", p0->worktime, p0->salesmoney, p0->basemoney, p0->wages);
									printf("\n");
									printf("\n");
								}
								else {
									printf("%4d", p0->age);
									printf("%5.1f%8.1f%7.0f%9.1f", p0->worktime, p0->salesmoney, p0->basemoney, p0->wages);
									printf("\n");
									printf("\n");
								}
							}
							p0 = p0->next;
						}
						printf("\n");
						for (i = 0; i < MAXCOL; i++)
							printf("*");
					}
					else {
						while (p0 != NULL) {
							if (strcmp(b->next->name , p0->name ) == 0) {
								printf("  ");
								printf("  ");
								printf("%10d", p0->file);
								printf("%10s", p0->name);
								printf("%5s", p0->sex);
								switch (p0->department) {
								case ���۲�:
									printf("%8s", "���۲�");
									break;
								case ������:
									printf("%8s", "������");
									break;
								case ���²�:
									printf("%8s", "���²�");
									break;
								}


								switch (p0->post) {
								case ���۾���:
									printf("%10s", "���۾���");
									break;
								case ����Ա:
									printf("%10s", "����Ա");
									break;
								case ����Ա:
									printf("%10s", "����Ա");
									break;
								case ����:
									printf("%10s", "����");
									break;
								}
								if (p0->post == ���۾���) {
									printf("%4d", p0->age);
									printf("%5.1f%8.1f%7.0f%9.1f", p0->worktime, p0->salesmoney, p0->basemoney, p0->wages);
									printf("\n");
									printf("\n");
								}
								else {
									printf("%4d", p0->age);
									printf("%5.1f%8.1f%7.0f%9.1f", p0->worktime, p0->salesmoney, p0->basemoney, p0->wages);
									printf("\n");
									printf("\n");
								}
							}
							p0 = p0->next;
						}
						printf("\n");
						for (i = 0; i < MAXCOL; i++)
							printf("*");
					}
					while (getchar() != '\n') continue;
					printf("���س����������˵�...");
					getchar();
					break;
				case 4:
					home();
					break;
				}
				p1 = head;

				fp = fopen(document, "wb");
				while (p1 != NULL) {
					fwrite(p1, sizeof(struct labour), 1, fp);
					p1 = p1->next;
				}
				fwrite(&filenum, sizeof(int), 1, fp);
				fwrite(&allsalesmoney, sizeof(int), 1, fp);
				fclose(fp);
			}
			home();
			break;
		case '\n': case '\r': {
			system("cls");
			for (i = 0; i < MAXCOL; i++)
				printf("*");
			printf("\n\n");
			printf("\t	   1.������ݵ���ǰ�·�.\n\n");
			printf("\t	   2.��������ʾԱ����Ϣ.\n\n");
			printf("\t	   3.����λ��ʾԱ����Ϣ.\n\n");
			printf("\t	   4.�˳���ϵͳ.\n\n");
			printf("\t	   5.���ص�ǰҳ��.\n\n");
			printf("\t	   6.������ҳ.\n");
			printf("\n\n");
			for (i = 0; i < MAXCOL; i++)
				printf("*");
			while (1) {
				printf("���������ѡ��:");
				scanf("%d", &choices);
				while (getchar() != '\n') continue;
				switch (choices) {
				case 1:
					add();
					home();
					break;
				case 2:
					Ap = inquirAp();
					home();
					break;
				case 3:
					Pt = inquirPt();
					home();
					break;

				case 4:
					End();
					home();
					break;
				case 5:
					home();
					break;
				case 6:
					Ap = 0;
					Pt = 0;
					per = 0;
					Menu();
					break;
				default:
					printf("�������.");
					break;
				}
			}
		}
		}
	}
}





void payrule(void) {
	int i;
	system("cls");
	for (i = 0; i < MAXCOL; i++)
		printf("*");
	printf("\n\n");
	printf("\t   A������:�̶���нΪ8000.\n");
	printf("\t   B������Ա:����ʱ���Сʱ���ʣ�100ԪÿСʱ��.\n");
	printf("\t   C������Ա:���۶��4%���.\n");
	printf("\t   D�����۾���:��н(5000)+��Ͻ�������۶��ܶ��0.5.\n");
	printf("\n\n");
	printf("\t\t\t\t�뾡����ȷ����,�緢��©���뼰ʱ��������ϵ.\n");
	for (i = 0; i < MAXCOL; i++)
		printf("*");
	for (i = 0; i < 30; i++)
		printf(" ");
	printf("������ҳ���밴�س���.");
	getchar();
}



void loadin(void) {
	int i;
	int temp = 0;
	int zzz = 0;
	char secret[7];
	char c;
	system("cls");
	for (i = 0; i < MAXCOL; i++)								//�߿�
		printf("*");
	printf("\n\n\t\t    ��������������������������������������������\n");
	printf("\t\t    ��               �û���¼                 ��\n");
	printf("\t\t    ��   ����������������������������������   ��\n");
	printf("\t\t    ��   ��  Ĭ���˻���dgut              ��   ��\n");
	printf("\t\t    ��   ����������������������������������   ��\n");
	printf("\t\t    ��   ����������������������������������   ��\n");
	printf("\t\t    ��   ��  ���룺                      ��   ��\n");
	printf("\t\t    ��   ����������������������������������   ��\n");
	printf("\t\t    ��                                        ��\n");
	printf("\t\t    ��                                        ��\n");
	printf("\t\t    ��                                        ��\n");
	printf("\t\t    ��                                        ��\n");
	printf("\t\t    ��                    ��ʼ���룺123456    ��\n");
	printf("\t\t    ��������������������������������������������\n\n");
	printf("                                                        ������س�������ϵͳ.\n");
	for (i = 0; i < MAXCOL; i++)
		printf("*");
	while (1) {
		c = getch();
		secret[temp] = c;
		switch (c) {
		case 27:case 8:
			if (temp == 0)
				continue;
			temp--;
			system("cls");
			for (i = 0; i < MAXCOL; i++)								//�߿�
				printf("*");
			printf("\n\n\t\t    ��������������������������������������������\n");
			printf("\t\t    ��               �û���¼                 ��\n");
			printf("\t\t    ��   ����������������������������������   ��\n");
			printf("\t\t    ��   ��  Ĭ���˻���dgut              ��   ��\n");
			printf("\t\t    ��   ����������������������������������   ��\n");
			printf("\t\t    ��   ����������������������������������   ��\n");
			printf("\t\t    ��   ��  ���룺");
			for (i = 0; i<temp; i++)
				printf("*");
			for (i = 0; i<6 - temp; i++)
				printf(" ");
			printf("                ��   ��\n");
			printf("\t\t    ��   ����������������������������������   ��\n");
			printf("\t\t    ��                                        ��\n");
			printf("\t\t    ��                                        ��\n");
			printf("\t\t    ��                                        ��\n");
			printf("\t\t    ��                                        ��\n");
			printf("\t\t    ��                    ��ʼ���룺123456    ��\n");
			printf("\t\t    ��������������������������������������������\n\n");
			printf("                                                        ������س�������ϵͳ.\n");
			for (i = 0; i < MAXCOL; i++)
				printf("*");
			break;



		case '\n':case '\r':
			secret[temp] = '\0';
			if (strcmp(secret, "123456") == 0) {
				printf("��½�ɹ�.");
				getchar();
				Menu();
			}
			else {
				printf("�����������������.");
				temp = 0;
				getchar();
				for (i = 0; i<6; i++)
					secret[i] = '0';
				secret[i] = '\0';
				loadin();
			}
			break;



		default:
			if (temp<6)
				temp++;
			system("cls");
			for (i = 0; i < MAXCOL; i++)								//�߿�
				printf("*");
			printf("\n\n\t\t    ��������������������������������������������\n");
			printf("\t\t    ��               �û���¼                 ��\n");
			printf("\t\t    ��   ����������������������������������   ��\n");
			printf("\t\t    ��   ��  Ĭ���˻���dgut              ��   ��\n");
			printf("\t\t    ��   ����������������������������������   ��\n");
			printf("\t\t    ��   ����������������������������������   ��\n");
			printf("\t\t    ��   ��  ���룺");
			for (i = 0; i<temp; i++)
				printf("*");
			for (i = 0; i<6 - temp; i++)
				printf(" ");
			printf("                ��   ��\n");
			printf("\t\t    ��   ����������������������������������   ��\n");
			printf("\t\t    ��                                        ��\n");
			printf("\t\t    ��                                        ��\n");
			printf("\t\t    ��                                        ��\n");
			printf("\t\t    ��                                        ��\n");
			printf("\t\t    ��                    ��ʼ���룺123456    ��\n");
			printf("\t\t    ��������������������������������������������\n\n");
			printf("                                                        ������س�������ϵͳ.\n");
			for (i = 0; i < MAXCOL; i++)
				printf("*");
			break;
		}
	}
	while (getchar() != '\n') continue;
}