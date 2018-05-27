/********************************************************************************
* FunctionName   : main()
* Description    : ???
* EntryParameter : None
* ReturnValue    : None
********************************************************************************/
#include "led.h"

#include "LPC11XX.H"
int main()
{
    LEDInit(); 
    
    LPC_IOCON->PIO3_2 &= ~(0x07);//?P1_9???GPIO
    LPC_GPIO3->DIR  &= ~(1<<2);//?P1_9?????
    LPC_IOCON->PIO3_3 &= ~(0x07);//?P1_10???GPIO
    LPC_GPIO3->DIR &= ~(1<<3);//?P1_10?????
    
    LPC_GPIO3->IE |= (1<<2); // ??P1.9??????
    LPC_GPIO3->IE |= (1<<3); // ??P1.10??????
    LPC_GPIO3->IS &= ~(1<<2); // ??P1.9???????
    LPC_GPIO3->IS &= ~(1<<3); // ??P1.10???????
    LPC_GPIO3->IEV &= ~(1<<2); // ??P1.9????????
    LPC_GPIO3->IEV &= ~(1<<3); // ??P1.10????????
    NVIC_EnableIRQ(EINT3_IRQn); // ??GPIO1??
    while(1)
    {
        ;
    }
}