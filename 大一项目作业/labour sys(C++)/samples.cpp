#include"public.h"
using std::cout;


/*	PrintChar("-----------------------", 20, 30, y + 14);
	PrintChar("▏", 4, 30, y + 15);
	PrintChar("岗位：", 6, 32, y + 15);
	PrintChar("▏", 4, 50, y + 15);
	PrintChar("-----------------------", 20, 30, y + 16);
	*/

void ClearScreen(void)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;

	GetConsoleScreenBufferInfo(hOut, &bInfo);

	COORD home = { 0,0 };

	//WORD att = bInfo.wAttributes;

	//unsigned long size = bInfo.dwSize.X * bInfo.dwSize.Y;

	unsigned long size = MAXCOL*MAXROW;
	//FillConsoleOutputAttribute(hOut, att, size, home, NULL);

	//FillConsoleOutputCharacter(hOut, ' ', size, home, NULL);
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
	for (int i = 0; i < MAXROW; i++)
			PrintChar("                                                                                          ",MAXCOL,0, i);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
}


void getFiles(std::string path, std::vector<std::string>& files)
{
	//文件句柄  
	long   hFile = 0;
	//文件信息  
	struct _finddata_t fileinfo;
	std::string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*.txt").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//如果是目录,迭代之  
			//如果不是,加入列表  
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}


void welcome(void)
{
	int i;
	for (i = 0; i < MAXCOL; i++)								//边框
		cout<<"*";
	cout << "\n\n\n\n";
	for (i = 0; i < MAXCOL / 4; i++)								//居中
		cout << " ";
	cout << "欢迎使用本员工工资管理系统.\n\n\n\n\n";

	for (i = 0; i < MAXCOL; i++)
		cout << "*";
}



void boundary(void)
{
	PrintChar("|", 3, MAXCOL - 12, 0);
	PrintChar("| 退出系统", 12, MAXCOL - 12, 1);
	PrintChar("------------", 12, MAXCOL - 12, 2);

	PrintChar("登陆方式：", 12, 5, 3);

	PrintChar("-------------------", 20, 27, 5);
	PrintChar("│ 游客/学生端登陆", 20, 26, 6);
	PrintChar("│", 3, 45, 6);
	PrintChar("-------------------", 20, 27, 7);

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t欢迎使用本员工系统.\n";
	for (int i = 0; i < MAXCOL; i++)
		cout << "*";
}


void exitsys(void)
{
	int i;
	for (i = 0; i < MAXCOL; i++)
		printf("*");
	printf("\n\n");
	printf("\n\n\t感谢使用本系统，若有问题请及时向工作人员反馈...\n\n\n");
	printf("\n\n");
	for (i = 0; i < MAXCOL; i++)
		printf("*");
	getch();
	exit(0);
}

void payrule(void) {
	int i;
	for (i = 0; i < MAXCOL; i++)
		cout << "*";
	cout << "\n\n";
	cout << "\t   A．经理:固定月薪为8000.\n";
	cout << "\t   B．技术员:工作时间×小时工资（100元每小时）.\n";
	cout << "\t   C．销售员:销售额×4%提成.\n";
	cout << "\t   D．销售经理:底薪(5000)+所辖部门销售额总额×0.5.\n";
	cout << "\n\n";
	cout << "\t\t\t\t请尽量正确操作,如发现漏洞请及时与作者联系.\n";
	for (i = 0; i < MAXCOL; i++)
		cout << "*";
	PrintChar("|", 3, MAXCOL - 12, 1);
	PrintChar("| 返回主页", 12, MAXCOL - 12, 2);
	PrintChar("------------", 12, MAXCOL - 12, 3);
}

void delay(int set) {
	time_t start_time, cur_time; // 变量声明 
	time(&start_time);
	do {
		time(&cur_time);
	} while ((cur_time - start_time) < set);
}



//qtime
void background(int y) {

	for(int i=0;i<MAXCOL;i++)
		PrintChar("*", 2, i, y);
	for(int i=0;i<24;i++)
		PrintChar("*", 1, 21 , i);
	PrintChar("-------------------", 15, 2, y+1);
	PrintChar("▏", 4, 2, y+1 + 1);

	PrintChar("月份查询", 10, 4, y + 1 + 1);
	PrintChar(tab, 4, 14, y + 1 + 1);
	PrintChar("▏", 4, 17, y + 1 + 1);
	PrintChar("-------------------", 15, 2, y + 2 + 1);
	PrintChar("-------------------", 15, 2, y + 4 + 1);
	PrintChar("▏", 4, 2, y + 5 + 1);
	PrintChar("部门查询", 10, 4, y + 5 + 1);
	PrintChar(tab, 4, 13, y + 5 + 1);
	PrintChar("▏", 4, 17, y + 5 + 1);
	PrintChar("-------------------", 15, 2, y + 6 + 1);
	PrintChar("-------------------", 15, 2, y + 8 + 1);
	PrintChar("▏", 4, 2, y + 9 + 1);
	PrintChar("统计结果", 10, 4, y + 9 + 1);
	PrintChar(tab, 4, 13, y + 9 + 1);
	PrintChar("▏", 4, 17, y + 9 + 1);
	PrintChar("-------------------", 15, 2, y + 10 + 1);
	PrintChar("-------------------", 15, 2, y + 12 + 1);
	PrintChar("▏", 4, 2, y + 13 + 1);
	PrintChar("服务索引", 10, 4, y + 13 + 1);
	PrintChar(tab, 4, 13, y + 13 + 1);
	PrintChar("▏", 4, 17, y + 13 + 1);
	PrintChar("-------------------", 15, 2, y + 14 + 1);
}

