#include <mega128.h>
#include <LCD.h>

char key;
unsigned int flag;
unsigned int posX=0, posY=0;
unsigned char buf[] = "                 ";


interrupt [USART1_RXC] void usart1_receive()    //보드에 수신
{
    flag = 1;
    key = UDR1;
    if(key == 13)
    {
        posX = 0;
        posY++;
        if (posY == 2)
        {
            posY = 0;
        }
        LCD_pos(posY, posX);
        LCD_STR(buf);
        LCD_pos(posY, posX);
    }
    else
    {
        LCD_pos(posY, posX);
        LCD_CHAR(key);
        posX++;
    }
}

void Init_USART1()
{
    UCSR1B |= (1<<RXCIE1)|(1<<RXEN1);
    UCSR1C = 0x00;
    UCSR1C |= (1<<UCSZ11)|(1<<UCSZ10);           //비동기 1배속, 8bit문자, No-parity, 1 stop bit
    UBRR1H = 0x00;                               //230,400bps
    UBRR1L = 0x03;

    SREG = 0x80;
}

void main()
{
    Init_USART1();
    LCD_Init();
    Port_Init();
    LCD_pos(0,0);
    while(1);
}