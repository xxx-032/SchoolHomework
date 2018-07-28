#include"public.h"
HANDLE hInput;  /*  获取标准输入设备句柄 */
COORD pos = { 0,0 };
INPUT_RECORD inRec;/*  返回数据记录 */
DWORD numRead; /*  返回已读取的记录数 */
int X, Y;/* X和Y的坐标 */




int input(int X, int Y)
{
	
	static int flag = 0;
	while (1) {

		
		//if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwEventFlags == RIGHTMOST_BUTTON_PRESSED)  /* 鼠标左键双击 */
		//	return 1;
		if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED) /* 鼠标右键单击 */
		{
			if (mode == MODE8) {
				if (page88 == 0) {
					if (::qdep == -1) {
						if (!worker::people.empty()) {
							if ((((int)worker::people.size() - page8 * 3) >= 0)) {
								if (X >= 24 && Y == 4)									//九个员工名单信息		
									return 40;
								if (X >= 24 && Y == 6)
									return 41;
								if (X >= 24 && Y == 8)
									return 42;
								if (X >= 24 && Y == 10)
									return 43;
								if (X >= 24 && Y == 12)
									return 44;
								if (X >= 24 && Y == 14)
									return 45;
								if (X >= 24 && Y == 16)
									return 46;
								if (X >= 24 && Y == 18)
									return 47;
								if (X >= 24 && Y == 20)
									return 48;
							}
							else if (((((int)worker::people.size() - (page8 - 1) * 3) % 9) == 8)) {
								if (X >= 24 && Y == 4)									//九个员工名单信息		
									return 40;
								if (X >= 24 && Y == 6)
									return 41;
								if (X >= 24 && Y == 8)
									return 42;
								if (X >= 24 && Y == 10)
									return 43;
								if (X >= 24 && Y == 12)
									return 44;
								if (X >= 24 && Y == 14)
									return 45;
								if (X >= 24 && Y == 16)
									return 46;
								if (X >= 24 && Y == 18)
									return 47;
							}
							else if (((((int)worker::people.size() - (page8 - 1) * 3) % 9) == 7)) {
								if (X >= 24 && Y == 4)									//九个员工名单信息		
									return 40;
								if (X >= 24 && Y == 6)
									return 41;
								if (X >= 24 && Y == 8)
									return 42;
								if (X >= 24 && Y == 10)
									return 43;
								if (X >= 24 && Y == 12)
									return 44;
								if (X >= 24 && Y == 14)
									return 45;
								if (X >= 24 && Y == 16)
									return 46;
							}
							else if (((((int)worker::people.size() - (page8 - 1) * 3) % 9) == 6)) {
								if (X >= 24 && Y == 4)									//九个员工名单信息		
									return 40;
								if (X >= 24 && Y == 6)
									return 41;
								if (X >= 24 && Y == 8)
									return 42;
								if (X >= 24 && Y == 10)
									return 43;
								if (X >= 24 && Y == 12)
									return 44;
								if (X >= 24 && Y == 14)
									return 45;
							}
							else if (((((int)worker::people.size() - (page8 - 1) * 3) % 9) == 5)) {
								if (X >= 24 && Y == 4)									//九个员工名单信息		
									return 40;
								if (X >= 24 && Y == 6)
									return 41;
								if (X >= 24 && Y == 8)
									return 42;
								if (X >= 24 && Y == 10)
									return 43;
								if (X >= 24 && Y == 12)
									return 44;
							}
							else if (((((int)worker::people.size() - (page8 - 1) * 3) % 9) == 4)) {
								if (X >= 24 && Y == 4)									//九个员工名单信息		
									return 40;
								if (X >= 24 && Y == 6)
									return 41;
								if (X >= 24 && Y == 8)
									return 42;
								if (X >= 24 && Y == 10)
									return 43;
							}
							else if (((((int)worker::people.size() - (page8 - 1) * 3) % 9) == 3)) {
								if (X >= 24 && Y == 4)									//九个员工名单信息		
									return 40;
								if (X >= 24 && Y == 6)
									return 41;
								if (X >= 24 && Y == 8)
									return 42;
							}
							else if (((((int)worker::people.size() - (page8 - 1) * 3) % 9) == 2)) {
								if (X >= 24 && Y == 4)									//九个员工名单信息		
									return 40;
								if (X >= 24 && Y == 6)
									return 41;
							}
							else if (((((int)worker::people.size() - (page8 - 1) * 3) % 9) == 1)) {
								if (X >= 24 && Y == 4)									//九个员工名单信息		
									return 40;
							}
						}
					}
					else {
						if (!worker::deppeople.empty()) {
							if ((((int)worker::deppeople.size() - page8 * 3) >= 0)) {
								if (X >= 24 && Y == 4)									//九个员工名单信息		
									return 40;
								if (X >= 24 && Y == 6)
									return 41;
								if (X >= 24 && Y == 8)
									return 42;
								if (X >= 24 && Y == 10)
									return 43;
								if (X >= 24 && Y == 12)
									return 44;
								if (X >= 24 && Y == 14)
									return 45;
								if (X >= 24 && Y == 16)
									return 46;
								if (X >= 24 && Y == 18)
									return 47;
								if (X >= 24 && Y == 20)
									return 48;
							}
							else if (((((int)worker::deppeople.size() - (page8 - 1) * 3) % 9) == 8)) {
								if (X >= 24 && Y == 4)									//九个员工名单信息		
									return 40;
								if (X >= 24 && Y == 6)
									return 41;
								if (X >= 24 && Y == 8)
									return 42;
								if (X >= 24 && Y == 10)
									return 43;
								if (X >= 24 && Y == 12)
									return 44;
								if (X >= 24 && Y == 14)
									return 45;
								if (X >= 24 && Y == 16)
									return 46;
								if (X >= 24 && Y == 18)
									return 47;
							}
							else if (((((int)worker::deppeople.size() - (page8 - 1) * 3) % 9) == 7)) {
								if (X >= 24 && Y == 4)									//九个员工名单信息		
									return 40;
								if (X >= 24 && Y == 6)
									return 41;
								if (X >= 24 && Y == 8)
									return 42;
								if (X >= 24 && Y == 10)
									return 43;
								if (X >= 24 && Y == 12)
									return 44;
								if (X >= 24 && Y == 14)
									return 45;
								if (X >= 24 && Y == 16)
									return 46;
							}
							else if (((((int)worker::deppeople.size() - (page8 - 1) * 3) % 9) == 6)) {
								if (X >= 24 && Y == 4)									//九个员工名单信息		
									return 40;
								if (X >= 24 && Y == 6)
									return 41;
								if (X >= 24 && Y == 8)
									return 42;
								if (X >= 24 && Y == 10)
									return 43;
								if (X >= 24 && Y == 12)
									return 44;
								if (X >= 24 && Y == 14)
									return 45;
							}
							else if (((((int)worker::deppeople.size() - (page8 - 1) * 3) % 9) == 5)) {
								if (X >= 24 && Y == 4)									//九个员工名单信息		
									return 40;
								if (X >= 24 && Y == 6)
									return 41;
								if (X >= 24 && Y == 8)
									return 42;
								if (X >= 24 && Y == 10)
									return 43;
								if (X >= 24 && Y == 12)
									return 44;
							}
							else if (((((int)worker::deppeople.size() - (page8 - 1) * 3) % 9) == 4)) {
								if (X >= 24 && Y == 4)									//九个员工名单信息		
									return 40;
								if (X >= 24 && Y == 6)
									return 41;
								if (X >= 24 && Y == 8)
									return 42;
								if (X >= 24 && Y == 10)
									return 43;
							}
							else if (((((int)worker::deppeople.size() - (page8 - 1) * 3) % 9) == 3)) {
								if (X >= 24 && Y == 4)									//九个员工名单信息		
									return 40;
								if (X >= 24 && Y == 6)
									return 41;
								if (X >= 24 && Y == 8)
									return 42;
							}
							else if (((((int)worker::deppeople.size() - (page8 - 1) * 3) % 9) == 2)) {
								if (X >= 24 && Y == 4)									//九个员工名单信息		
									return 40;
								if (X >= 24 && Y == 6)
									return 41;
							}
							else if (((((int)worker::deppeople.size() - (page8 - 1) * 3) % 9) == 1)) {
								if (X >= 24 && Y == 4)									//九个员工名单信息		
									return 40;
							}
						}
					}
				}
				return 404;
			}
		}
		if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) /* 鼠标左键单击 */
		{
			//welcome
			if (mode == MODE0)
				if (X > 0 && Y > 0)return 1;
			//登陆方式
			if (mode == MODE1) {
				if (X > MAXCOL - 12 && X < MAXCOL && Y > 0 && Y < 2)
					return 1;
				if (X > 26 && X < 45 && Y > 4 && Y < 7) /* 游客登陆 */
					return 2;
				else if (X > 26 && X < 45 && Y > 9 && Y < 13) /* 教师登陆 */
					return 3;
				else
					return 0;
				return 404;
			}
			//鼠标闪烁
			if (mode == MODE2) {
				if (X >= 30 && X <= 68 && Y == 9)
					return 0;
				return 404;
			}
			//暂空
			if (mode == MODE3) {
				if (X >= 30 && X <= 68 && Y == 6)
					return 0;
				if (X >= 30 && X <= 68 && Y == 9)
					return 1;
				if (X >= 25 && X <= 38 && Y == 13)
					return 2;
				if (X >= 44 && X <= 57 && Y == 13)
					return 3;
				return 404;
			}
			//qtime
			if (mode == MODE4) {
				if (X >= 2 && X <= 17 && Y >= 3 && Y <= 5)				//查询月份
					return 0;
				if (X >= 2 && X <= 17 && Y >= 7 && Y <= 9)				//查询部门
					return 1;
				if (X >= 2 && X <= 17 && Y >= 11 && Y <= 13)			//查询岗位
					return 3;
				if (X >= 2 && X <= 17 && Y >= 15 && Y <= 17)			//查询统计结果
					return 4;

					if (!worker::data.empty()) {
						if (((int)worker::data.size() - page4 * 3) >= 0) {
							if (X >= 43 && X <= 58 && Y >= 5 && Y <= 7) {				//第一部门
								return 5;
							}
							if (X >= 43 && X <= 58 && Y >= 11 && Y <= 13) {			//第二部门
								return 6;
							}
							if (X >= 43 && X <= 58 && Y >= 17 && Y <= 19) {			//第三部门
								return 7;
							}
						}
						else if ((((int)worker::data.size() - (page4 - 1) * 3) % 3) == 2) {
							if (X >= 43 && X <= 58 && Y >= 5 && Y <= 7) {				//第一部门
								return 5;
							}
							if (X >= 43 && X <= 58 && Y >= 11 && Y <= 13) {			//第二部门
								return 6;
							}
						}
						else if ((((int)worker::data.size() - (page4 - 1) * 3) % 3) == 1) {
							if (X >= 43 && X <= 58 && Y >= 5 && Y <= 7) {				//第一部门
								return 5;
							}
						}
						if (X >= 35 && X <= 45 && Y >= 21 && Y <= 22 && (page4 - 1)) {						//上一页

							return 8;
						}
						if (X >= 55 && X <= 75 && Y >= 21 && Y <= 22 && (((int)worker::data.size() - page4 * 3) > 0)) {						//下一页
							return 9;
						}
					}
				return 404;
			}
			//qdepartment
			if (mode == MODE5) {
				if (X >= 2 && X <= 17 && Y >= 3 && Y <= 5)				//查询月份
					return 0;
				if (X >= 2 && X <= 17 && Y >= 7 && Y <= 9)				//查询部门
					return 1;
				if (X >= 2 && X <= 17 && Y >= 11 && Y <= 13)			//查询岗位
					return 3;
				if (X >= 2 && X <= 17 && Y >= 15 && Y <= 17)			//查询统计结果
					return 4;

				if (!worker::dep.empty()) {
					if (((int)worker::dep.size() - page5 * 3) >= 0) {
						if (X >= 43 && X <= 58 && Y >= 5 && Y <= 7) {				//第一部门
							return 5;
						}
						if (X >= 43 && X <= 58 && Y >= 11 && Y <= 13) {			//第二部门
							return 6;
						}
						if (X >= 43 && X <= 58 && Y >= 17 && Y <= 19) {			//第三部门
							return 7;
						}
					}
					else if ((((int)worker::dep.size() - (page5 - 1) * 3) % 3) == 2) {
						if (X >= 43 && X <= 58 && Y >= 5 && Y <= 7) {				//第一部门
							return 5;
						}
						if (X >= 43 && X <= 58 && Y >= 11 && Y <= 13) {			//第二部门
							return 6;
						}
					}
					else if ((((int)worker::dep.size() - (page5 - 1) * 3) % 3) == 1) {
						if (X >= 43 && X <= 58 && Y >= 5 && Y <= 7) {				//第一部门
							return 5;
						}
					}
					if (X >= 35 && X <= 45 && Y >= 21 && Y <= 22 && (page5 - 1)) {						//上一页

						return 8;
					}
					if (X >= 55 && X <= 75 && Y >= 21 && Y <= 22 && (((int)worker::dep.size() - page5 * 3) > 0)) {						//下一页
						return 9;
					}
				}
				makedepartmentsure(0);
				return 404;
			}
			//qpos

			if (mode == MODE6) {		//岗位查询
				if (X >= 2 && X <= 17 && Y >= 3 && Y <= 5)				//查询月份
					return 0;
				if (X >= 2 && X <= 17 && Y >= 7 && Y <= 9)				//查询部门
					return 1;
				if (X >= 2 && X <= 17 && Y >= 11 && Y <= 13)			//查询岗位
					return 3;
				if (X >= 2 && X <= 17 && Y >= 15 && Y <= 17)			//查询统计结果
					return 4;
				if (X >= 43 && X <= 58 && Y >= 20 && Y <= 22)			   //查询销售经理
					return 8;
				if (X >= 43 && X <= 58 && Y >= 15 && Y <= 17)			//查询技术员
					return 7;
				if (X >= 43 && X <= 58 && Y >= 10 && Y <= 12)			//查询销售员
					return 6;
				if (X >= 43 && X <= 58 && Y >= 5 && Y <= 7)			//查询经理
					return 5;
				return 404;
			}

			//qcount
			if (mode == MODE7) {
				if (X >= 2 && X <= 17 && Y >= 3 && Y <= 5)				//查询月份
					return 0;
				if (X >= 2 && X <= 17 && Y >= 7 && Y <= 9)				//查询部门
					return 1;
				if (X >= 2 && X <= 17 && Y >= 11 && Y <= 13)			//查询岗位
					return 3;
				if (X >= 2 && X <= 17 && Y >= 15 && Y <= 17)			//查询统计结果
					return 4;

				if (X >= 43 && X <= 58 && Y >= 15 && Y <= 17)			//本月工资水平
					return 7;
				if (X >= 43 && X <= 58 && Y >= 10 && Y <= 12)			//部门工资水平
					return 6;

				return 404;
			}


			//个人信息展露
			if (mode == MODE8) {
				if (X >= 2 && X <= 17 && Y >= 3 && Y <= 5)				//查询月份
					return 0;
				if (X >= 2 && X <= 17 && Y >= 7 && Y <= 9)				//查询部门
					return 1;
				if (X >= 2 && X <= 17 && Y >= 11 && Y <= 13)			//查询岗位
					return 3;
				if (X >= 2 && X <= 17 && Y >= 15 && Y <= 17)			//查询统计结果
					return 4;

				if (fltell == 0) {
					if (page88 == 0) {
						if (X >= 1 && X <= 18 && Y ==1)			//添加员工
							return 60;
						if (::qdep == -1) {
							if (X >= 2 && X <= 17 && Y >= 19 && Y <= 21)			//添加员工
								return 20;
							if (!worker::people.empty()) {
								if (X >= 35 && X <= 45 && Y >= 21 && Y <= 22 && (page8 - 1)) {						//上一页
									return 16;
								}
								if (X >= 55 && X <= 75 && Y >= 21 && Y <= 22 && (((int)worker::people.size() - page8 * 3) > 0)) {						//下一页
									return 17;
								}
								if (X >= 25 && X <= 32 && Y >= 21 && Y <= 22 && (page8 - 1)) {						//首页
									return 18;
								}
								if (X >= 75 && X <= 82 && Y >= 21 && Y <= 22 && (((int)worker::people.size() - page8 * 3) > 0)) {						//末页
									return 19;
								}
								if ((((int)worker::people.size() - page8 * 3) >= 0)) {
									if (X >= 24 && Y == 4)									//九个员工名单信息		
										return 6;
									if (X >= 24 && Y == 6)
										return 7;
									if (X >= 24 && Y == 8)
										return 8;
									if (X >= 24 && Y == 10)
										return 9;
									if (X >= 24 && Y == 12)
										return 10;
									if (X >= 24 && Y == 14)
										return 11;
									if (X >= 24 && Y == 16)
										return 12;
									if (X >= 24 && Y == 18)
										return 13;
									if (X >= 24 && Y == 20)
										return 14;
								}
								else if (((((int)worker::people.size() - (page8 - 1) * 3) % 9) == 8)) {
									if (X >= 24 && Y == 4)									//九个员工名单信息		
										return 6;
									if (X >= 24 && Y == 6)
										return 7;
									if (X >= 24 && Y == 8)
										return 8;
									if (X >= 24 && Y == 10)
										return 9;
									if (X >= 24 && Y == 12)
										return 10;
									if (X >= 24 && Y == 14)
										return 11;
									if (X >= 24 && Y == 16)
										return 12;
									if (X >= 24 && Y == 18)
										return 13;
								}
								else if (((((int)worker::people.size() - (page8 - 1) * 3) % 9) == 7)) {
									if (X >= 24 && Y == 4)									//九个员工名单信息		
										return 6;
									if (X >= 24 && Y == 6)
										return 7;
									if (X >= 24 && Y == 8)
										return 8;
									if (X >= 24 && Y == 10)
										return 9;
									if (X >= 24 && Y == 12)
										return 10;
									if (X >= 24 && Y == 14)
										return 11;
									if (X >= 24 && Y == 16)
										return 12;
								}
								else if (((((int)worker::people.size() - (page8 - 1) * 3) % 9) == 6)) {
									if (X >= 24 && Y == 4)									//九个员工名单信息		
										return 6;
									if (X >= 24 && Y == 6)
										return 7;
									if (X >= 24 && Y == 8)
										return 8;
									if (X >= 24 && Y == 10)
										return 9;
									if (X >= 24 && Y == 12)
										return 10;
									if (X >= 24 && Y == 14)
										return 11;
								}
								else if (((((int)worker::people.size() - (page8 - 1) * 3) % 9) == 5)) {
									if (X >= 24 && Y == 4)									//九个员工名单信息		
										return 6;
									if (X >= 24 && Y == 6)
										return 7;
									if (X >= 24 && Y == 8)
										return 8;
									if (X >= 24 && Y == 10)
										return 9;
									if (X >= 24 && Y == 12)
										return 10;
								}
								else if (((((int)worker::people.size() - (page8 - 1) * 3) % 9) == 4)) {
									if (X >= 24 && Y == 4)									//九个员工名单信息		
										return 6;
									if (X >= 24 && Y == 6)
										return 7;
									if (X >= 24 && Y == 8)
										return 8;
									if (X >= 24 && Y == 10)
										return 9;
								}
								else if (((((int)worker::people.size() - (page8 - 1) * 3) % 9) == 3)) {
									if (X >= 24 && Y == 4)									//九个员工名单信息		
										return 6;
									if (X >= 24 && Y == 6)
										return 7;
									if (X >= 24 && Y == 8)
										return 8;
								}
								else if (((((int)worker::people.size() - (page8 - 1) * 3) % 9) == 2)) {
									if (X >= 24 && Y == 4)									//九个员工名单信息		
										return 6;
									if (X >= 24 && Y == 6)
										return 7;
								}
								else if (((((int)worker::people.size() - (page8 - 1) * 3) % 9) == 1)) {
									if (X >= 24 && Y == 4)									//九个员工名单信息		
										return 6;
								}
							}


							if (!worker::people.empty()) {
								if (X >= 25 && X <= 32 && Y == 1)			//工号排序
									return 25;
								if (X >= 37 && X <= 44 && Y == 1)			//姓名排序
									return 26;
								if (X >= 49 && X <= 56 && Y == 1)			//部门排序
									return 29;
								if (X >= 73 && X <= 80 && Y == 1)			//工资排序
									return 28;
								if (X >= 61 && X <= 68 && Y == 1)			//岗位排序
									return 27;
							}
						}
						else {
							if (!worker::deppeople.empty()) {
								if (X >= 35 && X <= 45 && Y >= 21 && Y <= 22 && (page8 - 1)) {						//上一页
									return 16;
								}
								if (X >= 55 && X <= 75 && Y >= 21 && Y <= 22 && (((int)worker::deppeople.size() - page8 * 3) > 0)) {						//下一页
									return 17;
								}
								if (X >= 25 && X <= 32 && Y >= 21 && Y <= 22 && (page8 - 1)) {						//首页
									return 18;
								}
								if (X >= 75 && X <= 82 && Y >= 21 && Y <= 22 && (((int)worker::deppeople.size() - page8 * 3) > 0)) {						//末页
									return 19;
								}
								if ((((int)worker::deppeople.size() - page8 * 3) >= 0)) {
									if (X >= 24 && Y == 4)									//九个员工名单信息		
										return 6;
									if (X >= 24 && Y == 6)
										return 7;
									if (X >= 24 && Y == 8)
										return 8;
									if (X >= 24 && Y == 10)
										return 9;
									if (X >= 24 && Y == 12)
										return 10;
									if (X >= 24 && Y == 14)
										return 11;
									if (X >= 24 && Y == 16)
										return 12;
									if (X >= 24 && Y == 18)
										return 13;
									if (X >= 24 && Y == 20)
										return 14;
								}
								else if (((((int)worker::deppeople.size() - (page8 - 1) * 3) % 9) == 8)) {
									if (X >= 24 && Y == 4)									//九个员工名单信息		
										return 6;
									if (X >= 24 && Y == 6)
										return 7;
									if (X >= 24 && Y == 8)
										return 8;
									if (X >= 24 && Y == 10)
										return 9;
									if (X >= 24 && Y == 12)
										return 10;
									if (X >= 24 && Y == 14)
										return 11;
									if (X >= 24 && Y == 16)
										return 12;
									if (X >= 24 && Y == 18)
										return 13;
								}
								else if (((((int)worker::deppeople.size() - (page8 - 1) * 3) % 9) == 7)) {
									if (X >= 24 && Y == 4)									//九个员工名单信息		
										return 6;
									if (X >= 24 && Y == 6)
										return 7;
									if (X >= 24 && Y == 8)
										return 8;
									if (X >= 24 && Y == 10)
										return 9;
									if (X >= 24 && Y == 12)
										return 10;
									if (X >= 24 && Y == 14)
										return 11;
									if (X >= 24 && Y == 16)
										return 12;
								}
								else if (((((int)worker::deppeople.size() - (page8 - 1) * 3) % 9) == 6)) {
									if (X >= 24 && Y == 4)									//九个员工名单信息		
										return 6;
									if (X >= 24 && Y == 6)
										return 7;
									if (X >= 24 && Y == 8)
										return 8;
									if (X >= 24 && Y == 10)
										return 9;
									if (X >= 24 && Y == 12)
										return 10;
									if (X >= 24 && Y == 14)
										return 11;
								}
								else if (((((int)worker::deppeople.size() - (page8 - 1) * 3) % 9) == 5)) {
									if (X >= 24 && Y == 4)									//九个员工名单信息		
										return 6;
									if (X >= 24 && Y == 6)
										return 7;
									if (X >= 24 && Y == 8)
										return 8;
									if (X >= 24 && Y == 10)
										return 9;
									if (X >= 24 && Y == 12)
										return 10;
								}
								else if (((((int)worker::deppeople.size() - (page8 - 1) * 3) % 9) == 4)) {
									if (X >= 24 && Y == 4)									//九个员工名单信息		
										return 6;
									if (X >= 24 && Y == 6)
										return 7;
									if (X >= 24 && Y == 8)
										return 8;
									if (X >= 24 && Y == 10)
										return 9;
								}
								else if (((((int)worker::deppeople.size() - (page8 - 1) * 3) % 9) == 3)) {
									if (X >= 24 && Y == 4)									//九个员工名单信息		
										return 6;
									if (X >= 24 && Y == 6)
										return 7;
									if (X >= 24 && Y == 8)
										return 8;
								}
								else if (((((int)worker::deppeople.size() - (page8 - 1) * 3) % 9) == 2)) {
									if (X >= 24 && Y == 4)									//九个员工名单信息		
										return 6;
									if (X >= 24 && Y == 6)
										return 7;
								}
								else if (((((int)worker::deppeople.size() - (page8 - 1) * 3) % 9) == 1)) {
									if (X >= 24 && Y == 4)									//九个员工名单信息		
										return 6;
								}
							}


							if (!worker::deppeople.empty()) {
								if (X >= 25 && X <= 32 && Y == 1)			//工号排序
									return 25;
								if (X >= 37 && X <= 44 && Y == 1)			//姓名排序
									return 26;
								if (X >= 49 && X <= 56 && Y == 1)			//部门排序
									return 29;
								if (X >= 73 && X <= 80 && Y == 1)			//工资排序
									return 28;
								if (X >= 61 && X <= 68 && Y == 1)			//岗位排序
									return 27;
							}
						}
					}
					else if (page88 == 2) {
						if (X >= 45 && X <= 52 && Y == 21)			//上一页
							return 35;
						if (X >= 63 && X <= 73 && Y >= 20 && Y <= 22)			//返回
							return 36;
					}
					else if (page88 == 1) {
						if (X >= 52 && X <= 59 && Y == 21)			//下一页
							return 34;
						if (X >= 63 && X <= 73 && Y >= 20 && Y <= 22)			//返回
							return 36;
					}
				}
				else {
					if (X >= 30 && X<40 && Y == 1)
						return 50;
					if (X >= 40 && X<50 && Y == 1)
						return 51;
					if (X >= 50 && X<60 && Y == 1)
						return 52;
					if (X >= 60 && X<70 && Y == 1)
						return 53;
				}
			return 404;
		}

			//输入个人信息
			if (mode == MODE9) {
				if (X >= 2 && X <= 17 && Y >= 3 && Y <= 5)				//查询月份
					return 0;
				if (X >= 2 && X <= 17 && Y >= 7 && Y <= 9)				//查询部门
					return 1;
				if (X >= 2 && X <= 17 && Y >= 11 && Y <= 13)			//查询岗位
					return 3;
				if (X >= 2 && X <= 17 && Y >= 15 && Y <= 17)			//查询统计结果
					return 4;
				if (X >= 30 && X <= 45 && Y ==8)				//姓名
					return 10;
				if (X >= 53 && X <= 73 && Y ==8)				//生日
					return 11;
				if (X >= 30 && X <= 45 && Y >= 11 && Y <= 12)				//性别
					return 12;
				if (X >= 30 && X <= 45 && Y >= 14 && Y <= 15)				//岗位
					return 13;
				if (X >= 53 && X <= 73 && Y >= 14 && Y <= 15)				//工作市场或销售额
					return 15;
				if (X >= 30 && X <= 40 && Y==21)
					return 16;
				if (X >= 63 && X <= 73 && Y == 21)
					return 17;
					return 404;
			}
			//qhelp
			if (mode == MODE10) {   //
				if (X >= 2 && X <= 17 && Y >= 4 && Y <= 6)				//查询月份
					return 0;
				if (X >= 2 && X <= 17 && Y >= 8 && Y <= 10)				//查询部门
					return 1;
				if (X >= 2 && X <= 17 && Y >= 12 && Y <= 14)			//查询岗位
					return 3;
				if (X >= 2 && X <= 17 && Y >= 16 && Y <= 18)			//查询统计结果
					return 4;
				if (X >= 43 && X <= 58 && Y >= 18 && Y <= 20)			   //退出系统
					return 8;
				if (X >= 43 && X <= 58 && Y >= 14 && Y <= 16)			//部门数据
					return 7;
				if (X >= 43 && X <= 58 && Y >= 10 && Y <= 12)			//月份管理
					return 6;
				if (X >= 43 && X <= 58 && Y >= 6 && Y <= 8)			//导入数据
					return 5;
					return 404;
			}
			//岗位查询
			if (mode == MODE11) {
				if (X >= 2 && X <= 17 && Y >= 4 && Y <= 6)				//查询月份
					return 0;
				if (X >= 2 && X <= 17 && Y >= 8 && Y <= 10)				//查询部门
					return 1;
				if (X >= 2 && X <= 17 && Y >= 12 && Y <= 14)			//查询岗位
					return 3;
				if (X >= 2 && X <= 17 && Y >= 16 && Y <= 18)			//查询统计结果
					return 4;
				if (X >= 43 && X <= 58 && Y >= 5 && Y <= 7)				//经理
					return 5;
				if (X >= 43 && X <= 58 && Y >= 10 && Y <= 12)			//销售员
					return 6;
				if (X >= 43 && X <= 58 && Y >= 15 && Y <= 17)			//技术员
					return 7;
				if (X >= 43 && X <= 58 && Y >= 20 && Y <= 22)			//销售经理
					return 8;
					return 404;
			}
			//统计结果
			if (mode == MODE12) {
				if (X >= 2 && X <= 17 && Y >= 4 && Y <= 6)				//查询月份
					return 0;
				if (X >= 2 && X <= 17 && Y >= 8 && Y <= 10)				//查询部门
					return 1;
				if (X >= 2 && X <= 17 && Y >= 12 && Y <= 14)			//查询岗位
					return 3;
				if (X >= 2 && X <= 17 && Y >= 16 && Y <= 18)			//查询统计结果
					return 4;
				if (X >= 43 && X <= 58 && Y >= 5 && Y <= 7)				//部门工资水平
					return 5;
				if (X >= 43 && X <= 58 && Y >= 10 && Y <= 12)			//部门平均水平
					return 6;
				if (X >= 43 && X <= 58 && Y >= 15 && Y <= 17)			//本月工资水平
					return 7;
				if (X >= 43 && X <= 58 && Y >= 20 && Y <= 22)			//本月平均水平
					return 8;
					return 404;
			}

			//输入部门信息
			if (mode == MODE13) {
				if (X >= 2 && X <= 17 && Y >= 3 && Y <= 5)				//查询月份
					return 0;
				if (X >= 2 && X <= 17 && Y >= 7 && Y <= 9)				//查询部门
					return 1;
				if (X >= 2 && X <= 17 && Y >= 11 && Y <= 13)			//查询岗位
					return 3;
				if (X >= 2 && X <= 17 && Y >= 15 && Y <= 17)			//查询统计结果
					return 4;
				if (X >= 45 && X <= 75 && Y == 12)						//输入部门信息
					return 5;
				if (X >= 30 && X <= 40 && Y == 21)						//确定
					return 6;
				if (X >= 63 && X <= 73 && Y == 21)						//返回
					return 7;
					return 404;
			}
			//部门索引
			if (mode == MODE14) {
				if (X >= 2 && X <= 17 && Y >= 3 && Y <= 5)				//查询月份
					return 0;
				if (X >= 2 && X <= 17 && Y >= 7 && Y <= 9)				//查询部门
					return 1;
				if (X >= 2 && X <= 17 && Y >= 11 && Y <= 13)			//查询岗位
					return 3;
				if (X >= 2 && X <= 17 && Y >= 15 && Y <= 17)			//查询统计结果
					return 4;
				if (X >= 42 && X <= 57 && Y == 11)						//增加部门
					return 5;
				if (X >= 42 && X <= 57 && Y == 15)						//删除部门
					return 6;

					return 404;
			}
			//查看部门删除
			if (mode == MODE15) {
				if (X >= 2 && X <= 17 && Y >= 3 && Y <= 5)				//查询月份
					return 0;
				if (X >= 2 && X <= 17 && Y >= 7 && Y <= 9)				//查询部门
					return 1;
				if (X >= 2 && X <= 17 && Y >= 11 && Y <= 13)			//查询岗位
					return 3;
				if (X >= 2 && X <= 17 && Y >= 15 && Y <= 17)			//查询统计结果
					return 4;

				if (!worker::dep.empty()) {
					if (((int)worker::dep.size() - page14 * 3) >= 0) {
						if (X >= 43 && X <= 58 && Y >= 5 && Y <= 7) {				//第一部门
							flag = makedepartmentsure(1);
							return 5;
						}
						if (X >= 43 && X <= 58 && Y >= 11 && Y <= 13) {			//第二部门
							flag = makedepartmentsure(1);
							return 6;
						}
						if (X >= 43 && X <= 58 && Y >= 17 && Y <= 19) {			//第三部门
							flag = makedepartmentsure(1);
							return 7;
						}
					}
					else if ((((int)worker::dep.size() - (page14 - 1) * 3) % 3) == 2) {
						if (X >= 43 && X <= 58 && Y >= 5 && Y <= 7) {				//第一部门
							flag = makedepartmentsure(1);
							return 5;
						}
						if (X >= 43 && X <= 58 && Y >= 11 && Y <= 13) {			//第二部门
							flag = makedepartmentsure(1);
							return 6;
						}
					}
					else if ((((int)worker::dep.size() - (page14 - 1) * 3) % 3) == 1) {
						if (X >= 43 && X <= 58 && Y >= 5 && Y <= 7) {				//第一部门
							flag = makedepartmentsure(1);
							return 5;
						}
					}
					if (X >= 35 && X <= 45 && Y >= 21&& Y <= 22 &&(page14-1) ) {						//上一页
						
						return 8;
					}
					if (X >= 55 && X <= 75 && Y >= 21 && Y <= 22 && (((int)worker::dep.size() - page14 * 3) > 0)) {						//下一页
						return 9;
					}
					if (flag) {
						if (X >= 23 && X <= 33 && Y >= 22 && Y <= 24)			//确认
							return 10;
						if (X >= 68 && X <= 78 && Y >= 22 && Y <= 24)			//取消
							return 11;
					}
				}
				makedepartmentsure(0);
					return 404;
			}
			//查看月份并删除
			if (mode == MODE16) {
				if (X >= 2 && X <= 17 && Y >= 3 && Y <= 5)				//查询月份
					return 0;
				if (X >= 2 && X <= 17 && Y >= 7 && Y <= 9)				//查询部门
					return 1;
				if (X >= 2 && X <= 17 && Y >= 11 && Y <= 13)			//查询岗位
					return 3;
				if (X >= 2 && X <= 17 && Y >= 15 && Y <= 17)			//查询统计结果
					return 4;

				if (!worker::data.empty()) {
					if (((int)worker::data.size() - page17 * 3) >= 0) {
						if (X >= 43 && X <= 58 && Y >= 5 && Y <= 7) {				//第一部门
							flag = makedatasure(1);
							return 5;
						}
						if (X >= 43 && X <= 58 && Y >= 11 && Y <= 13) {			//第二部门
							flag = makedatasure(1);
							return 6;
						}
						if (X >= 43 && X <= 58 && Y >= 17 && Y <= 19) {			//第三部门
							flag = makedatasure(1);
							return 7;
						}
					}
					else if ((((int)worker::data.size() - (page17 - 1) * 3) % 3) == 2) {
						if (X >= 43 && X <= 58 && Y >= 5 && Y <= 7) {				//第一部门
							flag = makedatasure(1);
							return 5;
						}
						if (X >= 43 && X <= 58 && Y >= 11 && Y <= 13) {			//第二部门
							flag = makedatasure(1);
							return 6;
						}
					}
					else if ((((int)worker::data.size() - (page17 - 1) * 3) % 3) == 1) {
						if (X >= 43 && X <= 58 && Y >= 5 && Y <= 7) {				//第一部门
							flag = makedatasure(1);
							return 5;
						}
					}
					if (X >= 35 && X <= 45 && Y >= 21 && Y <= 22 && (page17 - 1)) {						//上一页

						return 8;
					}
					if (X >= 55 && X <= 75 && Y >= 21 && Y <= 22 && (((int)worker::data.size() - page17 * 3) > 0)) {						//下一页
						return 9;
					}
					if (flag) {
						if (X >= 23 && X <= 33 && Y >= 22 && Y <= 24)			//确认
							return 10;
						if (X >= 68 && X <= 78 && Y >= 22 && Y <= 24)			//取消
							return 11;
					}
				}

				makedatasure(0);
				return 404;
			}
			//月份索引
			if (mode == MODE17) {
				if (X >= 2 && X <= 17 && Y >= 3 && Y <= 5)				//查询月份
					return 0;
				if (X >= 2 && X <= 17 && Y >= 7 && Y <= 9)				//查询部门
					return 1;
				if (X >= 2 && X <= 17 && Y >= 11 && Y <= 13)			//查询岗位
					return 3;
				if (X >= 2 && X <= 17 && Y >= 15 && Y <= 17)			//查询统计结果
					return 4;
				if (X >= 42 && X <= 57 && Y == 11)						//增加月份
					return 5;
				if (X >= 42 && X <= 57 && Y == 15)						//删除月份
					return 6;

					return 404;
			}
			//输入新增月份信息
			if (mode == MODE18) {
				if (X >= 2 && X <= 17 && Y >= 3 && Y <= 5)				//查询月份
					return 0;
				if (X >= 2 && X <= 17 && Y >= 7 && Y <= 9)				//查询部门
					return 1;
				if (X >= 2 && X <= 17 && Y >= 11 && Y <= 13)			//查询岗位
					return 3;
				if (X >= 2 && X <= 17 && Y >= 15 && Y <= 17)			//查询统计结果
					return 4;
				if (X >= 45 && X <= 75 && Y == 12)						//输入新增月份信息
					return 5;
				if (X >= 30 && X <= 40 && Y == 21)						//确定
					return 6;
				if (X >= 63 && X <= 73 && Y == 21)						//返回
					return 7;
					return 404;
			}
			//输入索引
			if (mode == MODE19) {
				if (X >= 2 && X <= 17 && Y >= 3 && Y <= 5)				//查询月份
					return 0;
				if (X >= 2 && X <= 17 && Y >= 7 && Y <= 9)				//查询部门
					return 1;
				if (X >= 2 && X <= 17 && Y >= 11 && Y <= 13)			//查询岗位
					return 3;
				if (X >= 2 && X <= 17 && Y >= 15 && Y <= 17)			//查询统计结果
					return 4;
				if (X >= 42 && X <= 57 && Y == 11)						//逐个导入
					return 5;
				if (X >= 42 && X <= 57 && Y == 15)						//批量导入
					return 6;

					return 404;
			}
		}
	}
}
void ShowCursor()//显示控制台光标
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,1 };

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void HideCursor()//隐藏控制台的光标 
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void mouse(char* argv[])
{
	//记录指向哪个位置
	int del = 0;

	std::vector<std::string>temp{};

	int setp = 0;
	std::string word[6];
	std::string newdepartment{};
	std::string newdata{};
	int page = 0;
	
	std::shared_ptr<worker>p = nullptr;
	int year=0, month=0, day=0,deal=0,mo=0,digit=0,digit1=0;


	struct Node{
		int data;
		int department;
		int flag;
	}index{ 0,0,0 };

	int rt=-1, flag = 0;
	int fl = 0;//添加成员case MODE10;
	int fff = 0, ffff = 0;//闪烁
	int xx = 0;
	int mmm=0;
	char c;
	HWND hwnd = FindWindow(TEXT("ConsoleWindowClass"), NULL);/*  控制台窗口句柄 */
	hInput = GetStdHandle(STD_INPUT_HANDLE); /*  输入设备句柄 */
	while (1) {
		HideCursor(); //隐藏控制台的光标 
		ReadConsoleInput(hInput, &inRec,10, &numRead); /* 读取1个输入事件 */
		switch (mode) {
		case MODE0:						//welcome()
			switch (inRec.EventType)
			{
			case MOUSE_EVENT:
			{
				if (inRec.Event.MouseEvent.dwButtonState) {
					pos = inRec.Event.MouseEvent.dwMousePosition; //
					Y = (int)pos.Y;								//
					X = (int)pos.X;			//
					rt = input(X,Y);
					switch (rt) {
					case 1:
						ClearScreen();
						boundary();
						mode = MODE1;
						break;
					}
				}
			}
			}
			break;

		case MODE1:						//boundry()
			switch (inRec.EventType)
			{
			case MOUSE_EVENT:
			{
				if (inRec.Event.MouseEvent.dwButtonState) {
					pos = inRec.Event.MouseEvent.dwMousePosition; //
					Y = (int)pos.Y;								//
					X = (int)pos.X;			//
					rt = input(X,Y);
					switch (rt) {
					case 1:
						ClearScreen();		
						exitsys();
						break;
					case 2:
						loadin();
						mode = MODE2;
						break;
					case 3:
						MessageBox(hwnd, TEXT("左键单击第一行"), TEXT("333"), 0);
						break;
					default:
						break;
					}
				}
			}
			break;
			}
			break;

		case MODE2:						//loadin
			switch (inRec.EventType)
			{
			case MOUSE_EVENT:
			{
				if (inRec.Event.MouseEvent.dwButtonState) {
					pos = inRec.Event.MouseEvent.dwMousePosition; //
					Y = (int)pos.Y;								//
					X = (int)pos.X;			//
					rt = input(X, Y);
					switch (rt) {
					case 0:
						fff = 1;
						break;
					}
				}
			}
			case KEY_EVENT:
				if (inRec.Event.KeyEvent.bKeyDown)
					switch (inRec.Event.KeyEvent.wVirtualKeyCode)
					{
					case VK_RETURN:         // 按回车时跳到下一行
						printf("\n");
						break;

					case VK_SPACE:          // 按空格时输出一个空格
						printf(" ");
						break;


					default:
						break;
					}
				// -- 打印字符
				c = inRec.Event.KeyEvent.uChar.AsciiChar;

				// 输出可以打印的字符（详参ASCII表）
				if (c > 0x20 && c < 0x7e)
				{
					loadprocess();
					mode = MODE4;
				}
				break;
			}
			if (fff == 1) {
				PrintChar("│", 2, 35, 9);
				delay(1);
				PrintChar(" ", 2, 35, 9);
				delay(1);
			}
			break;
		case MODE4:						//qtime //5.6.7对应打开各文件
			switch (inRec.EventType)
			{
			case MOUSE_EVENT:
			{
				if (inRec.Event.MouseEvent.dwButtonState) {
					pos = inRec.Event.MouseEvent.dwMousePosition; //
					Y = (int)pos.Y;								//
					X = (int)pos.X;			//
					rt = input(X, Y);
					switch (rt) {
					case 0:
						del = 0;
						::qdep = -1;
						page4 = 1;
						ClearScreen();
						qtime(0);
						mode = MODE4;
						break;
					case 1:
						del = 0;
						page4 = 1;
						ClearScreen();
						qdepartment(0);
						mode = MODE5;
						break;
					case 2:
						del = 0;
						::qdep = -1;
						page4 = 1;
						ClearScreen();
						qpos();
						mode = MODE6;
						break;
					case 3:
						del = 0;
						page4 = 1;
						ClearScreen();
						qcount();
						mode = MODE7;
						break;
					case 4:
						del = 0;
						::qdep = -1;
						page4 = 1;
						ClearScreen();
						qhelp();
						mode = MODE10;
						break;
					case 5:
						del = 1;
						xxxdata= 3 * (page4 - 1) + del - 1;
						index.data = 3 * (page4 - 1) + del - 1;
						index.flag = 1;
						ClearScreen();
						renew(argv);
						openfile(3*(page4-1)+del-1);
						if (::qdep == -1) {
							showlist(0);
							background22(2);
						}
						else {
							showlist(0,::qdep);
						}
						background2(2);
						mode=MODE8;
						break;
					case 6:
						del = 2;
						xxxdata = 3 * (page4 - 1) + del - 1;
						index.data = 3 * (page4 - 1) + del - 1;
						index.flag = 1;
						ClearScreen();
						renew(argv);
						openfile(3 * (page4 - 1) + del - 1);
						if (::qdep == -1) {
							showlist(0);
							background22(2);
						}
						else {
							showlist(0, ::qdep);
						}
						background2(2);
						mode = MODE8;
						break;
					case 7:
						del = 3;
						xxxdata = 3 * (page4 - 1) + del - 1;
						index.data = 3 * (page4 - 1) + del - 1;
						index.flag = 1;
						ClearScreen();
						renew(argv);
						openfile(3 * (page4 - 1) + del - 1);
						if (::qdep == -1) {
							showlist(0);
							background22(2);
						}
						else {
							showlist(0, ::qdep);
						}
						background2(2);
						mode = MODE8;
						break;
					case 8:
						--page4;
						ClearScreen();
						qtime(page4 - 1);
						mode = MODE4;
						break;
					case 9:
						++page4;
						ClearScreen();
						qtime(page4 - 1);
						mode = MODE4;
						break;
					}
				}
			}
			break;
			}
			break;
		case MODE5:				//qdepartment
			switch (inRec.EventType)
			{
			case MOUSE_EVENT:
			{
				if (inRec.Event.MouseEvent.dwButtonState) {
					pos = inRec.Event.MouseEvent.dwMousePosition; //
					Y = (int)pos.Y;								//
					X = (int)pos.X;			//
					rt = input(X, Y);
					switch (rt) {
					case 0:
						del = 0;
						::qdep = -1;
						page5 = 1;
						index.data = 0;
						index.flag = 0;
						ClearScreen();
						page = 0;
						qtime(0);
						mode = MODE4;
						break;
					case 1:
						del = 0;
						::qdep = -1;
						page5 = 1;
						index.data = 0;
						index.flag = 0;
						ClearScreen();
						page = 0;
						qdepartment(0);
						mode = MODE5;
						break;
					case 3:
						del = 0;
						page5 = 1;
						index.data = 0;
						index.flag = 0;
						ClearScreen();
						qcount();
						mode = MODE7;
						break;
					case 4:
						del = 0;
						::qdep = -1;
						page5 = 1;
						index.data = 0;
						index.flag = 0;
						ClearScreen();
						qhelp();
						mode = MODE10;
						break;
					case 5:
						del = 1;
						::qdep = 3 * (page5 - 1) + del - 1;
						if (index.flag) {
							index.department = 3 * (page5 - 1) + del - 1;
							ClearScreen();
							background(2);
							background10(2);
							background11(2);
							mode = MODE9;
						}
						else {
							ClearScreen();
							qtime(0);
							mode = MODE4;
						}
						break;
					case 6:
						del = 2;
						::qdep = 3 * (page5 - 1) + del - 1;
						if (index.flag) {
							index.department = 3 * (page5 - 1) + del - 1;
							ClearScreen();
							background(2);
							background10(2);
							background11(2);
							mode = MODE9;
						}
						else {
							ClearScreen();
							qtime(0);
							mode = MODE4;
						}
						break;
					case 7:
						del = 3;
						::qdep = 3 * (page5 - 1) + del - 1;
						if (index.flag) {
							index.department = 3 * (page5 - 1) + del - 1;
							ClearScreen();
							background(2);
							background10(2);
							background11(2);
							mode = MODE9;
						}
						else {
							ClearScreen();
							qtime(0);
							mode = MODE4;
						}
						break;
					case 8:
						--page5;
						ClearScreen();
						qdepartment(page5 - 1);
						mode = MODE5;
						break;
					case 9:
						++page5;
						ClearScreen();
						qdepartment(page5 - 1);
						mode = MODE5;
						break;
					}
				}
			}
			break;
			}
			break;
		case MODE7:				//qcount
			switch (inRec.EventType)
			{
			case MOUSE_EVENT:
			{
				if (inRec.Event.MouseEvent.dwButtonState) {
					pos = inRec.Event.MouseEvent.dwMousePosition; //
					Y = (int)pos.Y;								//
					X = (int)pos.X;			//
					rt = input(X, Y);
					switch (rt) {
					case 0:
						ClearScreen();
						qtime(page);
						mode = MODE4;
						break;
					case 1:
						ClearScreen();
						qdepartment(0);
						mode = MODE5;
						break;
					case 2:
						ClearScreen();
						qpos();
						mode = MODE6;
						break;
					case 3:
						ClearScreen();
						qcount();
						mode = MODE7;
						break;
					case 4:
						ClearScreen();
						qhelp();
						mode = MODE10;
						break;
					case 6:
						if (xxxdata != -1&&::qdep!=-1) {
							ClearScreen();
							departmentwages(worker::dep[qdep]);
							background(2);
							mode = MODE7;
						}
						else {
							ClearScreen();
							qcount();
							mode = MODE7;
							PrintChar("请先选择日期和部门.", sizeof("请先选择日期和部门."), 25, 1);
						}
						break;
					case 7:
						if (xxxdata != -1) {
							ClearScreen();
							allmenwages();
							background(2);
							mode = MODE7;
						}
						else {
							ClearScreen();
							qcount();
							mode = MODE7;
							PrintChar("请先选择日期和部门.", sizeof("请先选择日期和部门."), 25,  1);
						}
						break;
					}
				}
			}
			}
			break;
		case MODE8:
			switch (inRec.EventType)
			{
			case MOUSE_EVENT:
			{
				if (inRec.Event.MouseEvent.dwButtonState) {
					pos = inRec.Event.MouseEvent.dwMousePosition; //
					Y = (int)pos.Y;								//
					X = (int)pos.X;			//
					rt = input(X, Y);
					switch (rt) {
					case 0:
						fltell = 0;
						mmm = 0;
						page88 = 0;
						::qdep = -1;
						page8 = 1;
						index.data = 0;
						index.flag = 0;
						ClearScreen();
						qtime(page);
						mode = MODE4;
						break;
					case 1:
						fltell = 0;
						mmm = 0;
						page88 = 0;
						::qdep = -1;
						page8 = 1;
						index.data = 0;
						index.flag = 0;
						ClearScreen();
						qdepartment(0);
						mode = MODE5;
						break;
					case 2:
						fltell = 0;
						mmm = 0;
						page88 = 0;
						::qdep = -1;
						page8 = 1;
						index.data = 0;
						index.flag = 0;
						ClearScreen();
						qpos();
						mode = MODE6;
						break;
					case 3:
						fltell = 0;
						mmm = 0;
						page88 = 0;
						::qdep = -1;
						page8 = 1;
						index.data = 0;
						ClearScreen();
						qcount();
						mode = MODE7;
						break;
					case 4:
						fltell = 0;
						mmm = 0;
						page88 = 0;
						::qdep = -1;
						page8 = 1;
						index.data = 0;
						index.flag = 0;
						ClearScreen();
						qhelp();
						mode = MODE10;
						break;
					case 16:
						--page8;
						ClearScreen();
						showlist(page8 - 1);
						mode = MODE8;
						break;
					case 17:
						++page8;
						ClearScreen();
						showlist(page8 - 1);
						mode = MODE8;
						break;
					case 18:
						page8 = 1;
						ClearScreen();
						showlist(page8 - 1);
						mode = MODE8;
					case 19:
						page8 = 1 + worker::people.size() / 3;
						ClearScreen();
						showlist(page8 - 1);
						mode = MODE8;
					case 20:
						::qdep = -1;
						page8 = 1;
						ClearScreen();
						qdepartment(0);
						mode = MODE5;
						break;
					case 25:
						idsort(::qdep);
						ClearScreen();
						background2(2);
						showlist(page8 - 1);
						mode = MODE8;
						break;
					case 26:
						namesort(::qdep);
						ClearScreen();
						background2(2);
						showlist(page8 - 1);
						mode = MODE8;
						break;
					case 27:
						possort(::qdep);
						ClearScreen();
						background2(2);
						showlist(page8 - 1);
						mode = MODE8;
						break;
					case 28:
						wagessort(::qdep);
						ClearScreen();
						background2(2);
						showlist(page8 - 1);
						mode = MODE8;
						break;
					case 29:
						departmentsort(::qdep);
						ClearScreen();
						background2(2);
						showlist(page8 - 1);
						mode = MODE8;
						break;


					case 6:
						ClearScreen();
						background7(2);
						del = 1;
						background(2);
						page88 = 1;
						worker::people[(page8 - 1) * 3 + del - 1]->privateprint(0);
						sss(page88);
						mode = MODE8;
						break;
					case 7:
						ClearScreen();
						background7(2);
						del = 2;
						background(2);
						page88 = 1;
						worker::people[(page8 - 1) * 3 + del - 1]->privateprint(0);
						sss(page88);
						mode = MODE8;
						break;
					case 8:
						ClearScreen();
						background7(2);
						del = 3;
						background(2);
						page88 = 1;
						worker::people[(page8 - 1) * 3 + del - 1]->privateprint(0);
						sss(page88);
						mode = MODE8;
						break;
					case 9:
						ClearScreen();
						background7(2);
						del = 4;
						background(2);
						page88 = 1;
						worker::people[(page8 - 1) * 3 + del - 1]->privateprint(0);
						sss(page88);
						mode = MODE8;
						break;
					case 10:
						ClearScreen();
						background7(2);
						del = 5;
						background(2);
						page88 = 1;
						worker::people[(page8 - 1) * 3 + del - 1]->privateprint(0);
						sss(page88);
						mode = MODE8;
						break;
					case 11:
						ClearScreen();
						background7(2);
						del = 6;
						background(2);
						page88 = 1;
						worker::people[(page8 - 1) * 3 + del - 1]->privateprint(0);
						sss(page88);
						mode = MODE8;
						break;
					case 12:
						ClearScreen();
						background7(2);
						del = 7;
						background(2);
						page88 = 1;
						worker::people[(page8 - 1) * 3 + del - 1]->privateprint(0);
						sss(page88);
						mode = MODE8;
						break;
					case 13:
						ClearScreen();
						background7(2);
						del = 8;
						background(2);
						page88 = 1;
						worker::people[(page8 - 1) * 3 + del - 1]->privateprint(0);
						sss(page88);
						mode = MODE8;
						break;
					case 14:
						ClearScreen();
						background7(2);
						del = 9;
						background(2);
						page88 = 1;
						worker::people[(page8 - 1) * 3 + del - 1]->privateprint(0);
						sss(page88);
						mode = MODE8;
						break;




					case 34:
						ClearScreen();
						background8(2);
						background(2);
						page88 = 2;
						if (!mmm) {
							worker::people[(page8 - 1) * 3 + del - 1]->privateprint(1);
						}
						else {
							if (!worker::FINDID.empty()) {
								worker::FINDID[0]->privateprint(1);
							}
							if (!worker::FINDNAME.empty()) {
								worker::FINDNAME[0]->privateprint(1);
							}
						}
						sss(page88);
						mode = MODE8;
						break;
					case 35:
						ClearScreen();
						background7(2);
						background(2);
						page88 = 1;
						if (!mmm) {
						worker::people[(page8 - 1) * 3 + del - 1]->privateprint(0);
						}
						else {
							if (!worker::FINDID.empty()) {
								worker::FINDID[0]->privateprint(0);
							}
							if (!worker::FINDNAME.empty()) {
								worker::FINDNAME[0]->privateprint(0);
							}
						}
						sss(page88);
						mode = MODE8;
						break;
					case 36:
						page88 = 0;
						mmm = 0;
						ClearScreen();
						background2(2);
						showlist(page8 - 1);
						mode = MODE8;
						break;


					case 40:	
						fltell = 1;
						del = 1;
						ClearScreen();
						showlist(page8 - 1);
						background9();
						mode = MODE8;
						break;
					case 41:
						fltell = 1;
						del = 2;
						ClearScreen();
						showlist(page8 - 1);
						background9();
						mode = MODE8;
						break;
					case 42:
						fltell = 1;
						del = 3;
						ClearScreen();
						showlist(page8 - 1);
						background9();
						mode = MODE8;
						break;
					case 43:
						fltell = 1;
						del = 4;
						ClearScreen();
						showlist(page8 - 1);
						background9();
						mode = MODE8;
						break;
					case 44:
						fltell = 1;
						del = 5;
						ClearScreen();
						showlist(page8 - 1);
						background9();
						mode = MODE8;
						break;
					case 45:
						fltell = 1;
						del = 6;
						ClearScreen();
						showlist(page8 - 1);
						background9();
						mode = MODE8;
						break;
					case 46:
						fltell = 1;
						del = 7;
						ClearScreen();
						showlist(page8 - 1);
						background9();
						mode = MODE8;
						break;
					case 47:
						fltell = 1;
						del = 8;
						ClearScreen();
						showlist(page8 - 1);
						background9();
						mode = MODE8;
						break;
					case 48:
						fltell = 1;
						del = 9;
						ClearScreen();
						showlist(page8 - 1);
						background9();
						mode = MODE8;
						break;



					case 50:
						deleteone((page8 - 1) * 3 + del - 1,index.data,argv);
						page8 = 1;
						fltell = 0;
						del = 0;
						page88 = 0;
						mmm = 0;
						::qdep = -1;
						ClearScreen();
						showlist(page8 - 1);
						background2(2);
						mode = MODE8;
						break;
					case 51:
						xxxnum = (page8 - 1) * 3 + del - 1;
						ClearScreen();
						background(2);
						background10(2);
						background11(2);
						worker::people[(page8 - 1) * 3 + del - 1]->coo();
						mode = MODE9;
						break;
					case 52:
						fltell = 0;
						page88 = 0;
						mmm = 0;
						del = 0;
						::qdep = -1;
						ClearScreen();
						background2(2);
						showlist(page8 - 1);
						mode = MODE8;
						break;
					case 53:
						fltell = 0;
						page88 = 0;
						mmm = 0;
						::qdep = -1;
						page8 = 1;
						index.data = 0;
						index.flag = 0;
						ClearScreen();
						qtime(page);
						mode = MODE4;
						break;
					case 60:
						mmm = mouseprocess9();
						if(mmm==0)
							MessageBox(hwnd, TEXT("查无此人."), TEXT("请重新输入"), 0);
						else {
							if (!worker::FINDID.empty()) {
								page88 = 1;
								worker::FINDID[0]->privateprint(0);
							}
							if (!worker::FINDNAME.empty()) {
								page88 = 1;
								worker::FINDNAME[0]->privateprint(0);
							}
						}
						mode = MODE8;
						break;
					}
				}
			}
			break;
			}
		break;


		case MODE9:		//添加员工
			switch (inRec.EventType)
			{
			case MOUSE_EVENT:
			{
				if (inRec.Event.MouseEvent.dwButtonState) {
					pos = inRec.Event.MouseEvent.dwMousePosition; //
					Y = (int)pos.Y;								//
					X = (int)pos.X;			//
					rt = input(X, Y);
					switch (rt) {
					case 0:
						xxxnum = -1;
						index.data = 0;
						index.department = 0;
						index.flag = 0;
						ClearScreen();
						page = 0;
						qtime(0);
						mode = MODE4;
						break;
					case 1:
						xxxnum = -1;
						index.data = 0;
						index.department = 0;
						index.flag = 0;
						ClearScreen();
						page = 0;
						qdepartment(0);
						mode = MODE5;
						break;
					case 2:
						xxxnum = -1;
						index.data = 0;
						index.department = 0;
						index.flag = 0;
						ClearScreen();
						qpos();
						mode = MODE6;
						break;
					case 3:
						xxxnum = -1;
						index.data = 0;
						index.department = 0;
						index.flag = 0;
						ClearScreen();
						qcount();
						mode = MODE7;
						break;
					case 4:
						xxxnum = -1;
						index.data = 0;
						index.department = 0;
						index.flag = 0;
						ClearScreen();
						qhelp();
						mode = MODE10;
						break;


					case 10:	//姓名
						word[0] = mouseprocess1();
						/*
						xx=fn(word[0]);
						if (xx == 1) {
							MessageBox(hwnd, TEXT("输入名字有重复."), TEXT("请重新输入"), 0);
							ClearScreen();
							index.department = 0;
							qdepartment(0);
							mode = MODE5;
						}
						*/
						//寻找是否有同名然后处理id问题
						break;
					case 11:	//生日
						word[1] = mouseprocess2();
						deal = atoi(word[1].c_str());
						for (int i = 0, temp = deal; temp != 0; i++, temp /= 10)
							mo++;
						if (mo == 8)
							//处理跳出
							for (; mo != 0; ) {
								if (mo > 6) {
									day = deal % 100;
									deal /= 100;
									mo -= 2;
								}
								if (mo > 4 && mo <= 6) {
									month = deal % 100;
									deal /= 100;
									mo -= 2;
								}
								if (mo >= 0 && mo <= 4) {
									year = deal % 10000;
									deal /= 10000;
									mo -= 4;
								}
							}
						break;
					case 12:	//性别
						word[2] = mouseprocess3();
						if (word[2] != "男" || word[2] != "女")
							fl = 0;
						break;
					case 13:	//岗位
						word[4] = mouseprocess4();
						if (worker::departmentpeople[word[4]] > 1) {
							fl = 0;
							break;
						}
						for (auto &b : worker::post) {
							if (word[4] == b) {
								if (word[4] == "经理")
									fl = MANAGER;
								if (word[4] == "销售经理")
									fl = SALESMANAGER;
								if (word[4] == "技术员")
									fl = TECHNICIAN;
								if (word[4] == "销售员")
									fl = SALESMAN;
								break;
							}
							else
								fl = 0;
						}
						break;
					case 15:	//工作时长,销售额
						word[5] = mouseprocess5();
						break;
					case 16:
						if (xxxnum == -1) {
							if (fl == 0) {
								MessageBox(hwnd, TEXT("输入职位信息有误."), TEXT("请重新输入"), 0);
								ClearScreen();
								index.department = 0;
								qdepartment(0);
								mode = MODE5;
							}
							else
							{
								std::vector<std::shared_ptr<worker>>hhh;
								word[3] = worker::dep[index.department];
								switch (fl) {
								case MANAGER:
									p = std::make_shared<manager>((int)(MANAGER*pow(10, 6)) + worker::allmen + 1, word[0], word[2], word[3], day, month, year);
									worker::people.push_back(p);
									break;
								case SALESMANAGER:
									p = std::make_shared<salesmanager>((int)(SALESMANAGER*pow(10, 6)) + worker::allmen + 1, word[0], word[2], word[3], day, month, year);
									worker::departmentsalesmanager[word[3]]++;
									hhh.push_back(p);
									worker::people.push_back(p);
									break;
								case TECHNICIAN:
									p = std::make_shared<techman>((int)(TECHNICIAN*pow(10, 6)) + worker::allmen + 1, word[0], word[2], word[3], day, month, year, atoi(word[5].c_str()));
									worker::people.push_back(p);
									break;
								case SALESMAN:
									p = std::make_shared<salesman>((int)(SALESMAN*pow(10, 6)) + worker::allmen + 1, word[0], word[2], word[3], day, month, year, atoi(word[5].c_str()));
									std::dynamic_pointer_cast<salesman>(p)->setcurwages();
									worker::people.push_back(p);
									break;
								}
								for(auto x:hhh){
									x->renewsalesmanager();
								}

								savefile(index.data);
								for (int i = 0; i < 6; i++)
									word[i]="";
								MessageBox(hwnd, TEXT("恭喜你添加成功."), TEXT(""), 0);
							}
						}
						else {
							std::vector<std::shared_ptr<worker>>hhh;
							if (word[0].empty())
								word[0] = worker::people[xxxnum]->getname();
							if (word[1].empty()) {
								day = (worker::people[xxxnum]->getbirth()).day;
								month = (worker::people[xxxnum]->getbirth()).month;
								year = (worker::people[xxxnum]->getbirth()).year;
							}
							if (word[2].empty())
								word[2] = worker::people[xxxnum]->getsex();
							if (index.department==0)
								word[3] = worker::people[xxxnum]->getdepartment();
							if (word[4].empty())
								word[4] = worker::people[xxxnum]->getpos();
							if (word[5].empty()) {
								char a[20];
								if (worker::people[xxxnum]->getpos() == std::string("技术员"))
									itoa(worker::people[xxxnum]->getworktime(), a, 10);
								if (worker::people[xxxnum]->getpos() == std::string("销售员"))
									itoa(worker::people[xxxnum]->getworktime(), a, 10);
								word[5] = a;
							}
							for (auto &b : worker::post) {
								if (word[4] == b) {
									if (word[4] == "经理")
										fl = MANAGER;
									if (word[4] == "销售经理")
										fl = SALESMANAGER;
									if (word[4] == "技术员")
										fl = TECHNICIAN;
									if (word[4] == "销售员")
										fl = SALESMAN;
									break;
								}
							}
								switch (fl) {
								case MANAGER:
									p = std::make_shared<manager>((int)(MANAGER*pow(10, 6)) + worker::allmen + 1, word[0], word[2], word[3], day, month, year);
									worker::people.push_back(p);
									break;
								case SALESMANAGER:
									p = std::make_shared<salesmanager>((int)(SALESMANAGER*pow(10, 6)) + worker::allmen + 1, word[0], word[2], word[3], day, month, year);
									worker::departmentsalesmanager[word[3]]++;
									hhh.push_back(p);
									worker::people.push_back(p);
									break;
								case TECHNICIAN:
									p = std::make_shared<techman>((int)(TECHNICIAN*pow(10, 6)) + worker::allmen + 1, word[0], word[2], word[3], day, month, year, atoi(word[5].c_str()));
									worker::people.push_back(p);
									break;
								case SALESMAN:
									p = std::make_shared<salesman>((int)(SALESMAN*pow(10, 6)) + worker::allmen + 1, word[0], word[2], word[3], day, month, year, atoi(word[5].c_str()));
									std::dynamic_pointer_cast<salesman>(p)->setcurwages();
									worker::people.push_back(p);
									break;
								}
								deleteone(xxxnum, xxxdata, argv);
								for (auto x : hhh) {
									x->renewsalesmanager();
								}
								MessageBox(hwnd, TEXT("修改成功."), TEXT(""), 0);
								index.data = 0;
								index.department = 0;
								index.flag = 0;
								fltell = 0;
								ClearScreen();
								page = 0;
								qtime(0);
								mode = MODE4;
						}
						break;
					case 17://返回
						xxxnum = -1;
						ClearScreen();
						index.department = 0;
						qdepartment(0);
						mode = MODE5;
						break;

					}
				}
			}
			break;
			}
			break;
			
		case MODE10:	//qhelp
			switch (inRec.EventType)
			{
			case MOUSE_EVENT:
			{
				if (inRec.Event.MouseEvent.dwButtonState) {
					pos = inRec.Event.MouseEvent.dwMousePosition; //
					Y = (int)pos.Y;								//
					X = (int)pos.X;			//
					rt = input(X, Y);
					switch (rt) {
					case 0:
						ClearScreen();
						qtime(page);
						mode = MODE4;
						break;
					case 1:
						ClearScreen();
						qdepartment(0);
						mode = MODE5;
						break;
					case 2:

						ClearScreen();
						qpos();
						mode = MODE6;
						break;
					case 3:

						ClearScreen();
						qcount();
						mode = MODE7;
						break;
					case 4:

						ClearScreen();
						qhelp();
						mode = MODE10;
						break;
					case 8:		//退出系统

						ClearScreen();
						exitsys();
						break;
					case 7:		//增加部门

						ClearScreen();
						background(2);
						background6(2);
						mode=MODE14;
						break;
					case 6:		//管理月份

						ClearScreen();
						background(2);
						background5(2);
						mode = MODE17;
						break;
					case 5:		//输入信息用

						ClearScreen();
						background(2);
						background4(2);
						mode = MODE19;
						break;
					}
				}
			}
			break;
			}
			break;

		case MODE11:
			switch (inRec.EventType)
			{
			case MOUSE_EVENT:
			{
				if (inRec.Event.MouseEvent.dwButtonState) {
					pos = inRec.Event.MouseEvent.dwMousePosition; //
					Y = (int)pos.Y;								//
					X = (int)pos.X;			//
					rt = input(X, Y);
					switch (rt) {
					case 0:
						ClearScreen();
						qtime(page);
						mode = MODE4;
						break;
					case 1:
						ClearScreen();
						qdepartment(0);
						mode = MODE5;
						break;
					case 2:

						ClearScreen();
						qpos();
						mode = MODE6;
						break;
					case 3:

						ClearScreen();
						qcount();
						mode = MODE7;
						break;
					case 4:

						ClearScreen();
						qhelp();
						mode = MODE10;
						break;
					case 5:
						break;
					}
				}
			}
			break;
			}
			break;

		case MODE12:
			switch (inRec.EventType)
			{
			case MOUSE_EVENT:
			{
				if (inRec.Event.MouseEvent.dwButtonState) {
					pos = inRec.Event.MouseEvent.dwMousePosition; //
					Y = (int)pos.Y;								//
					X = (int)pos.X;			//
					rt = input(X, Y);
					switch (rt) {
					case 0:
						ClearScreen();
						qtime(page);
						mode = MODE4;
						break;
					case 1:
						ClearScreen();
						qdepartment(0);
						mode = MODE5;
						break;
					case 2:

						ClearScreen();
						qpos();
						mode = MODE6;
						break;
					case 3:

						ClearScreen();
						qcount();
						mode = MODE7;
						break;
					case 4:

						ClearScreen();
						qhelp();
						mode = MODE10;
						break;

					}
				}
			}
			break;
			}
			break;

		case MODE13:		//动态添加部门
			switch (inRec.EventType)
			{
			case MOUSE_EVENT:
			{
				if (inRec.Event.MouseEvent.dwButtonState) {
					pos = inRec.Event.MouseEvent.dwMousePosition; //
					Y = (int)pos.Y;								//
					X = (int)pos.X;			//
					rt = input(X, Y);
					switch (rt) {
					case 0:
						ClearScreen();
						qtime(page);
						mode = MODE4;
						break;
					case 1:
						ClearScreen();
						qdepartment(0);
						mode = MODE5;
						break;
					case 2:

						ClearScreen();
						qpos();
						mode = MODE6;
						break;
					case 3:

						ClearScreen();
						qcount();
						mode = MODE7;
						break;
					case 4:

						ClearScreen();
						qhelp();
						mode = MODE10;
						break;
					case 5:
						background12(2);
						ShowCursor();
						PrintChar("         ", 10, 45, 12);
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 45,12 });
						newdepartment = mouseprocess6();
						flag = mouseprocess7(newdepartment);
						if (flag == 0) {
							ClearScreen();
							background(2);
							background6(2);
							mode = MODE14;
						}
						break;
					case 6:
						if (flag == 1) {
							worker::dep.push_back(newdepartment);
							savedepartment();
							renewdepartment();
							MessageBox(hwnd, TEXT("新增部门成功."), TEXT(""), 0);
						}
						ClearScreen();
						qhelp();
						mode = MODE10;
						break;
					case 7:
						ClearScreen();
						background(2);
						background6(2);
						mode = MODE14;
						break;
					}
				}
			}
			break;
			}
			break;
			break;
		case MODE14:		//选择部门方式
			switch (inRec.EventType)
			{
			case MOUSE_EVENT:
			{
				if (inRec.Event.MouseEvent.dwButtonState) {
					pos = inRec.Event.MouseEvent.dwMousePosition; //
					Y = (int)pos.Y;								//
					X = (int)pos.X;			//
					rt = input(X, Y);
					switch (rt) {
					case 0:
						page14 = 1;
						ClearScreen();
						qtime(page);
						mode = MODE4;
						break;
					case 1:
						page14 = 1;
						ClearScreen();
						qdepartment(0);
						mode = MODE5;
						break;
					case 2:
						page14 = 1;
						ClearScreen();
						qpos();
						mode = MODE6;
						break;
					case 3:
						page14 = 1;
						ClearScreen();
						qcount();
						mode = MODE7;
						break;
					case 4:
						page14 = 1;
						ClearScreen();
						qhelp();
						mode = MODE10;
						break;

					case 5:
						ClearScreen();
						background(2);
						background12(2);
						mode = MODE13;
						break;
					case 6:
						ClearScreen();
						qdepartment(0);
						mode = MODE15;
						break;

					}
				}
			}
			break;
			}
			break;
		case MODE15:		//动态删除部门
			switch (inRec.EventType)
			{
			case MOUSE_EVENT:
			{
				if (inRec.Event.MouseEvent.dwButtonState) {
					pos = inRec.Event.MouseEvent.dwMousePosition; //
					Y = (int)pos.Y;								//
					X = (int)pos.X;			//
					rt = input(X, Y);
					switch (rt) {
					case 0:
						del = 0;
						ClearScreen();
						page14 = 1;
						qtime(0);
						mode = MODE4;
						break;
					case 1:
						del = 0;
						ClearScreen();
						page14 = 1;
						qdepartment(0);
						mode = MODE5;
						break;
					case 2:
						del = 0;
						page14 = 1;
						ClearScreen();
						qpos();
						mode = MODE6;
						break;
					case 3:
						del = 0;
						page14 = 1;
						ClearScreen();
						qcount();
						mode = MODE7;
						break;
					case 4:
						del = 0;
						page14 = 1;
						ClearScreen();
						qhelp();
						mode = MODE10;
						break;
					case 5:
						del = 1;
						break;
					case 6:
						del = 2;
						break;
					case 7:
						del = 3;
						break;
					case 8:
						--page14;
						ClearScreen();
						qdepartment(page14-1);
						mode = MODE15;
						break;
					case 9:
						++page14;
						ClearScreen();
						qdepartment(page14-1);
						mode = MODE15;
						break;
					case 10:
						ClearScreen();
						for (auto& x : worker::dep) {
							if (x == worker::dep[worker::dep.size() - (page14 - 1) * 3 - del])
								continue;
							temp.push_back(x);
						}
						worker::dep.swap(std::vector<std::string>(temp));
						savedepartment();	
						renewdepartment();
						MessageBox(hwnd, TEXT("删除部门成功."), TEXT(""), 0);
						qhelp();
						mode = MODE10;
						break;
					case 11:
						ClearScreen();
						qdepartment(page14 - 1);
						mode = MODE15;
						break;
					}
				}
			}
			break;
			}
			break;

		case MODE17:
			switch (inRec.EventType)
			{
			case MOUSE_EVENT:
			{
				if (inRec.Event.MouseEvent.dwButtonState) {
					pos = inRec.Event.MouseEvent.dwMousePosition; //
					Y = (int)pos.Y;								//
					X = (int)pos.X;			//
					rt = input(X, Y);
					switch (rt) {
					case 0:
						ClearScreen();
						qtime(page);
						mode = MODE4;
						break;
					case 1:
						ClearScreen();
						qdepartment(0);
						mode = MODE5;
						break;
					case 2:

						ClearScreen();
						qpos();
						mode = MODE6;
						break;
					case 3:

						ClearScreen();
						qcount();
						mode = MODE7;
						break;
					case 4:

						ClearScreen();
						qhelp();
						mode = MODE10;
						break;

					case 5:
						ClearScreen();
						background(2);
						background13(2);
						mode = MODE18;
						break;
					case 6:
						ClearScreen();
						qtime(0);
						mode = MODE16;
						break;

					}
				}
			}
			break;
			}
			break;

		case MODE18:
			switch (inRec.EventType)
			{
			case MOUSE_EVENT:
			{
				if (inRec.Event.MouseEvent.dwButtonState) {
					pos = inRec.Event.MouseEvent.dwMousePosition; //
					Y = (int)pos.Y;								//
					X = (int)pos.X;			//
					rt = input(X, Y);
					switch (rt) {
					case 0:
						ClearScreen();
						qtime(0);
						mode = MODE4;
						break;
					case 1:
						ClearScreen();
						qdepartment(0);
						mode = MODE5;
						break;
					case 2:

						ClearScreen();
						qpos();
						mode = MODE6;
						break;
					case 3:

						ClearScreen();
						qcount();
						mode = MODE7;
						break;
					case 4:

						ClearScreen();
						qhelp();
						mode = MODE10;
						break;
					case 5:
						background13(2);
						ShowCursor();
						PrintChar("         ", 10, 45, 12);
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 45,12 });
						std::cin.clear();	// 重置 cin 输入状态
						std::cin.sync();	// 清除 cin 缓冲区未读取信息
						getline(std::cin, newdata);
						flag = mouseprocess8(newdata);
						if (flag == 0) {
							ClearScreen();
							background(2);
							background5(2);
							mode = MODE17;
						}
						break;
					case 6:
						if (flag == 1) {
							worker::data.push_back(newdata);
							newdata = newdata + ".txt";
							adddata(newdata);
							renew(argv);
							MessageBox(hwnd, TEXT("新增月份成功."), TEXT(""), 0);
						}
						ClearScreen();
						qhelp();
						mode = MODE10;
						break;
					case 7:
						ClearScreen();
						background(2);
						background5(2);
						mode = MODE17;
						break;
					}
				}
			}
			break;
			}
			break;
			break;

		case MODE16:
			switch (inRec.EventType)
			{
			case MOUSE_EVENT:
			{
				if (inRec.Event.MouseEvent.dwButtonState) {
					pos = inRec.Event.MouseEvent.dwMousePosition; //
					Y = (int)pos.Y;								//
					X = (int)pos.X;			//
					rt = input(X, Y);
					switch (rt) {
					case 0:
						del = 0;
						page17 = 1;
						ClearScreen();
						qtime(0);
						mode = MODE4;
						break;
					case 1:
						del = 0;
						page17 = 1;
						ClearScreen();
						qdepartment(0);
						mode = MODE5;
						break;
					case 2:
						del = 0;
						page17 = 1;
						ClearScreen();
						qpos();
						mode = MODE6;
						break;
					case 3:
						del = 0;
						page17 = 1;
						ClearScreen();
						qcount();
						mode = MODE7;
						break;
					case 4:
						del = 0;
						page17 = 1;
						ClearScreen();
						qhelp();
						mode = MODE10;
						break;
					case 5:
						del = 1;
						break;
					case 6:
						del = 2;
						break;
					case 7:
						del = 3;
						break;
					case 8:
						--page17;
						ClearScreen();
						qtime(page17 - 1);
						mode = MODE15;
						break;
					case 9:
						++page17;
						ClearScreen();
						qtime(page17 - 1);
						mode = MODE15;
						break;
					case 10:
						ClearScreen();
						for (auto& x : worker::data) {
							if (x == worker::data[worker::data.size() - (page17 - 1) * 3 - del])
								continue;
							temp.push_back(x);
						}
						deletedata((worker::data[worker::data.size() - (page17 - 1) * 3 - del] + ".txt").c_str());
						worker::data.swap(std::vector<std::string>(temp));
						renew(argv);
						MessageBox(hwnd, TEXT("删除月份成功."), TEXT(""), 0);
						qhelp();
						mode = MODE10;
						break;
					case 11:
						ClearScreen();
						qtime(page17 - 1);
						mode = MODE17;
						break;
					}
				}
			}
			break;
			}
			break;



		case MODE19:		//选择导入数据方式
			switch (inRec.EventType)
			{
			case MOUSE_EVENT:
			{
				if (inRec.Event.MouseEvent.dwButtonState) {
					pos = inRec.Event.MouseEvent.dwMousePosition; //
					Y = (int)pos.Y;								//
					X = (int)pos.X;			//
					rt = input(X, Y);
					switch (rt) {
					case 0:
						ClearScreen();
						qtime(page);
						mode = MODE4;
						break;
					case 1:
						ClearScreen();
						qdepartment(0);
						mode = MODE5;
						break;
					case 2:

						ClearScreen();
						qpos();
						mode = MODE6;
						break;
					case 3:

						ClearScreen();
						qcount();
						mode = MODE7;
						break;
					case 4:

						ClearScreen();
						qhelp();
						mode = MODE10;
						break;

					case 5:
						break;
					case 6://批量导入
						break;

					}
				}
			}
			break;
			}
			break;
		case MODE20:		//对应打开相应月份文件可提供操作
			break;
		case MODE21:		//对应打开相应部门文件可提供操作
			break;
		case MODE22:		//
			break;


		}
	}
}



