#include <reg52.h>
//************实现功能************
//四个按钮，一个复位键。button 1234 分别代表数字1234，按下该按键，自动点亮加和后表示的LED小灯，实现按键识别与led计算
//************实现功能************
//************按键端口名称定义************
sbit BT1=P3^2;
sbit BT2=P3^3;
sbit BT3=P3^4;
sbit BT4=P3^5;
//************按键端口名称定义************

//************数据类型定义************
typedef signed char int8;       //8位有符号字符型
typedef signed int int16;       //16位有符号整型
typedef signed long int32;     	//32位有符号长整型
typedef unsigned char uint8;    //8位无符号字符型
typedef unsigned int uint16;    //16位无符号整型
typedef unsigned long uint32;   //32位无符号长整型
typedef unsigned char uchar;		//无符号字符 
//************数据类型定义************

uchar count;	//计数按键几次
uchar temp;		//led灯的状态
uchar a,b;		

void delay10ms(void); //延时程序
void key();          //按键判断程序
void move();         //广告灯向左移动移动函数


void main()
{
count=0;  //初始华参数设置
	temp=0xfe;
	P1=0xff;
	P1=temp;
	while(1)  //永远循环,扫描判断按键是否按下
	{
		key();    //调用按键识别函数
		move();   //调用广告灯移动函数
	}	
}
	
void delay10ms(void) //延时程序
{
	unsigned char i,j;
	for(i=20;i>0;i--)
	for(j=248;j>0;j--);
}

void key()           //按键判断程序
{
	if(BT1==0)  //判断是否按下键盘1
	{
		delay10ms(); //延时,软件去干扰
		if(BT1==0)   //确认按键按下
		{
			count++;     //按键计数加1
			if(count==8) //计8次重新计数
			{
				count=0;    //将count清零
			}
		}
		while(BT1==0);//按键锁定,每按一次count只加1.
	}
	
	if(BT2==0)  //判断是否按下键盘2
	{
		delay10ms(); //延时,软件去干扰
		if(BT2==0)   //确认按键按下
		{
			count=count+2;     //按键计数加1
			if(count>8) //计8次重新计数
			{
				count=count-8;    //将count清零
			}
		}
		while(BT2==0);//按键锁定,每按一次count只加1.
	}
	
	if(BT3==0)  //判断是否按下键盘1
	{
		delay10ms(); //延时,软件去干扰
		if(BT3==0)   //确认按键按下
		{
			count=count+3;     //按键计数加1
			if(count>8) //计8次重新计数
			{
				count=count-8;    //将count清零
			}
		}
		while(BT3==0);//按键锁定,每按一次count只加1.
	}
	
	if(BT4==0)  //判断是否按下键盘1
	{
		delay10ms(); //延时,软件去干扰
		if(BT4==0)   //确认按键按下
		{
			count=count+4;     //按键计数加1
			if(count>8) //计8次重新计数
			{
				count=count-8;    //将count清零减少8
			}
		}
		while(BT4==0);//按键锁定,每按一次count只加1.
	}
	
}

void move()
{
	a=temp<<count;
	b=temp>>(8-count);
	P1=a|b;
}
