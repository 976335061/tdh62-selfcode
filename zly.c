#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
void welcome1();//导航界面1
void welcome2();//2
void choosesuccd();//流程界面1
void chooseaver();//2
void chooseA();//3
void chooseB();//4
void choosetotal();//5
void calcview1();//计算界面1——输入
void calcview2();//输出逐差界面
void calcview3();//输出平均值
void choosecalcul();//计算选择
double average(double *,int);//平均值计算
void calcul1();//逐差法求平均值及A
void calcul2();//求平均值及A
void calcul3();//B类不确定度
int next();
int guide1();//界面控制选择1
int guide2();//2
int guide3();//3
int NOW=1,Select=1;
double UncerA=0,Aver=0,uncerB=0.0; 
main()
{
	for(;;)
	{
		guide1();//界面1
		if(Select==1)//选择进入
		{
			guide2();//界面2
		}
		if(Select==2)
			guide3();//界面3
		if(NOW==6)//返回上一级目录
			continue;
		else//进入计算界面
			switch(NOW)
		{
case 1:calcview1();
	calcul1();
	calcview2();
	   next();
	   break;
case 2:calcview1();
	calcul2();
	calcview3();
	next();
		}
		
	}
}
int guide1()//界面1，导航界面(控制)
{
	char keyCode; 
	for(;;)
	{
		if(Select==1)
			welcome1();
		if(Select==2)
			welcome2();
		fflush(stdin);
		keyCode=getch();
		if(keyCode==-32)
		{
			keyCode=getch();
			fflush(stdin);
			if(Select==1)
			{
				Select=2;
			}
			else if(Select==2)
			{
				Select=1;
			}
		}
		if (keyCode==13)//回车，确认进入下一界面
			return 0;
	}
}
int guide2()//界面2，功能界面(输出+控制)
{
	int keyCode;
	for(keyCode=1000;;)
	{
		{
			
			if(keyCode==1000)
			{
				system("cls");
				printf("\n  ****************************欢迎使用不确定度计算器**************************\n");
				printf("\n");
				printf("        \t\t\t》》》功能介绍《《《\n");
				printf("\n\t\t1.关于软件 ");
				printf("\n\n\t\t2.逐差求平均值："); 
				printf("\n\n\t\t3.A类不确定度，采取简便的算数平均差方法进行计算。");
				printf("\n\n\t\t4.总不确定度的合成，采取简便的算数平均差方法进行计算。\n");
				printf("\n\t\t请输入1-4选择你要了解的选项，按回车确认按N返回上一级"); 
				
			}
			fflush(stdin);
			keyCode=getchar();
			if(keyCode==78||keyCode==110)//返回上级界面
			{
				return 0;
			}
			else if(keyCode<49||keyCode>52 )//输入限制
			{
				printf("\t\t抱歉没有这个选项，请重新输入\n");
				continue;
			}
			if(keyCode==49)//输入1，关于软件
			{
				system("cls");
				printf("\n  ****************************欢迎使用不确定度计算器**************************\n");
				printf("\n");
				printf("        \t\t\t》》》功能介绍《《《\n");
				printf("1.关于软件\n(1)流程说明：\n你可以从计算流程的任意位置进入获得你所需的单项值，\n如果你需要一连串的计算，从你未计算出数据的位置进入即可。\n");
				printf("例如：已经知道了平均值，\n需要进行总不确定度的计算,则需要从A类或者B类不确定度的获取开始");
				printf("\n\n(2)界面操作：功能介绍界面使用数字进行选取所需功能，其他界面则使用方向键与回车进行选择与确认");
				printf("\n\n(3)关于数据：a.数据组数可以自由选择，但组数必须为整数\nb.出于计算机字长及C语言数据格式的限制，本程序只支持有效数字不大于16且小数位不大于6的数据\nc.在输入数据时空格与回车都将确认数据的输入\nd.由于计算算法，逐差法数据个数必须为偶数");
				printf("\n\n(4)问题反馈：如果对软件有任何疑问请发送邮件至873581178@qq.com与我联系，将十分感激您为本程序提供建议或意见\n");
				printf("\n\t\t输入N返回上一级"); 
				fflush(stdin);
				keyCode=getchar();
				if(keyCode==78||keyCode==110)//返回上级界面
				{
					keyCode=1000;
					continue;
				}
				
			}
			if(keyCode==50)//输入2，功能1介绍
			{
				system("cls");
				printf("\n  ****************************欢迎使用不确定度计算器**************************\n");
				printf("2.逐差求平均值：");
				printf("\n(1)对输出的数据计算各组逐差，并求出各组逐差，逐差的平均值。利用逐差与逐差的平均值可计算A类不确定度。\n(2)在研究物理过程中，当自变量之间的函数呈多项式的形式，且自变量按等差级数变化时，可以用逐差法处理数据\n");
				printf("\n\t\t输入N返回上一级"); 
				fflush(stdin);
				keyCode=getchar();
				if(keyCode==78||keyCode==110)
				{
					keyCode=1000;
					continue;
				}
			}
			if(keyCode==51)//输入3，功能2介绍
			{
				system("cls");
				printf("\n  ****************************欢迎使用不确定度计算器**************************\n");
				printf("\n\n3.A类不确定度，采取简便的算数平均差方法进行计算。\n");
				printf("\n\t\t输入N返回上一级");
				fflush(stdin);
				keyCode=getchar();
				if(keyCode==78||keyCode==110)
				{
					keyCode=1000;
					continue;
				}
			}
			
			if(keyCode==52)//输入4，功能3介绍
			{
				system("cls");
				printf("\n  ****************************欢迎使用不确定度计算器**************************\n");	
				printf("\n\n4.总不确定度的合成，采取简便的算数平均差方法进行计算。\n");
				printf("\n\t\t输入N返回上一级"); 
				fflush(stdin);
				keyCode=getchar();
				if(keyCode==78||keyCode==110)
				{
					keyCode=1000;
					continue;
				}
			}
		}
	}
}

