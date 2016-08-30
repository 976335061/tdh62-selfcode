// 计算题.cpp : 定义控制台应用程序的入口点。
//
#include"stdafx.h"
#include "windows.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"
#include "conio.h"
#define cls system("cls")

//全局变量
struct ti {
	int t1;//1
	int flag;//+
	int t2;//1
	int ans;//2
	int times;
}t[10];
int right = 0, wrong = 0, point = 0;
//主界面
int showwelcome();

//主界面
int start();


//屏幕输出显示
int toshow(int a);

//出题
int ct();

//答题，（全局变量）
void check();

//给出得分
void repo1(int);

//给出评价，选择是否结束退出
int end();

//答题区题目显示
void sc(int a);

//光标移动
void gotoxy(int y, int x)
{
	COORD pos;
	pos.X = x - 1;
	pos.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//画框
void linef(int x1, int y1, int x2, int y2) {
	int i, slong;
	slong = y2 - y1 - 1;
	gotoxy(x1, y1 + 1);
	for (i = 0; i < slong; i++) {
		printf("-");
	}
	gotoxy(x2, y1 + 1);
	for (i = 0; i < slong; i++) {
		printf("-");
	}
	for (i = x1 + 1; i <= x2 - 1; i++) {
		gotoxy(i, y1);
		printf("|");
		gotoxy(i, y2);
		printf("|");
	}
}


int main()
{
	int t=1;
	while(t)
	{
		ct();
		showwelcome();
		start();
		check();
		t=end();
	}
	
	exit(0);
	return 0;
}

int showwelcome() {
	//设置标题，清屏，调整控制台大小，设置颜色
	system("title 计算题");
	cls;
	system("color f1");
	system("mode con cols=80 lines=35");
	//显示欢迎信息
	gotoxy(12, 30);
	printf("欢迎使用");
	Sleep(1000);
	return 0;
}

int ct() {
int i,a,b,c;
srand(time(0));//是用当前时间值作为随机数种子，任何随机数发生器都需要一个种子
i = 0;


while (i < 10)
{
	a = rand() % 51;//产生0~51的随机数
	b = rand() % 51;//产生0~51的随机数
	c = rand() % 2;//产生0~1的随机数
	if (c) {
		if (a + b <= 50) {
			t[i].t1 = a;
			t[i].t2 = b;
			t[i].flag = c;
			t[i].ans = (a+b);
			t[i].times = 0;
			i++;
		}
	}
	if (!c) {
		if (a - b > 0) {
			t[i].t1 = a;
			t[i].t2 = b;
			t[i].flag = c;
			t[i].ans = (a-b);
			t[i].times = 0;
			i++;
		}
	}
}
return 1;
}

int start() {
	int i,p;
	cls;
	linef(1, 1, 35, 30);
	
	linef(1, 31, 35,79);
	
	gotoxy(28, 32);
	for (i = 0; i < 47; i++) {
		printf("-");
	}
	
	gotoxy(1,8);
	printf("题目、小题分");
	gotoxy(1, 52);
	printf("作答");
	gotoxy(28, 52);
	printf("评分");
	for (i = 0,p=3; i < 10; i++,p+=3) {
	gotoxy(p, 6);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	char flag ;
	char step[10];
	if (t[i].flag == 1) {
		flag = '+';
	}
	else {
		flag = '-';
	}

	printf("%d %c %d  未作答", t[i].t1,flag/**/, t[i].t2);

	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	

	
	}
	gotoxy(30, 65);
	printf("答对   题");
	gotoxy(31, 65);
	printf("答错   题");
	gotoxy(32, 65);
	printf("得分   ");
//	gotoxy(33, 61);
//	printf("当前评价      ");
	gotoxy(8, 42);
	printf("题目：");//10,49
	gotoxy(11, 42);
	printf("你的回答：");//13,52
	//15,50
	gotoxy(20, 35);
	printf("每道题有 3 次作答机会");
	gotoxy(22, 35);
	printf("一次性答对得 10 分");
	gotoxy(23, 35);
	printf("第二次答对得 7 分");
	gotoxy(24, 35);
	printf("第三次答对得 5 分");

	return 1;
}

int toshow(int p) {
	int a;
	char flag;
	a = p;
	gotoxy(30, 69);
	printf(" ");
	gotoxy(31, 69);
	printf(" ");
	gotoxy(32, 71);
	printf("  ");
	p = 3 * (p+1);
	gotoxy(p,6);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	if (t[a].flag == 1) {
		flag = '+';
	}
	else {
		flag = '-';
	}
	printf("%d %c %d  已作答",t[a].t1,flag,t[a].t2);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);

	return 1;
}

void sc(int a) {
	char flag;
	gotoxy(8, 49);
	if (t[a].flag == 1) {
		flag = '+';
	}
	else {
		flag = '-';
	}
	printf("                   ");
	gotoxy(8, 49);
	printf("%d %c %d", t[a].t1, flag, t[a].t2);
	gotoxy(11,52);
	printf("     ");
	gotoxy(11,52);
}

void check()
 {
	int da,i;
	for(i=0;i<10;)
	{
		sc(i);
		scanf("%d",&da);
		if(t[i].ans==da)
		{
			toshow(i);
			right++;
			repo1(i);
			i++;		
		}
		else
		{
			gotoxy(15,48);
			printf("答错了,再来一次吧");
			gotoxy(11,52);
			printf("      ");
			gotoxy(11,52);
			(t[i].times)++;
			if(t[i].times==3)
			{	
				gotoxy(15,48);
				printf("                    ");
				toshow(i);
				wrong++;
				repo1(i);
				i++;
			}
		}
	}
}

void repo1(int i) {
	gotoxy(30, 70);
	printf("%d", right);
	gotoxy(31, 70);
	printf("%d", wrong);
	gotoxy(32, 71);
	switch(t[i].times)
	{
		case 0: point+=10;break;
		case 1: point+=7;break;
		case 2: point+=5;break;
	}
	printf("%d", point);
}


int end()
{
	char z,y='y';
	cls;
	linef(1, 1, 35,79);
	gotoxy(12,33);
	printf("本次测试的得分：%d",point);
	gotoxy(13,33);
	printf("共答对：%d",right);
	gotoxy(14,33);
	printf("共答错：%d",wrong);
	gotoxy(15,33);
	printf("你的评定：");
	switch((point<60)+(point<70)+(point<80)+(point<90))
	{
	case 0:printf("SMART!");break;
	case 1:printf("GOOD!");break;
	case 2:printf("OK");break;
	case 3:printf("PASS");break;
	case 4:printf("TRYAGAIN");break;
	}
	gotoxy(16,33);
	fflush(stdin);
	printf("是否要再来一次？(Y/N)");
	z = _getch();
	if(z=='y'||z=='Y')
		return 1;
	gotoxy(17,33);
		return 0;
}


