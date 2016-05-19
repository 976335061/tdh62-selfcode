/*
方便自己编写程序的一些小东西
welcome里wtype=1--首次运行程序
wtpye!=1--重新加载欢迎页面
state（从checkstate设定）=1--没有录入学生信息
（从newstudentinfo设定）=2--刚刚重新录入了学生信息
传递给getchoose=1取得数字选择
=2取得是否选择返回1：是 返回2：否
（=3取得方向选择gotoxy（system.h））
welcome返回
1.学生信息表操作
11.重建、新建
12.增加
13.删除
2.成绩操作
21.录入全新成绩表
22.录入个人成绩
23.更改成绩
888.读取完整欢迎页面
999.程序出现关键错误
1000.应转到主菜单
*/

//头文件及一些声明
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "conio.h"
//函数声明
int clear();
int welcome(int wtype);
void outputline();
int checkstate();
int getchoose();
void mainpage();
int newstudent();
int newsocks();
int getsocks();
int getout();
//变量声明
static char emptyc=' ';
static int i,j,k,lastaddst=0;
static int choosetype,choose;//对于是否选择，选择1：是，选择2：否，
#define studentidlen 40
#define studentnamelen 20
//student infomation
struct student {
	char id[studentidlen];
	char name[studentnamelen];
}stu[100];
struct socks{
	int soc1;
	int soc2;
	int soc3;
}soc[100];


//End
//主函数，通过主函数实现主要功能
void main (){
	int st;
	clear();
	st = welcome(1);
	mainpage();

}
//欢迎屏幕
int welcome(int wtype){
	int state;
	if(wtype==1){
		SetConsoleTitle("学生成绩管理系统----by谭道桓");//通过Windows.h里的SetConsoleTitle设置标题
		clear();//清空屏幕
		printf("\n\n\n\n%28c欢迎使用学生成绩管理系统\n%33c设计：谭道桓\n%31c学号:201511106312\n\n%15c正在加载中",emptyc,emptyc,emptyc,emptyc);
		for(i=0;i<40;i++){
			Sleep(15);//Sleep3秒，确保之前内容没有快速被覆盖，之后清空屏幕
			for(j=0;j<i;j++){
				printf("#");
				}
			for(k=38-i;k>=0;k--){
				printf("-");
			}
			printf(">\r%15c正在加载中<",emptyc);
		}//造成真的在加载的错觉,日后增加文件操作可在这完成
		printf("\n%34c加载完成！\n",emptyc);
		Sleep(1500);
		clear();
	}//首次加载
	outputline();
	state=checkstate();
    system("color f9");//设定输出窗口颜色

	if(state==1){
		printf("你还没有录入任何学生信息，录入学生信息请输入Y或者直接按回车，坚持不录入学生信息请输入N\n注意：如果没有录入学生信息，之后部分功能将异常或无法使用。\n");
		choose=getchoose(2);//chooseose类型1：数字，类型2：是否
		if(choose==1){
			return 11;
		}
		else if(choose==2){
			return 888;
		}
		else {
		return 999;
		}
	}
	if(state==2){
		printf("你刚刚创建了学生信息表，马上录入成绩请输入Y或者直接按回车，不录入输入N\n");
		choose=getchoose(2);//chooseose类型1：数字，类型2：是否
		if(choose==1){
			return 21;
		}
		else if(choose==2){
			return 888;
		}
		else {
		return 999;
		}
	}
	if(wtype!=1){
	return 1000;
	}
	return 0;
}
//主界面处理


void mainpage(){
	char keyCode;
	int nowselect=1,q=1;
	for(;;){
			for(;;){
		clear();
		q=nowselect;
		if(q==1)
			printf("\n\n\n\t\t\t<---    1.录入学生信息\t--->\n\n\n");
		else
			printf("\n\n\n\t\t\t\t1.录入学生信息\n\n\n");
		if(q==2)
			printf("\t\t\t<---    2.输入学生成绩\t--->\n\n\n");
		else 
			printf("\t\t\t\t2.输入学生成绩\n\n\n");
		if(q==3)
			printf("\t\t\t<---    3.查看成绩\t--->\n\n\n");
		else 
			printf("\t\t\t\t3.查看成绩\n\n\n");
		if(q==4)
			printf("\t\t\t<---    4.查看统计报表\t--->\n\n\n");
		else
			printf("\t\t\t\t4.查看统计报表\n\n\n");
		if(q==0)
			printf("\t\t\t<---    0.退出程序\t--->\n\n\n");
		else
			printf("\t\t\t\t0.退出程序\n\n\n");
		printf("通过Tab和方向键可以轮换选择或直接输入数字，按下Enter来确认选择");
		fflush(stdin);
			keyCode=getch();
			if(keyCode==9){
				if(nowselect==4)
					nowselect=0;
				else
					nowselect=nowselect+1;
				}
			else if(keyCode==13){
				break;
			}
			else if(keyCode==-32){
				keyCode=getch();
				if(keyCode==72)
					if(nowselect==0)
						nowselect=4;
					else 
						nowselect=nowselect-1;
				if(keyCode==80)
					if(nowselect==4)
						nowselect=0;
					else nowselect=nowselect+1;
			}
			else if(keyCode-48<5 &&keyCode-48>=0){
				nowselect=keyCode-48;
			}
		}
		//选择结束
		if(nowselect==0){
			exit(0);
		}
		if(nowselect==1){
			newstudent();
		}
		if(nowselect==2){
			newsocks();
		}
		if(nowselect==3){
			getsocks();
		}
		if(nowselect==4){
			getout();
		}
	}
} 
//正式处理数据
int newstudent(){
	int oldlastaddst;
	clear();
	
	printf("\n\n\t本程序最多允许录入100名学生信息。按任意键继续或N返回主页面");

	if(getchoose(3)!=1){
		return 0;
	}
	clear();
	oldlastaddst=lastaddst;
	for(i=lastaddst;i<=100;i++){
		printf("\n\n\t\t\t录入学生信息：\n\n");
		printf("\t学号：");
		scanf("%s",stu[i].id);
		fflush(stdin);
		printf("\t姓名：");
		scanf("%s",stu[i].name);
		fflush(stdin);
		lastaddst=i;
		printf("\n\t录入成功，按任意键继续或按N返回主页面");
		if(getchoose(3)==0){
			break;
		}
		clear();
		printf("\t\t\t本次录入的学生信息\n\n");
		printf("\t\t----------------+----------------\n");
		printf("\t\t|\t学号\t+\t姓名\t|\n");
		printf("\t\t|---------------+---------------|\n");
		for(j=oldlastaddst;j<=i;j++){
			printf("\t\t|\t%s\t+\t%s\t|\n",stu[j].id,stu[j].name);
		}
		printf("\t\t----------------+----------------\n");
	}
		return 0;

}
int newsocks(){
	return 0;
}
int getsocks(){
	return 0;
}
int getout(){
	return 0;
}

//清空屏幕上所有内容
int clear(){
	system("cls");
	return 1;
}
int getchoose(int t){
	if(t==3){
		char ch;
		ch=getchar();
		fflush(stdin);
		if(ch!='n' && ch!='N'){
			return 1;
		}
		else return 0;
	}
	else return 1;
}
//方便output
void outputline(){
	for(i=0;i<79;i++){
		printf("*");
	}
	printf("\n");
}
int checkstate(){
	return 55;
}
