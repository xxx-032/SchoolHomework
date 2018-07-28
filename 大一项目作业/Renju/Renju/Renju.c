#include<stdio.h>			//printf()函数头文件
// stidio 就是指"standard buffered input&output"
//带缓冲的标准输入输出,用到标准输入输入输出函数时,就要包含这个头文件！
#include<stdlib.h>			//atoi()函数头文件
//stdlib 头文件即standard library标准库头文件
#include<ctype.h>
//ctype.h是C标准函数库中的头文件，定义了一批C语言字符分类函数，用于测试字符是否属于特定的字符类别，如字母字符、控制字符等等。既支持单字节（Byte)字符，也支持宽字符。
#include<string.h>
//C语言里面关于字符数组的函数定义的头文件，常用函数有strlen、strcmp、strcpy等等
#include<conio.h> 
#include<time.h>

void Qingping(void);					//清除屏幕内容
void Menu(void);						//菜单栏
void Set(void);						//设置(位置输入和方向输入,人机难度设置) 未实现
void computer_judge(int row, int col);			//人机对战
void Rule(void);						//查看规则
void About_us(void);					//关于我们
void Ranking_list(void);				//排行榜
int Judge(int, int, int);						//胜负判断
void picture(int);
void chessboard(int);				//显示棋盘
void chessboard2(int);
void Game_start(void);				//开始游戏
void initStatus();					//初始化数据
void setStatus(int *, int *, int);					//获取数据
int getStatus(int, int);					//获取数据
void choiceagain(int, int);						//菜单选择
void game_choice(int);						//游戏胜利后选择			
void menu_choice(void);						//菜单选择
void Inputpoint(int *, int *, int);				//获取玩家下子点
void Reset(int, int);							//悔棋		游戏过程中的功能未实现(悔棋及多次悔棋。设置,撤销,计时,强行退出游戏，人机对战）
void End(void);							//正常退出显示界面			//游戏内容设置(字体大小,最好实现画面和背景)
void insert_list(void);					//更新排行榜
void edit_list(void);					//修改排行榜信息
void initStatus2(void);					//初始化键盘操作
void load(void);						//重载游戏
void save(void);						//保存棋局情况
void savemedia(void);					//保存棋局录像
void media(void);						//录像回放
void loadscore(void);					//保存人机棋局位置
void savescore(void);					//保存人机棋局位置
struct Player {							//用于排行榜（未实现）
	int num;						//实现名次序列
	char name[20];						//用于存储玩家信息
	int score;						//下棋步数得分
									//double time;
	struct Player *next;					//指向下一个玩家信息
}*head = NULL;							//全局变量头指针
#define MAXROW 40						//生成框架大小,用于调整游戏边框（行距）
#define MAXCOL 60						//列距
#define nrow 17							//控制棋盘大小及边框（行距）
#define ncol 17							//列距
#define status_Blank -1					//判断下棋情况，初始化-1为空
#define status_Black 0					//判断下棋情况，0为黑棋下子
#define status_White 1					//判断下棋情况，1为白棋下子
#define chess_Blank "┼"				//情况为-1时，输出棋盘结构
#define chess_Black "●"				//情况为0时，输出黑子
#define chess_White "○"				//情况为1时，输出白子
#define normal 0					//棋盘正常输出情况
#define action 1					//棋盘菜单模式
#define reset 2						//悔棋棋局显示模式
#define winer -1					//胜利后棋盘显示
#define guangbiao 10				//键盘操作显示光标
int nowrow = 2;						//光标所在行
int nowcol = 2;						//光标所在列
int oldrow = 0;						//下棋所在行
int oldcol = 0;						//下棋所在列
int location[nrow][ncol];				//保存棋盘情况和下子位置
int score[nrow][ncol];				//电脑计算位置分数
int nStep = 0;						//全局变量计算步数
int ntimes = 1;						//计算玩家游戏次数
int rtimes = 1;						//重置次数
int getsmode = 0;					//操作模式
int wins = 0;						//判断胜利情况
int ptimes = 0;						//用来设置背景玩的
int c_row = 10;						//电脑初始化下棋位置所在行
int c_col = 10;						//电脑初始化下棋位置所在列
int c_flag = 0;						//人机判断玩家已下棋标志
int c_choice = 0;					//人机模式
FILE *fp;							//全局文件指针
/*************************************************************************************************************************
[函数名称]main
[函数功能]程序主函数,即入口函数
[函数参数]无
[返回值]int：说明程序的退出状态
*************************************************************************************************************************/


void picture(int mode)									//壁纸元素
{	
	if (mode == 0) {								//壁纸1
		int i;
		Qingping();
		for (i = 0; i < MAXCOL; i++)								//边框
			printf("*");
		printf("\n\n\n\n");
		printf("\t听说游戏支持两种操作模式，快去设置试试吧！\n");
		printf("\t\t\t  PS：人机也可以喔.");
		printf("\n\n\n\n\n\n");
		printf("\t\t\t\t按回车键继续游戏.\n");
		for (i = 0; i < MAXCOL; i++)								//边框
			printf("*");
		fflush(stdin);
		ptimes++;
		getchar();
		getchar();
	}
	if (mode == 1) {										//壁纸2
		int i;
		Qingping();
		for (i = 0; i < MAXCOL; i++)								//边框
			printf("*");
		printf("\n\n\n\n");
		printf("\t游戏操作提示在右侧.\n");
		printf("\t游戏中按回车键右侧还会出现菜单栏喔.\n");
		printf("\n\n\n\n");
		printf("\t\t\t\t按回车键继续游戏.\n");
		for (i = 0; i < MAXCOL; i++)								//边框
			printf("*");
		ptimes++;
		fflush(stdin);
		getchar();
		getchar();
	}
	if (mode == 2) {									//壁纸3
		int i;
		Qingping();
		for (i = 0; i < MAXCOL; i++)								//边框
			printf("*");
		printf("\n\n\n\n");
		printf("\t  加载游戏同样支持人机对战,请玩家尽量享受游戏.");
		printf("\n\n\n\n\n\n");
		printf("\t\t\t\t按回车键继续游戏.\n");
		for (i = 0; i < MAXCOL; i++)								//边框
			printf("*");
		ptimes++;
		fflush(stdin);
		getchar();
		getchar();
	}
	if (mode == 3) {									//壁纸4
		int i;
		Qingping();
		for (i = 0; i < MAXCOL; i++)								//边框
			printf("*");
		printf("\n");
		printf("播放时无提示,请谨记以下操作：\n\n\n\n");
		printf("\t\t\t    R.回主页菜单.\n");
		printf("\t\t  上一页.A \tD.下一页");
		printf("\n\n\n\t\t录像仅回放上一局情况.\n\n\n");
		printf("\t\t\t\t按回车键继续游戏.\n");
		for (i = 0; i < MAXCOL; i++)								//边框
			printf("*");
		ptimes++;
		fflush(stdin);
		getchar();
		getchar();
	}
}




int main(void)											//主函数
{
	int i;
	system("mode con cols=60 lines=40");						//控制显示命令屏大小
	system("color 07");
	for (i = 0; i < MAXCOL; i++)								//边框
		printf("*");
	printf("\n\n\n\n");
	for (i = 0; i < MAXCOL / 4; i++)								//居中
		printf(" ");
	printf("欢迎进入五子棋游戏.\n\n\n\n\n");
	for (i = 0; i < MAXCOL * 5 / 8; i++)								//居中
		printf(" ");
	printf("请输入回车键继续游戏.\n");
	for (i = 0; i < MAXCOL; i++)
		printf("*");
	while (getchar() != '\n')
		printf(" ");
	picture(ptimes % 3);
	Menu();														//调用菜单函数

	return 0;//如果返回0,则代表程序正常退出；返回其他数字的含义则由系统决定
}




void Qingping(void)					//清除屏幕内容
{
	system("cls");                      //清屏
}



void Menu(void)							//菜单栏
{
	int i;
	Qingping();
	printf("玩家你好,欢迎你来到五子棋游戏.\n");
	for (i = 0; i < MAXCOL; i++)								//边框
		printf("*");
	printf("\n\n\n");
	printf("\t1.开始游戏\t2.载入游戏\t3.排行榜\n");
	printf("\n\n");
	for (i = 0; i < MAXCOL; i++)								//居中
		printf(" ");
	printf("\t4.查看规则\t5.关于我们\t6.退出\n");
	printf("\n\n");
	printf("\t7.设置\t\t8.人机对战\t9.录像回放\n");
	printf("\n\n\n\n");
	for (i = 0; i < MAXCOL; i++)								//边框
		printf("*");
	menu_choice();												//获取用户选择
}




