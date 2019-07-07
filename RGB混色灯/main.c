/*********************************************************************************************************
** 工程功能 ：RGB
** 工程作者 ：Charles Chan
** 工程版本 ：V1.0
*********************************************************************************************************/
#include<STC12C5A60S2.h>
#include<key_scan.h>

#define uchar	unsigned	char
#define uint	unsigned	int
	
#define FSCLK 11059200 
//#define FSCLK 12000000

sbit LED0 = P0^0;
sbit LED1 = P0^1;
sbit LED2 = P0^2;

/*********************************************************************************************************
** 函数功能 ：延时函数
** 函数说明 ：利用软件延时，占用CPU，经调试最小延时的单位大约为1ms，
** 入口参数 ：time:需要延时的时间，单位ms，如time = 1000，则延时1000ms
** 出口参数 ：无
*********************************************************************************************************/
void Delay_ms(uint time)
{
	uint i,j;
	for(i = 0;i < time;i ++)
		for(j = 0;j < 930;j ++);
}
uchar time=0,key;
uint PWM_LOW1=9,PWM_LOW2=9,PWM_LOW3=9;


void Delay(unsigned int t)
{
 while(--t);
}


void main()
{
	TMOD = 0x01;
	TH0 = (65536-FSCLK/12/3334)/256;
  TL0 = (65536-FSCLK/12/3334)%256;  //50ms
  ET0 = 1; 
  EA = 1;   //打开总中断
  LED0 = 1;
	LED1 = 1;
	LED2 = 1;
  TR0 = 1;  //打开定时器
	
	
	while(1)
	{
		key = Key_Scan();	 //在while(1)里面不断循环执行按键扫描程序Key_Scan(),Key_Scan()不断将按键的返回值赋给变量key
	//red+
		if(key == 1)		 //key!=0说明有按键被按下
		{
		if(PWM_LOW1 == 10)
		{
			PWM_LOW1 = 0;
		}
		else
		{
		  PWM_LOW1 ++;
		}
		}
		
		//green +
		if(key == 2)		 //key!=0说明有按键被按下
		{
		if(PWM_LOW2 == 10)
		{
			PWM_LOW2 = 0;
		}
		else
		{
		  PWM_LOW2 ++;
		}
		}
		
		//blue +
		if(key == 3)		 //key!=0说明有按键被按下
		{
		if(PWM_LOW3 == 10)
		{
			PWM_LOW3 = 0;
		}
		else
		{
		  PWM_LOW3 ++;
		}
		}
	
		//white light on
		if(key == 4)		 //key!=0说明有按键被按下
		{
			PWM_LOW1 = 5;
			PWM_LOW2 = 5;
			PWM_LOW3 = 5;
		}
		
		
		//little yellow
		if(key == 5)		 //key!=0说明有按键被按下
		{
		  PWM_LOW1 = 2;
			PWM_LOW2 = 2;
			PWM_LOW3 = 8;
		}
		//deep yellow
		if(key == 6)		 //key!=0说明有按键被按下
		{
			PWM_LOW1 = 2;
			PWM_LOW2 = 2;
			PWM_LOW3 = 10;
		}
		//orange
		if(key == 7)		 //key!=0说明有按键被按下
		{
			PWM_LOW1 = 1;
			PWM_LOW2 = 8;
			PWM_LOW3 = 10;
		}
		
		// light off
		if(key == 8)		 //key!=0说明有按键被按下
		{
		  PWM_LOW1 = 10;
			PWM_LOW2 = 10;
			PWM_LOW3 = 10;
		}
		
		//pink color 3
		if(key == 9)		 //key!=0说明有按键被按下
		{
			PWM_LOW1 = 4;
			PWM_LOW2 = 8;
			PWM_LOW3 = 7;
		}
		//pink color 2
		if(key == 10)		 //key!=0说明有按键被按下
		{
		  PWM_LOW1 = 2;
			PWM_LOW2 = 8;
			PWM_LOW3 = 2;
		}
		//pink color 1
		if(key == 11)		 //key!=0说明有按键被按下
		{
		  PWM_LOW1 = 5;
			PWM_LOW2 = 10;
			PWM_LOW3 = 8;
		}
		
		
		
		
		if(key == 12)		 //key!=0说明有按键被按下
		{
			if(PWM_LOW3 == 10 || PWM_LOW2 == 10 || PWM_LOW1 == 10)
			{
			}
			else 
			{
			  PWM_LOW1 ++;
				PWM_LOW2 ++;
				PWM_LOW3 ++;
			}
		
		}
		
		if(key == 13)		 //key!=0说明有按键被按下
		{
			PWM_LOW1 = 10;
			PWM_LOW2 = 10;
			PWM_LOW3 = 1;
			Delay(5000000000);
			if(PWM_LOW3 == 0 || PWM_LOW2 == 0 || PWM_LOW1 == 0)
			{
			}
			else 
			{
				uchar h;
       	for(h=10;h>0;h--)
				{
			  PWM_LOW1 --;
				Delay(5000000000);
				}
				for(h=10;h>0;h--)
				{
			  PWM_LOW1 ++;
				Delay(5000000000);
				}
				for(h=10;h>0;h--)
				{
			  PWM_LOW2 --;
				Delay(5000000000);
				}
				for(h=10;h>0;h--)
				{
			  PWM_LOW2 ++;
				Delay(5000000000);
				}
				for(h=5;h>0;h--)
				{
			  PWM_LOW2 --;
				Delay(5000000000);
					PWM_LOW3 ++;
				}
			}
		}
		if(key == 14)		 //key!=0说明有按键被按下
		{
			PWM_LOW1 = 10;
			PWM_LOW2 = 5;
			PWM_LOW3 = 10;
			Delay(5000000000);
				if(PWM_LOW3 == 0 || PWM_LOW2 == 0 || PWM_LOW1 == 0)
			{
			}
			else 
			{
				uchar h;
        for(h=5;h>0;h--)
				{
			  PWM_LOW2 ++;
				Delay(5000000000);
				}
				for(h=10;h>0;h--)
				{
			  PWM_LOW3 --;
				Delay(5000000000);
				}
        for(h=10;h>0;h--)
				{
			  PWM_LOW3 ++;
				Delay(5000000000);
				}
				for(h=10;h>0;h--)
				{
			  PWM_LOW1 --;
				Delay(5000000000);
				}
			}
		}
		if(key == 15)		 //key!=0说明有按键被按下
		{
			PWM_LOW1 = 2;
			PWM_LOW2 = 2;
			PWM_LOW3 = 10;
				Delay(5000000000);
				if(PWM_LOW3 == 0 || PWM_LOW2 == 0 || PWM_LOW1 == 0)
			{
			}
			else 
			{
				uchar h;
        for(h=8;h>0;h--)
				{
			  PWM_LOW2 ++;
				Delay(5000000000);
				}
				for(h=10;h>0;h--)
				{
			  PWM_LOW3 --;
				Delay(5000000000);
				}
				for(h=10;h>0;h--)
				{
			  PWM_LOW3 ++;
				Delay(5000000000);
				}
				for(h=10;h>0;h--)
				{
			  PWM_LOW2 --;
				Delay(5000000000);
				}
			}
			
		}
		
			if(key == 16)		 //key!=0说明有按键被按下
		{
			if(PWM_LOW3 == 0 || PWM_LOW2 == 0 || PWM_LOW1 == 0)
			{
			}
			else 
			{
			  PWM_LOW1 --;
				PWM_LOW2 --;
				PWM_LOW3 --;
			}
		}
	}
	}

	
void time0() interrupt 1 
{
TH0 = (65536-FSCLK/12/3334)/256;
TL0 = (65536-FSCLK/12/3334)%256;
time ++;
if(time >= 10) 
{
time = 0;
}
if(time >= PWM_LOW1) 
{
LED0 = 0;
}
else 
{
	LED0 = 1;
}
if(time >= PWM_LOW2) 
{
LED1 = 0;
}
else 
{
	LED1 = 1;
}
if(time >= PWM_LOW3) 
{
LED2 = 0;
}
else 
{
	LED2 = 1;
}
}
	
		


/************************** (C) COPYRIGHT 2011 Blue Sky Teams *****END OF FILE*****************************/