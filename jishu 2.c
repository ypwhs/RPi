#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <wiringPi.h>
int DIO = 7, SCK = 9, RCK = 8;
unsigned char t[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
void setup() {
    wiringPiSetup();
    pinMode(DIO, OUTPUT); pinMode(SCK, OUTPUT); pinMode(RCK, OUTPUT);
    pinMode(1, OUTPUT);
}
void blink(int pin){
  digitalWrite(pin, 1);
  digitalWrite(pin, 0);
}
int udelay = 5;
void shiftOut(long indata){
    int i,j;
    for(i=0;i<8;i++){
        digitalWrite(DIO, indata & (1 << (7 - i)));
        blink(SCK);
        usleep(udelay);
    }
}
long num=1;
void loop(){
    int i=0;
    long b=num;
    while(b>0){
        shiftOut(1 << (7 - i));
        shiftOut(t[b%10]);
        blink(RCK);
        b/=10;
        i++;
    }
}
void dispthread(void){
    while(1)loop();
}
int main()
{
    setup();
    int i=0,bei=10;
    printf("start thread\n");
    pthread_t id;
    pthread_create(&id,NULL,(void *) dispthread,NULL);
    printf("start\n");
    while(1){
        num++;
        if(num%100==0){
            digitalWrite(1, 1);
            usleep(1);
            digitalWrite(1, 0);
        }
        usleep(10000);
    }
}