std::string mouseprocess1() {
	std::string word;
	std::cin.clear();	// 重置 cin 输入状态
	std::cin.sync();	// 清除 cin 缓冲区未读取信息

	ShowCursor();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 38,8 });
	PrintChar("      ", 7, 38, 8);
	getline(std::cin, word);
	HideCursor();
	return word;
}

std::string mouseprocess2() {
	std::string word;
	std::cin.clear();	// 重置 cin 输入状态
	std::cin.sync();	// 清除 cin 缓冲区未读取信息
	ShowCursor();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 61,8 });
	PrintChar("         ", 10, 61, 8);
	getline(std::cin, word);
	HideCursor();
	return word;
}

std::string mouseprocess3() {
	std::string word;
	std::cin.clear();	// 重置 cin 输入状态
	std::cin.sync();	// 清除 cin 缓冲区未读取信息
	ShowCursor();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 38,11 });
	PrintChar("         ", 10, 38, 11);
	getline(std::cin, word);
	HideCursor();
	return word;
}

std::string mouseprocess4() {
	std::string word;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 38,14 });
	PrintChar("         ", 10, 38, 14);
	std::cin.clear();	// 重置 cin 输入状态
	std::cin.sync();	// 清除 cin 缓冲区未读取信息
	ShowCursor();
	getline(std::cin, word);
	HideCursor();
	for (auto &b : worker::post) {
		if (word == b) {
			break;
		}
		if (word == "技术员") {
			PrintChar("-----------------------", 20, 53, 13);
			PrintChar("▏", 4, 53, 14);
			PrintChar("工作时长：", 10, 55, 14);
			PrintChar("▏", 2, 73, 14);
			PrintChar("-----------------------", 20, 53, 15);
		}
		if (word == "销售员") {
			PrintChar("-----------------------", 20, 53, 13);
			PrintChar("▏", 4, 53, 14);
			PrintChar("销售额：", 10, 55, 14);
			PrintChar("▏", 2, 73, 14);
			PrintChar("-----------------------", 20, 53, 15);
		}
	}
	return word;
}


