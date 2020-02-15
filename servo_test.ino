#include <Servo.h>

Servo myservo;
int pos1 = 0;


void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  Serial.begin(9600);

}

void loop() {
  pos1 = 0;
  do{
          myservo.write(pos1);
          delay(100);
          pos1 = (pos1 + 5);
          Serial.println(pos1);
          }while(pos1 < 180);// put your main code here, to run repeatedly:

  pos1 = 180;

  delay(1000);
  do{
          myservo.write(pos1);
          delay(100);
          pos1 = (pos1 - 5);
          Serial.println(pos1);
          }while(pos1 > 0);// put your main code here, to run repeatedly:

          

}
