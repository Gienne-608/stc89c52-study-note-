#include <reg52.h>
/**********
源码来自网络，部分注释本人学习所加
**********/

typedef unsigned int uint;
typedef unsigned char uchar;

uint count,count_ms=100;
				//	 0	   1	2	 3	  4	   5   6	7	 8	  9	   10
uchar code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xbf};

sbit P2_0 = P2^0;
sbit P2_1 = P2^1;
sbit P2_2 = P2^2;
sbit P2_3 = P2^3;

/*
* 延时函数  毫秒级
*/
void delay(uint z)
{
	uint x,y;
	for(x=z;z>0;z--)
		for(y=110;y>0;y--)
		;
}                        
/********************************************************************
* 名称 : Timer1Init()
* 功能 : 定时器1初始化
* 输入 : 无
* 输出 : 无
***********************************************************************/
void Timer1Init(void)		//10毫秒@11.0592MHz
{
//	AUXR &= 0xBF;		//定时器时钟12T模式
	TMOD &= 0x0F;		//设置定时器模式
	TL1 = 0x00;		//设置定时初值
	TH1 = 0xDC;		//设置定时初值
	TF1 = 0;		//清除TF1标志
	TR1 = 1;		//定时器1开始计时
	ET1 = 1;        //enable timer1 interrupt
    EA = 1;          //open global interrupt switch
}

/********************************************************************
* 名称 : display()
* 功能 : 数码管显示函数
* 输入 : Dis_data1,Dis_data2,Dis_data3,Dis_data4
* 输出 : 无
***********************************************************************/
void display(uint Dis_data1,uint Dis_data2,uint Dis_data3,uint Dis_data4)
{   
   P0=table[Dis_data1];
   P2_0 = 0;
   delay(2);
   P2_0 = 1;

   P0=table[Dis_data2];
   P2_1 = 0;
   delay(2);
   P2_1 = 1;

   P0=table[Dis_data3];
   P2_2 = 0;
   delay(2);
   P2_2 = 1;

    P0=table[Dis_data4];
   P2_3 = 0;
   delay(2);
   P2_3 = 1;
   
}

/********************************************************************
* 名称 : main()
* 功能 : 主函数
* 输入 : 无
* 输出 : 无
***********************************************************************/
void main()
{
	Timer1Init();
	count=100;
	count_ms=1000;
	while(1)
	{
		display(10,count%100/10,count%10,10);
	
	}	
}

/********************************************************************
* 名称 : void tm1_isr() interrupt 3 using 1
* 功能 : 定时器1中断服务函数
* 输入 : 无
* 输出 : 无
***********************************************************************/
void tm1_isr() interrupt 3 using 1
{
	TL1 = 0x00;		//设置定时初值
	TH1 = 0xDC;		//设置定时初值
    if (count_ms-- == 0)               //1ms * 1000 -> 1s
    {
        count_ms=1000;
		if(count==0)
		{
			count=100;
		}
		count --;              //reset counter
    }
}

