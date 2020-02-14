/*
 * VSE.c
 *
 * Created: 2/11/2020 6:22:57 PM
 * Author : Aya ayman
 */ 

#include "gpio.h"
#include "USART.h"
#include "interrupts.h"
#include "led.h"
#include "pushButton.h"
#include "SPI.h"

#define F_CPU 16000000UL
#include <util/delay.h>

volatile uint8_t Speed=0;

int main(void)
{
	 sei();
	 /*Variables Declaration and initialization*/
	 uint8_t rec_data=0;
	 uint8_t BTN_Increase;
	 uint8_t BTN_Decrease;
	 pushButtonInit(BTN_0);
	 pushButtonInit(BTN_1);
	 /*UART Initialization*/
	//--------[ UART Init ]--------
	UART_cfg uart1_cfg;
	uart1_cfg.baudrate =	   9600;
	uart1_cfg.dataBits =	   UART_Bits_8;
	uart1_cfg.mode =		   UART_Transceiver;
	uart1_cfg.parity =		   No_Parity;
	uart1_cfg.sampleEdge =     RisingEdg;
	uart1_cfg.stopBits =	   StopBits_1;
	uart1_cfg.uartSync =	   UART_Async;
	uart1_cfg.uartInterrupts = UART_No_Interrupts;
	UART_Init(&uart1_cfg);
	 /*SPI Initialization*/
	 SPI_Init(SPI_Master, SPI_CLK_F_64 , SPI_Mode0,LSB_First ,SPI_Interrupts_Disabled);
	 /*Instructions used only once*/
	 _delay_ms(1000);
	 UART_Write_String(" Welcome... \n");
	 UART_Write_String(" Please Enter the Initial Speed\n");
	 while(!(UCSRA & (1<<7)));
	 Speed = UDR;
     UART_Write_String("You have entered \n");
	 UART_Write(Speed-48);
	 SPI_Write(Speed);
	 SPI_Write(Speed);
	 SPI_Write(Speed);
	 
    while(1) 
    {
		  if (pushButtonGetStatus(BTN_0)==Pressed)
		  {
				 Speed++;
				 SPI_Write(Speed);
				 UART_Write(Speed);
				 UART_Write_String("\r\n");
				_delay_ms(500);
		  }
		  if (pushButtonGetStatus(BTN_1)==Pressed)
		  {
			  Speed--;
			  if(Speed <'0')
			  {
					Speed='0';
			  }
			  else
			  {
					 SPI_Write(Speed);
					 UART_Write(Speed);
					 UART_Write_String("\r\n");
			  }
			  _delay_ms(500);
		  }
    }
}