void menu_choice(void)										//菜单选择
{
	int choice;
	while (1) {												//循环输入，直到玩家选择退出
		printf("请输入你的选择,并按回车确定你的选择:");
		scanf_s("%d", &choice);								//用户输入
		switch (choice) {
		case 1:

			nStep = 0;						//初始化步数
			if (getsmode == 0)				//初始化键入坐标操作
				initStatus();
			if (getsmode == 1)				//初始化键盘直接操作
				initStatus2();
			c_choice = 0;
			Game_start();						//开始游戏
			break;
		case 2:
			load();
			if (c_choice == 1)
				loadscore();
			Game_start();
			break;
		case 3:
			Ranking_list();					//排行榜
			Menu();					//返回菜单
			break;
		case 4:
			Rule();						//规则
			Menu();						//返回菜单
			break;
		case 5:
			About_us();					//有关我们
			Menu();						//返回菜单
			break;
		case 6:
			End();						//退出游戏
			break;						//返回菜单
		case 7:
			Set();						//设置游戏
			Menu();
			break;
		case 8:
			if (getsmode == 0)			//初始化键入坐标操作
				initStatus();
			if (getsmode == 1)			//初始化键盘直接操作
				initStatus2();
			c_choice = 1;
			fp = fopen("score.txt", "w");
			fclose(fp);
			Game_start();
			break;
		case 9:
			picture(3);					//直接显示壁纸4
			media();					//录像回放
			break;
		default:
			printf("输入错误,请输入菜单栏对应的整数.\n");
			printf("\n");
			getchar();
			break;
		}
	}
}


void savemedia(void)
{
	int i = 0, j = 0;
	if (((fp = fopen("video.txt", "a+")) == NULL)) {		//若不存在文件则创建并初始化
		initStatus();
	}
	fp = fopen("video.txt", "a+");							//若存在则在文件尾增加棋局情况
	fseek(fp, 0, SEEK_END);
	for (i = 0; i < nrow; i++) {
		for (j = 0; j < ncol; j++) {
			if ((location[i][j]) == guangbiao) {			//若为键盘操作则初始化光标
				fprintf(fp, "%3d", status_Blank);		
				continue;
			}
			fprintf(fp, "%3d", location[i][j]);
		}
	}
	fprintf(fp, "%3d", nStep);								//标志棋盘是否胜利且为是否开始状态
	fclose(fp);
}




void media(void)
{
	int i = 0, j = 0, flen, len, Step;
	char choice;
	if ((fp = fopen("video.txt", "r")) != NULL) {			//检查录像文件是否为空，提示玩家信息
		fseek(fp, 0, SEEK_END);
		flen = ftell(fp);
		fseek(fp, 0, SEEK_SET);
		if (flen == ftell(fp)) {
			printf("无录像文件,请游戏一局再回来欣赏你的风姿.\n");
		}

		else {
			fseek(fp, 870L, SEEK_SET);					//不为空则定位操作
			len = ftell(fp);
			fseek(fp, 0, SEEK_SET);
			while (ftell(fp) != flen) {
				while (ftell(fp) != len) {
					if ((ftell(fp)) == (len - 3)) {		//%3d 占3个字节长度
						fscanf(fp, "%d", &Step);
						continue;
					}
					fscanf(fp, "%d", &location[i][j]);
					j++;
				}
				chessboard(winer);
				choice = getch();
				if (choice == 'a' || choice == 'A' || choice == 'd' || choice == 'D' || choice == 'r' || choice == 'R') {
					i = 0; j = 0;
					switch (choice) {					//玩家键盘直接选择
					case 'a':case 'A':
						fseek(fp, -870L, SEEK_CUR);			//定位操作
						len = ftell(fp);
						fseek(fp, -870L, SEEK_CUR);
						break;
					case 'd':case 'D':
						fseek(fp, 870L, SEEK_CUR);
						len = ftell(fp);
						fseek(fp, -870L, SEEK_CUR);
						break;
					case 'r':case 'R':
						system("color 07");
						picture(ptimes % 3);
						Menu();
						break;
					}
				}
			}
		}
	}
	else {
		fp = fopen("video.txt", "w");
		printf("无录像文件,请游戏一局再回来欣赏你的风姿.\n");
	}
	fclose(fp);
	printf("播放完毕,回车键返回主菜单");
	getchar();
	getchar();
	system("color 07");
	picture(ptimes % 3);
	Menu();
}



void save(void)						//保存最后一次棋局状况
{
	int i, j;
	fp = fopen("load.txt", "w+");						//每次更新棋局状况
	fseek(fp, 0, SEEK_SET);
	for (i = 0; i < nrow; i++) {
		for (j = 0; j < ncol; j++) {
			fprintf(fp, "%3d", location[i][j]);
		}
	}
	fprintf(fp, "%3d", wins);
	if (getsmode == 0)
		fprintf(fp, "%3d", nStep + 1);					//判断是否为空情况和胜利状况
	if (getsmode == 1)
		fprintf(fp, "%3d", nStep );
	fprintf(fp, "%3d", c_choice);
	fclose(fp);
}



void Set(void) {					//操作设置
	int choice;
	int i;
	Qingping();
	for (i = 0; i < MAXCOL; i++)								//边框
		printf("*");
	printf("\n\n");
	printf("\t\t1.键入坐标操作.\n\n\n");
	printf("\t\t2.键盘直接操作.\n\n\n");
	printf("\t\t3.返回主菜单.\n\n");
	printf("\n\n");
	for (i = 0; i < MAXCOL; i++)								//边框
		printf("*");
	printf("请输入你的选择,并按回车确定你的选择:");
	scanf_s("%d", &choice);
	while (choice < 1 || choice>3) {
		printf("输入错误,请输入菜单栏对应的整数:\n");
		scanf_s("%d", &choice);
	}
	switch (choice) {
	case 1:
		getsmode = 0;						//键入操作模式
		Menu();
		break;
	case 2:
		getsmode = 1;						//坐标操作模式
		Menu();
		break;
	case 3:
		Menu();
		break;
	}
	getchar();
}


void load(void) {
	int i = 0, j = 0, flen;
	if ((fp = fopen("load.txt", "r")) != NULL) {				//判断文件状况是否为空，空则初始化，否则则读入文件

	}
	else {
		if (getsmode == 0)
			initStatus();
		if (getsmode == 1)
			initStatus2();
		fp = fopen("load.txt", "r");
	}
	fseek(fp, 0, SEEK_END);
	flen = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	while (ftell(fp) != flen) {
		if ((ftell(fp)) == (flen - 9)) {
			fscanf(fp, "%3d", &wins);
			fscanf(fp, "%3d", &nStep);
			fscanf(fp, "%3d", &c_choice);
			continue;
		}
		fscanf(fp, "%3d", &location[i][j]);
		j++;
	}
	fclose(fp);
	if (wins == 1) {
		if (getsmode == 1) {
			for (i = 0; i < nrow; i++) {
				for (j = 0; j < ncol; j++) {
					location[i][j] = status_Blank;					//初始化棋盘位置情况
				}
			}
			location[nowrow][nowcol] = guangbiao;
			nStep = 0;
		}
		else {
			for (i = 0; i < nrow; i++) {
				for (j = 0; j < ncol; j++) {
					location[i][j] = status_Blank;					//初始化棋盘位置情况
				}
			}
			nStep = 0;												//判断已经胜利则初始化棋局
		}
	}
}



void Rule(void)						//查看规则
{
	int i;
	Qingping();
	for (i = 0; i < MAXCOL; i++)								//边框
		printf("*");
	printf("\n\n");
	printf("游戏规则如下:\n\n");
	printf("\t本游戏棋子分为黑白两色,棋盘大小为15×15,棋子放置于棋盘线交叉点上,");
	printf("两人对局,各执一色,轮流下一子,先将横，竖或斜线的5个或5个以上同");
	printf("色棋子连成不间断的一排者为胜。\n");
	printf("\n\n\n\n\t\t先手玩家棋子颜色为黑色。");
	//printf("可以通过设置设置先手问题和棋子颜色问题。");//未实现
	printf("\n\n");
	for (i = 0; i < MAXCOL; i++)								//边框
		printf("*");
	printf("返回主页面请按回车键.");
	getchar();
	getchar();
}




