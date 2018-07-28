#include<stdio.h>;
#include<stdlib.h>;

enum department { 销售部 = 1, 技术部 = 2, 人事部 = 3 };
enum POST { 销售经理 = 1, 销售员 = 2, 技术员 = 3, 经理 = 4 };
#define MAXCOL 80		
#define MAXROW 40

/*
1)	所有员工信息按当月工资从高到低排序并显示。
2)	某个岗位的员工信息按当月工资从高到低排序并显示。
6.	统计：
1)	统计并显示某个部门的平均工资、最低工资、最高工资。
2)	统计并显示某个部门超出平均工资的人数与员工信息。
3)	统计并显示所有员工中的最低工资和最高工资员工的信息。
4)	统计并显示所有员工超出平均工资的人数与员工信息。

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
char document[25] = "员工人员总览";
int Ap = 0, Pt = 0, sum = 0;
char Pfilenum = '\0';
int jihao = 1;
int biaozhi = 1;
int permonth[50] = { 0 };
int per = 0;

void main(void)
{
	/*
	加密
	欢迎界面
	选择内容
	实现功能（1.	添加数据  2.	修改数据  3.	删除数据  4.	查询数据 ）

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
	system("mode con cols=80 lines=40");						//控制显示命令屏大小
	for (i = 0; i < MAXCOL; i++)								//边框
		printf("*");
	printf("\n\n\n\n");
	for (i = 0; i < MAXCOL / 4; i++)								//居中
		printf(" ");
	printf("欢迎使用本员工工资管理系统.\n\n\n\n\n");
	for (i = 0; i < MAXCOL * 5 / 8; i++)								//居中
		printf(" ");
	printf("请输入回车键进入系统.\n");
	for (i = 0; i < MAXCOL; i++)
		printf("*");
	getchar();
	loadin();
}


void Menu(void) {
	int i, choice;
	system("cls");
	printf("\t\t\t欢迎使用员工工资管理系统.\n");
	for (i = 0; i < MAXCOL; i++)								//边框
		printf("*");
	printf("\n\n");
	printf("\t\t\t  1.查询工资.\n");
	printf("\n\n");
	printf("\t\t\t  2.工资细则.\n");
	printf("\n\n");
	printf("\t\t\t  3.退出本系统.\n");
	printf("\n\n");
	printf("\t\t\t\t\t\t操作方法:\n");
	printf("\t\t\t\t\t\t\t      ┌──┐\n");
	printf("\t\t\t\t\t\t↑\t      │    │\n");
	printf("\t\t\t\t\t\t \t┌──┘    │\n");
	printf("\t\t\t\t\t  ←    ↓   → │   回车   │\n");
	printf("\t\t\t\t\t\t\t└─────┘\n");

	printf("\t\t\t\t\t┌──────┐\n");
	printf("\t\t\t\t\t│    空格    │\n");
	printf("\t\t\t\t\t└──────┘\n");
	for (i = 0; i < MAXCOL; i++)
		printf("*");
	while (1) {
		printf("请输入你的选择,并按回车确定你的选择:");
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
			printf("输入错误,请输入菜单栏对应的整数.\n");
		}
	}
}


//修改姓名那里出大错了。记得改
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
	int allsalesmoney = 0;					//没完成的，得闲找个位置丢进去.在add
	struct labour  *p = NULL, *p0 = NULL, *p1 = NULL, *p2 = NULL, *p3 = NULL, *zz = NULL,*zzz=NULL;			//*p保存用户数据


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


	printf("请输入此员工入职工作年份和月份(eg:201608):");
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

	printf("请输入员工姓名：");
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
	printf("请输入员工性别：");
	scanf("%s", p->sex);
	while (getchar() != '\n') continue;
	printf("请输入员工年龄：");
	scanf("%d", &p->age);
	while (getchar() != '\n') continue;
	enum department b;
	enum POST a;
	printf("		1.销售部	2.技术部	3.人事部\n");
	do {
		printf("请按数字提示确定员工所属部门,并按回车确定你的选择:");
		scanf("%d", &b);
		while (getchar() != '\n') continue;
		switch (b) {
		case 销售部:
			p->department = 销售部;
			break;
		case 技术部:
			p->department = 技术部;
			break;
		case 人事部:
			p->department = 人事部;
			break;
		default:
			printf("输入错误,请输入部门对应的整数.\n");
			getchar();
			break;
		}
	} while (b < 1 && b > 3);

	printf("		1.销售经理	2.销售员	3.技术员	4.经理\n");
	do {

		printf("请按数字提示确定员工所属职务,并按回车确定你的选择:");
		scanf("%d", &a);
		while (getchar() != '\n') continue;
		switch (a) {
		case 销售经理:
			p1 = head;
			while (p1 != NULL) {
				if (p->file == p1->file)
					if (p1->post == 销售经理&&p1->department == b) {
						printf("每个部门只能有一个销售经理,操作失败.\n");
						printf("按任意键回到主界面.");
						getchar();
						home();
					}
				p1 = p1->next;
			}
			p->post = 销售经理;
			p->worktime = 0;
			p->salesmoney = 0;
			p->basemoney = 5000;
			p->wages = p->basemoney + allsalesmoney*0.05;
			break;
		case 销售员:
			p->post = 销售员;
			p->worktime = 0;
			printf("请输入该员工所属部门该月销售额：");
			scanf("%lf", &p->salesmoney);
			allsalesmoney += p->salesmoney;
			p->basemoney = 0;
			p->wages = p->salesmoney*0.4;
			break;
		case 技术员:
			p->post = 技术员;
			printf("请输入该员工该月工作时间(累计小时总数)：");
			scanf("%lf", &p->worktime);
			p->basemoney = 0;
			p->wages = (p->worktime) * 100;
			break;
		case 经理:
			p->post = 经理;
			p->worktime = 0;
			p->basemoney = 0;
			p->wages = 8000;
			break;
		default:
			printf("输入错误,请输入职务对应的整数.\n");
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
		//增加个判断file月份的
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
	printf("添加成功,再次输入回车键回到系统.");
	getchar();
}


int inquirAp(void) {			//部门显示信息		一页一个部门这样子。标题是部门，
	int b;
	printf("		1.销售部		2.技术部		3.人事部\n\n");						//选择后应出现边框和员工信息.
	do {
		printf("请按数字提示确定查询的部门信息,并按回车确定你的选择:");
		scanf("%d", &b);
		getchar();
		switch (b) {
		case 销售部:

			break;
		case 技术部:

			break;
		case 人事部:

			break;
		default:
			printf("输入错误,请输入部门对应的整数.\n");
			getchar();
			break;
		}
	} while (b < 1 && b > 3);


	return b;

}	   //边框没弄好的



int inquirPt(void) {			//职位显示信息
	int a;

	printf("		1.销售经理	2.销售员	3.技术员	4.经理\n\n");
	do {

		printf("请按数字提示确定员工所属职务,并按回车确定你的选择:");
		scanf("%d", &a);
		while (getchar() != '\n') continue;
		switch (a) {
		case 销售经理:

			break;
		case 销售员:

			break;
		case 技术员:

			break;
		case 经理:

			break;
		default:
			printf("输入错误,请输入查询职务对应的整数.\n");
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
	printf("\n\n\t感谢使用本系统，若有问题请及时向工作人员反馈...\n\n\n");
	printf("\n\n");
	for (i = 0; i < MAXCOL; i++)
		printf("*");
	exit(0);
}



void home(void) {
	int choices, i, k = 0;
	int flen = 0, len = 0, choice, psum = 0, rsum = 0;
	int filenum = 0;
	int allsalesmoney = 0;			//用来算全部平均工资
	int xswages = 0, rswages = 0, jswages = 0;			//每部门工资
	int xssalesmoney = 0, rssalesmoney = 0, jssalesmoney = 0;		//每部门销售工资
	int flag = 0;			//Ap,Pt
	int allsum = 0;			//平均工资人数
	double allwages = 0;		//每月全部工资.
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
								case 销售部:
									xssalesmoney += Ap1->salesmoney;
									break;
								case 技术部:
									jssalesmoney += Ap1->salesmoney;
									break;
								case 人事部:
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
						case 销售部:
							xssalesmoney += p->salesmoney;
							break;
						case 技术部:
							jssalesmoney += p->salesmoney;
							break;
						case 人事部:
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
		case 销售部:
			if (p0->post == 销售经理) {
				p0->wages = xssalesmoney*0.05 + p0->basemoney;
			}
			Apwages += p0->wages;
			break;
		case 技术部:
			if (p0->post == 销售经理) {
				p0->wages = jssalesmoney*0.05 + p0->basemoney;
			}
			Apwages += p0->wages;
			break;
		case 人事部:
			if (p0->post == 销售经理) {
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
	printf("  \t职工号    姓名  性别   部门     岗位  年龄            当月工资  \n");	//员工表，员工表隔壁可以选择看经理和员工之类的
	printf("\t\t\t\t\t\t   工时 月销售额 底薪 合计工资\n");

	i = 0;
	if (p0 == NULL)
		printf("\n\n\t\t\t       暂无员工信息.\n\n\n");
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
							printf("→");
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
					case 销售部:
						printf("%8s", "销售部");
						break;
					case 技术部:
						printf("%8s", "技术部");
						break;
					case 人事部:
						printf("%8s", "人事部");
						break;
					}


					switch (p0->post) {
					case 销售经理:
						printf("%10s", "销售经理");
						break;
					case 销售员:
						printf("%10s", "销售员");
						break;
					case 技术员:
						printf("%10s", "技术员");
						break;
					case 经理:
						printf("%10s", "经理");
						break;
					}
					if (p0->post == 销售经理) {
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
	printf("        上一页                   ←   →                  下一页\n");
	printf("\t\t\t\t   %d/%d", sum / 10 + 1, asum / 10 + 1);
	printf("\n");
	if (flag == 0 || flag == 1) {
		printf("\t\t\t    回车键呼出菜单栏.    \t平均工资:%.2lf", allwages / psum);
		printf("\n\t\t\t\t\t\t\t平均工资以上人数为:%d\n", allsum);
	}
	else
		printf("\t\t\t    回车键呼出菜单栏. ");

	if (Ap != 0|| Pt != 0) {
		Ap = 0;
		Pt = 0;
		printf("按回车键返回系统首页...");
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
						printf("已经是第一页了.");
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
							printf("  \t职工号    姓名  性别   部门     岗位  年龄            当月工资  \n");	//员工表，员工表隔壁可以选择看经理和员工之类的
							printf("\t\t\t\t\t\t   工时 月销售额 底薪 合计工资\n");
							sum -= 10;
							rpsum -= 10;
							i = 0;
							allwages = 0; Apwages = 0;
							while (p0 != NULL&&p0->file == permonth[per]) {
								switch (p0->department) {
								case 销售部:
									if (p0->post == 销售经理) {
										p0->wages = xssalesmoney*0.05 + p0->basemoney;
									}
									Apwages += p0->wages;
									break;
								case 技术部:
									if (p0->post == 销售经理) {
										p0->wages = jssalesmoney*0.05 + p0->basemoney;
									}
									Apwages += p0->wages;
									break;
								case 人事部:
									if (p0->post == 销售经理) {
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
												printf("→");
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
											case 销售部:
												printf("%8s", "销售部");
												break;
											case 技术部:
												printf("%8s", "技术部");
												break;
											case 人事部:
												printf("%8s", "人事部");
												break;
											}


											switch (p0->post) {
											case 销售经理:
												printf("%10s", "销售经理");
												break;
											case 销售员:
												printf("%10s", "销售员");
												break;
											case 技术员:
												printf("%10s", "技术员");
												break;
											case 经理:
												printf("%10s", "经理");
												break;
											}
											if (p0->post == 销售经理) {
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
							printf("  \t职工号    姓名  性别   部门     岗位  年龄            当月工资  \n");	//员工表，员工表隔壁可以选择看经理和员工之类的
							printf("\t\t\t\t\t\t   工时 月销售额 底薪 合计工资\n");

							while (p0 != NULL) {
								if (p0->file == permonth[per]) {
									switch (p0->department) {
									case 销售部:
										if (p0->post == 销售经理) {
											p0->wages = xssalesmoney*0.05 + p0->basemoney;
										}
										Apwages += p0->wages;
										break;
									case 技术部:
										if (p0->post == 销售经理) {
											p0->wages = jssalesmoney*0.05 + p0->basemoney;
										}
										Apwages += p0->wages;
										break;
									case 人事部:
										if (p0->post == 销售经理) {
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
												printf("→");
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
											case 销售部:
												printf("%8s", "销售部");
												break;
											case 技术部:
												printf("%8s", "技术部");
												break;
											case 人事部:
												printf("%8s", "人事部");
												break;
											}


											switch (p0->post) {
											case 销售经理:
												printf("%10s", "销售经理");
												break;
											case 销售员:
												printf("%10s", "销售员");
												break;
											case 技术员:
												printf("%10s", "技术员");
												break;
											case 经理:
												printf("%10s", "经理");
												break;
											}
											if (p0->post == 销售经理) {
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
						printf("        上一页                   ←   →                  下一页\n");
						printf("\t\t\t\t   %d/%d", sum / 10 + 1, psum / 10 + 1);
						printf("\n");
						if (flag == 0 || flag == 1) {
							printf("\t\t\t    回车键呼出菜单栏.    \t平均工资:%.2lf", allwages / psum);
							printf("\n\t\t\t\t\t\t\t平均工资以上人数为:%d\n", allsum);
						}
						break;
					}
					break;
				case 77:
					if (sum == asum) {
						printf("已到最后一页,请尝试其他操作.");
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
							printf("  \t职工号    姓名  性别   部门     岗位  年龄            当月工资  \n");	//员工表，员工表隔壁可以选择看经理和员工之类的
							printf("\t\t\t\t\t\t   工时 月销售额 底薪 合计工资\n");
							allwages = 0; Apwages = 0;
							while (p0 != NULL&&p0->file == permonth[per]) {
								switch (p0->department) {
								case 销售部:
									if (p0->post == 销售经理) {
										p0->wages = xssalesmoney*0.05 + p0->basemoney;
									}
									Apwages += p0->wages;
									break;
								case 技术部:
									if (p0->post == 销售经理) {
										p0->wages = jssalesmoney*0.05 + p0->basemoney;
									}
									Apwages += p0->wages;
									break;
								case 人事部:
									if (p0->post == 销售经理) {
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
												printf("→");
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
											case 销售部:
												printf("%8s", "销售部");
												break;
											case 技术部:
												printf("%8s", "技术部");
												break;
											case 人事部:
												printf("%8s", "人事部");
												break;
											}


											switch (p0->post) {
											case 销售经理:
												printf("%10s", "销售经理");
												break;
											case 销售员:
												printf("%10s", "销售员");
												break;
											case 技术员:
												printf("%10s", "技术员");
												break;
											case 经理:
												printf("%10s", "经理");
												break;
											}
											if (p0->post == 销售经理) {
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
							printf("  \t职工号    姓名  性别   部门     岗位  年龄            当月工资  \n");	//员工表，员工表隔壁可以选择看经理和员工之类的
							printf("\t\t\t\t\t\t   工时 月销售额 底薪 合计工资\n");


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
									case 销售部:
										if (p0->post == 销售经理) {
											p0->wages = xssalesmoney*0.05 + p0->basemoney;
										}
										Apwages += p0->wages;
										break;
									case 技术部:
										if (p0->post == 销售经理) {
											p0->wages = jssalesmoney*0.05 + p0->basemoney;
										}
										Apwages += p0->wages;
										break;
									case 人事部:
										if (p0->post == 销售经理) {
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
												printf("→");
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
											case 销售部:
												printf("%8s", "销售部");
												break;
											case 技术部:
												printf("%8s", "技术部");
												break;
											case 人事部:
												printf("%8s", "人事部");
												break;
											}


											switch (p0->post) {
											case 销售经理:
												printf("%10s", "销售经理");
												break;
											case 销售员:
												printf("%10s", "销售员");
												break;
											case 技术员:
												printf("%10s", "技术员");
												break;
											case 经理:
												printf("%10s", "经理");
												break;
											}
											if (p0->post == 销售经理) {
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
						printf("        上一页                   ←   →                  下一页\n");
						printf("\t\t\t\t   %d/%d", sum / 10 + 1, psum / 10 + 1);
						printf("\n");
						if (flag == 0 || flag == 1) {
							printf("\t\t\t    回车键呼出菜单栏.    \t平均工资:%.2lf", allwages / psum);
							printf("\n\t\t\t\t\t\t\t平均工资以上人数为:%d\n", allsum);
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
						printf("  \t职工号    姓名  性别   部门     岗位  年龄            当月工资  \n");	//员工表，员工表隔壁可以选择看经理和员工之类的
						printf("\t\t\t\t\t\t   工时 月销售额 底薪 合计工资\n");
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
											printf("→");
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
										case 销售部:
											printf("%8s", "销售部");
											break;
										case 技术部:
											printf("%8s", "技术部");
											break;
										case 人事部:
											printf("%8s", "人事部");
											break;
										}


										switch (p0->post) {
										case 销售经理:
											printf("%10s", "销售经理");
											break;
										case 销售员:
											printf("%10s", "销售员");
											break;
										case 技术员:
											printf("%10s", "技术员");
											break;
										case 经理:
											printf("%10s", "经理");
											break;
										}
										if (p0->post == 销售经理) {
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
						printf("        上一页                   ←   →                  下一页\n");
						printf("\t\t\t\t   %d/%d", sum / 10 + 1, asum / 10 + 1);
						printf("\n");
						if (flag == 0 || flag == 1) {
							printf("\t\t\t    回车键呼出菜单栏.    \t平均工资:%.2lf", allwages / psum);
							printf("\n\t\t\t\t\t\t\t平均工资以上人数为:%d\n", allsum);
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
						printf("  \t职工号    姓名  性别   部门     岗位  年龄            当月工资  \n");	//员工表，员工表隔壁可以选择看经理和员工之类的
						printf("\t\t\t\t\t\t   工时 月销售额 底薪 合计工资\n");
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
											printf("→");
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
										case 销售部:
											printf("%8s", "销售部");
											break;
										case 技术部:
											printf("%8s", "技术部");
											break;
										case 人事部:
											printf("%8s", "人事部");
											break;
										}


										switch (p0->post) {
										case 销售经理:
											printf("%10s", "销售经理");
											break;
										case 销售员:
											printf("%10s", "销售员");
											break;
										case 技术员:
											printf("%10s", "技术员");
											break;
										case 经理:
											printf("%10s", "经理");
											break;
										}
										if (p0->post == 销售经理) {
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
						printf("        上一页                   ←   →                  下一页\n");
						printf("\t\t\t\t   %d/%d", sum / 10 + 1, asum / 10 + 1);
						printf("\n");
						if (flag == 0 || flag == 1) {
							printf("\t\t\t    回车键呼出菜单栏.    \t平均工资:%.2lf", allwages / psum);
							printf("\n\t\t\t\t\t\t\t平均工资以上人数为:%d\n", allsum);
						}
						break;
					}
					break;
				}
			}
			break;
		case ' ':
			if (flag == 0 || flag == 1) {
				printf("你想对此员工信息作何修改:\n");
				printf("1.修改信息.	2.删除信息.	3.查看此员工完整信息.	4.返回操作. :");
				scanf("%d", &ca);
				switch (ca) {
				case 1:
					printf("想要修改该职工什么信息？\n");
					printf("1.姓名	2.部门	3.职务	4.性别	5.年龄	\n");
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
							printf("		1.销售部	2.技术部	3.人事部\n");
							do {
								printf("该职工修改后的部门为:");
								scanf("%d", &ca2);
								while (getchar() != '\n') continue;
								switch (ca2) {
								case 销售部:
									b->department = 销售部;
									break;
								case 技术部:
									b->department = 技术部;

									break;
								case 人事部:
									b->department = 人事部;


									break;
								default:
									printf("输入错误,请输入部门对应的整数.\n");
									getchar();
									break;
								}
							} while (ca2 < 1 && ca2 > 3);

							break;
						case 3:
							printf("		1.销售经理	2.销售员	3.技术员	4.经理\n");

							do {
								printf("该职工修改后的职务为:");
								scanf("%d", &ca2);
								while (getchar() != '\n') continue;
								switch (ca2) {
								case 销售经理:
									b->post = 销售经理;
									b->worktime = 0;
									b->basemoney = 5000;
									b->wages = b->basemoney + allsalesmoney*0.05;
									break;
								case 销售员:
									b->post = 销售员;
									b->worktime = 0;
									printf("请输入该员工所属部门该月销售额：");
									scanf("%lf", &b->salesmoney);
									b->basemoney = 0;
									allsalesmoney += b->salesmoney;
									b->wages = b->salesmoney*0.4;
									break;
								case 技术员:
									b->post = 技术员;
									printf("请输入该员工该月工作时间(累计小时总数)：");
									scanf("%lf", &b->worktime);
									b->basemoney = 0;
									b->wages = (b->worktime) * 100;
									break;
								case 经理:
									b->post = 经理;
									b->worktime = 0;
									b->basemoney = 0;
									b->wages = 8000;
									break;
								default:
									printf("输入错误,请输入职务对应的整数.\n");
									getchar();
								}
							} while (ca2 < 1 && ca2 > 4);
							break;
						case 4:
							printf("该职工修改后的性别为:");
							scanf("%s", b->sex);
							while (getchar() != '\n') continue;
							break;
						case 5:
							printf("该职工修改后的年龄为:");
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
							printf("		1.销售部	2.技术部	3.人事部\n");
							do {
								printf("该职工修改后的部门为:");
								scanf("%d", &ca2);
								while (getchar() != '\n') continue;
								switch (ca2) {
								case 销售部:
									b->next->department = 销售部;
									hey = head;
									while (hey != NULL) {
										if (p->file == hey->file)
											if (p1->post == 销售经理&&hey->department == b) {
												printf("每个部门只能有一个销售经理,操作失败.\n");
												printf("按任意键回到主界面.");
												getchar();
												home();
											}
										p1 = p1->next;
									}
									break;
								case 技术部:
									b->next->department = 技术部;
									hey = head;
									while (hey != NULL) {
										if (p->file == hey->file)
											if (p1->post == 销售经理&&hey->department == b) {
												printf("每个部门只能有一个销售经理,操作失败.\n");
												printf("按任意键回到主界面.");
												getchar();
												home();
											}
										p1 = p1->next;
									}
									break;
								case 人事部:
									b->next->department = 人事部;
									hey = head;
									while (hey != NULL) {
										if (p->file == hey->file)
											if (p1->post == 销售经理&&hey->department == b) {
												printf("每个部门只能有一个销售经理,操作失败.\n");
												printf("按任意键回到主界面.");
												getchar();
												home();
											}
										p1 = p1->next;
									}
									break;
								default:
									printf("输入错误,请输入部门对应的整数.\n");
									getchar();
									break;
								}
							} while (ca2 < 1 && ca2 > 3);

							break;
						case 3:
							printf("		1.销售经理	2.销售员	3.技术员	4.经理\n");

							do {
								printf("该职工修改后的职务为:");
								scanf("%d", &ca2);
								while (getchar() != '\n') continue;
								switch (ca2) {
								case 销售经理:
									b->next->post = 销售经理;
									b->next->worktime = 0;
									b->next->basemoney = 5000;
									b->next->wages = b->next->basemoney + allsalesmoney*0.05;
									break;
								case 销售员:
									b->next->post = 销售员;
									b->next->worktime = 0;
									printf("请输入该员工所属部门该月销售额：");
									scanf("%lf", &b->next->salesmoney);
									b->next->basemoney = 0;
									allsalesmoney += b->next->salesmoney;
									b->next->wages = b->next->salesmoney*0.4;
									break;
								case 技术员:
									b->next->post = 技术员;
									printf("请输入该员工该月工作时间(累计小时总数)：");
									scanf("%lf", &b->next->worktime);
									b->next->basemoney = 0;
									b->next->wages = (b->next->worktime) * 100;
									break;
								case 经理:
									b->next->post = 经理;
									b->next->worktime = 0;
									b->next->basemoney = 0;
									b->next->wages = 8000;
									break;
								default:
									printf("输入错误,请输入职务对应的整数.\n");
									getchar();
								}
							} while (ca2 < 1 && ca2 > 4);
							break;
						case 4:
							printf("该职工修改后的性别为:");
							scanf("%s", b->next->sex);
							while (getchar() != '\n') continue;
							break;
						case 5:
							printf("该职工修改后的年龄为:");
							scanf("%s", b->next->sex);
							while (getchar() != '\n') continue;
							break;
						}
					}
					if (ca1 != 1) {
						printf("修改成功.回车键返回页面.");
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
					printf("删除成功.回车键返回页面.");
					while (getchar() != '\n') continue;
					getchar();
					break;
				case 3:
					system("cls");
					p0 = head;
					for (i = 0; i < 3 * MAXCOL / 7; i++)
						printf(" ");
					if (b == NULL) {
						printf("职工号:%d", head->num);
					}
					else
						printf("职工号:%d", b->next->num);
					printf("\n");
					for (i = 0; i < MAXCOL; i++)
						printf("*");
					printf("  \t工作月份    姓名  性别   部门     岗位  年龄            当月工资  \n");	//员工表，员工表隔壁可以选择看经理和员工之类的
					printf("\t\t\t\t\t\t     工时 月销售额 底薪 合计工资\n");

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
								case 销售部:
									printf("%8s", "销售部");
									break;
								case 技术部:
									printf("%8s", "技术部");
									break;
								case 人事部:
									printf("%8s", "人事部");
									break;
								}


								switch (p0->post) {
								case 销售经理:
									printf("%10s", "销售经理");
									break;
								case 销售员:
									printf("%10s", "销售员");
									break;
								case 技术员:
									printf("%10s", "技术员");
									break;
								case 经理:
									printf("%10s", "经理");
									break;
								}
								if (p0->post == 销售经理) {
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
								case 销售部:
									printf("%8s", "销售部");
									break;
								case 技术部:
									printf("%8s", "技术部");
									break;
								case 人事部:
									printf("%8s", "人事部");
									break;
								}


								switch (p0->post) {
								case 销售经理:
									printf("%10s", "销售经理");
									break;
								case 销售员:
									printf("%10s", "销售员");
									break;
								case 技术员:
									printf("%10s", "技术员");
									break;
								case 经理:
									printf("%10s", "经理");
									break;
								}
								if (p0->post == 销售经理) {
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
					printf("按回车键返回主菜单...");
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
			printf("\t	   1.添加数据到当前月份.\n\n");
			printf("\t	   2.按部门显示员工信息.\n\n");
			printf("\t	   3.按岗位显示员工信息.\n\n");
			printf("\t	   4.退出本系统.\n\n");
			printf("\t	   5.返回当前页面.\n\n");
			printf("\t	   6.返回首页.\n");
			printf("\n\n");
			for (i = 0; i < MAXCOL; i++)
				printf("*");
			while (1) {
				printf("请输入你的选择:");
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
					printf("输入错误.");
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
	printf("\t   A．经理:固定月薪为8000.\n");
	printf("\t   B．技术员:工作时间×小时工资（100元每小时）.\n");
	printf("\t   C．销售员:销售额×4%提成.\n");
	printf("\t   D．销售经理:底薪(5000)+所辖部门销售额总额×0.5.\n");
	printf("\n\n");
	printf("\t\t\t\t请尽量正确操作,如发现漏洞请及时与作者联系.\n");
	for (i = 0; i < MAXCOL; i++)
		printf("*");
	for (i = 0; i < 30; i++)
		printf(" ");
	printf("返回主页面请按回车键.");
	getchar();
}



void loadin(void) {
	int i;
	int temp = 0;
	int zzz = 0;
	char secret[7];
	char c;
	system("cls");
	for (i = 0; i < MAXCOL; i++)								//边框
		printf("*");
	printf("\n\n\t\t    ┌────────────────────┐\n");
	printf("\t\t    │               用户登录                 │\n");
	printf("\t\t    │   ┌───────────────┐   │\n");
	printf("\t\t    │   │  默认账户：dgut              │   │\n");
	printf("\t\t    │   └───────────────┘   │\n");
	printf("\t\t    │   ┌───────────────┐   │\n");
	printf("\t\t    │   │  密码：                      │   │\n");
	printf("\t\t    │   └───────────────┘   │\n");
	printf("\t\t    │                                        │\n");
	printf("\t\t    │                                        │\n");
	printf("\t\t    │                                        │\n");
	printf("\t\t    │                                        │\n");
	printf("\t\t    │                    初始密码：123456    │\n");
	printf("\t\t    └────────────────────┘\n\n");
	printf("                                                        请输入回车键进入系统.\n");
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
			for (i = 0; i < MAXCOL; i++)								//边框
				printf("*");
			printf("\n\n\t\t    ┌────────────────────┐\n");
			printf("\t\t    │               用户登录                 │\n");
			printf("\t\t    │   ┌───────────────┐   │\n");
			printf("\t\t    │   │  默认账户：dgut              │   │\n");
			printf("\t\t    │   └───────────────┘   │\n");
			printf("\t\t    │   ┌───────────────┐   │\n");
			printf("\t\t    │   │  密码：");
			for (i = 0; i<temp; i++)
				printf("*");
			for (i = 0; i<6 - temp; i++)
				printf(" ");
			printf("                │   │\n");
			printf("\t\t    │   └───────────────┘   │\n");
			printf("\t\t    │                                        │\n");
			printf("\t\t    │                                        │\n");
			printf("\t\t    │                                        │\n");
			printf("\t\t    │                                        │\n");
			printf("\t\t    │                    初始密码：123456    │\n");
			printf("\t\t    └────────────────────┘\n\n");
			printf("                                                        请输入回车键进入系统.\n");
			for (i = 0; i < MAXCOL; i++)
				printf("*");
			break;



		case '\n':case '\r':
			secret[temp] = '\0';
			if (strcmp(secret, "123456") == 0) {
				printf("登陆成功.");
				getchar();
				Menu();
			}
			else {
				printf("密码错误，请重新输入.");
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
			for (i = 0; i < MAXCOL; i++)								//边框
				printf("*");
			printf("\n\n\t\t    ┌────────────────────┐\n");
			printf("\t\t    │               用户登录                 │\n");
			printf("\t\t    │   ┌───────────────┐   │\n");
			printf("\t\t    │   │  默认账户：dgut              │   │\n");
			printf("\t\t    │   └───────────────┘   │\n");
			printf("\t\t    │   ┌───────────────┐   │\n");
			printf("\t\t    │   │  密码：");
			for (i = 0; i<temp; i++)
				printf("*");
			for (i = 0; i<6 - temp; i++)
				printf(" ");
			printf("                │   │\n");
			printf("\t\t    │   └───────────────┘   │\n");
			printf("\t\t    │                                        │\n");
			printf("\t\t    │                                        │\n");
			printf("\t\t    │                                        │\n");
			printf("\t\t    │                                        │\n");
			printf("\t\t    │                    初始密码：123456    │\n");
			printf("\t\t    └────────────────────┘\n\n");
			printf("                                                        请输入回车键进入系统.\n");
			for (i = 0; i < MAXCOL; i++)
				printf("*");
			break;
		}
	}
	while (getchar() != '\n') continue;
}