int guide3()//界面3，流程界面(控制)
{
	char keyCode; 
	do{
		if(NOW==1)
			choosesuccd();
		if(NOW==2)
			chooseaver();
		if(NOW==3)
			chooseA();
		if(NOW==4)
			chooseB();
		if(NOW==5)
			choosetotal();
		fflush(stdin);
		keyCode=getch();
		if(NOW==1||NOW==2)
		{
			if(keyCode==-32)
			{
				keyCode=getch();
				fflush(stdin);
				if(keyCode==80||keyCode==72)
					if(NOW==1)
						NOW=2;
					else
						NOW=1;
					else if(keyCode==77)
						NOW=3;
			}//end if (keycode==-32)
		}//end if (now=1.2)
		if(NOW==3||NOW==4)
		{
			if(keyCode==-32)
			{
				keyCode=getch();
				fflush(stdin);
				if(keyCode==80||keyCode==72)
					if(NOW==3)
						NOW=4;
					else
						NOW=3;
					else if(keyCode==77)
						NOW=5;
					else if(keyCode==75)
						NOW=2;
			}//end if (keycode==-32)
		}//end if (now=3.4)
		if(NOW==5){
			if(keyCode==-32){
				keyCode=getch();
				fflush(stdin);
				if(keyCode==75)
					NOW=3;
			}//end if (keycode==-32)
		}//end if (now=3.4)
		if(keyCode==78||keyCode==110)//返回上级菜单
		{
			NOW=6;
			break;
		}
		if(keyCode==13)
			return 0;//回车跳出循环
	}
	while(1);
}
void welcome1()//输出界面
{
	system("cls");
	printf("\n  ****************************欢迎使用不确定度计算器**************************\n");
	printf("\t\t\t\t┌───────┐\n");
	printf("\t\t\t     >>>│   功能介绍   │\n");
	printf("\t\t\t\t│              │\n");
	printf("\t\t\t\t└───────┘\n");
	printf("\t\t\t\t┌───────┐\n");
	printf("\t\t\t\t│   开始计算   │\n");
	printf("\t\t\t\t│              │\n");
	printf("\t\t\t\t└───────┘\n");
	printf("\t\t\t\t请按方向键进行选择，回车进行确认");
}
void welcome2()
{
	system("cls");
	printf("\n  ****************************欢迎使用不确定度计算器**************************\n");
	printf("\t\t\t\t┌───────┐\n");
	printf("\t\t\t\t│   功能介绍   │\n");
	printf("\t\t\t\t│              │\n");
	printf("\t\t\t\t└───────┘\n");
	printf("\t\t\t\t┌───────┐\n");
	printf("\t\t\t     >>>│   开始计算   │\n");
	printf("\t\t\t\t│              │\n");
	printf("\t\t\t\t└───────┘\n");
	printf("\t\t\t\t请按方向键进行选择，回车进行确认");
}
void choosesuccd()//Successive difference逐差
{
	system("cls");
	printf("\n  ****************************欢迎使用不确定度计算器**************************\n");
	printf("\t┌───────┐\n");
	printf("  》》》│逐差法求平均值├──┐\n");
	printf("\t│计算平均值,求A│    │\n");
	printf("\t└───────┘    │\n");
	printf("\t┌───────┐    │  ┌──────┐\n");
	printf("\t│   平均值     ├──┴─┤A类不确定度 ├────┐  ┌──────┐\n");
	printf("\t│              │        │            │        │  │ 总不确定度 │\n");
	printf("\t└───────┘        └──────┘        ├─┤            │\n");
	printf("\t\t\t\t  ┌──────┐        │  │            │\n");
	printf("\t\t\t\t  │B类不确定度 ├────┘  └──────┘\n");
	printf("\t\t\t\t  │            │\n");
	printf("\t\t\t\t  └──────┘\n");
	printf("\t\t\t\t请按方向键进行选择，回车进行确认,返回请输入N");
}
void chooseaver()	//平均值
{
	system("cls");
	printf("\n  ****************************欢迎使用不确定度计算器**************************\n");
	printf("\t┌───────┐\n");
	printf("\t│逐差法求平均值├──┐\n");
	printf("\t│              │    │\n");
	printf("\t└───────┘    │\n");
	printf("\t┌───────┐    │┌──────┐\n");
	printf("  》》》│   平均值     ├──┴┤A类不确定度 ├───┐  ┌──────┐\n");
	printf("\t│计算平均值,求A│      │            │      │  │ 总不确定度 │\n");
	printf("\t└───────┘      └──────┘      ├─┤            │\n");
	printf("\t\t\t\t┌──────┐      │  │            │\n");
	printf("\t\t\t\t│B类不确定度 ├───┘  └──────┘\n");
	printf("\t\t\t\t│            │\n");
	printf("\t\t\t\t└──────┘\n");
	printf("\t\t\t\t请按方向键进行选择，回车进行确认，返回请输入N");
}
void chooseA()//A类不确定度
{
	system("cls");
	printf("\n  ****************************欢迎使用不确定度计算器**************************\n");
	printf("\t┌───────┐\n");
	printf("\t│逐差法求平均值├──┐\n");
	printf("\t│              │    │\n");
	printf("\t└───────┘    │\n");
	printf("\t┌──────┐        ┌──────┐\n");
	printf("\t│   平均值   │  》》》│A类不确定度 ├────┐  ┌──────┐\n");
	printf("\t│            │        │   输入A    │        │  │ 总不确定度 │\n");
	printf("\t└──────┘        └──────┘        ├─┤\t\t  │\n");
	printf("\t\t\t\t┌──────┐        │  │            │\n");
	printf("\t\t\t\t│B类不确定度 ├────┘  └──────┘\n");
	printf("\t\t\t\t│            │\n");
	printf("\t\t\t\t└──────┘\n");
	printf("\t\t\t\t请按方向键进行选择，回车进行确认，返回请输入N");
}
void chooseB()//B类不确定度
{
	system("cls");
	printf("\n  ****************************欢迎使用不确定度计算器**************************\n");
	printf("\t┌───────┐\n");
	printf("\t│逐差法求平均值├──┐\n");
	printf("\t│              │    │\n");
	printf("\t└───────┘    │\n");
	printf("\t┌──────┐      │┌──────┐\n");
	printf("\t│   平均值   ├───┴┤A类不确定度 ├────┐  ┌──────┐\n");
	printf("\t│            │        │            │        │  │ 总不确定度 │\n");
	printf("\t└──────┘        └──────┘        ├─┤            │\n");
	printf("\t\t\t\t┌──────┐        │  │            │\n");
	printf("\t\t\t\t│B类不确定度 ├────┘  └──────┘\n");
	printf("\t\t\t  》》》│ 选择B      │\n");
	printf("\t\t\t\t└──────┘\n");
	printf("\t\t\t\t请按方向键进行选择，回车进行确认，返回请输入N");
}
void choosetotal()//总不确定度
{
	system("cls");
	printf("\n  ****************************欢迎使用不确定度计算器**************************\n");
	printf("\t┌───────┐\n");
	printf("\t│逐差法求平均值├──┐\n");
	printf("\t│              │    │\n");
	printf("\t└───────┘    │\n");
	printf("\t┌──────┐      │┌──────┐\n");
	printf("\t│   平均值   ├───┴┤A类不确定度 ├────┐   ┌──────┐\n");
	printf("\t│            │        │            │        │   │ 总不确定度 │\n");
	printf("\t└──────┘        └──────┘        │>>>│  输入A,B   │\n");
	printf("\t\t\t\t┌──────┐        │   │            │\n");
	printf("\t\t\t\t│B类不确定度 ├────┘   └──────┘\n");
	printf("\t\t\t\t│            │\n");
	printf("\t\t\t\t└──────┘\n");
	printf("\t\t\t\t请按方向键进行选择，回车进行确认，返回请输入N");
}
int next()
{		
	int num;
	printf("是否继续进行总不确定度的计算，是请输入Y，否请输入N");
	fflush(stdin);
	num=getchar();
	if(num==89||num==121)
	{
		calcul2();
	}
	if(num==110||num==78)
		return 0;
}
void calcview1()
{
	printf("\n	****************************欢迎使用不确定度计算器**************************\n");
	printf("┌────────────────────────────────────┐\n");
	printf("│								 数据输入区 							  │\n\n");
}
void calcview2()
{
	printf("\n	  ****************************结果输出**************************\n");
	printf("┌──────┬─────────────────────────────┐\n");
	printf("│逐差平均值  │ %.2lf\n",Aver);
	printf("├──────┼─────────────────────────────┤\n");
	printf("│A类不确定度 │ %.2lf\n",UncerA);
	printf("├──────┼─────────────────────────────┤\n");
	printf("│B类不确定度 │\n");
	printf("├──────┼─────────────────────────────┤\n"); 
	printf("│总不确定度  │\n");
	printf("└──────┴─────────────────────────────┘\n");
}

