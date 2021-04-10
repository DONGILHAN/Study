/*
 * test.c
 *
 * Created: 2019-10-16 오후 5:01:45
 * Author: trace
 */

#include <mega128.h>
#include <delay.h>
#include <stdio.h>

void Init_USART1(void)
{
    UCSR1A = 0x02; // 2X
    UCSR1B = (1<<RXEN1)|(1<<TXEN1);

    // default : asyncronous, stop 1bit, data 8 bit
    //UCSR1C = ()0x06;
    //UCSR1C &= ~(1 << UMSEL0);

    UBRR1H = 0x00;
    UBRR1L = 15; //115200 Bps
}
void putch_USART1(char data)
{
    while(!(UCSR1A & (1<<UDRE1)));
    UDR1 = data;
}
char getch_USART1()
{
    while(!(UCSR1A & (1<<RXC1)));
    return UDR1;
}
void Init_ADC(){
    //free running mode, ref->AVCC, ADC right array
    ADMUX |= (1<<REFS0);//|(1<<REFS1) AVCC -> 2.56V
    ADCSRA |= (1<<ADEN)|(1<<ADFR);
}

void LCD_Decimal(unsigned char num, short AD_dat)
{
    unsigned char Decimal[5];
    Decimal[4]='0'+AD_dat/10000;
    AD_dat=AD_dat%10000;
    Decimal[3]='0'+AD_dat/1000;
    AD_dat=AD_dat%1000;
    Decimal[2]='0'+AD_dat/100;
    AD_dat=AD_dat%100;
    Decimal[1]='0'+AD_dat/10;
    AD_dat=AD_dat%10;
    Decimal[0]='0'+AD_dat/1;

    if(num == 0){
        putch_USART1(Decimal[3]);
        putch_USART1(Decimal[2]);
        putch_USART1(Decimal[1]);
        putch_USART1(Decimal[0]);
        putch_USART1(' ');
    }else if(num == 1){
        putch_USART1(Decimal[4]);
        putch_USART1('.');
        putch_USART1(Decimal[3]);
        putch_USART1(Decimal[2]);
        putch_USART1(Decimal[1]);
        putch_USART1(Decimal[0]);
        putch_USART1('V');
        putch_USART1(' ');
    }
}


void main(void)
{
    short Voltage;

    Init_USART1();
    Init_ADC();

    while (1)
    {
        ADCSRA |=(1<<ADSC);
        Voltage = (short)((0.0025*ADCW)*10000);
        if(getch_USART1()=='a'){
            LCD_Decimal(0,ADCW);
            LCD_Decimal(1,Voltage);
        }

    }
}