void insert_list(void)								//创建排行
{
	struct Player *p, *p0, *p1 = NULL, *p2 = NULL, *p3 = NULL;
	int flen;
	if ((fp = fopen("ranklist.txt", "r")) != NULL) {
	}
	else {
		((fp = fopen("ranklist.txt", "w")) == NULL);
	}
	fseek(fp, 0, SEEK_END);
	flen = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	if ((p = (struct Player*)malloc(sizeof(struct Player))) == NULL) {	//指针申请内存空间
		printf("不能成功分配存储块！\n");
		exit(0);
	}							
	if (ftell(fp) == flen) {
		head = NULL;
	}
	else {
		head = p;
		while (ftell(fp) != flen) {
			fscanf(fp, "%d", &p->num);
			fscanf(fp, "%s", p->name);
			fscanf(fp, "%d", &p->score);
			if ((p0 = (struct Player*)malloc(sizeof(struct Player))) == NULL) {	//指针申请内存空间
				printf("不能成功分配存储块！\n");
				exit(0);
			}
			p1 = p;
			p->next = p0;
			p = p0;
			ntimes++;
		}
		if (ntimes>1)
			p1->next = NULL;
	}
	if ((p = (struct Player*)malloc(sizeof(struct Player))) == NULL) {	//指针申请内存空间
		printf("不能成功分配存储块！\n");
		exit(0);
	}
	p->next = NULL;
	printf("新用户你好,请输入玩家姓名：");
	scanf("%s", p->name);							//输入姓名
	p->num = ntimes;							//根据游戏次数自动排号
	p->score = nStep;							//步数统计
	p0 = p; 								//不改变原有p地址，防止操作失误导致地址丢失
	p1 = head;								//不改变原有头地址，防止操作失误导致地址丢失
	if (head == NULL) {							//若头指针为空，则新指针作为头指针
		head = p0;
		p0->next = NULL;
	}
	else {
		while ((p0->score >= p1->score) && (p1->next != NULL)) {		//寻找新指针成绩对应前后位置
			p2 = p1;
			p1 = p1->next;
		}
		if (p0->score >= p1->score) {					//若指向尾结点，则作为尾结点指向NULL
			p1->next = p0;
			p0->next = NULL;
		}
		else if (head == p1) {						//若指向头结点，则作头结点，再把头指针指向头结点
			if (ntimes == 1)
				p0->next = NULL;
			else {
				p3 = p2->next;
				p2->next = p0;
				p0->next = p3;
			}
		}
		else {								//若在两点中间则插入其中
			p2->next = p0;
			p0->next = p1;
		}
	}
	fclose(fp);
	if ((fp = fopen("ranklist.txt", "w")) == NULL)
	{
		fprintf(fp, "Can not open output file.\n");
		exit(0);
	}
	fseek(fp, 0, SEEK_SET);
	p = head;
	ntimes = 1;
	while (p != NULL) {
		p->num = ntimes;
		p = p->next;
		ntimes++;
	}
	p = head;
	while (p != NULL) {
		fprintf(fp, "%3d%8s%3d", p->num, p->name, p->score);			//输出信息
		p = p->next;
	}
	fclose(fp);
	getchar();
}



void edit_list(void)								//修改排行榜内玩家姓名
{
	int ltimes = 0, flen, choice2;
	char name[20], choice;
	struct Player *p, *p0, *p1 = NULL, *p2 = NULL, *p3 = NULL;
	if ((fp = fopen("ranklist.txt", "r")) == NULL)
	{
		fprintf(fp, "Can not open output file.\n");
		exit(0);
	}
	fseek(fp, 0, SEEK_END);
	flen = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	if (ftell(fp) == flen) {
		printf("请先创建新玩家才能修改信息.\n");
		printf("若要继续操作请输入(1.新玩家登记	2.返回菜单)：");
		while (1) {												//循环输入，直到玩家选择退出
			fflush(stdin);								//清除缓冲区域
			scanf_s("%d", &choice2);								//用户输入
			switch (choice2) {
			case 1:
				insert_list();
				break;
			case 2:
				picture(ptimes % 3);
				Menu();
				break;
			default:
				printf("输入错误,请输入提示信息上对应的整数.\n");
				fflush(stdin);
				break;
			}
		}
	}
	else {
		if ((p = (struct Player*)malloc(sizeof(struct Player))) == NULL) {	//指针申请内存空间
			printf("不能成功分配存储块！\n");
			exit(0);
		}
		head = p;
		while (ftell(fp) != flen) {
			fscanf(fp, "%d", &p->num);
			fscanf(fp, "%s", p->name);
			fscanf(fp, "%d", &p->score);
			if ((p0 = (struct Player*)malloc(sizeof(struct Player))) == NULL) {	//指针申请内存空间
				printf("不能成功分配存储块！\n");
				exit(0);
			}
			if (ftell(fp) == flen)
				p0 = NULL;
			p->next = p0;
			p = p0;
			ltimes++;
		}
	}
	fclose(fp);
	if (p != NULL) {
		p->next = NULL;
	}
	p0 = head;
	printf("请输入需要修改的玩家姓名：");
	scanf("%s", name);							//输入姓名
	while ((strcmp(p0->name, name) != 0) && (p0->next != NULL)) {
		p0 = p0->next;
	}
	if (strcmp(p0->name, name) != 0) {						//判断姓名位置
		printf("排行榜内并无有关此玩家信息,请确认是否输入错误.\n");
		printf("是否继续执行修改操作？若继续输入Y,取消返回菜单输入N\n");
		do {
			scanf("%c", &choice);					//输入选择
			choice = toupper(choice);
			if ((choice != 'Y') && (choice != 'N'))
				printf("输入错误，请输入提示信息对应的字母：");
		} while ((choice != 'Y') && (choice != 'N'));			//判断选择
		switch (choice) {						//选择成立对应的选择
		case 'Y':
			insert_list();						//修改信息
			game_choice((nStep - 1) % 2);				//返回游戏最后幕间
			break;
		case 'N':
			game_choice((nStep - 1) % 2);				//返回游戏最后幕间
		}
	}
	else {
		printf("该玩家原始数据为：num=%d  score=%d\n", p0->num, p0->score);
		printf("若输入玩家名字错误请按F,无误请按Y:");
		fflush(stdin);
		do {
			getchar();
			scanf("%c", &choice);					//输入选择
			choice = toupper(choice);
			if ((choice != 'Y') && (choice != 'F'))
				printf("输入错误，请输入提示信息对应的字母：");
		} while ((choice != 'Y') && (choice != 'F'));
		switch (choice) {
		case 'Y':
			break;
		case 'F':
			edit_list();
			break;
		}
		printf("确认无误后,请输入新的名字：");
		p1 = head;
		while (strcmp(p1->name, p0->name) != 0) {
			p2 = p1;
			p1 = p1->next;
		}
		if ((p1 == head) && (p2 == NULL)&& (p1->next == NULL)) {
			head = NULL;
		}
		else if ((p1 == head) && (p1->next != NULL)) {
			head = p1->next;
		}
		else {
			p2->next = p1->next;
		}
		scanf("%s", p0->name);						//修改姓名
		p0->score = nStep;
		p1 = head;
		if (head == NULL) {							//若头指针为空，则新指针作为头指针
			head = p0;
			p0->next = NULL;
		}
		else {
			while ((p0->score >= p1->score) && (p1->next != NULL)) {		//寻找新指针成绩对应前后位置
				p2 = p1;
				p1 = p1->next;
			}
			if ((p1->next == NULL) && (p0->score >= p1->score)) {
				p1->next = p0;
				p0->next = NULL;
			}
			else if ((p1->next == NULL) && (p0->score < p1->score)) {
				p2->next = p0;
				p0->next = p1;
			}
			else if (p1 == head) {
				p0->next = p1;
				head = p0;
			}
			else {								//若在两点中间则插入其中
				p2->next = p0;
				p0->next = p1;
			}
		}
		printf("修改成功,按回车后返回主菜单.");
		if ((fp = fopen("ranklist.txt", "w")) == NULL)
		{
			fprintf(fp, "Can not open output file.\n");
			exit(0);
		}
		fseek(fp, 0, SEEK_SET);
		p = head;
		ntimes = 1;
		while (p != NULL) {
			p->num = ntimes;
			p = p->next;
			ntimes++;
		}
		p = head;
		while (p != NULL) {
			fprintf(fp, "%3d%8s%3d", p->num, p->name, p->score);			//输出信息
			p = p->next;
		}
		fclose(fp);
		getchar();
		getchar();
	}
}