double average(double *p,int k)
{
	int n;
	double average,sum=0,x=0;//平均值计算，输出  
	for(n=0;n<k;n++)   
	{ 
		x=p[n];
		sum=sum+x;
	}
	average=sum/(float)k;
	return average;
}

double calcul1()//逐差法求平均值及A
{
	int groupn,half,n;//goupn数据组数，half组数的一半，n循环计数。
	double *pData=0,*delta=0,c=0;//pData用于存储输入的数据，delta用于存储逐差的数据
	for(;;)//分配内存
				{
		printf ("\t\t\t请输入数据的组数(偶数)：");
		scanf ("%d",&groupn);
		half=(groupn/2);
		if(groupn%2!=0)
		{
			printf("/t/t/t请输入偶数组数.");
			continue;
		}
		delta = (double*) calloc (half,sizeof(double));
		pData = (double*) calloc (groupn,sizeof(double));
		if (delta==NULL) exit (1);
		if (pData==NULL) exit (1);
		break;
				}
	for (n=0;n<groupn;n++)//数据输入
	{
		printf ("\t\t\t请输入#%d组数据：",n+1);
		scanf ("%lf",&pData[n]);
	}
	
		  for (n=0;n<half;n++)//逐差计算与输出
		  {
			  delta[n]=fabs(pData[(half+n)]-pData[n]);
		  }
		  Aver=average(delta,half);//计算逐差平均
		  n=0;
		  while(n<half)//计算A类不确定度
		  {
			  c+=fabs(Aver-delta[n]);
			  n++;
		  }
		  UncerA=c*(1/pow(half,2));
		  free (pData);
		  free (delta);
		  return 0;
} 