void background2(int y)
{
	PrintChar("工号", 8, 25, y - 1);
	PrintChar(tab, 4, 30, y - 1);
	PrintChar("姓名", 8, 37, y - 1);
	PrintChar(tab, 4, 42, y - 1);
	PrintChar("部门", 8, 49, y - 1);
	PrintChar(tab, 4, 54, y - 1);
	PrintChar("岗位", 8, 61, y - 1); 
	PrintChar(tab, 4, 66, y - 1);
	PrintChar("工资", 8, 73, y - 1);
	PrintChar(tab, 4, 78, y - 1);


	PrintChar("员工查询：", 11, 0, 1);

}

void background22(int y = 2) {
	PrintChar("-------------------", 15, 2, y + 16 + 1);
	PrintChar("▏", 4, 2, y + 17 + 1);
	PrintChar("添加员工", 10, 4, y + 17 + 1);
	PrintChar("╋", 4, 13, y + 17 + 1);
	PrintChar("▏", 4, 17, y + 17 + 1);
	PrintChar("-------------------", 15, 2, y + 18 + 1);
}

void showlist(int page) {
	int y = 2;
	int index = 0;
	background(y);

	if (!worker::people.empty()) {
		for (auto p = worker::people.begin() + page * 3; p != worker::people.end() && index != 9; p++, index++) {
			(*p)->print(y+(index+1)*2);
		}
		showlistup(page);
		showlistdown(page);
	}
}


bool showlistup(int page) {
	int y = 2;
	if (page >= 1) {
		PrintChar("首页", 8, 25, y + 20);
		PrintChar("上一页", 8, 40, y + 20);
		PrintChar("◣", 4, 35, y + 20);
	}
	return page ? 1 : 0;
}


bool showlistdown(int page) {
	int y = 2;
	if (((int)worker::people.size() - (page + 1) * 3) > 0) {
		PrintChar("下一页", 8, 55, y + 20);
		PrintChar(tab, 4, 65, y + 20);
		PrintChar("末页", 8, 75, y + 20);
	}
	return ((int)worker::people.size() - (page + 1) * 3) > 0 ? 1 : 0;
}

void getlist(int dep) {
	for (auto p = worker::people.begin(); p != worker::people.end(); p++) {
		if (worker::dep[dep] == (*p)->getdepartment()) {
			worker::deppeople.push_back((*p));
		}
	}
}


void showlist(int page,const int dep) {
	int y = 2;
	int index = 0;
	background(y);
	getlist(dep);
	if (!worker::people.empty()) {
		if (!worker::deppeople.empty()) {
			for (auto p = worker::deppeople.begin() + page * 3;
				p != worker::deppeople.end() && index != 9; 
				index++, ++p) {
				(*p)->print(y + (index + 1) * 2);
			}
			showlistup(page, dep);
			showlistdown(page, dep);
		}
	}
}

bool showlistup(int page, const int dep) {
	int y = 2;
	if (page >= 1) {
		PrintChar("首页", 8, 25, y + 20);
		PrintChar("上一页", 8, 40, y + 20);
		PrintChar("◣", 4, 35, y + 20);
	}
	return page ? 1 : 0;
}


bool showlistdown(int page, const int dep) {
	int y = 2;
	if (((int)worker::deppeople.size() - (page + 1) * 3) > 0) {
		PrintChar("下一页", 8, 55, y + 20);
		PrintChar(tab, 4, 65, y + 20);
		PrintChar("末页", 8, 75, y + 20);
	}
	return ((int)worker::deppeople.size() - (page + 1) * 3) > 0 ? 1 : 0;
}



//qhelp
void background3(int y)
{
	for (int i = 25; i<76; i++)
		PrintChar("-", 2, i, 4);
	for (int c = 5; c<y + 21; c++)
		PrintChar("▏", 2, 25, c);
	for (int c = 5; c<y + 21; c++)
		PrintChar("▏", 2, 76, c);
	for (int i = 25; i<76; i++)
		PrintChar("-", 2, i, y + 21);
	PrintChar("-------------------", 15, 42, y+4);
	PrintChar("▏", 4, 42, y+5);
	PrintChar("导入数据", 10, 44, y + 5);
	PrintChar(tab, 4, 53, y + 5);
	PrintChar("▏", 4, 57, y + 5);
	PrintChar("-------------------", 15, 42, y + 6);

	PrintChar("-------------------", 15, 42, y + 8);
	PrintChar("▏", 4, 42, y + 9);
	PrintChar("月份管理", 10, 44, y + 9);
	PrintChar(tab, 4, 53, y + 9);
	PrintChar("▏", 4, 57, y + 9);
	PrintChar("-------------------", 15, 42, y + 10);

	PrintChar("-------------------", 15, 42, y + 12);
	PrintChar("▏", 4, 42, y + 13);
	PrintChar("部门管理", 10, 44, y + 13);
	PrintChar(tab, 4, 53, y + 13);
	PrintChar("▏", 4, 57, y + 13);
	PrintChar("-------------------", 15, 42, y + 14);

	PrintChar("-------------------", 15, 42, y + 16);
	PrintChar("▏", 4, 42, y + 17);
	PrintChar("退出系统", 10, 44, y + 17);
	PrintChar(tab, 4, 53, y + 17);
	PrintChar("▏", 4, 57, y + 17);
	PrintChar("-------------------", 15, 42, y + 18);


}


