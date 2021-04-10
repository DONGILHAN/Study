
#include <mega128.h>
#include <LCD.h>;

int count = 0;
unsigned char cnt = 0;
unsigned char sec1, sec2, min, hour = 0;
unsigned char S1, S2, M, H = 0;
unsigned char Han[] = {0x0a, 0x1e, 0x03, 0x0a, 0x02, 0x10, 0x10, 0x1f};
unsigned char Kim[] = {0x1d, 0x05, 0x05, 0x00, 0x1f, 0x11, 0x11, 0x1f};
unsigned char str_team[] = " 13 Team";
unsigned char str_cnt[] = "00:00:00:00";
bit go = 1;

void Init_Reg()
{
    DDRB = 0xff;
    DDRD = 0x00;
}

void Init_INT()
{
    EIMSK = 0x0f;
    EICRA = 0xff;
    SREG |= 0x80;
}

void Init_Timer1()
{
    TIMSK = (1<<TOIE1) | (1<<OCIE2);
    TCCR1B = (1<<CS11);
    TCNT1 = -921;
    /*
    TCNT1H = 0xfb;
    TCNT1L = 0x27;
    */

}

interrupt [TIM1_OVF] void timer1_ovferflow()
{
    TCNT1 = -921;

    count++;

    if(count == 1000)
    {
        PORTB = ~PORTB;
        count = 0;
    }
}

void Init_Timer2()
{
    TCCR2 = (1<<WGM21) | (1<<CS21) | (1<<CS20);
    OCR2 = 23;
}

interrupt [TIM2_COMP] void timer2_compare()
{
    if(go == 1)
        cnt++;

    if(cnt == 100)
    {
        cnt = 0;
        sec1++;
        if(sec1 >= 100)
        {
            sec1 = 0;
            sec2++;
        }

        if(sec2 >= 60)
        {
            sec2 = 0;
            min++;
        }

        if(min >= 60)
        {
            min=0;
            hour++;
        }

        if(hour >= 24)
            hour = 0;
    }

}

void CGRAM_Set()
{
    int i;

    LCD_delay(1);
    LCD_Comm(0x40);
    LCD_delay(1);

    for(i=0; i<8; i++)
    {
        LCD_Data(Han[i]);
        LCD_delay(1);
    }

    LCD_Comm(0x48);
    LCD_delay(1);

    for(i=0; i<8; i++)
    {
        LCD_Data(Kim[i]);
        LCD_delay(1);
    }
}

void Init_Print()
{
    LCD_pos(0,0);
    LCD_Data(0x00);
    LCD_Data(0x01);
    LCD_STR(str_team);
    LCD_pos(1,0);
    LCD_STR(str_cnt);
}

void Cnt_Print()
{
    LCD_pos(1,0);
    LCD_CHAR(hour/10 + '0');
    LCD_CHAR(hour%10 + '0');

    LCD_pos(1,3);
    LCD_CHAR(min/10 + '0');
    LCD_CHAR(min%10 + '0');

    LCD_pos(1,6);
    LCD_CHAR(sec2/10 + '0');
    LCD_CHAR(sec2%10 + '0');

    LCD_pos(1,9);
    LCD_CHAR(sec1/10 + '0');
    LCD_CHAR(sec1%10 + '0');
}

interrupt [EXT_INT0] void ext_int0()
{
    go = ~go;
}

interrupt [EXT_INT1] void ext_int1()
{
    sec1 = 0;
    sec2 = 0;
    min = 0;
    hour = 0;
}

interrupt [EXT_INT2] void ext_int2()
{
    S1 = sec1;
    S2 = sec2;
    M = min;
    H = hour;
}

interrupt [EXT_INT3] void ext_int3()
{
    sec1 = S1;
    sec2 = S2;
    min = M;
    hour = H;
}

void main()
{
    Init_Reg();
    Init_INT();
    Init_Timer1();
    Init_Timer2();
    CGRAM_Set();
    LCD_Init();
    PORTB = 0xff;
    Init_Print();

    while(1)
        Cnt_Print();
}