std::string mouseprocess5() {
	std::string word;
	std::cin.clear();	// 重置 cin 输入状态
	std::cin.sync();	// 清除 cin 缓冲区未读取信息
	ShowCursor();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 65,14 });
	PrintChar("         ", 10, 65, 14);
	getline(std::cin, word);
	HideCursor();
	return word;
}


std::string mouseprocess6() {
	std::string newdepartment;
	std::cin.clear();	// 重置 cin 输入状态
	std::cin.sync();	// 清除 cin 缓冲区未读取信息
	getline(std::cin,newdepartment);
	return newdepartment;
}
bool mouseprocess7(std::string newdepartment) {
	HWND hwnd = FindWindow(TEXT("ConsoleWindowClass"), NULL);
	if (newdepartment.empty()) {
		MessageBox(hwnd, TEXT("输入内容为空,请重新输入."), TEXT(""), 0);
		return false;
	}
	else {
		for (auto &x : worker::dep) {
			if (newdepartment == x) {
				MessageBox(hwnd, TEXT("已经有相同部门,请重新输入."), TEXT(""), 0);
				return false;
			}
		}
	}
	return true;
}


bool mouseprocess8(std::string newdata) {
	HWND hwnd = FindWindow(TEXT("ConsoleWindowClass"), NULL);
	if (newdata.empty()) {
		MessageBox(hwnd, TEXT("输入内容为空,请重新输入."), TEXT(""), 0);
		return false;
	}
	else {
		if (newdata.size() !=std::string("201611").size()) {
			MessageBox(hwnd, TEXT("月份格式错误,请重新输入."), TEXT(""), 0);
			return false;
		}
		for (auto& x : worker::data) {
			if (newdata == x) {
				MessageBox(hwnd, TEXT("已经有相同月份,请重新输入."), TEXT(""), 0);
				return false;
			}
		}
	}
	return true;
}


bool mouseprocess9(void) {
	std::string name;
	ShowCursor();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 11,1 });
	getline(std::cin, name);
	if (worker::FINDNAME.empty())
		findname(name);
	else {
		std::vector<std::shared_ptr<worker>>().swap(worker::FINDNAME);
		findname(name);
	}
	if (worker::FINDID.empty())
		findid(atoi(name.c_str()));
	else {
		std::vector<std::shared_ptr<worker>>().swap(worker::FINDNAME);
		findid(atoi(name.c_str()));
	}
	HideCursor();
	if (worker::FINDNAME.empty() || worker::FINDID.empty())
		return false;
	else
		return true;
}