void Ranking_list(void)				//排行榜
{
	int i, flen;
	struct Player *p, *p0 = NULL, *p1 = NULL;
	if ((fp = fopen("ranklist.txt", "r")) != NULL) {
	}
	else {
		((fp = fopen("ranklist.txt", "w")) == NULL);
	}
	fseek(fp, 0, SEEK_END);
	flen = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	if ((p = (struct Player*)malloc(sizeof(struct Player))) == NULL) {	//指针申请内存空间
		printf("不能成功分配存储块！\n");
		exit(0);
	}
	head = p;
	if (ftell(fp) == flen) {
		p->next = NULL;								//保证尾指针为空
	}
	else {
		while (ftell(fp) != flen) {
			fscanf(fp, "%d", &p->num);
			fscanf(fp, "%s", p->name);
			fscanf(fp, "%d", &p->score);
			if ((p0 = (struct Player*)malloc(sizeof(struct Player))) == NULL) {	//指针申请内存空间
				printf("不能成功分配存储块！\n");
				exit(0);
			}
			p1 = p;
			p->next = p0;
			p = p0;
		}
	}
	if (p1 != NULL) {
		p1->next = NULL;
	}
	p0 = head;
	Qingping();
	for (i = 0; i < MAXCOL; i++)								//边框
		printf("*");
	printf("\n");
	printf("\t\t五子棋得分榜\n");
	printf("%-5s %-5s %-5s\n", "名次", "玩家", "步数");
	while (p0 != NULL) {
		if (p0->num < 0)
			break;
		printf("  %-3d %-8s %-5d\n", p0->num, p0->name, p0->score);			//输出信息
		p0 = p0->next;
	}
	printf("\n\n\n\n");
	printf("\t说明：步数越少排名越高");
	printf("返回主页面请按回车键.\n");
	for (i = 0; i < MAXCOL; i++)								//边框
		printf("*");
	fclose(fp);
	fflush(stdin);
	getchar();
	getchar();
}


void About_us(void)						//关于我们
{
	int i;
	Qingping();
	for (i = 0; i < MAXCOL; i++)								//边框
		printf("*");
	printf("\n\n");
	printf("关于我们:\n");
	printf("\t该项目目的在于休闲时候供用户娱乐使用,用户可通过本游戏锻炼思维能力,益于健智.");
	printf("\n\n\n\n\t本游戏由软酷网www.ruanku.com支持，该游戏版本为V1.0.\n");
	for (i = 0; i < MAXCOL; i++)								//边框
		printf("*");
	printf("返回主页面请按回车键.");
	getchar();
	getchar();
}



void End(void)						//正常退出显示界面
{
	int i;
	Qingping();
	for (i = 0; i < MAXCOL; i++)								//边框
		printf("*");
	printf("\n\n");
	printf("\n\n\t感谢你的使用,欢迎你的再次到来.\n\n\n");
	printf("\t\t若这次使用达不到你预期效果，请及时与我们联系\n");
	for (i = 0; i < MAXCOL; i++)								//边框
		printf("*");
	printf("退出程序请再次按回车键.");
	getchar();
	exit(0);
}


void chessboard(int mode)				//显示棋盘
{
	int row, col, y, status;
	char x;
	Qingping();
	system("color 30");
	for (row = 0; row <= nrow; row++) {							//输出棋盘
		for (col = 0; col <= ncol; col++) {
			if (row == 0 && col == 0)
				printf("┏");
			else if (row == 1 && col > 0 && col < 3)
				printf(" ");
			else if (row == 1 && col > 0 && col <= ncol) {
				x = 'A' + col - 3;
				printf("%2c", x);
			}
			else if (col == 1 && row > 0 && row < nrow) {
				if (row > 0 && row <= 10)
					printf("0");
				y = row - 1;
				printf("%d", y);
			}
			else if (row == 0 && col == ncol)
				printf("┓");
			else if (row == 0)
				printf("━");
			else if (col == 0 && row != 0 && row != nrow)
				printf("┃");
			else if (col == ncol && row != 0 && row != nrow)
				printf("┃");
			else if (col == 0 && row == nrow)
				printf("┗");
			else if (row == nrow && col == ncol)
				printf("┛");
			else if (row == nrow && col != 0 && col != ncol)
				printf("━");
			else {
				status = getStatus(row, col);					//判断下棋情况，按情况输出黑棋白棋
				if (status == status_Blank)
					printf(chess_Blank);
				if (status == status_Black)
					printf(chess_Black);
				if (status == status_White)
					printf(chess_White);
			}


		}
		if (mode == normal || mode == reset) {								//棋盘正常情况
			if (row == 1)
				printf("┃");
			if (row == 2)
				printf("\t先手玩家手执黑子.");
			if (row == 6)
				printf("若要下棋,");
			if (row == 7)
				printf("请输入棋盘上对应的坐标");
			if (row == 8)
				printf("\t例如：");
			if (row == 9)
				printf("\t输入:A00,A1,b1等.");
			if (row == 11)
				printf("   回车键打开菜单栏.");
		}
		if (mode == action) {								//棋盘菜单情况
			if (row == 1) {
				printf("┃");
				printf("菜");
			}
			if (row == 2) {
				printf("单：");
			}
			if (row == 3) {
				printf("栏");
			}
			if (row == 4)
				printf("\t   1.返回主菜单");
			if (row == 6)
				printf("\t   2.返回游戏");
			if (row == 8)
				printf("\t   3.游戏规则");
			if (row == 10)
				printf("\t   4.退出游戏");
			if (row == 12)
				printf("\t   5.悔棋");
		}
		if (mode == winer) {								//棋盘胜利情况
			if (row == 1) {
				printf("┃");
			}
		}
		printf("\n");
	}
	if (mode == normal)
		getchar();
	fflush(stdin);
}


void initStatus()							//初始化键入操作棋局
{
	int i, j;
	nStep = 0;
	wins = 0;
	for (i = 0; i < nrow; i++) {
		for (j = 0; j < ncol; j++) {
			location[i][j] = status_Blank;					//初始化棋盘位置情况
		}
	}
	if (nStep == 0) {										//保存录像，若刚开始则初始化
		fp = fopen("video.txt", "w");
		fclose(fp);
	}
	fp = fopen("load.txt", "w");							//保存最后棋局情况
	fseek(fp, 0, SEEK_SET);
	for (i = 0; i < nrow; i++) {
		for (j = 0; j < ncol; j++) {
			fprintf(fp, "%3d", location[i][j]);
		}
	}
	fclose(fp);
	save();													//更新棋局最后情况
	savemedia();											//更新录像情况
}

int getStatus(int row, int col)					//获取数据
{
	return location[row][col];					//返回该点情况，是否存在棋子.
}



void setStatus(int *col, int *row, int status)				//数组存储棋子位置
{
	location[*row][*col] = status;					//数组存储棋子位置
	save();											//更新棋局最后情况
	savemedia();									//更新录像情况
	rtimes = 1;										//重置情况+1
	c_flag = 1;										//判断玩家已经下棋
}




int Judge(int col, int row, int color)						//胜负判断
{
	int x = 1, y = 1, y_x = 1, x_y = 1;
	int i;
	for (i = 1; i < 5; i++) {
		if (location[row][col - i] == color)				//横向判断胜负
			if (row > 0 && col - i > 0)
				x++;
			else
				break;
	}
	for (i = 1; i < 5; i++) {
		if (location[row][col + i] == color)
			if (col + i < 17)
				x++;
			else
				break;
	}
	if (x >= 5)
		return color;
	for (i = 1; i < 5; i++) {
		if (location[row - i][col] == color)				//竖向判断胜负
			if (row - i > 0)
				y++;
			else
				break;
	}
	for (i = 1; i < 5; i++) {
		if (location[row + i][col] == color)
			if (row + i < 17)
				y++;
			else
				break;
	}
	if (y >= 5)
		return color;
	for (i = 1; i < 5; i++) {
		if (location[row + i][col - i] == color)			//东北方向判断胜负
			if (row + i < 17 && col - i > 0)
				x_y++;
			else
				break;
	}
	for (i = 1; i < 5; i++) {
		if (location[row - i][col + i] == color)
			if (row - i > 0 && col + i < 17)
				x_y++;
			else
				break;
	}
	if (x_y >= 5)
		return color;
	for (i = 1; i < 5; i++) {
		if (location[row - i][col - i] == color)			//西北方向判断胜负
			if (row - i > 0 && col - i > 0)
				y_x++;
			else
				break;
	}
	for (i = 1; i < 5; i++) {
		if (location[row + i][col + i] == color)
			if (row + i < 17 && col + i < 17)
				y_x++;
			else
				break;
	}
	if (y_x >= 5)
		return color;
	return -1;
}