//qhelp 月份管理
void background5(int y)
{
	for (int i = 25; i<76; i++)
		PrintChar("-", 2, i, 4);
	for (int c = 5; c<y + 21; c++)
		PrintChar("▏", 2, 25, c);
	for (int c = 5; c<y + 21; c++)
		PrintChar("▏", 2, 76, c);
	for (int i = 25; i<76; i++)
		PrintChar("-", 2, i, y + 21);


	PrintChar("-------------------", 15, 42, y + 8);
	PrintChar("▏", 4, 42, y + 9);
	PrintChar("增加月份", 10, 44, y + 9);
	PrintChar(tab, 4, 53, y + 9);
	PrintChar("▏", 4, 57, y + 9);
	PrintChar("-------------------", 15, 42, y + 10);

	PrintChar("-------------------", 15, 42, y + 12);
	PrintChar("▏", 4, 42, y + 13);
	PrintChar("删除月份", 10, 44, y + 13);
	PrintChar(tab, 4, 53, y + 13);
	PrintChar("▏", 4, 57, y + 13);
	PrintChar("-------------------", 15, 42, y + 14);


}

//qhelp 部门管理
void background6(int y)
{
	for (int i = 25; i<76; i++)
		PrintChar("-", 2, i, 4);
	for (int c = 5; c<y + 21; c++)
		PrintChar("▏", 2, 25, c);
	for (int c = 5; c<y + 21; c++)
		PrintChar("▏", 2, 76, c);
	for (int i = 25; i<76; i++)
		PrintChar("-", 2, i, y + 21);


	PrintChar("-------------------", 15, 42, y + 8);
	PrintChar("▏", 4, 42, y + 9);
	PrintChar("增加部门", 10, 44, y + 9);
	PrintChar(tab, 4, 53, y + 9);
	PrintChar("▏", 4, 57, y + 9);
	PrintChar("-------------------", 15, 42, y + 10);

	PrintChar("-------------------", 15, 42, y + 12);
	PrintChar("▏", 4, 42, y + 13);
	PrintChar("删除部门", 10, 44, y + 13);
	PrintChar(tab, 4, 53, y + 13);
	PrintChar("▏", 4, 57, y + 13);
	PrintChar("-------------------", 15, 42, y + 14);


}

//qhelp 导入信息
void background4(int y)
{
	for (int i = 25; i<76; i++)
		PrintChar("-", 2, i, 4);
	for (int c = 5; c<y + 21; c++)
		PrintChar("▏", 2, 25, c);
	for (int c = 5; c<y + 21; c++)
		PrintChar("▏", 2, 76, c);
	for (int i = 25; i<76; i++)
		PrintChar("-", 2, i, y + 21);


	PrintChar("-------------------", 15, 42, y + 8);
	PrintChar("▏", 4, 42, y + 9);
	PrintChar("逐个输入", 10, 44, y + 9);
	PrintChar(tab, 4, 53, y + 9);
	PrintChar("▏", 4, 57, y + 9);
	PrintChar("-------------------", 15, 42, y + 10);

	PrintChar("-------------------", 15, 42, y + 12);
	PrintChar("▏", 4, 42, y + 13);
	PrintChar("批量输入", 10, 44, y + 13);
	PrintChar(tab, 4, 53, y + 13);
	PrintChar("▏", 4, 57, y + 13);
	PrintChar("-------------------", 15, 42, y + 14);


	PrintChar("-------------------", 10, 63, y + 18);
	PrintChar("▏", 4, 63, y + 19);
	PrintChar("返回", 8, 65, y + 19);
	PrintChar(tab, 4, 70, y + 19);
	PrintChar("▏", 3, 73, y + 19);
	PrintChar("-------------------", 10, 63, y + 20);
}




void background7(int y)
{
	for (int i = 25; i<76; i++)
		PrintChar("-", 2, i, 4);
	for (int c = 5; c<y + 21; c++)
		PrintChar("▏", 2, 25, c);
	for (int c = 5; c<y + 21; c++)
		PrintChar("▏", 2, 76, c);
	for (int i = 25; i<76; i++)
		PrintChar("-", 2, i, y + 21);

	PrintChar("个人基本信息表", 20, 42, y + 3);
	PrintChar("-----------------------", 20, 30, y + 5);
	PrintChar("▏", 4, 30, y + 6);
	PrintChar("姓名：", 6, 32, y + 6);
	PrintChar("▏", 4, 50, y + 6);
	PrintChar("-----------------------", 20, 30, y + 7);

	PrintChar("-----------------------", 20, 30, y + 8);
	PrintChar("▏", 4, 30, y + 9);
	PrintChar("性别：", 6, 32, y + 9);
	PrintChar("▏", 4, 50, y + 9);
	PrintChar("-----------------------", 20, 30, y + 10);

	PrintChar("-----------------------", 20, 30, y + 11);
	PrintChar("▏", 4, 30, y + 12);
	PrintChar("部门：", 6, 32, y + 12);
	PrintChar("▏", 4, 50, y + 12);
	PrintChar("-----------------------", 20, 30, y + 13);

	PrintChar("-----------------------", 20, 30, y + 14);
	PrintChar("▏", 4, 30, y + 15);
	PrintChar("岗位：", 6, 32, y + 15);
	PrintChar("▏", 4, 50, y + 15);
	PrintChar("-----------------------", 20, 30, y + 16);



	PrintChar("-----------------------", 20, 53, y + 5);
	PrintChar("▏", 4, 53, y + 6);
	PrintChar("部门id：", sizeof("部门id："), 55, y + 6);
	PrintChar("▏", 2, 73, y + 6);
	PrintChar("-----------------------", 20, 53, y + 7);

	PrintChar("-----------------------", 20, 53, y + 8);
	PrintChar("▏", 4, 53, y + 9);
	PrintChar("生日：", 6, 55, y + 9);
	PrintChar("▏", 2, 73, y + 9);
	PrintChar("-----------------------", 20, 53, y + 10);

	PrintChar("-----------------------", 20, 53, y + 11);
	PrintChar("▏", 4, 53, y + 12);
	PrintChar("工作时长：", 10, 55, y + 12);
	PrintChar("▏", 2, 73, y + 12);
	PrintChar("-----------------------", 20, 53, y + 13);

	PrintChar("-----------------------", 20, 53, y + 14);
	PrintChar("▏", 4, 53, y + 15);
	PrintChar("固定薪资：", 10, 55, y + 15);
	PrintChar("▏", 2, 73, y + 15);
	PrintChar("-----------------------", 20, 53, y + 16);



	PrintChar("-------------------", 10, 63, y + 18);
	PrintChar("▏", 4, 63, y + 19);
	PrintChar("返回", 8, 65, y + 19);
	PrintChar(tab, 4, 70, y + 19);
	PrintChar("▏", 3, 73, y + 19);
	PrintChar("-------------------", 10, 63, y + 20);
}

