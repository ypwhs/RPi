#include <wiringPi.h>
#include <stdio.h>
#define LED 0
#define Sensor 1
void takePhoto(){
	FILE *p=fopen("img/now.txt","r");
	int num = 0;
	if(p == NULL){
		FILE *q=fopen("img/now.txt","w");
		fprintf(q, "%d", num+1);
		num++;
		fclose(q);
	}else{
		fscanf(p, "%d", &num);
		FILE *q=fopen("img/now.txt","w");
		fprintf(q, "%d", num+1);
		num++;
		fclose(q);
		fclose(p);
	}
	char cmd[200]={0};
	sprintf(cmd, "raspistill -t 1 -o img/%d.jpg -w 1920 -h 1080", num);
	printf("%s\n", cmd);
	system(cmd);
}
int main()
{
	wiringPiSetup();
	pinMode(LED, OUTPUT);
	pinMode(Sensor, INPUT);
	digitalWrite(LED, LOW);
	while(1){
		int sensor = digitalRead(Sensor);
		if(sensor){
			digitalWrite(LED, HIGH);
			takePhoto();
		}else {
			printf("No human\n");
			digitalWrite(LED, LOW);
		}
		delay(500);
	}
}
