#include "NUC1xx.h"
#include "Driver\DrvSYS.h"
#include "NUC1xx-LB_002\Seven_segment.h"
#include "DrvADC.h"
#include "NUC1xx-LB_002\LCD_Driver.h"
int32_t main (void)
{
	char text[16];
	unint16_t value;
	UNLOCKREG();
	 SYSCLK->PWRCON.XTL12M_EN = 1;
	SYSCLK->CLKSEL0.HCLK_S = 0;
	LOCKREG();
	Initial_panel();
	clr_all_panel();
	print_lcd(0 , "variable resistor");
	DrvADC_Open(ADC_SINGLE_END , ADC_SINGLE_OP, 0x40(00100000b), INTERNAL_HCLK , 1);
	while(1)
	{
		DrvADC_StartConvert();
		while(DrvADC_IsConversionDone()==FALSE);
		value = ADC->ADDR[6].RSLT & 0xFFF
		sprintf(text , "value: %d" , value);
		print_lcd(1,text);
	}
	
}