//个人基类信息表。连同7使用
void background8(int y)
{
	for (int i = 25; i<76; i++)
		PrintChar("-", 2, i, 4);
	for (int c = 5; c<y + 21; c++)
		PrintChar("▏", 2, 25, c);
	for (int c = 5; c<y + 21; c++)
		PrintChar("▏", 2, 76, c);
	for (int i = 25; i<76; i++)
		PrintChar("-", 2, i, y+21);

	PrintChar("个人基本信息表", 20, 42, y + 3);
	PrintChar("-----------------------", 20, 30, y + 5);
	PrintChar("▏", 4, 30, y + 6);
	PrintChar("销售额：", 8, 32, y + 6);
	PrintChar("▏", 4, 50, y + 6);
	PrintChar("-----------------------", 20, 30, y + 7);

	PrintChar("-----------------------", 20, 30, y + 8);
	PrintChar("▏", 4, 30, y + 9);
	PrintChar("实得月薪：", 10, 32, y + 9);
	PrintChar("▏", 4, 50, y + 9);
	PrintChar("-----------------------", 20, 30, y + 10);



	PrintChar("-------------------", 10, 63, y + 18);
	PrintChar("▏", 4, 63, y + 19);
	PrintChar("返回", 8, 65, y + 19);
	PrintChar(tab, 4, 70, y + 19);
	PrintChar("▏", 3, 73, y + 19);
	PrintChar("-------------------", 10, 63, y + 20);
}

void sss(int page) {
	int y = 2;
	if (page == 2) {
		PrintChar("上一页", 8, 45, y + 19);
	}
	if (page == 1) {
		PrintChar("下一页", 8, 52, y + 19);
	}
}


//右键提示
void background9(void)		//右键使用
{
	PrintChar(" 删除   ", 10, 30, 1);

	PrintChar(" 修改   ", 10, 40,1);

	PrintChar(" 取消   ", 10, 50, 1);

	PrintChar(" 返回   ", 10, 60, 1);
}


//添加员工
void background10(int y)
{
	for (int i = 25; i<76; i++)
		PrintChar("-", 2, i, 4);
	for (int c = 5; c<y + 21; c++)
		PrintChar("▏", 2, 25, c);
	for (int c = 5; c<y + 21; c++)
		PrintChar("▏", 2, 76, c);
	for (int i = 25; i<76; i++)
		PrintChar("-", 2, i, y + 21);

	PrintChar("个人基本信息表", 15, 42, y + 3);
	PrintChar("-----------------------", 20, 30, y + 5);
	PrintChar("▏", 4, 30, y + 6);
	PrintChar("姓名：", 6, 32, y + 6);
	PrintChar("▏", 4, 50, y + 6);
	PrintChar("-----------------------", 20, 30, y + 7);

	PrintChar("-----------------------", 20, 30, y + 8);
	PrintChar("▏", 4, 30, y + 9);
	PrintChar("性别：", 6, 32, y + 9);
	PrintChar("▏", 4, 50, y + 9);
	PrintChar("-----------------------", 20, 30, y + 10);
	/*
	PrintChar("-----------------------", 20, 30, y + 11);
	PrintChar("▏", 4, 30, y + 12);
	PrintChar("部门：", 6, 32, y + 12);
	PrintChar("▏", 4, 50, y + 12);
	PrintChar("-----------------------", 20, 30, y + 13);
	*/
	PrintChar("-----------------------", 20, 30, y + 11);
	PrintChar("▏", 4, 30, y + 12);
	PrintChar("岗位：", 6, 32, y + 12);
	PrintChar("▏", 4, 50, y + 12);
	PrintChar("-----------------------", 20, 30, y + 13);



	PrintChar("-----------------------", 20, 53, y + 5);
	PrintChar("▏", 4, 53, y + 6);
	PrintChar("生日：", 6, 55, y + 6);
	PrintChar("▏", 2, 73, y + 6);
	PrintChar("-----------------------", 20, 53, y + 7);



	PrintChar("-------------------", 10, 30, y + 18);
	PrintChar("▏", 4, 30, y + 19);
	PrintChar("确认", 8, 32, y + 19);
	PrintChar(tab, 4, 37, y + 19);
	PrintChar("▏", 3, 40, y + 19);
	PrintChar("-------------------", 10, 30, y + 20);


	PrintChar("-------------------", 10, 63, y + 18);
	PrintChar("▏", 4, 63, y + 19);
	PrintChar("返回", 8, 65, y + 19);
	PrintChar(tab, 4, 70, y + 19);
	PrintChar("▏", 3, 73, y + 19);
	PrintChar("-------------------", 10, 63, y + 20);
}


//温馨提示
void background11(int y) {
	PrintChar("温馨提示:岗位分别有销售员,销售经理,经理和技术员.", sizeof("温馨提示:岗位分别有销售员,销售经理,经理和技术员."),25,y-1);
}		


