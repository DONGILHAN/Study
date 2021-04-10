#include <mega128.h>

void putch_USART1(char data)
{
    while( !(UCSR1A & (1<<UDRE1)));
    if( (data>='a') && (data <= 'z'))
    {
        data = data -'a'+'A';
    }
    else if( (data >='A') && (data <='Z'))
    {
        data = data - 'A' +'a';
    }
    else
    {
        data= '?';
    }
    UDR1 = data;
}

char getch_USART1(void)
{
    while (! (UCSR1A & (1<<RXC1)));
    return UDR1;
}


void Init_USART1(void)
{
    UCSR1A = 0x00;
    UCSR1B = (1<<RXEN1)|(1<<TXEN1);
    UCSR1C = (1<<UPM11)|(1<<UCSZ11)|(1<<UCSZ10);

    UBRR1H = 0;
    UBRR1L = 95;
}


void main(void)
{
    Init_USART1();
    while (1)
    {
        putch_USART1(getch_USART1());
    }
}