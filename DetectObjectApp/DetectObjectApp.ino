#define pirPin 2
int calibrationTime = 30;
long unsigned int lowIn;
long unsigned int pause = 5000;
boolean lockLow = true;
boolean takeLowTime;
int pirStat = 0;  

const int buzzer = 9; //buzzer to arduino pin 9


void setup(){
  Serial.begin(9600); // Starting Serial Terminal
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  pinMode(pirPin, INPUT);

}



const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor



long ultrasonic() {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   cm = microsecondsToCentimeters(duration);
   Serial.print(cm);
   Serial.print("cm");  
   Serial.println();
   delay(100);
   return cm;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

void loop() {
  
   if(ultrasonic()<30){
     tone(buzzer, 1000); // Send 1KHz sound signal...
      digitalWrite(pirPin,HIGH);
   }
   else{
    noTone(buzzer);
     digitalWrite(pirPin, LOW);
   }
}