void choiceagain(int row, int col)								//游戏中菜单
{
	int choice;
	while (1) {												//循环输入，直到玩家选择退出
		fflush(stdin);
		printf("请输入你的选择,并按回车确定你的选择:");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:
			system("color 07");
			picture(ptimes % 3);
			Menu();							//菜单			
			break;
		case 2:
			Game_start();						//游戏重载
			break;
		case 3:
			system("color 07");
			Rule();							//游戏规则
			Menu();							//游戏菜单
			break;
		case 4:
			system("color 07");
			End();							//结束游戏
			break;
		case 5:
			Reset(row, col);
			break;
		default:
			printf("输入错误,请输入菜单上对应的整数.\n");
			getchar();
			break;
		}
	}
}




void Inputpoint(int *pcol, int *prow, int Color)					//下棋并判断游戏过程中玩家选择
{
	char readLocation[8];								//获得用户输入的坐标
	int status = status_Blank, input;						//初始化数据
															//根据执子方，提示用户输入坐标
	if (Color == status_Black)
		printf("黑子下,请输入坐标编号:");
	if (Color == status_White)
		printf("白子下,请输入坐标编号:");
	fflush(stdin);									//清除缓冲区内容
	input = getchar();								//获取用户输入
	if (input == 10) {								//回车弹出菜单
		chessboard(action);							//游戏菜单
		choiceagain(*prow, *pcol);								//菜单选择
	}
	else
		readLocation[0] = input;
	scanf("%s", &readLocation[1]);						//读取输入棋子位置


	fflush(stdin);								//清除缓冲区域
	*pcol = (int)toupper(readLocation[0]) - 'A' + nrow - 15;		//根据用户输入字符若是小写先转换成大写字母再转换成整数(用来判断是否超出范围）
	*prow = atoi(&readLocation[1]) + ncol - 16;				//atoi()函数为系统函数，用来将字符串转换为整数，若字符串无法转换为整数则返回0.
	if (*pcol < 2 || *pcol>16 || *prow < 2 || *prow>16) {
		printf("坐标不存在!\n");
		getchar();
		Inputpoint(pcol, prow, Color);					//重新输入棋子
	}
	status = getStatus(*prow, *pcol);						//获取该点情况，判断是否存在棋子
	if (status != status_Blank) {
		printf("已有棋子!\n");
		getchar();
		Inputpoint(pcol, prow, Color);					//重新输入棋子
	}
}


void Reset(int row, int col)				//重置情况
{
	if (getsmode == 0) {						//键入坐标操作
		if (nStep == 0) {																	//判断开局与否
			printf("游戏刚开始,请先下棋才能执行该功能.连按回车确定继续游戏\n");
			getchar();
			getchar();
			Game_start();
		}
		else if (rtimes == 1) {								//判断悔棋
			location[row][col] = status_Blank;
			nStep--;
			rtimes++;
			Game_start();
		}
		else {												//判断玩家多次悔棋情况
			rtimes++;
			printf("注意游戏平衡,不支持多次悔棋.");
			getchar();
			getchar();
			Game_start();
		}
	}
	if (getsmode == 1) {									//键盘操作
		if (nStep == 0) {
			printf("游戏刚开始,请先下棋才能执行该功能.连按回车确定继续游戏\n");
			getchar();
			getchar();
			Game_start();
		}
		else if (rtimes == 1) {								//与上基本相同，初始化光标元素
			location[nowrow][nowcol] = status_Blank;
			nowrow = oldrow;
			nowcol = oldcol;
			location[oldrow][oldcol] = guangbiao;
			nStep--;
			rtimes++;
			Game_start();
		}
		else {
			rtimes++;
			printf("注意游戏平衡,不支持多次悔棋.");
			getchar();
		}
	}
}



void game_choice(int color)							//游戏胜利后选择提示信息
{
	int choice, choices = 1;
	char choose;
	chessboard(winer);						//棋盘胜利情况
	if (color == status_Black) {					//判断玩家胜负
		printf("\t\t恭喜黑子获胜.\n");
	}
	if (color == status_White) {
		printf("\t\t恭喜白子获胜.\n");
	}
	printf("现在你有以下选择：\n");
	printf("1.新玩家登记   2.玩家信息更新   3.查看排行榜   4.返回主菜单 5.结束游戏\n");

	while (1) {												//循环输入，直到玩家选择退出
		fflush(stdin);								//清除缓冲区域
		printf("请输入你的选择,并按回车确定你的选择:");
		scanf_s("%d", &choice);								//用户输入
		switch (choice) {
		case 1:
			if (choices == 1) {
				insert_list();
				printf("登记成功,请继续按菜单操作.\n");
				choices++;
				fflush(stdin);								//清除缓冲区域
			}
			else {
				getchar();
				printf("你确定要在同一局下同时登记多个玩家吗？Y or N:");
				do {
					scanf("%c", &choose);					//输入选择
					choose = toupper(choose);
					if ((choose != 'Y') && (choose != 'N'))
						printf("输入错误，请输入提示信息对应的字母：");
				} while ((choose != 'Y') && (choose != 'N'));			//判断选择情况
				switch (choose) {
				case 'Y':
					insert_list();
					printf("登记成功,请继续按菜单操作.\n");
					getchar();
					game_choice(color);					//返回游戏
					break;
				case 'N':
					game_choice(color);					//返回游戏		
				}
			}
			choice++;
			break;
		case 2:
			edit_list();					//修改玩家姓名
			system("color 07");
			Menu();						//返回菜单
			break;
		case 3:
			system("color 07");
			Ranking_list();					//排行榜
			Menu();
			break;
		case 4:
			system("color 07");
			picture(ptimes % 3);
			Menu();
			break;
		case 5:
			system("color 07");
			End();						//退出游戏
			break;
		}
	}
}


void chessboard2(int mode)				//显示键盘操作棋盘
{
	int row, col, y, status;
	char x;
	Qingping();
	system("color 30");
	for (row = 0; row <= nrow; row++) {							//输出棋盘
		for (col = 0; col <= ncol; col++) {
			if (row == 0 && col == 0)
				printf("┏");
			else if (row == 1 && col > 0 && col < 3)
				printf(" ");
			else if (row == 1 && col > 0 && col <= ncol) {
				x = 'A' + col - 3;
				printf("%2c", x);
			}
			else if (col == 1 && row > 0 && row < nrow) {
				if (row > 0 && row <= 10)
					printf("0");
				y = row - 1;
				printf("%d", y);
			}
			else if (row == 0 && col == ncol)
				printf("┓");
			else if (row == 0)
				printf("━");
			else if (col == 0 && row != 0 && row != nrow)
				printf("┃");
			else if (col == ncol && row != 0 && row != nrow)
				printf("┃");
			else if (col == 0 && row == nrow)
				printf("┗");
			else if (row == nrow && col == ncol)
				printf("┛");
			else if (row == nrow && col != 0 && col != ncol)
				printf("━");
			else {
				status = getStatus(row, col);					//判断下棋情况，按情况输出黑棋白棋
				if (status == guangbiao)
					printf("□");
				if (status == status_Blank)
					printf(chess_Blank);
				if (status == status_Black)
					printf(chess_Black);
				if (status == status_White)
					printf(chess_White);
			}
		}
		if (mode == normal) {
			if (row == 1)
				printf("┃");
			if (row == 3)
				printf("  操作方法:");
			if (row == 5)
				printf("\t\tW  R");
			if (row == 7) {
				printf("\t     A");
				printf("  S");
				printf("  D");
			}
			if (row == 9)
				printf("\t      空格键");
			if (row == 11)
				printf("	   提示：R键悔棋.");
			if (row == 12)
				printf("	    回车键为菜单.");
			if (row == 15)
				printf("  提示：重载游戏后");
			if (row == 16)
				printf("    按键移动光标即出现.");
		}
		if (mode == action) {								//棋盘菜单情况
			if (row == 1) {
				printf("┃");
				printf("菜");
			}
			if (row == 2) {
				printf("单：");
			}
			if (row == 3) {
				printf("栏");
			}
			if (row == 4)
				printf("	   1.返回主菜单");;
			if (row == 6)
				printf("\t   2.返回游戏");
			if (row == 8)
				printf("\t   3.游戏规则");
			if (row == 10)
				printf("\t   4.退出游戏");
			if (row == 12)
				printf("\t   5.悔棋");
		}
		printf("\n");
	}
}



