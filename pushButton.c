/*
 * pushButton.c
 *
 * Created: 1/17/2020 5:55:40 PM
 *  Author: Khaled Magdy
 */ 
#include "pushButton.h"

void pushButtonInit(En_buttonId_t en_butotn_id)
{
   switch(en_butotn_id)
   {
      case BTN_0:
                   gpioPinDirection(BTN_0_GPIO, BTN_0_BIT, INPUT);
                   break;
      case BTN_1:
                   gpioPinDirection(BTN_1_GPIO, BTN_1_BIT, INPUT);
                   break;
      case BTN_2:
                   gpioPinDirection(BTN_2_GPIO, BTN_2_BIT, INPUT);
                   break;
      case BTN_3:
                   gpioPinDirection(BTN_3_GPIO, BTN_3_BIT, INPUT);
                   break;
      default:
                   break;
   }
}

En_buttonStatus_t pushButtonGetStatus(En_buttonId_t en_butotn_id)
{
   En_buttonStatus_t ret = 0x00;
   switch(en_butotn_id)
   {
       case BTN_0:
	               SwDelay_ms(15);
                   ret = gpioPinRead(BTN_0_GPIO, BTN_0_BIT)? Pressed:Released;
                   break;
       case BTN_1:
	               SwDelay_ms(15);
                   ret = gpioPinRead(BTN_1_GPIO, BTN_1_BIT)? Pressed:Released;
                   break;
       case BTN_2:
	               SwDelay_ms(15);
                   ret = gpioPinRead(BTN_2_GPIO, BTN_2_BIT)? Pressed:Released;
                   break;
       case BTN_3:
	               SwDelay_ms(15);
                   ret = gpioPinRead(BTN_3_GPIO, BTN_3_BIT)? Pressed:Released;
                   break;
       default:
                   break;
   }
   return ret;
}