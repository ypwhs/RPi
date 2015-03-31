#include <stdio.h>
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
void shiftOut(long indata){
    int i;
    for(i=0;i<8;i++){
        digitalWrite(DIO, indata & (1 << (7 - i)));
        blink(SCK);
        nanosleep(0,10000);
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

int main()
{
    setup();
    int i=0;
    while(1){
        i++;
        if(i==100){
            //printf("%ld\n",num);
            num++;
            i=0;
            if(num%100==0){
                digitalWrite(1, 1);
                delay(1);
                digitalWrite(1, 0);
            }
        }
        loop();
    }
}
