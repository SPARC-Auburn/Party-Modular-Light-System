/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */
//const int pingPin = 6;
int counter = 0;
int sensorVal = 0;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  //Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(12, LOW);   // turn the LED on (HIGH is the voltage level)
  pinMode(2, INPUT_PULLUP);
}

// the loop function runs over and over again forever
void loop() { 
    sensorVal = digitalRead(2);
    //Serial.println(sensorVal);
    if (sensorVal==HIGH)
      strobe(5);
    else {
      digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(13, LOW);   // turn the LED on (HIGH is the voltage level)
    }
    
}
long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
void strobe (int t)
{
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(12, LOW);   // turn the LED on (HIGH is the voltage level)
    delay(t*100); 
    digitalWrite(13, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(t*100); // Approximately 10% duty cycle @ 1KHz
}
void cycle (int t)
{
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(12, LOW);   // turn the LED on (HIGH is the voltage level)
    for (double i =0; i<255;i++)
    {
     analogWrite(3, i);
     delay(t); // Approximately 10% duty cycle @ 1KHz
 
    }
    for (double i =255; i>0;i--)
    {
     analogWrite(3, i);
     delay(t); // Approximately 10% duty cycle @ 1KHz
 
    }
    digitalWrite(13, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
    for (double i =0; i<255;i++)
    {
     analogWrite(3, i);
     delay(t); // Approximately 10% duty cycle @ 1KHz
 
    }
    for (double i =255; i>0;i--)
    {
     analogWrite(3, i);
     delay(t); // Approximately 10% duty cycle @ 1KHz
 
    }
  
}
void fadeup(int t)
{
  for (double i =0; i<255;i++)
    {
     analogWrite(3, i);
     delay(t); // Approximately 10% duty cycle @ 1KHz
 
    }
}
void fadedown(int t)
{
  for (double i =255; i>0;i--)
    {
     analogWrite(3, i);
     delay(t); // Approximately 10% duty cycle @ 1KHz
 
    }
}



