#include <reg52.h>
/********************************************************************
源码来自于KR电子，部分注释为本人学习所加
***********************************************************************/

#define uchar unsigned char 
sbit P2_0 = P2^0;
sbit P2_1 = P2^1;
sbit P2_2 = P2^2;
sbit P2_3 = P2^3;

uchar code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,
                        0xf8,0x80,0x90};//共阳数字编码  0.1.2.3.4....9 数组内表示数码管显示数字的值。

/********************************************************************
* 名称 : Delay()
* 功能 : 延时
* 输入 : i
* 输出 : 无
***********************************************************************/
void delay(uchar i)	 //延时函数
{
  uchar j,k; 
  for(j=i;j>0;j--)
    for(k=125;k>0;k--);
}

/********************************************************************
* 名称 : display()
* 功能 : 数码管显示函数
* 输入 : 无
* 输出 : 无
***********************************************************************/
void display() //显示函数
{
  
   P0=table[0];
   P2_0 = 0;
   delay(5);
   P2_0 = 1;

   P0=table[1];
   P2_1 = 0;
   delay(5);
   P2_1 = 1;

   P0=table[2];
   P2_2 = 0;
   delay(5);
   P2_2 = 1;

    P0=table[3];
   P2_3 = 0;
   delay(5);
   P2_3 = 1;
   
}
/********************************************************************
* 名称 : main()
* 功能 : 主函数
* 输入 : 无
* 输出 : 无
***********************************************************************/
void main(void)
{   
	while(1)
	{
		display();
	}
}
