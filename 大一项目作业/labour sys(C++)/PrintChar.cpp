#include "public.h"
void PrintChar(char *ch, UINT count, UINT x, UINT y)  //在坐标(x,y)处输出字符串ch,ch里有count个字符
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	ULONG unuse;
	pos.X = x;
	pos.Y = y;
	CONSOLE_SCREEN_BUFFER_INFO bInfo; // 窗口缓冲区信息
	GetConsoleScreenBufferInfo(h, &bInfo);
	WriteConsoleOutputCharacterA(h, ch, count, pos, &unuse);
}