void initStatus2()						//初始化键盘操作棋盘
{
	int i, j;
	wins = 0;
	for (i = 0; i < nrow; i++) {
		for (j = 0; j < ncol; j++) {
			location[i][j] = status_Blank;					//初始化棋盘位置情况
		}
	}
	location[nowrow][nowcol] = guangbiao;
	if (nStep == 0) {									//保存录像和最后一步位置情况
		fp = fopen("video.txt", "w");
		fclose(fp);
	}
	fp = fopen("load.txt", "w");
	fseek(fp, 0, SEEK_SET);
	for (i = 0; i < nrow; i++) {
		for (j = 0; j < ncol; j++) {
			fprintf(fp, "%3d", location[i][j]);
		}
	}
	savemedia();
	fclose(fp);
}


void control()						//键盘操作方法
{
	char choice;
	choice = getch();
	switch (choice) {
	case 'w':case 'W':				//向上移动
		if (nowrow - 1 < 2) {
			if (location[nowrow][nowcol] == guangbiao)
				location[nowrow][nowcol] = status_Blank;
			nowrow = nrow;
		}
		if (getStatus(nowrow - 1, nowcol) == status_Blank) {
			location[nowrow - 1][nowcol] = guangbiao;
			if (location[nowrow][nowcol] == guangbiao)
				location[nowrow][nowcol] = status_Blank;
		}
		if (getStatus(nowrow - 1, nowcol) != status_Blank) {
			if (location[nowrow][nowcol] == guangbiao)
				location[nowrow][nowcol] = status_Blank;
		}
		nowrow = nowrow - 1;
		break;
	case 'a':case 'A':						//向左移动
		if (nowcol - 1 < 2) {
			if (location[nowrow][nowcol] == guangbiao)
				location[nowrow][nowcol] = status_Blank;
			nowcol = ncol;
		}
		if (getStatus(nowrow, nowcol - 1) == status_Blank) {
			location[nowrow][nowcol - 1] = guangbiao;
			if (location[nowrow][nowcol] == guangbiao)
				location[nowrow][nowcol] = status_Blank;
		}
		if (getStatus(nowrow, nowcol - 1) != status_Blank) {
			if (location[nowrow][nowcol] == guangbiao)
				location[nowrow][nowcol] = status_Blank;
		}

		nowcol = nowcol - 1;
		break;
	case 's':case 'S':							//向下移动
		if (nowrow + 1 >= nrow) {
			if (location[nowrow][nowcol] == guangbiao)
				location[nowrow][nowcol] = status_Blank;
			nowrow = 1;
		}
		if (getStatus(nowrow + 1, nowcol) == status_Blank) {
			location[nowrow + 1][nowcol] = guangbiao;
			if (location[nowrow][nowcol] == guangbiao)
				location[nowrow][nowcol] = status_Blank;
		}
		if (getStatus(nowrow + 1, nowcol) != status_Blank) {
			if (location[nowrow][nowcol] == guangbiao)
				location[nowrow][nowcol] = status_Blank;
		}
		nowrow = nowrow + 1;
		break;
	case 'd':case 'D':							//向右移动
		if (nowcol + 1 >= ncol) {
			if (location[nowrow][nowcol] == guangbiao)
				location[nowrow][nowcol] = status_Blank;
			nowcol = 1;
		}
		if (getStatus(nowrow, nowcol + 1) == status_Blank) {
			location[nowrow][nowcol + 1] = guangbiao;
			if (location[nowrow][nowcol] == guangbiao)
				location[nowrow][nowcol] = status_Blank;
		}
		if (getStatus(nowrow, nowcol + 1) != status_Blank) {
			if (location[nowrow][nowcol] == guangbiao)
				location[nowrow][nowcol] = status_Blank;
		}
		nowcol = nowcol + 1;
		break;
	case ' ':									//确定下棋
		if (getStatus(nowrow, nowcol) == guangbiao) {
			oldrow = nowrow;
			oldcol = nowcol;
			location[nowrow][nowcol] = nStep % 2;
		}
		else {
			printf("已有棋子!");
			break;
		}
		rtimes = 1;
		nStep++;
		c_flag = 1;
		save();
		savemedia();
		break;
	case'\r':										
		chessboard2(action);							//游戏菜单
		choiceagain(oldrow, oldcol);
		break;
	case'r':case'R':								//悔棋
		if (nStep == 0) {
			printf("游戏刚开始,请先下棋才能执行该功能.连按回车确定继续游戏\n");
			getchar();
			getchar();
			Game_start();
		}
		else if (rtimes == 1) {
			location[nowrow][nowcol] = status_Blank;
			nowrow = oldrow;
			nowcol = oldcol;
			location[oldrow][oldcol] = guangbiao;
			nStep--;
			rtimes++;
			Game_start();
		}
		else {
			rtimes++;
			printf("注意游戏平衡,不支持多次悔棋.");
			getchar();
		}
		break;
	default:
		printf("输入错误.");
		break;
	}
}




void Game_start(void)								//开始游戏
{
	if (getsmode == 0 && c_choice == 0) {
		int s_row = -1, s_col = -1, win;								//存放棋子位置行列数
		if ((fp = fopen("score.txt", "r")) != NULL) {
			fscanf(fp, "%3d%3d", &s_row, &s_col);
		}
		else {
			fp = fopen("score.txt", "w");
			fprintf(fp, "%3d%3d", s_row, s_col);
		}
		if (rtimes < 3) {
			chessboard(normal);									//输出棋盘
		}
		else
			chessboard(reset);
		do
		{
			Inputpoint(&s_col, &s_row, nStep % 2);								//获取用户下子点
			setStatus(&s_col, &s_row, nStep % 2);								//存储下棋情况.
			chessboard(normal);														//获取下棋情况，更新棋盘
			win = Judge(s_col, s_row, nStep % 2);							//胜负判断
			nStep++;
			if (nStep >= 255) {
				printf("平局.按回车键回到主界面.");
				getchar();
				break;
			}
		} while (win == -1);
		if (win != -1) {
			wins = 1;
			save();
			game_choice((nStep - 1) % 2);							//棋盘胜利后局面
		}
		if (nStep >= 255) {
			wins = 1;
			save();
			Menu();						//返回菜单
		}
	}
	if (getsmode == 1 && c_choice == 0) {
		int win;
		chessboard2(normal);
		do {
			control();
			chessboard2(normal);
			win = Judge(oldcol, oldrow, (nStep - 1) % 2);
			if (nStep >= 255) {
				printf("平局.按回车键回到主界面.");
				getchar();
				break;
			}
		} while (win == -1);
		if (win != -1) {
			wins = 1;
			save();
			game_choice((nStep - 1) % 2);							//棋盘胜利后局面
		}
		if (nStep >= 255) {
			wins = 1;
			save();
			Menu();						//返回菜单
		}
	}
	if (getsmode == 1 && c_choice == 1) {
		int win;
		chessboard2(normal);
		do {
			control();
			chessboard2(normal);
			win = Judge(oldcol, oldrow, (nStep - 1) % 2);
			if (nStep >= 255) {
				printf("平局.按回车键回到菜单界面.");
				getchar();
				break;
			}
			if (win != -1)
				break;
			if (c_flag == 1) {
				computer_judge(oldcol, oldrow);
				chessboard2(normal);
				win = Judge(c_col, c_row, nStep % 2);
				nStep++;
				save();
				savescore();
				savemedia();
				if (nStep >= 255) {
					printf("平局.按回车键回到菜单界面.");
					getchar();
					break;
				}
				c_flag = 0;
			}
		}while (win == -1);
		if (win != -1) {
			wins = 1;
			save();
			game_choice((nStep - 1) % 2);							//棋盘胜利后局面
		}
		if (nStep >= 255) {
			wins = 1;
			save();
			Menu();						//返回菜单
		}
	}
	if (getsmode == 0 && c_choice == 1) {
		int s_row = -1, s_col = -1, win;								//存放棋子位置行列数
		if (rtimes < 3) {
			chessboard(normal);									//输出棋盘
		}
		else
			chessboard(reset);
		do
		{
			Inputpoint(&s_col, &s_row, nStep % 2);								//获取用户下子点
			setStatus(&s_col, &s_row, nStep % 2);								//存储下棋情况.
			chessboard(normal);														//获取下棋情况，更新棋盘
			win = Judge(s_col, s_row, nStep % 2);							//胜负判断
			nStep++;
			if (win != -1)
				break;
			if (c_flag == 1) {
				computer_judge(oldcol, oldrow);
				chessboard2(normal);
				win = Judge(c_col, c_row, nStep % 2);
				nStep++;
				save();
				savescore();
				savemedia();
				if (nStep >= 255) {
					printf("平局.按回车键回到菜单界面.");
					getchar();
					break;
				}
				c_flag = 0;
			}
		} while (win == -1);
		if (win != -1) {
			wins = 1;
			save();
			game_choice((nStep - 1) % 2);							//棋盘胜利后局面
		}
		if (nStep >= 255) {
			wins = 1;
			save();
			Menu();						//返回菜单
		}
	}
}




