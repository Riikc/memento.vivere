//Brain #1 Sensor for temperature,humidity and Ultrasonic distance
//Blink each EL channel (A-H) on according to stimulus & repeat

#include <dht.h>
dht DHT;

// use unsigned long for long variables that hold time, too much data for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// check to see if it's time to blink the EL wire; that is, if the difference
// between the current time and last time you blinked the LED is bigger than
// the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

// constants won't change:
const long cooldown = 3500; // interval for sensors
const int trigPin = 11; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 12; // Echo Pin of Ultrasonic Sensor

long duration, inches, cm;   // Variables to make the calculation for measured distance.
long microseconds;


void setup() 
{ 
  Serial.begin(9600);   //Begin Comms with computer

  //DHT Sensor Setup
  delay(1500);//Delay before boot & access sensor 
  
  // The EL channels are on pins 2 through 9
  // Initialize the pins as outputs
  pinMode(2, OUTPUT);  // channel A  
  pinMode(3, OUTPUT);  // channel B   
  pinMode(4, OUTPUT);  // channel C
  pinMode(5, OUTPUT);  // channel D    
  pinMode(6, OUTPUT);  // channel E
  pinMode(7, OUTPUT);  // channel F
  pinMode(8, OUTPUT);  // channel G
  pinMode(9, OUTPUT);  // channel H
  // We also have two status LEDs, pin 10 on the Escudo, 
  // and pin 13 on the Arduino itself
  pinMode(A0, INPUT); //DHT sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() 
{

  int x;
  
    float temperature = (DHT.temperature);
    float humidity = (DHT.humidity);
    float distance = (cm);
        
  // check to see if the difference between the current time
  // and last time you blinked the EL is bigger than
  // the interval at which you want to blink the LED.
  // Test DHT & Ultrasonic sensors 
  unsigned long currentMillis = millis();
  
    if (currentMillis - previousMillis >= cooldown){
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    
    DHT.read11(A0);

    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);

//Variables to make the calculation for measured distance.
inches = microsecondsToInches(duration);
cm = microsecondsToCentimeters(duration);

    Serial.print(inches);
    Serial.print(" in, ");
    Serial.print(cm);
    Serial.print(" cm");
    Serial.println();


    }
 
// ACTION#1 :Step through three EL channels (pins 2 through 4)
for (x=2; x<=4; x++){
if(temperature <=20.00)
    {
    digitalWrite(x, HIGH);   // turn the EL channel on
    delay(1000);             // wait for 1/10 second
    digitalWrite(x, LOW);    // turn the EL channel off
    }
  else if(temperature >= 21.00 && temperature <= 25.00)
    {
    digitalWrite(x, HIGH);   // turn the EL channel on
    delay(750);            // wait for 1/10 second
    digitalWrite(x, LOW);    // turn the EL channel off
    }
    else if(temperature >= 26.00 && temperature <= 30.00)
    {
    digitalWrite(x, HIGH);   // turn the EL channel on
    delay(500);            // wait for 1/10 second
    digitalWrite(x, LOW);    // turn the EL channel off
    }
    else if(temperature >= 31.00 && temperature < 35.00)
    {
    digitalWrite(x, HIGH);   // turn the EL channel on
    delay(250);            // wait for 1/10 second
    digitalWrite(x, LOW);    // turn the EL channel off
    }
  else if(temperature >= 36.00)
    {
    digitalWrite(x, HIGH);   // turn the EL channel on
    delay(100);              // wait for 1/10 second
    digitalWrite(x, LOW);    // turn the EL channel off
    }

  }

// ACTION #2 Step through next three EL channels (pins 5 through 7)
  for (x=5; x<=7; x++){
  if(cm <= 4)
  {
    digitalWrite(x, HIGH);   // turn the EL channel on
    delay(100);              // wait for 1/10 second
    digitalWrite(x, LOW);    // turn the EL channel off

  }
  else if(cm >= 5 && cm <= 20)
  {
    digitalWrite(x, HIGH);   // turn the EL channel on
    delay(250);              // wait for 1/10 second
    digitalWrite(x, LOW);    // turn the EL channel off

  }
  else if(cm >= 21 && cm <= 40)
  {
    digitalWrite(x, HIGH);   // turn the EL channel on
    delay(500);              // wait for 1/10 second
    digitalWrite(x, LOW);    // turn the EL channel off
 
  }
  else if(cm >= 41 && cm <= 80)
  {
    digitalWrite(x, HIGH);   // turn the EL channel on
    delay(750);              // wait for 1/10 second
    digitalWrite(x, LOW);    // turn the EL channel off

  }
  else if(cm >= 81)
  {
    digitalWrite(x, HIGH);   // turn the EL channel on
    delay(1000);              // wait for 1/10 second
    digitalWrite(x, LOW);    // turn the EL channel off

  }
  }

  // ACTION #3 Step through last two EL channels (pins 8 through 9)
 for (x=8; x<=9; x++){
  if(humidity <=30.00)
  {
    digitalWrite(x, HIGH);   // turn the EL channel on
    delay(1000);              // wait for 1/10 second
    digitalWrite(x, LOW);    // turn the EL channel off
   }
  else if(humidity >= 31.00 && humidity < 35.00)
  {
    digitalWrite(x, HIGH);   // turn the EL channel on
    delay(750);              // wait for 1/10 second
    digitalWrite(x, LOW);    // turn the EL channel off
  }
  else if(humidity >= 36.00 && humidity < 40.00)
  {
    digitalWrite(x, HIGH);   // turn the EL channel on
    delay(500);              // wait for 1/10 second
    digitalWrite(x, LOW);    // turn the EL channel off
  }
  else if(humidity >= 41.00 && humidity < 50.00)
  {
    digitalWrite(x, HIGH);   // turn the EL channel on
    delay(250);              // wait for 1/10 second
    digitalWrite(x, LOW);    // turn the EL channel off
  }
  else if(humidity >= 50.00)
  {
    digitalWrite(x, HIGH);   // turn the EL channel on
    delay(100);              // wait for 1/10 second
    digitalWrite(x, LOW);    // turn the EL channel off
  }
  }

} /*Loop has ended*/
/* The following trigPin/echoPin cycle is used to determine the
   distance in cm & inches of the nearest object by bouncing soundwaves off of it. */ 
long microsecondsToInches(long microseconds)
{
return microseconds / 74 / 2;
}
long microsecondsToCentimeters(long microseconds)
{
return microseconds / 29 / 2;
}
