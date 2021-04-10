#include <mega128.h>

unsigned char ch;

interrupt [USART1_RXC] void usart1_receive (void)
{
    ch = UDR1;

    if(ch == '1') PORTB = 0x00;
    else if (ch == '2') PORTB = 0xff;

}


void Init_USART1(void)
{
    UCSR1A =0x02;
    UCSR1B = (1<<RXCIE1)|(1<<RXEN1)|(1<<TXEN1);

    UCSR1C = 0x0c;

    UBRR1H = 0x00;
    UBRR1L = 15;
    SREG |= 0x80;
}

void main(void)
{
    DDRB = 0xff;
    Init_USART1();
}