//新增部门
void background12(int y) {	
	background(2);
	PrintChar("新增部门名称:", sizeof("新增部门名称:"), 32, y + 10);
	PrintChar("-------------------", 10, 30, y + 18);
	PrintChar("▏", 4, 30, y + 19);
	PrintChar("确认", 8, 32, y + 19);
	PrintChar(tab, 4, 37, y + 19);
	PrintChar("▏", 3, 40, y + 19);
	PrintChar("-------------------", 10, 30, y + 20);


	PrintChar("-------------------", 10, 63, y + 18);
	PrintChar("▏", 4, 63, y + 19);
	PrintChar("返回", 8, 65, y + 19);
	PrintChar(tab, 4, 70, y + 19);
	PrintChar("▏", 3, 73, y + 19);
	PrintChar("-------------------", 10, 63, y + 20);

	PrintChar("部门名称示例:XX部", sizeof("部门名称示例:XX部"), 40, y + 14);
}		

//新增月份
void background13(int y) {
	background(2);
	PrintChar("新增月份名称:", sizeof("新增月份名称:"), 32, y + 10);
	PrintChar("-------------------", 10, 30, y + 18);
	PrintChar("▏", 4, 30, y + 19);
	PrintChar("确认", 8, 32, y + 19);
	PrintChar(tab, 4, 37, y + 19);
	PrintChar("▏", 3, 40, y + 19);
	PrintChar("-------------------", 10, 30, y + 20);


	PrintChar("-------------------", 10, 63, y + 18);
	PrintChar("▏", 4, 63, y + 19);
	PrintChar("返回", 8, 65, y + 19);
	PrintChar(tab, 4, 70, y + 19);
	PrintChar("▏", 3, 73, y + 19);
	PrintChar("-------------------", 10, 63, y + 20);
	PrintChar("部门月份示例:201706", sizeof("部门名称示例:201706"), 40, y + 14);
}


void qtime(int page)
{
	int y = 2;
	int index = 0;
	background(y);

	PrintChar("选择查询月份.", sizeof("选择查询月份."), 25, y - 1);

	if (!worker::data.empty()) {
		for (auto p = worker::data.begin() + page * 3; p != worker::data.end() && index != 3; p++, index++) {
			PrintChar("-------------------", 15, 43, (y + 2 + index * 6));
			PrintChar("▏", 4, 43, (y + 3 + index * 6));
			PrintChar(const_cast<char*>((*p).c_str()), (*p).size(), 47, (y + 3 + index * 6));
			PrintChar(tab, 4, 55, (y + 3 + index * 6));
			PrintChar("▏", 4, 58, (y + 3 + index * 6));
			PrintChar("-------------------", 15, 43, (y + 4 + index * 6));
		}
		qdataup(page);
		qdatadown(page);
	}
}


bool qdataup(int page) {
	int y = 2;
	if (page >= 1) {
		PrintChar("上一页", 8, 40, y + 20);
		PrintChar("◣", 4, 35, y + 20);
	}
	return page ? 1 : 0;
}

bool qdatadown(int page) {
	int y = 2;
	if (((int)worker::data.size() - (page + 1) * 3) > 0) {
		PrintChar("下一页", 8, 55, y + 20);
		PrintChar(tab, 4, 65, y + 20);
	}
	return ((int)worker::data.size() - (page + 1) * 3) > 0 ? 1 : 0;
}


void qdepartment(int page)
{
	int y = 2;
	int index = 0;
	background(y);
	PrintChar("选择查询部门.", sizeof("选择查询部门."), 25, y - 1);
	if (!worker::dep.empty()) {
		for (auto p = worker::dep.begin() + page * 3; p != worker::dep.end() && index != 3; p++, index++) {
			PrintChar("-------------------", 15, 43, (y + 2+index*6));
			PrintChar("▏", 4, 43, (y + 3 + index * 6));
			PrintChar(const_cast<char*>((*p).c_str()), (*p).size(), 47, (y +3 + index * 6));
			PrintChar(tab, 4, 55, (y + 3 + index * 6));
			PrintChar("▏", 4, 58, (y + 3 + index * 6));
			PrintChar("-------------------", 15, 43,( y +4 + index * 6));
		}
		qdepartmentup(page);
		qdepartmentdown(page);
	}
}

bool qdepartmentup(int page) {
	int y = 2;
	if (page >= 1) {
		PrintChar("上一页", 8, 40, y + 20);
		PrintChar("◣", 4, 35, y + 20);
	}
	return page ? 1 : 0;
}

bool qdepartmentdown(int page) {
	int y = 2;
	if (((int)worker::dep.size() - (page+1) * 3) > 0) {
		PrintChar("下一页", 8, 55, y + 20);
		PrintChar(tab, 4, 65, y + 20);
	}
	return ((int)worker::dep.size() - (page + 1) * 3) > 0 ? 1 : 0;
}

bool makedepartmentsure(int f) {
	int y = 4;
	if (f == 1) {
		PrintChar("-------------------", 10, 23, y + 18);
		PrintChar("▏", 4, 23, y + 19);
		PrintChar("确认", 8, 25, y + 19);
		PrintChar(tab, 4, 30, y + 19);
		PrintChar("▏", 3, 33, y + 19);
		PrintChar("-------------------", 10, 23, y + 20);
		PrintChar("-------------------", 10, 68, y + 18);
		PrintChar("▏", 4, 68, y + 19);
		PrintChar("取消", 8, 70, y + 19);
		PrintChar(tab, 4, 75, y + 19);
		PrintChar("▏", 3, 78, y + 19);
		PrintChar("-------------------", 10, 68, y + 20);
	}
	return f;
}

