#include <wiringPi.h>
#include <stdio.h>
#include <time.h>
#define LED 0
#define Sensor 1
void takePhoto(){
	FILE *p=fopen("/var/www/img/now.txt","r");
	int num = 0;
	if(p == NULL){
		FILE *q=fopen("/var/www/img/now.txt","w");
		fprintf(q, "%d", num+1);
		num++;
		fclose(q);
	}else{
		fscanf(p, "%d", &num);
		FILE *q=fopen("/var/www/img/now.txt","w");
		fprintf(q, "%d", num+1);
		num++;
		fclose(q);
		fclose(p);
	}
	char cmd[200]={0};
	sprintf(cmd, "raspistill -t 1 -o /var/www/img/%d.jpg -w 1920 -h 1080", num);

	FILE *log=fopen("/var/www/img/log.txt", "a");
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	rawtime += 8*3600;
	timeinfo = localtime ( &rawtime );
	fprintf(log, "%d\t%ld\t%s", num, rawtime, asctime(timeinfo));
	fclose(log);

	printf("%s\n", cmd);
	system(cmd);
}
int main()
{
	wiringPiSetup();
	pinMode(LED, OUTPUT);
	pinMode(Sensor, INPUT);
	while(1){
		int sensor = digitalRead(Sensor);
		if(sensor){
			delay(100);
			if(digitalRead(Sensor)){
				digitalWrite(LED, HIGH);
				takePhoto();
				delay(300);
				digitalWrite(LED, LOW);
			}
		}else {
			printf("No human\n");
			digitalWrite(LED, LOW);
		}
		delay(100);
	}
}