void savescore(void)				//电脑判断棋盘空位置得分
{
	int i, j;
	fp = fopen("score.txt", "w+");
	fseek(fp, 0, SEEK_SET);
	for (i = 0; i < nrow; i++) {
		for (j = 0; j < ncol; j++) {
			fprintf(fp, "%10d", score[i][j]);
		}
	}
	fprintf(fp, "%3d", wins);
	if (getsmode == 0)
		fprintf(fp, "%3d", nStep + 1);
	if (getsmode == 1)
		fprintf(fp, "%3d", nStep + 1);
	fclose(fp);
}



void loadscore(void) {				//重新载入游戏后更新棋盘空位置得分
	int i = 0, j = 0, flen;
	if ((fp = fopen("score.txt", "r")) != NULL) {
	}
	else {
		fp = fopen("score.txt", "w");
	}
	fseek(fp, 0, SEEK_END);
	flen = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	while (ftell(fp) != flen) {
		if ((ftell(fp)) == (flen - 6)) {
			fscanf(fp, "%3d", &wins);
			fscanf(fp, "%3d", &nStep);
			continue;
		}
		fscanf(fp, "%10d", &score[i][j]);
		j++;
	}
	fclose(fp);
	if (wins == 1) {
		if (getsmode == 1) {
			for (i = 0; i < nrow; i++) {
				for (j = 0; j < ncol; j++) {
					score[i][j] = status_Blank;					//初始化棋盘位置情况
				}
			}
			score[nowrow][nowcol] = guangbiao;
			nStep = 0;
		}
		else {
			for (i = 0; i < nrow; i++) {
				for (j = 0; j < ncol; j++) {
					score[i][j] = status_Blank;					//初始化棋盘位置情况
				}
			}
			nStep = 0;
		}
	}
	fp = fopen("score.txt", "w");
	fclose(fp);
}

