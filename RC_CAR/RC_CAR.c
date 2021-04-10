#include <delay.h>
#include <mega128.h>
#include <stdio.h>
#include <LCD.h>

#define SONIC_DIS 116

#define SERVO_ZERO 0

unsigned char msec, sec=1, min, hour;

void Init_Timer2(void);
void Motor_Init();
void Init_Timer3A();

void Servo_Motor(int angle);
void Sonic(int* Sonic_L, int* Sonic_M, int* Sonic_R,);
void insertion_sort(int list[], int n);
void IR(unsigned char* IR_state);
void DC_Motor(int DC_Left, int DC_Right);

void Watch_Print();



void main()
{
/************************* 아트메가 초기화 *********************************/

    unsigned char IR_state=0; //적외선 센서의 black or white 표시 0비트 오른쪽, 1비트 왼쪽
    int Sonic_L, Sonic_M, Sonic_R, Sonic_Diff; // 초음파 센서로 센싱한 거리
    //int turn_cnt;

    SREG &= 0x7f;  //안정적인 동작을 위해 인터럽트 차단

    Init_Timer3A();  // 서보모터 타이머
    Motor_Init();    // DC모터 타이머
    Port_Init();     // LCD 포트 초기화
    LCD_Init();      // LCD 초기화
    Init_Timer2();   // LCD에 표시할 타이머 초

    DDRD=0x00;  // 초음파 echo 수신
    DDRF=0x00;  // 적외선 센서부분
    DDRB=0xf1;        // 초음파 동작부 / 모터 속도 제어부.
    DDRE=0xff;        // 모터 출력부.

    SREG |= 0x80; // 인터럽트 허용






/************************* 주행 알고리즘 START**********************/

    /////////초반 직진 구간///////
    Servo_Motor(0);
    //DC_Motor(100, 100); // 디버깅을 위해 지움
    //delay_ms(1000);
    ////////////////////////////

    while(1)
    {

        Sonic(&Sonic_L, &Sonic_M, &Sonic_R);
/////////////////////////////////초음파 주행 알고리즘////////////////////////

        // 초음파 좌우 거리의 차
        Sonic_Diff = Sonic_L-Sonic_R;

        //////////////벽에 아주 근접했을시 정지 및 후진 주행//////////////
        // 1. 좌우 초음파 초근접  감지
        // 2. 정지
        // 3. 서보모터 방향 전환 및 약간 후진
        // 4. 서보모터 방향 전환 및 약간 전진
        // 5. 정상 동작 복귀

//        if(Sonic_L<10){ //일시정지 이후 서보 꺾어 출발. (왼쪽이 가까워진 상태) -> 우회전
//            DC_Motor(0,0); //left, right / +:전진  -후진 / -100, -50, 0, 50, 100 5개의 값
//            delay_ms(50); // 딜레이 사용시 LCD 타이머에 딜레이 발생하는 문제 있음
//            Servo_Motor(20);
//            DC_Motor(50,50);
//            delay_ms(50);
//        } else if(Sonic_R<10){ //일시정지 이후 서보 꺾어 출발. (오른쪽이 가까워진 상태) -> 좌회전
//            DC_Motor(0,0); //left right
//            delay_ms(50);
//            Servo_Motor(-20);
//            DC_Motor(50,50);
//            delay_ms(50);
//        }

        //////////////////////////////////////////////////////////////



        /////////////////// 코너 좌회전, 우회전 ////////////////////////
        // 1. 전방 거리 일정 이하 && 좌우 거리 큰 차이 인식
        // 2. 정지
        // 3. 서보모터 회전 및 후진
        // 4. 정지
        // 5. 서보모터 방향 회전 및 직진
        // 6. 필요 시 위의 과정을 일정기간 반복
        // 7. 정상 동작 복귀



        //Sonic_Diff : 왼쪽 - 오른쪽
        if((Sonic_M<60)&&(Sonic_M>8)&&(Sonic_L>20)){//->일정 영역에서의 초음파 감지 불가     //정면 벽과 가까워지고 왼쪽이 뚫린 상태 (좌회전), 거리가 너무 멀면 오히려 거리가 작게 나옴
            DC_Motor(0,0);                              // 전체적으로 오른쪽으로 갈 때보다 높은 값 필요
            delay_ms(200); // 완전히 멈추는데 200정도 필요
            Servo_Motor(-40);    // 뒷바퀴가 너무 안 돌아서 방향을 그대로 하는 것보다는 이렇게 하는 것이 좋음
            delay_ms(100);        //한쪽 바퀴는 앞으로, 다른 바퀴는 정지
            DC_Motor(-50, 100);  //(0,100)을 넣을 경우 왼쪽 바퀴가 돌아가서 이것을 막기 위한 것.
            delay_ms(1200);       //90도 회전 : 1200~정도의 딜레이 ->건전지 사용량에 따라 다름

            DC_Motor(0,0);
            Servo_Motor(0);
            delay_ms(200);

            Sonic(&Sonic_L, &Sonic_M, &Sonic_R);  // 현재 상태를 파악하기 위해 초음파 사용
            delay_ms(100);

            while((Sonic_L>50)&&(Sonic_M>35)){   // 턴을 완벽하게 했으나 왼쪽이 뚫려있는 경우 또 한번 도는 것을 방지하기 위해 사용
                DC_Motor(100, 100);
                delay_ms(50);
                DC_Motor(0, 0);
                delay_ms(100);
                Sonic(&Sonic_L, &Sonic_M, &Sonic_R);
                delay_ms(100);
                Sonic(&Sonic_L, &Sonic_M, &Sonic_R);
            }

            if((Sonic_L>20)&&(Sonic_R>20)){
                if(Sonic_L>Sonic_R){
                    Servo_Motor(-40);    // 뒷바퀴가 너무 안 돌아서 방향을 그대로 하는 것보다는 이렇게 하는 것이 좋음
                    delay_ms(100);        //한쪽 바퀴는 앞으로, 다른 바퀴는 정지
                    DC_Motor(-50, 100);  //(0,100)을 넣을 경우 왼쪽 바퀴가 돌아가서 이것을 막기 위한 것.
                    delay_ms(100);       //90도 회전 : 1200~정도의 딜레이 ->건전지 사용량에 따라 다름
                }
                else if(Sonic_R>Sonic_L){
                    Servo_Motor(35);
                    delay_ms(100);
                    DC_Motor(100, -100);
                    delay_ms(100);
                }
                delay_ms(200);
                Sonic(&Sonic_L, &Sonic_M, &Sonic_R);
                delay_ms(100);
            }

        } else if((Sonic_M<40)&&(Sonic_M>8)&&(Sonic_R>20)) {         //정면 벽과 가까워지고 오른쪽이 뚫린 상태 (우회전), 거리가 너무 멀면 오히려 거리가 작게 나옴,
            DC_Motor(0,0);                                               // 정면 벽 기준이 40이상이면 오히려 뒤로 빠집니다.
            delay_ms(200);                                           //Sonic_R의 최댓값은 19정도의 수치
            Servo_Motor(35);
            delay_ms(100);
            DC_Motor(100, -100);
            delay_ms(1200);

            DC_Motor(0, 0);
            Servo_Motor(0);
            delay_ms(200);

            Sonic(&Sonic_L, &Sonic_M, &Sonic_R);
            delay_ms(100);

            while((Sonic_R>50)&&(Sonic_M>35)){
                DC_Motor(100, 100);
                delay_ms(50);
                DC_Motor(0, 0);
                delay_ms(100);
                Sonic(&Sonic_L, &Sonic_M, &Sonic_R);
                delay_ms(100);
            }
            if((Sonic_L>20)&&(Sonic_R>20)){
                if(Sonic_L>Sonic_R){
                    Servo_Motor(-40);    // 뒷바퀴가 너무 안 돌아서 방향을 그대로 하는 것보다는 이렇게 하는 것이 좋음
                    delay_ms(100);        //한쪽 바퀴는 앞으로, 다른 바퀴는 정지
                    DC_Motor(-50, 100);  //(0,100)을 넣을 경우 왼쪽 바퀴가 돌아가서 이것을 막기 위한 것.
                    delay_ms(100);       //90도 회전 : 1200~정도의 딜레이 ->건전지 사용량에 따라 다름
                }
                else if(Sonic_R>Sonic_L){
                    Servo_Motor(35);
                    delay_ms(100);
                    DC_Motor(100, -100);
                    delay_ms(100);
                }
                delay_ms(200);
                Sonic(&Sonic_L, &Sonic_M, &Sonic_R);
                delay_ms(100);
            }

        }

        //////////////////////////////////////////////////////////////

        ///////////////////// 일반주행모드 /////////////////////////////
        // 1. 좌우 초음파 거리 차이 감지-> 차이가 일정 값 이상이면 살짝 회전
        //    거리 차이가 너무 크면 개방 공간에 있는 것이므로 각도를 바꾸지 않음
        // 2. 해당 차이를 서보모터에 전달
        // 3. 지속적인 직진

        if(((Sonic_Diff<=2)&&(Sonic_Diff>=-2))){
            Servo_Motor(-Sonic_Diff*12); // 방향은 -를 붙여야 알맞음
        }
        else if(((Sonic_Diff<=4)&&(Sonic_Diff>=-4))){
            Servo_Motor(-Sonic_Diff*8);
        }
        else if(((Sonic_Diff<=7)&&(Sonic_Diff>=7))){
            Servo_Motor(-Sonic_Diff*6);
        }

        else if(((Sonic_Diff<=15)&&(Sonic_Diff>=-15))){
            Servo_Motor(-Sonic_Diff*3);
        }
        DC_Motor(100, 100); // 바퀴 멈춤 방지
        delay_ms(10);
        DC_Motor(50, 50);
        //////////////////////////////////////////////////////////////


        ///////////////////적외선 알고리즘////////////////////////

//        if((Sonic_L>40)&&(Sonic_M>40)&&(Sonic_R>40)){ //개방 공간일 때만 IR 동작
//            IR(&IR_state);
//
//            switch(IR_state){ // state의 0번 비트와 1번 비트가 다를 때만 즉 양쪽 IR의 white, black가 다를 때만 동작
//                case 0x01: // 0001 -> 오른쪽  IR에 High -> 왼쪽  black, 오른쪽 white
//                    Servo_Motor(-20); //왼쪽 회전
//                    DC_Motor(50,50);
//                    delay_ms(50);
//                break;
//
//                case 0x02: //0010 -> 왼쪽  IR에 High -> 왼쪽 white, 오른쪽 black
//                    Servo_Motor(20); // 오른쪽 회전
//                    DC_Motor(50,50);
//                    delay_ms(50);
//                break;
//            }
//        }


        ///////////////////////////////////////////////////////



/************************* 주행 알고리즘 END **********************/
        Watch_Print(); // 타이머 출력
    }
}


