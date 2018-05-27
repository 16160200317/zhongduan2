#ifndef __LED_H__
#define __LED_H__
#include "LPC11XX.H"

#define LED1_ON()  (LPC_GPIO2->DATA &= ~(1<<0))
#define LED1_OFF() (LPC_GPIO2->DATA |= (1<<0))

#define LED2_ON()  (LPC_GPIO2->DATA &= ~(1<<1))
#define LED2_OFF() (LPC_GPIO2->DATA |= (1<<1))

#define KEY1_DOWN() ((LPC_GPIO3->DATA & (1<<2)) != (1<<2))
#define KEY2_DOWN() ((LPC_GPIO3->DATA & (1<<3))!=(1<<3))
void PIOINT3_IRQHandler();
void LEDInit();
#endif //__LED_H__