void computer_judge(int row,int col)				//电脑判断位置下棋
{
	int i, j,num=0,max=0,count=0,flag=0,k,number=0;
	int x = 0, y = 0, y_x = 0, x_y = 0, index1=10, index2=10;
	int f_x = 0, f_y = 0, f_y_x = 0, f_x_y = 0;
	loadscore();
	if (nStep == 0) {													//初始化棋盘得分
		for (i = 0; i < nrow; i++) {
			for (j = 0; j < ncol; j++) {
				score[i][j] = 0;
			}
		}
	}
	for (i = row - 4; i <= row + 4; i++) {									//判断玩家下棋位置情况更新得分，与上基本相同
		for (j = col - 4; j <= col + 4; j++) {
			x = 0; y = 0; y_x = 0; x_y = 0;
			f_x = 0; f_y = 0; f_y_x = 0; f_x_y = 0;
			if (i < 2 || i >= nrow)
				break;
			if (j < 2 || j >= ncol)
				continue;
			if (location[i][j] == status_Blank) {
				x = 0; y = 0; y_x = 0; x_y = 0;
				for (k = 1; k < 5; k++) {
					if (location[i][j - k] == status_Black)
						if (i > 0 && j - k > 0) 
							x++;
					if (location[i][j - k] == status_White)
						if (i > 0 && j - k > 0)
							x--;
				}
				for (k = 1; k < 5; k++) {
					if (location[i][j - k] == status_Black)
						if (i > 0 && j - k > 0)
							f_x++;
						else
							break;
				}
				for (k = 1; k < 5; k++) {
					if (location[i][j + k] == status_Black)
						if (j + k < 17)
							x++;
					if (location[i][j + k] == status_White)
						if (j + k < 17)
							x--;
				}
				for (k = 1; k < 5; k++) {
					if (location[i][j + k] == status_Black)
						if (j + k < 17)
							f_x++;
						else
							break;
				}

				for (k = 1; k < 5; k++) {
					if (location[i - k][j] == status_Black)
						if (i - k > 0)
							y++;
					if (location[i - k][j] == status_White)
						if (i - k > 0)
							y--;
				}
				for (k = 1; k < 5; k++) {
					if (location[i - k][j] == status_Black)
						if (i - k > 0)
							f_y++;
						else
							break;
				}
				for (k = 1; k < 5; k++) {
					if (location[i + k][j] == status_Black)
						if (i + k < 17)
							y++;
					if (location[i + k][j] == status_White)
						if (i + k < 17)
							y--;
				}
				for (k = 1; k < 5; k++) {
					if (location[i + k][j] == status_Black)
						if (i + k < 17)
							f_y++;
						else
							break;
				}
				for (k = 1; k < 5; k++) {
					if (location[i + k][j - k] == status_Black)
						if (i + k < 17 && j - k > 0)
							x_y++;
					if (location[i + k][j - k] == status_White)
						if (i + k < 17 && j - k > 0)
							x_y--;
				}
				for (k = 1; k < 5; k++) {
					if (location[i + k][j - k] == status_Black)
						if (i + k < 17 && j - k > 0)
							f_x_y++;
						else
							break;
				}
				for (k = 1; k < 5; k++) {
					if (location[i - k][j + k] == status_Black)
						if (i - k > 0 && j + k < 17)
							x_y++;
					if (location[i - k][j + k] == status_White)
						if (i - k > 0 && j + k < 17)
							x_y--;
				}
				for (k = 1; k < 5; k++) {
					if (location[i - k][j + k] == status_Black)
						if (i - k > 0 && j + k < 17)
							f_x_y++;
						else
							break;
				}
				for (k = 1; k < 5; k++) {
					if (location[i - k][j - k] == status_Black)
						if (i - k > 0 && j - k > 0)
							y_x++;
					if (location[i - k][j - k] == status_White)
						if (i - k > 0 && j - k > 0)
							y_x--;
				}
				for (k = 1; k < 5; k++) {
					if (location[i - k][j - k] == status_Black)
						if (i - k > 0 && j - k > 0)
							f_y_x++;
						else
							break;
				}
				for (k = 1; k < 5; k++) {
					if (location[i + k][j + k] == status_Black)
						if (i + k < 17 && j + k < 17)
							y_x++;
					if (location[i - k][j - k] == status_White)
						if (i - k > 0 && j - k > 0)
							y_x--;
				}
				for (k = 1; k < 5; k++) {
					if (location[i + k][j + k] == status_Black)
						if (i + k < 17 && j + k < 17)
							f_y_x++;
						else
							break;
				}
				if (x > 2 || y > 2 || x_y > 2 || y_x > 2) {					//相邻相同棋子累计
					if (f_x > 2)
						score[i][j] += 100 * f_x;
					if (y > 2)
						score[i][j] += 100 * f_y;
					if (y_x > 2)
						score[i][j] += 100 * f_y_x;
					if (x_y > 2)
						score[i][j] += 100 * f_x_y;
					continue;
				}
				if (x > 1 || y > 1 || x_y > 1 || y_x > 1) {					//相邻5个存在不同棋子情况累计
					if (x > 1)
						score[i][j] += 40 * x;
					if (y > 1)
						score[i][j] += 40 * y;
					if (y_x > 1)
						score[i][j] += 40 * y_x;
					if (x_y > 1)
						score[i][j] += 40 * x_y;
					continue;
				}														//不属于以上所有情况
				if (i == row - 4 && j > col - 4 && j < col + 4 || i == row + 4 && j > col - 4 && j < col + 4 || j == col - 4 && i >= row - 4 && i <= row + 4 || j == col + 4 && i >= row - 4 && i <= row + 4)
					score[i][j] += 10;
				if (i == row - 3 && j > col - 3 && j < col + 3 || i == row + 3 && j > col - 3 && j < col + 3 || j == col - 3 && i >= row - 3 && i <= row + 3 || j == col + 3 && i >= row - 3 && i <= row + 3)
					score[i][j] += 20;
				if (i == row - 2 && j > col - 2 && j < col + 2 || i == row + 2 && j > col - 2 && j < col + 2 || j == col - 2 && i >= row - 2 && i <= row + 2 || j == col + 2 && i >= row - 2 && i <= row + 2)
					score[i][j] += 30;
				if (i == row - 1 && j > col - 1 && j < col + 1 || i == row + 1 && j > col - 1 && j < col + 1 || j == col - 1 && i >= row - 1 && i <= row + 1 || j == col + 1 && i >= row - 1 && i <= row + 1)
					score[i][j] += 40;
			}
		}
	}
	score[row][col] = location[row][col];
	max = score[index1][index2];
	for (i = 2; i < nrow; i++) {
		for (j = 2; j < ncol; j++) {
			if (score[i][j] > max && location[i][j] != status_Black) {
				index1 = i;
				index2 = j;
				max = score[index1][index2];
			}
		}
	}

	for (i = 2; i < nrow; i++) {
		for (j = 2; j < ncol; j++) {
			if (score[i][j] == max && location[i][j] != status_Black)
				num++;
		}
	}
	number = num;													//若得分位置较多，则由电脑随机判断下棋位置
	if (num > 1) {
		srand((unsigned)time(NULL));
		number = 0 + rand() % num;
	}
	for (i = 2; i < nrow; i++) {
		for (j = 2; j < ncol; j++) {
			if (count == number && location[i][j] != status_Black) {
				location[i][j] = status_White;
				c_row = i;
				c_col = j;
				flag = 1;
				break;
			}
			if (score[i][j] == max && location[i][j] != status_Black) {
				count++;
				if (count == number) {
					location[i][j] = status_White;
					c_row = i;
					c_col = j;
					flag = 1;
					break;
				}
			}
		}
		if (flag == 1)
			break;
	}

	for (i = c_row - 4; i <= c_row + 4; i++) {								//判断电脑下棋位置情况更新得分，与上基本相同
		for (j = c_col - 4; j <= c_col + 4; j++) {
			x = 0; y = 0; y_x = 0; x_y = 0;
			f_x = 0; f_y = 0; f_y_x = 0; f_x_y = 0;
			if (i < 2 || i >= nrow)
				break;
			if (j < 2 || j >= ncol)
				continue;
			if (location[i][j] == status_Blank) {
				x = 0; y = 0; y_x = 0; x_y = 0;
				for (k = 1; k < 5; k++) {
					if (location[i][j - k] == status_Black)
						if (i > 0 && j - k > 0)
							x++;
					if (location[i][j - k] == status_White)
						if (i > 0 && j - k > 0)
							x--;
				}
				for (k = 1; k < 5; k++) {
					if (location[i][j - k] == status_Black)
						if (i > 0 && j - k > 0)
							f_x++;
						else
							break;
				}
				for (k = 1; k < 5; k++) {
					if (location[i][j + k] == status_Black)
						if (j + k < 17)
							x++;
					if (location[i][j + k] == status_White)
						if (j + k < 17)
							x--;
				}
				for (k = 1; k < 5; k++) {
					if (location[i][j + k] == status_Black)
						if (j + k < 17)
							f_x++;
						else
							break;
				}

				for (k = 1; k < 5; k++) {
					if (location[i - k][j] == status_Black)
						if (i - k > 0)
							y++;
					if (location[i - k][j] == status_White)
						if (i - k > 0)
							y--;
				}
				for (k = 1; k < 5; k++) {
					if (location[i - k][j] == status_Black)
						if (i - k > 0)
							f_y++;
						else
							break;
				}
				for (k = 1; k < 5; k++) {
					if (location[i + k][j] == status_Black)
						if (i + k < 17)
							y++;
					if (location[i + k][j] == status_White)
						if (i + k < 17)
							y--;
				}
				for (k = 1; k < 5; k++) {
					if (location[i + k][j] == status_Black)
						if (i + k < 17)
							f_y++;
						else
							break;
				}
				for (k = 1; k < 5; k++) {
					if (location[i + k][j - k] == status_Black)
						if (i + k < 17 && j - k > 0)
							x_y++;
					if (location[i + k][j - k] == status_White)
						if (i + k < 17 && j - k > 0)
							x_y--;
				}
				for (k = 1; k < 5; k++) {
					if (location[i + k][j - k] == status_Black)
						if (i + k < 17 && j - k > 0)
							f_x_y++;
						else
							break;
				}
				for (k = 1; k < 5; k++) {
					if (location[i - k][j + k] == status_Black)
						if (i - k > 0 && j + k < 17)
							x_y++;
					if (location[i - k][j + k] == status_White)
						if (i - k > 0 && j + k < 17)
							x_y--;
				}
				for (k = 1; k < 5; k++) {
					if (location[i - k][j + k] == status_Black)
						if (i - k > 0 && j + k < 17)
							f_x_y++;
						else
							break;
				}
				for (k = 1; k < 5; k++) {
					if (location[i - k][j - k] == status_Black)
						if (i - k > 0 && j - k > 0)
							y_x++;
					if (location[i - k][j - k] == status_White)
						if (i - k > 0 && j - k > 0)
							y_x--;
				}
				for (k = 1; k < 5; k++) {
					if (location[i - k][j - k] == status_Black)
						if (i - k > 0 && j - k > 0)
							f_y_x++;
						else
							break;
				}
				for (k = 1; k < 5; k++) {
					if (location[i + k][j + k] == status_Black)
						if (i + k < 17 && j + k < 17)
							y_x++;
					if (location[i - k][j - k] == status_White)
						if (i - k > 0 && j - k > 0)
							y_x--;
				}
				for (k = 1; k < 5; k++) {
					if (location[i + k][j + k] == status_Black)
						if (i + k < 17 && j + k < 17)
							f_y_x++;
						else
							break;
				}
				if (x > 2 || y > 2 || x_y > 2 || y_x > 2) {
					if (f_x > 2)
						score[i][j] += 80 * f_x;
					if (y > 2)
						score[i][j] += 80 * f_y;
					if (y_x > 2)
						score[i][j] += 80 * f_y_x;
					if (x_y > 2)
						score[i][j] += 80 * f_x_y;
					continue;
				}
				if (x > 1 || y > 1 || x_y > 1 || y_x > 1) {
					if (x > 1)
						score[i][j] += 30 * x;
					if (y > 1)
						score[i][j] += 30 * y;
					if (y_x > 1)
						score[i][j] += 30 * y_x;
					if (x_y > 1)
						score[i][j] += 30 * x_y;
					continue;
				}
				if (i == c_row - 4 && j > c_col - 4 && j < c_col + 4 || i == c_row + 4 && j > c_col - 4 && j < c_col + 4 || j == c_col - 4 && i >= c_row - 4 && i <= c_row + 4 || j == c_col + 4 && i >= c_row - 4 && i <= c_row + 4)
					score[i][j] += 10;
				if (i == c_row - 3 && j > c_col - 3 && j < c_col + 3 || i == c_row + 3 && j > c_col - 3 && j < c_col + 3 || j == c_col - 3 && i >= c_row - 3 && i <= c_row + 3 || j == c_col + 3 && i >= c_row - 3 && i <= c_row + 3)
					score[i][j] += 20;
				if (i == c_row - 2 && j > c_col - 2 && j < c_col + 2 || i == c_row + 2 && j > c_col - 2 && j < c_col + 2 || j == c_col - 2 && i >= c_row - 2 && i <= c_row + 2 || j == c_col + 2 && i >= c_row - 2 && i <= c_row + 2)
					score[i][j] += 30;
				if (i == c_row - 1 && j > c_col - 1 && j < c_col + 1 || i == c_row + 1 && j > c_col - 1 && j < c_col + 1 || j == c_col - 1 && i >= c_row - 1 && i <= c_row + 1 || j == c_col + 1 && i >= c_row - 1 && i <= c_row + 1)
					score[i][j] += 40;
			}
		}
	}
	score[c_row][c_col] = location[c_row][c_col];
}

