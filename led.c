
#include "led.h"
#include "LPC11XX.H"
/********************************************************************************
* FunctionName   : LEDInit()
* Description    : LED?????
* EntryParameter : None
* ReturnValue    : None
********************************************************************************/

void LEDInit()
{
    LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16); // ??IOCON?? 
    LPC_IOCON->PIO2_0 &= ~0x07;    
    LPC_IOCON->PIO2_0 |= 0x00; //?P1.0????GPIO
    LPC_IOCON->PIO2_1 &= ~0x07;   
    LPC_IOCON->PIO2_1 |= 0x00; //?P1.1????GPIO
    LPC_SYSCON->SYSAHBCLKCTRL &= ~(1<<16); // ??IOCON??
    
    LPC_SYSCON->SYSAHBCLKCTRL |= (1<<6);  //??AHB???GPIO??    
    LPC_GPIO2->DIR |= (1<<0); // ?P1.0???????
    LPC_GPIO2->DATA |= (1<<0); // ?P1.0??????
    LPC_GPIO2->DIR |= (1<<1); // ?P1.1???????
    LPC_GPIO2->DATA |= (1<<1); // ?P1.1??????
}
/********************************************************************************
* FunctionName   : PIOINT1_IRQHandler()
* Description    : P1???????
* EntryParameter : None
* ReturnValue    : None
********************************************************************************/

void PIOINT3_IRQHandler()
{
    if((LPC_GPIO3->MIS & (1<<2))==(1<<2)) // ???P1.9?????
    {
        LED1_ON();
        while(KEY1_DOWN());
        LED1_OFF();
        LPC_GPIO3->IC = (1<<2);  // ???
    }
    if((LPC_GPIO3->MIS & (1<<3))==(1<<3)) // ???P1.10?????
    {
        LED2_ON();
        while(KEY2_DOWN());
        LED2_OFF();
        LPC_GPIO3->IC = (1<<3);  // ???
    }
}