void Motor_Init()
{
    TCCR1A |= (1<<COM1A1)|(1<<WGM10)|(1<<COM1B1);
    TCCR1B |= (1<<WGM12)|(1<<CS11);   //비반전, 고속PWM 모드, 8분주
}

void Init_Timer3A()
{
    TCCR3A = 0x82;   //1010 1010 -> 1000 0010  -> DC모터 출력부를 꺼버리는 현상. 수정완료
    //비교일치에서 클리어, top에서 셋
    //FAST PWM(TOP=ICRn)
    TCCR3B = 0x1A;   //0001 1010
    //8분주 = 0.5usec
    OCR3AH = 3000>>8;
    OCR3AL = 3000&0xff;
    //DDRE = 0x08;                  //DC랑 충돌.
    ICR3H = 39999>>8;
    ICR3L = 39999&0xff;
}

void Servo_Motor(int angle)
{
    angle -= SERVO_ZERO;
    OCR3AH = (angle*14+3640)>>8;
    OCR3AL = (angle*14+3640)&0xFF;
}

void Sonic(int* Sonic_L, int* Sonic_M, int* Sonic_R,)
{
    unsigned char cnt;

    int out1;
    int out2;
    int out3;
    ///중간값 필터를 위한 변수
    int buf_L[9];
    int buf_M[9];
    int buf_R[9];

    unsigned char buffer1[];
    unsigned char buffer2[];
    unsigned char buffer3[];

    TIMSK &= ~(1<<OCIE2); //안정적인 동작을 위해 LCD 타이머 인터럽트 제거
    for(cnt=9; cnt!=0; cnt--){  // 표본 수집
        while(PIND.0==0){
            PORTB.0=1;
            delay_us(10);
            PORTB.0=0;
        }

        TCNT0=0;
        TCCR0=7;
        while(PIND.0==1);
        TCCR0=0;
        out1=TCNT0;
//        out1*=128;    // cm 변환 필요 없음
//        out1/=SONIC_DIS;
        buf_L[cnt] = out1;
        delay_ms(3); //딜레이 너무 작을시 무한루프 빠짐. 1ms에서 무한루프 경험

        while(PIND.1==0){
            PORTB.0=1;
            delay_us(10);
            PORTB.0=0;
        }
        TCNT0=0;
        TCCR0=7;
        while(PIND.1==1);
        TCCR0=0;
        out2=TCNT0;
//        out2*=128;
//        out2/=SONIC_DIS;
        buf_M[cnt] = out2;
        delay_ms(3);

        while(PIND.2==0){
            PORTB.0=1;
            delay_us(10);
            PORTB.0=0;
        }
        TCNT0=0;
        TCCR0=7;
        while(PIND.2==1);
        TCCR0=0;
        out3=TCNT0;
//        out3*=128;
//        out3/=SONIC_DIS;
        buf_R[cnt] = out3;
        delay_ms(3);
    }
    TIMSK |= (1<<OCIE2);


    // 삽임정렬 사용 -> 안정한 정렬, 대부분이 이미 정렬되어 있는 경우 매우 효율적, 레코드 수가 적으면 유리함
    // 퀵정렬은 이미 정렬되어 있을 경우 비효율적일 수 있음 + 코드비전에서 무한 재귀함수 호출이 가능하다며 컴파일러가 삭제함.
    insertion_sort(buf_L,9);
    if(buf_L[4]>60) buf_L[4]=60; // 초음파 이상 동작 방지
    *Sonic_L = buf_L[4];

    insertion_sort(buf_M,9);
    if(buf_M[4]>60) buf_M[4]=60;
    *Sonic_M = buf_M[4];

    insertion_sort(buf_R,9);
    if(buf_R[4]>60) buf_R[4]=60;
    *Sonic_R = buf_R[4];

    sprintf(buffer1,"%3dL",out1);
    LCD_pos(0,0);
    LCD_STR(buffer1);

    sprintf(buffer2,"%3dM",out2);
    LCD_STR(buffer2);

    sprintf(buffer3,"%3dR",out3);
    LCD_STR(buffer3);
}