bool makedatasure(int f) {
	int y = 4;
	if (f == 1) {
		PrintChar("-------------------", 10, 23, y + 18);
		PrintChar("▏", 4, 23, y + 19);
		PrintChar("确认", 8, 25, y + 19);
		PrintChar(tab, 4, 30, y + 19);
		PrintChar("▏", 3, 33, y + 19);
		PrintChar("-------------------", 10, 23, y + 20);
		PrintChar("-------------------", 10, 68, y + 18);
		PrintChar("▏", 4, 68, y + 19);
		PrintChar("取消", 8, 70, y + 19);
		PrintChar(tab, 4, 75, y + 19);
		PrintChar("▏", 3, 78, y + 19);
		PrintChar("-------------------", 10, 68, y + 20);
	}
	return f;
}

void qpos(void)
{
	int y = 2;
	background(y);
	PrintChar("-------------------", 15, 43, y + 2);
	PrintChar("▏", 4, 43, y + 3);
	PrintChar("经理", 7, 48, y + 3);
	PrintChar(tab, 4, 55, y + 3);
	PrintChar("▏", 4, 58, y + 3);
	PrintChar("-------------------", 15, 43, y + 4);


	PrintChar("-------------------", 15, 43, y + 7);
	PrintChar("▏", 4, 43, y + 8);
	PrintChar("销售员", 7, 47, y + 8);
	PrintChar(tab, 4, 55, y + 8);
	PrintChar("▏", 4, 58, y + 8);
	PrintChar("-------------------", 15, 43, y + 9);

	PrintChar("-------------------", 15, 43, y + 12);
	PrintChar("▏", 4, 43, y + 13);
	PrintChar("技术员", 7, 47, y + 13);
	PrintChar(tab, 4, 55, y + 13);
	PrintChar("▏", 4, 58, y + 13);
	PrintChar("-------------------", 15, 43, y + 14);

	PrintChar("-------------------", 15, 43, y + 17);
	PrintChar("▏", 4, 43, y + 18);
	PrintChar("销售经理", 10, 46, y + 18);
	PrintChar(tab, 4, 55, y + 18);
	PrintChar("▏", 4, 58, y + 18);
	PrintChar("-------------------", 15, 43, y + 19);
}

void qcount(void)
{
	int y = 2;
	background(y);


	PrintChar("----------------------", 18, 41, y + 7);
	PrintChar("▏", 4, 41, y + 8);
	PrintChar("部门工资水平", 12, 43, y + 8);
	PrintChar(tab, 4, 55, y + 8);
	PrintChar("▏", 4, 59, y + 8);
	PrintChar("----------------------", 18, 41, y + 9);

	PrintChar("----------------------", 18, 41, y + 12);
	PrintChar("▏", 4, 41, y + 13);
	PrintChar("本月工资水平", 12, 43, y + 13);
	PrintChar(tab, 4, 55, y + 13);
	PrintChar("▏", 4, 59, y + 13);
	PrintChar("----------------------", 18, 41, y + 14);


}


void qhelp(void) {
	background(2);
	background3(2);
}

void qtimetrue(int page) {
	int y = 2;
	int index = 0;
	std::string year, month;
	if (!worker::data.empty()) {
		for (auto p = worker::data[0].c_str(); *p != '\0'; p++, index++)
			if (index < 4)
				year += *p;
			else
				month += *p;
	}
	if(!year.empty())
	PrintChar(const_cast<char*>((year+"年"+month+"月").c_str()), 12, 4, y+1 + 1);
}


void idsort(int dep) {
	static int idi = 0;
	if (dep == -1) {
		if (idi % 2 == 0)
			std::sort(worker::people.begin(), worker::people.end(), [](std::shared_ptr<worker>a, std::shared_ptr<worker>b) {return a->getid() < b->getid(); });
		if (idi % 2 == 1)
			std::sort(worker::people.begin(), worker::people.end(), [](std::shared_ptr<worker>a, std::shared_ptr<worker>b) {return a->getid() > b->getid(); });
	}
	else {
		if (idi % 2 == 0)
			std::sort(worker::deppeople.begin(), worker::deppeople.end(), [](std::shared_ptr<worker> a, std::shared_ptr<worker>b) {return a->getid() < b->getid(); });
		if (idi % 2 == 1)
			std::sort(worker::deppeople.begin(), worker::deppeople.end(), [](std::shared_ptr<worker>a, std::shared_ptr<worker>b) {return a->getid() > b->getid(); });
	}
	idi++;
}

void namesort(int dep) {
	static int namei = 0;
	if (dep == -1) {
		if (namei % 2 == 0)
			std::sort(worker::people.begin(), worker::people.end(), [](std::shared_ptr<worker>a, std::shared_ptr<worker>b) {return a->getname() < b->getname(); });
		if (namei % 2 == 1)
			std::sort(worker::people.begin(), worker::people.end(), [](std::shared_ptr<worker>a, std::shared_ptr<worker>b) {return a->getname() > b->getname(); });
	}
	else {
		if (namei % 2 == 0)
			std::sort(worker::deppeople.begin(), worker::deppeople.end(), [](std::shared_ptr<worker>a, std::shared_ptr<worker>b) {return a->getname() < b->getname(); });
		if (namei % 2 == 1)
			std::sort(worker::deppeople.begin(), worker::deppeople.end(), [](std::shared_ptr<worker>a, std::shared_ptr<worker>b) {return a->getname() > b->getname(); });
	}
	namei++;
}

