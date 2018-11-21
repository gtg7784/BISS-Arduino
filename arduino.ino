//HC02-48
#define TRIG 10
#define ECHO 11
//CDS
int bright = 0;
//IR
int IR = 0;
// Sound
int Sound = 0;

void setup() {
  //Serial start
  Serial.begin(9600);
  //CDS
  pinMode(16, INPUT);
  //HC02-48
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
  //Ultrasonic Raning Module
  pinMode(14, INPUT);
  pinMode(15, INPUT);
}

void loop() {
  //CDS
  bright = analogRead(16);
  Serial.print(bright); //print CDS
  Serial.print("|");

  digitalWrite(TRIG, LOW);
  delay(0.0002);
  digitalWrite(TRIG, HIGH);
  delay(0.001);
  digitalWrite(TRIG, LOW);

  
  long distance = pulseIn(ECHO, HIGH)/58.2;
  Serial.print(distance); //print HC02-48
  Serial.print("|");
  //Ultrasonic Ranging Module
  IR = analogRead(14);
  Serial.print(IR); //print right motor
  Serial.print("|");
  Sound = analogRead(15);
  Serial.print(Sound); //print right motor
  Serial.println(" ");
}