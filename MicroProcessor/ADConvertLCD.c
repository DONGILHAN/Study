#include <LCD.h>
#include <mega128.h>
#include <delay.h>
#include <stdio.h>

unsigned char sel = 0X00;
unsigned char temp= 0X00;
unsigned char key= 0X00;
unsigned char quit[] = "QUIT";

void LCD_Decimal(unsigned char num, short AD_dat){
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
    AD_dat=AD_dat%1;

    if(num == 0){
        LCD_Pos(0, 10);
        LCD_Data(Decimal[3]);
        LCD_Pos(0, 11);
        LCD_Data(Decimal[2]);
        LCD_Pos(0, 12);
        LCD_Data(Decimal[1]);
        LCD_Pos(0, 13);
        LCD_Data(Decimal[0]);
    }
    else if(num == 1){
        LCD_Pos(1, 10);
        LCD_Data(Decimal[4]);
        LCD_Pos(1, 11);
        LCD_Data('.');
        LCD_Pos(1, 12);
        LCD_Data(Decimal[3]);
        LCD_Pos(1, 13);
        LCD_Data(Decimal[2]);
        LCD_Pos(1, 14);
        LCD_Data(Decimal[1]);
        LCD_Pos(1, 15);
        LCD_Data(Decimal[0]);
        LCD_Pos(1, 16);
        LCD_Data('v');

    }
}

void Init_ADC(){
    ADMUX = (1<<REFS1)|(1<<REFS0);             //내부 기준전압 사용, 좌측정렬
    ADCSRA = (1<<ADEN)|(1<<ADFR)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);  //Enable, 128분주비
    ADCSRA |= (1<<ADSC);
}

void Init_USART1(){      //1배속 전송모드, 비동기모드, 19200Bps, 1 stop bit, 8 data bit
    UCSR1A = 0x00;
    UCSR1B |= (1<<RXEN1)|(1<<RXCIE1);
    UCSR1C = 0x00;
    UCSR1C |= (1<<UCSZ10)|(1<<UCSZ11); //비동기, 패리티x, 1정지비트, 8 data bit
    UBRR1H = 0x00;
    UBRR1L = 0x2f;     //47 = 19200

    SREG = 0x80;

}

//
interrupt[ADC_INT] void adc_isr(void){
    PORTB = 0xff;
}

interrupt [USART1_RXC] void usart1_receive(){   //보드에 수신
    sel = UDR1;
    if(sel != 13){
        temp = sel;
    }else if(sel == 13){
        key = temp;
    }
}

void main(){
    DDRD = 0x00;
    DDRB = 0xff;
    PORTB = 0xf0;
    Init_USART1();
    LCD_PORT_Init();
    LCD_Init();
    LCD_Pos(0,0);
    LCD_Str("Voltage:");
    LCD_Pos(1,0);
    LCD_Str("R.Value:");
    Init_ADC();

    while(1){
        short Voltage;
        Voltage = (short)((0.0025*ADCW)*10000);

        LCD_Decimal(0, ADCW);
        LCD_Decimal(1, Voltage);

        if(key == 'S'){
            ADCSRA = (1<<ADIF);     //flag 진입
            PORTB = 0x00;
        }
        if(key == 'F'){
            ADCSRA |= (1<<ADEN)|(1<<ADFR)|(1<<ADSC)|(1<<ADIE)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
            PORTB = 0xff;
        }
        if(key == 'Q'){
            ADCSRA = (1<<ADIF);
            LCD_Clear();
            LCD_Str(quit);
        }
        delay_ms(100);
    }
}