void insertion_sort(int list[], int n)    // 매개변수로 정렬할 배열과 요소의 개수를 받음
{
    int i, j, key;

    // 인텍스 0은 이미 정렬된 것으로 볼 수 있다.
    for(i=1; i<n; i++){
        key = list[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사

        // 현재 정렬된 배열은 i-1까지이므로 i-1번째부터 역순으로 조사한다.
        // j 값은 음수가 아니어야 되고
        // key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+1번째로 이동
        for(j=i-1; j>=0 && list[j]>key; j--){
            list[j+1] = list[j]; // 레코드의 오른쪽으로 이동
        }
        list[j+1] = key;
    }
}

void IR(unsigned char* IR_state)
{
    if(PINF.0==1) //white, right
    {
        *IR_state |= 0x01;
    }
    else if(PINF.0==0) //black, right
    {
        *IR_state &= ~0x01;
    }

    if(PINF.1==1)  //white, left
    {
        *IR_state |= 0x02;
    }
    else if(PINF.1==0) //black, left
    {
        *IR_state &= ~0x02;
    }
}

void DC_Motor(int DC_Left, int DC_Right){ //0xa0으로 하면 어댑터로 동작시켜도 주행을 못 함. 왼쪽이 오른쪽보다 더 느림

    switch(DC_Left)                                     //왼쪽바퀴의 힘이 약함. 전체적으로 왼쪽 속도 빠르게 설정해둠. 오른쪽+1
    {
        case 100:            //000                              //기본 주행시.
            OCR1AH = 0x00;
            OCR1AL = 0xff;      //듀티비 설정 fast
            PORTE &= 0xef;      //0b11101111 과 기존 PORTE의 레지스터를  and 처리 -> 0x10자리만 0으로
            PORTE |= 0x20;      //DC모터 Left Forward
            break;
        case 50:           //011                                //우회전시 사용
            OCR1AH = 0x00;
            OCR1AL = 0xb8;      //듀티비 설정 slow                //우회전시 왼쪽바퀴를 더 빨리돌림. case50 이 그 역할.
            PORTE &= 0xef;      //0b11101111 과 기존 PORTE의 레지스터를  and 처리 -> 0x10자리만 0으로
            PORTE |= 0x20;      //DC모터 Left Forward
            break;
        case 0:            //001
            OCR1AH = 0x00;      //듀티비 설정 stop
            OCR1AL = 0x00;      //Stop은 OCR을 0으로 만듦으로써 멈추게 함. PORTE 변화 필요 x
            break;
        case -50:            //010
            OCR1AH = 0x00;
            OCR1AL = 0xe0;      //듀티비 설정 fast
            PORTE &= 0xdf;      //0b11011111 과 기존 PORTE의 레지스터를  and 처리 -> 0x20자리만 0으로
            PORTE |= 0x10;      //DC모터 Left Backward
            break;
        case -100:           //100                          //기본 후진 속도를 줄이면 움직이지 못함. 전진보다 빠른속도.
            OCR1AH = 0x00;
            OCR1AL = 0xff;      //듀티비 설정 slow
            PORTE &= 0xdf;      //0b11011111 과 기존 PORTE의 레지스터를  and 처리 -> 0x20자리만 0으로
            PORTE |= 0x10;      //DC모터 Left Backward
            break;
    }

    switch(DC_Right)
    {
        case 100:            //000
            OCR1BH = 0x00;
            OCR1BL = 0xff;      //듀티비 설정 fast
            PORTE &= 0xbf;      //0b10111111 과 기존 PORTE의 레지스터를  and 처리 -> 0x40자리만 0으로
            PORTE |= 0x80;      //DC모터 Right Forward
            break;
        case 50:           //011
            OCR1BH = 0x00;
            OCR1BL = 0xb0;      //듀티비 설정 slow
            PORTE &= 0xbf;      //0b10111111 과 기존 PORTE의 레지스터를  and 처리 -> 0x40자리만 0으로
            PORTE |= 0x80;      //DC모터 Right Forward
            break;
        case 0:            //001
            OCR1BH = 0x00;      //듀티비 설정 stop
            OCR1BL = 0x00;      //Stop은 OCR을 0으로 만듦으로써 멈추게 함. PORTE 변화 필요 x
            break;
        case -50:            //010
            OCR1BH = 0x00;
            OCR1BL = 0xb8;      //듀티비 설정 fast
            PORTE &= 0x7f;      //0b01111111  과 기존 PORTE의 레지스터를  and 처리 -> 0x80자리만 0으로
            PORTE |= 0x40;      //DC모터 Right Backward
            break;
        case -100:           //100
            OCR1BH = 0x00;
            OCR1BL = 0xff;      //듀티비 설정 slow
            PORTE &= 0x7f;      //0b01111111  과 기존 PORTE의 레지스터를  and 처리 -> 0x80자리만 0으로
            PORTE |= 0x40;      //DC모터 Right Backward
            break;

    }
}

void Init_Timer2(void)
{
    TCCR2 = (1<<WGM21)|(1<<CS22)|(1<<CS20); //1024분주비 "101"
    OCR2  = 50; // 정확히는 156.25
    TIMSK |= (1<< OCIE2);
    SREG |= 0x80;
}

interrupt [TIM2_COMP] void timer2_compare(void)
{
    // 인터럽트 외부에 if문을 사용할 시 너무 느립니다.
    msec++;
    if(msec >= 100)
    {
        msec = 0;
        sec++;
    }
    if( sec >= 60 )
    {
        sec = 0 ;
        min++;
    }
    if( min >= 60 )
    {
        min = 0;
        hour++;
    }
    if( hour >= 24 )
    {
        hour = 0;
    }
}

void Watch_Print(void)  //타이머 인터럽트 서비스 루틴으로 옮기면 main이 동작하지 않습니다.
{                       // 반드시 함수로 바깥에 넣어야 할 것 같습니다.
    LCD_pos(1, 0);
    LCD_CHAR(hour / 10 + '0');
    LCD_CHAR(hour % 10 + '0');

    LCD_pos(1, 3);
    LCD_CHAR(min / 10 + '0');
    LCD_CHAR(min % 10 + '0');

    LCD_pos(1, 6);
    LCD_CHAR(sec / 10 + '0');
    LCD_CHAR(sec % 10 + '0');

    LCD_pos(1, 9);
    LCD_CHAR(msec / 10 + '0');
    LCD_CHAR(msec % 10 + '0');
}