void possort(int dep) {
	static int posi = 0;
	if (dep == -1) {
		if (posi % 2 == 0)
			std::sort(worker::people.begin(), worker::people.end(), [](std::shared_ptr<worker>a, std::shared_ptr<worker>b) {return a->getpos() < b->getpos(); });
		if (posi % 2 == 1)
			std::sort(worker::people.begin(), worker::people.end(), [](std::shared_ptr<worker>a, std::shared_ptr<worker>b) {return a->getpos() > b->getpos(); });
	}
	else {
		if (posi % 2 == 0)
			std::sort(worker::deppeople.begin(), worker::deppeople.end(), [](std::shared_ptr<worker>a, std::shared_ptr<worker>b) {return a->getpos() < b->getpos(); });
		if (posi % 2 == 1)
			std::sort(worker::deppeople.begin(), worker::deppeople.end(), [](std::shared_ptr<worker>a, std::shared_ptr<worker>b) {return a->getpos() > b->getpos(); });
	}
	posi++;
}

void wagessort(int dep) {
	static int wagesi = 0;
	if (dep == -1) {
		if (wagesi % 2 == 0)
			std::sort(worker::people.begin(), worker::people.end(), [](std::shared_ptr<worker>a, std::shared_ptr<worker>b) {return a->getcurwages() < b->getcurwages(); });
		if (wagesi % 2 == 1)
			std::sort(worker::people.begin(), worker::people.end(), [](std::shared_ptr<worker>a, std::shared_ptr<worker>b) {return a->getcurwages() > b->getcurwages(); });
	}
	else {
		if (wagesi % 2 == 0)
			std::sort(worker::deppeople.begin(), worker::deppeople.end(), [](std::shared_ptr<worker>a, std::shared_ptr<worker>b) {return a->getcurwages() < b->getcurwages(); });
		if (wagesi % 2 == 1)
			std::sort(worker::deppeople.begin(), worker::deppeople.end(), [](std::shared_ptr<worker>a, std::shared_ptr<worker>b) {return a->getcurwages() > b->getcurwages(); });
	}
	wagesi++;
}

void departmentsort(int dep) {
	static int departmenti = 0;
	if (dep == -1) {
		if (departmenti % 2 == 0)
			std::sort(worker::people.begin(), worker::people.end(), [](std::shared_ptr<worker>a, std::shared_ptr<worker>b) {return a->getdepartment() < b->getdepartment(); });
		if (departmenti % 2 == 1)
			std::sort(worker::people.begin(), worker::people.end(), [](std::shared_ptr<worker>a, std::shared_ptr<worker>b) {return a->getdepartment() > b->getdepartment(); });
	}
	else {
		if (departmenti % 2 == 0)
			std::sort(worker::deppeople.begin(), worker::deppeople.end(), [](std::shared_ptr<worker>a, std::shared_ptr<worker>b) {return a->getdepartment() < b->getdepartment(); });
		if (departmenti % 2 == 1)
			std::sort(worker::deppeople.begin(), worker::deppeople.end(), [](std::shared_ptr<worker>a, std::shared_ptr<worker>b) {return a->getdepartment() > b->getdepartment(); });
	}
	departmenti++;
}

void findname(const std::string&b) {
	for (auto p = worker::people.begin(); p != worker::people.end(); p++) {
		if (b == (*p)->getname()) {
			worker::FINDNAME.push_back((*p));
		}
	}
}


bool fn(const std::string&b) {
	int flag = 0;
	for (auto p = worker::people.begin(); p != worker::people.end(); p++) {
		if (b == (*p)->getname()) {
			flag = 1;
		}
	}
	return flag;
}

bool fi(const int id) {
	int flag = 0;
	for (auto p = worker::people.begin(); p != worker::people.end(); p++) {
		if (id == (*p)->getid()) {
			flag = 1;
		}
	}
	return flag;
}

void findid(const int id) {
	for (auto p = worker::people.begin(); p != worker::people.end(); p++) {
		if (id == (*p)->getid()) {
			worker::FINDID.push_back((*p));
		}
	}
}

void adddata(const std::string&c) {
	std::ofstream p(c.c_str());
	p.close();
}

void deletedata(const std::string&c) {
	remove(c.c_str());
}

void savedepartment() {
	std::ofstream out;
	out.open("department.bat");
	if (!worker::dep.empty()) {
		for (auto x : worker::dep)
			out << x.c_str()<<std::endl;
	}
	out.close();
}

void renewdepartment() {
	int flen = 0;
	std::ifstream in("department.bat");
	std::vector<std::string>().swap(worker::dep);
	if (!in) {
		//没有数据处理时
	}
	else{
		in.seekg(0, std::ios::end);
		flen = in.tellg();
		in.seekg(0,std::ios::beg);
		if (flen == in.tellg()) {
		}
		while(flen!=in.tellg()) {
			std::string department{};
			getline(in, department);
			if(!department.empty())
			worker::dep.push_back(department);
		}
	}
	in.close();
}


void deleteone(int num,int open, char* argv[]) {
	std::ofstream out(worker::readfile[open].c_str());
	for (auto &x : worker::people) {
		if (x== worker::people[num])
			continue;
		x->save(out);
	}
	out.close();
	renew(argv);
	openfile(open);
}



/*
1)	统计并显示某个部门的平均月工资、最低月工资、最高月工资。
2)	统计并显示某个部门超出本部门平均月工资的人数与员工信息。
3)	统计并显示所有员工中的最低月工资和最高月工资员工的信息。
4)	统计并显示所有员工超出平均月工资的人数与员工信息。
*/