void calcul2()//平均值及A
{
	int groupn,n;//goupn数据组数，n循环计数。
	double *pData=0,*delta=0,c=0;//pData用于存储输入的数据
	printf ("\t\t\t请输入数据的组数：");
	scanf ("%d",&groupn);
	pData = (double*) calloc (groupn,sizeof(double));
	if (pData==NULL) exit (1);
	for (n=0;n<groupn;n++)//数据输入
	{
		printf ("\t\t\t请输入#%d组数据：",n+1);
		scanf ("%lf",&pData[n]);
	}
	
		  Aver=average(pData,groupn);//计算平均值
		  for(n=0;n<groupn;n++)
		  {
			  UncerA=fabs(pData[n]-Aver);//计算A类不确定度
		  }
		  free(pData);
} 
void calcview3()
{
	printf("\n	  ****************************结果输出**************************\n");
	printf("┌──────┬─────────────────────────────┐\n");
	printf("│	平均值	  │ %.2lf\n",Aver);
	printf("├──────┼─────────────────────────────┤\n");
	printf("│A类不确定度 │ %.2lf\n",UncerA);
	printf("├──────┼─────────────────────────────┤\n");
	printf("│B类不确定度 │\n");
	printf("├──────┼─────────────────────────────┤\n"); 
	printf("│总不确定度  │\n");
	printf("└──────┴─────────────────────────────┘\n");
}
void calcul3()	   /* 求B类不确定度 */
{
	int chose_b=0;	   /* 接收用户的选项 */
	int num_calc=0;    /* 用于统计用户输入非法值的次数 */
	printf("\n求B类不确定度,您可以选择本程序提供的参考值或输入一个值\n");
	printf("请输入的选项： ");
	printf("┌──────┬───────┬─────────┬───────┐\n");
	printf("  1.米尺	  │  0.5mm 	  │ 2.游标卡尺 	  │  0.02mm \n");
	printf("├──────┼───────┼─────────┼───────┤\n");
	printf("  3.千分尺	  │  0.01mm	  │ 4.游标卡尺 	  │  0.05mm \n");
	printf("├──────┼───────┼─────────┼───────┤\n"); 
	printf("  5.物理天平  │  0.05g 	  │ 6.自定义		  │%lf,uncerB\n");
	printf("└──────┴───────┴─────────┴───────┘\n");
	while (1)
	{
		fflush(stdin);
		scanf("%d",chose_b);
		if (chose_b>=1 && chose_b<=7)
		{
			switch(chose_b)
			{
			case 1 : uncerB=0.5; break;
			case 2 : uncerB=0.02; break;
			case 3 : uncerB=0.05; break;
			case 4 : uncerB=0.01; break;
			case 5 : uncerB=0.05; break;
			case 6 : uncerB=0.005; break;
			case 7 : printf("\n请输入仪器允差： ");
				uncerB=getch();
				break;
			}break;
		}
		else
		{
			printf("没有这个选项，请重新输入\n");
			continue;
		}
	}
