#include <stdio.h>																											 
#include "NUC1xx.h"
#include "DrvSYS.h"
#include "DrvPWM.h"
#include "DrvADC.h"
#include "LCD_Driver.h"


 int32_t main (void)
{  char value[15];  
    			   
	float volt = 0;
	UNLOCKREG();
	SYSCLK->PWRCON.XTL12M_EN = 1; 	//Enable 12Mhz and set HCLK->12Mhz
	SYSCLK->CLKSEL0.HCLK_S = 0;
	LOCKREG();
	InitPWM(6);
	

	
	
	Initial_panel();  // initialize LCD pannel
  clr_all_panel();  // clear LCD panel 
  print_lcd(0,"variable reistor");

	DrvADC_Open(ADC_SINGLE_END,ADC_SINGLE_OP , 0x40,INTERNAL_HCLK , 1); 	//0x40 FOR CHANNEL 6
	while(1)
   {
    DrvADC_StartConvert();   // start A/D conversion
    //while(DrvADC_IsConversionDone()==FALSE);
     PWMA->CMR0=ADC->ADDR[6].RSLT<<4;
		 
		 volt = ((float)ADC->ADDR[6].RSLT/4095.0  )*3.3;
    sprintf(value,"%fV",volt);  //ADC CHANNEL 6
		print_lcd(1, value);
    }
	}