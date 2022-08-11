#include<stdio.h>
#include "NUC1xx.h"
#include "DrvSYS.h"
#include "DrvGPIO.h"
#include "LCD_Driver.h"
#include "DrvPWM.h"
#include "DrvADC.h"

int32_t main()
{
	uint16_t x=0xffff;
	UNLOCKREG();
	SYSCLK->PWRCON.XTL12M_EN = 1;
	SYSCLK->CLKSEL0.HCLK_S = 0;
	LOCKREG();
	InitPWM();
	Initial_panel();
	clr_all_panel();
	print_lcd(0,"var reg");
	
	while(1)
	{
		PWMA->CMR0 = x;
		x = x-1;
		DrvSYS_Delay(5000);
	}
	
	}