void departmentwages(const std::string &department) {
	//处理一下cout出来
	int num = 0;
	char a[20], b[20], c[20],d[20];
	int size = 0, size1 = 0, size2 = 0, size3 = 0;
	double avermonthmoney = 0;
	avermonthmoney = worker::departmentallmoney[department]/ worker::departmentpeople[department];
	for (auto &x : worker::people) {
		if (x->getdepartment() == department)
			if (x->getcurwages() > avermonthmoney)
				num++;
	}
	itoa(avermonthmoney, a, 10);
	itoa(worker::departmentlowestmoney[department], b, 10);
	itoa(worker::departmenthighestmoney[department], c, 10);
	itoa(num, d, 10);
	while (a[size++] != '\0');
	while (b[size1++] != '\0');
	while (c[size2++] != '\0');
	while (d[size3++] != '\0');
	PrintChar("默认为当前所选月份.", sizeof("默认为当前所选月份."), 25, 1);
	int y = 2;
	PrintChar("---------------------------------------------", 45, 25, y + 4 + 1);
	PrintChar("▏", 4, 25, y + 5 + 1);
	PrintChar("该部门的平均月工资:", sizeof("该部门的平均月工资:"), 27, y + 5 + 1);
	PrintChar(tab, 4, 67, y + 5 + 1);
	PrintChar("▏", 4, 70, y + 5 + 1);
	PrintChar("---------------------------------------------", 45, 25, y + 6 + 1);
	PrintChar("---------------------------------------------", 45, 25, y + 8 + 1);
	PrintChar("▏", 4, 25, y + 9 + 1);
	PrintChar("该部门的最低月工资:", sizeof("该部门的平均月工资:"), 27, y + 9 + 1);
	PrintChar(tab, 4, 67, y + 9 + 1);
	PrintChar("▏", 4, 70, y + 9 + 1);
	PrintChar("---------------------------------------------", 45, 25, y + 10 + 1);
	PrintChar("---------------------------------------------", 45, 25, y + 12 + 1);
	PrintChar("▏", 4, 25, y + 13 + 1);
	PrintChar("该部门的最高月工资:", sizeof("该部门的平均月工资:"), 27, y + 13 + 1);
	PrintChar(tab, 4, 67, y + 13 + 1);
	PrintChar("▏", 4, 70, y + 13 + 1);
	PrintChar("---------------------------------------------", 45, 25, y + 14 + 1);
	PrintChar("---------------------------------------------", 45, 25, y + 16 + 1);
	PrintChar("▏", 4, 25, y + 17 + 1);
	PrintChar("该部门超出本部门平均月工资的人数:", sizeof("该部门超出本部门平均月工资的人数:"), 27, y + 17 + 1);
	PrintChar(tab, 4, 67, y + 17 + 1);
	PrintChar("▏", 4, 70, y + 17 + 1);
	PrintChar("---------------------------------------------", 45, 25, y + 18 + 1);
	PrintChar(a, size, 48, y + 5 + 1);
	PrintChar(b, size1, 48, y + 9 + 1);
	PrintChar(c, size2, 48, y + 13 + 1);
	PrintChar(d, size3, 62, y + 17 + 1);
}

void allmenwages() {
	int num = 0;
	char a[20], b[20], c[20], d[20];
	int size = 0, size1 = 0, size2 = 0, size3 = 0;
	double avermonthmoney = 0;
	avermonthmoney = worker::allmoney / worker::allmen;
	for (auto &x : worker::people) {
			if (x->getcurwages() > avermonthmoney)
				num++;
	}
	itoa(avermonthmoney, a, 10);
	itoa(worker::lowestmoney, b, 10);
	itoa(worker::highestmoney, c, 10);
	itoa(num, d, 10);
	while (a[size++] != '\0');
	while (b[size1++] != '\0');
	while (c[size2++] != '\0');
	while (d[size3++] != '\0');
	PrintChar("默认为当前所选月份.", sizeof("默认为当前所选月份."), 25, 1);
	int y = 2;
	PrintChar("---------------------------------------------", 45, 25, y + 4 + 1);
	PrintChar("▏", 4, 25, y + 5 + 1);
	PrintChar("该部门的平均月工资:", sizeof("该部门的平均月工资:"), 27, y + 5 + 1);
	PrintChar(tab, 4, 67, y + 5 + 1);
	PrintChar("▏", 4, 70, y + 5 + 1);
	PrintChar("---------------------------------------------", 45, 25, y + 6 + 1);
	PrintChar("---------------------------------------------", 45, 25, y + 8 + 1);
	PrintChar("▏", 4, 25, y + 9 + 1);
	PrintChar("该部门的最低月工资:", sizeof("该部门的平均月工资:"), 27, y + 9 + 1);
	PrintChar(tab, 4, 67, y + 9 + 1);
	PrintChar("▏", 4, 70, y + 9 + 1);
	PrintChar("---------------------------------------------", 45, 25, y + 10 + 1);
	PrintChar("---------------------------------------------", 45, 25, y + 12 + 1);
	PrintChar("▏", 4, 25, y + 13 + 1);
	PrintChar("该部门的最高月工资:", sizeof("该部门的平均月工资:"), 27, y + 13 + 1);
	PrintChar(tab, 4, 67, y + 13 + 1);
	PrintChar("▏", 4, 70, y + 13 + 1);
	PrintChar("---------------------------------------------", 45, 25, y + 14 + 1);
	PrintChar("---------------------------------------------", 45, 25, y + 16 + 1);
	PrintChar("▏", 4, 25, y + 17 + 1);
	PrintChar("该部门超出本部门平均月工资的人数:", sizeof("该部门超出本部门平均月工资的人数:"), 27, y + 17 + 1);
	PrintChar(tab, 4, 67, y + 17 + 1);
	PrintChar("▏", 4, 70, y + 17 + 1);
	PrintChar("---------------------------------------------", 45, 25, y + 18 + 1);
	PrintChar(a, size, 48, y + 5 + 1);
	PrintChar(b, size1, 48, y + 9 + 1);
	PrintChar(c, size2, 48, y + 13 + 1);
	PrintChar(d, size3, 62, y + 17 + 1);
}

