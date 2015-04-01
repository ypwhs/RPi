#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <wiringPi.h>
#include <wiringShift.h>
int DIO = 7, SCK = 9, RCK = 8;
unsigned char t[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
void setup() {
    wiringPiSetup();
    pinMode(DIO, OUTPUT); pinMode(SCK, OUTPUT); pinMode(RCK, OUTPUT);
    pinMode(1, PWM_OUTPUT);
}
long num=1;
void blink(int pin){
    digitalWrite(pin,1);
    digitalWrite(pin,0);
}
void loop(){
    int i=0;
    long b=num;
    while(b>0){
        shiftOut(DIO,SCK,MSBFIRST,1 << (7 - i));
        shiftOut(DIO,SCK,MSBFIRST,t[b%10]);
        blink(RCK);
        b/=10;
        i++;
        delayMicroseconds(50);
    }
}
void dispthread(void){
    while(1)loop();
}
int main()
{
    setup();
    int i=0,bei=10;
    printf("显示线程开始\n");
    pthread_t id;
    pthread_create(&id,NULL,(void *) dispthread,NULL);
    printf("主线程开始\n");
    while(1){
        num++;
        pwmWrite(1,num%100);
        usleep(10000);
    }
}
