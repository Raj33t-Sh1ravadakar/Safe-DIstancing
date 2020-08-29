const int pingPin = 2; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 4; // Echo Pin of Ultrasonic Sensor
int buzzPin = 3;

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(buzzPin, OUTPUT);
   digitalWrite(buzzPin, LOW);
}

void loop() {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   if(cm>=2000)
   {
    digitalWrite(buzzPin, HIGH);
   }
   if(cm<=100)
   {
    digitalWrite(buzzPin, HIGH);
   }
   else
   {
    digitalWrite(buzzPin, LOW);
   }
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
