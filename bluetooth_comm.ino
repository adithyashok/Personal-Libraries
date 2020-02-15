// Bluetooth setup
#define ledPin LED_BUILTIN
#include <SoftwareSerial.h>
SoftwareSerial BT(3, 4);
int state = 0;
int state_prev = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(115200); // define the proper baudrate, which is 115200
  BT.begin(115200); // setup bluetooth
}

void loop() {
 if (BT.available()) /* If data is available on serial port */{
     state = BT.parseInt();
 } 
 if (state == 1) {
  state_prev = state;
  digitalWrite(ledPin, LOW); // Turn LED OFF
  Serial.println("LED: OFF"); // Send back, to the phone, the String "LED: ON"
  state = 0;
 }
 else if (state == 2) {
  state_prev = state;
  digitalWrite(ledPin, HIGH);
  Serial.println("LED: ON");;
  state = 0;
 }

 else if(state_prev == 2){
  digitalWrite(ledPin, HIGH);
  delay(250);
  digitalWrite(ledPin, LOW);
  delay(250);
 }

 
}
