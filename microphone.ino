// Sound Activated EL Wire Brain
// Blink EL Wire to music and other ambient sound.
// Based on JenFoxBot's code
void setup() {
  Serial.begin(9600);  
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
//Initialize input pins on EL Sequencer
  pinMode(A1, INPUT);
}
void loop() 
{
  int amp = digitalRead(A1);

  //If Gate output detects sound, turn EL Wire on
  if(amp == HIGH){

    digitalWrite(2, HIGH); //turn EL channel on
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);

    delay(100);
  }

    digitalWrite(2, LOW); //turn EL channel off
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);

   
}
