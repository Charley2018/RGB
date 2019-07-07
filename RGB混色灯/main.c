/*********************************************************************************************************
** ���̹��� ��RGB
** �������� ��Charles Chan
** ���̰汾 ��V1.0
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
** �������� ����ʱ����
** ����˵�� �����������ʱ��ռ��CPU����������С��ʱ�ĵ�λ��ԼΪ1ms��
** ��ڲ��� ��time:��Ҫ��ʱ��ʱ�䣬��λms����time = 1000������ʱ1000ms
** ���ڲ��� ����
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
  EA = 1;   //�����ж�
  LED0 = 1;
	LED1 = 1;
	LED2 = 1;
  TR0 = 1;  //�򿪶�ʱ��
	
	
	while(1)
	{
		key = Key_Scan();	 //��while(1)���治��ѭ��ִ�а���ɨ�����Key_Scan(),Key_Scan()���Ͻ������ķ���ֵ��������key
	//red+
		if(key == 1)		 //key!=0˵���а���������
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
		if(key == 2)		 //key!=0˵���а���������
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
		if(key == 3)		 //key!=0˵���а���������
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
		if(key == 4)		 //key!=0˵���а���������
		{
			PWM_LOW1 = 5;
			PWM_LOW2 = 5;
			PWM_LOW3 = 5;
		}
		
		
		//little yellow
		if(key == 5)		 //key!=0˵���а���������
		{
		  PWM_LOW1 = 2;
			PWM_LOW2 = 2;
			PWM_LOW3 = 8;
		}
		//deep yellow
		if(key == 6)		 //key!=0˵���а���������
		{
			PWM_LOW1 = 2;
			PWM_LOW2 = 2;
			PWM_LOW3 = 10;
		}
		//orange
		if(key == 7)		 //key!=0˵���а���������
		{
			PWM_LOW1 = 1;
			PWM_LOW2 = 8;
			PWM_LOW3 = 10;
		}
		
		// light off
		if(key == 8)		 //key!=0˵���а���������
		{
		  PWM_LOW1 = 10;
			PWM_LOW2 = 10;
			PWM_LOW3 = 10;
		}
		
		//pink color 3
		if(key == 9)		 //key!=0˵���а���������
		{
			PWM_LOW1 = 4;
			PWM_LOW2 = 8;
			PWM_LOW3 = 7;
		}
		//pink color 2
		if(key == 10)		 //key!=0˵���а���������
		{
		  PWM_LOW1 = 2;
			PWM_LOW2 = 8;
			PWM_LOW3 = 2;
		}
		//pink color 1
		if(key == 11)		 //key!=0˵���а���������
		{
		  PWM_LOW1 = 5;
			PWM_LOW2 = 10;
			PWM_LOW3 = 8;
		}
		
		
		
		
		if(key == 12)		 //key!=0˵���а���������
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
		
		if(key == 13)		 //key!=0˵���а���������
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
		if(key == 14)		 //key!=0˵���а���������
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
		if(key == 15)		 //key!=0˵���а���������
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
		
			if(key == 16)		 //key!=0˵���а���������
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