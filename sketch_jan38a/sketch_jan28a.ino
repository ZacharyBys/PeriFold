#include <Servo.h>

Servo servoDown; 
Servo servoRight;
Servo servoLeft; 

const int leftUp = 170;
const int leftFlat = 10;
const int downUp = 15;
const int downFlat = 160;
const int rightUp = 0;
const int rightFlat = 125; 

const int rightWingHigh = 60;
const int rightWingLow = 100;
const int leftWingHigh = 80;
const int leftWingLow = 35;

const int redPin = A1;
const int greenPin = A2;
const int bluePin = A3;

const int irSensor = A4;

int idleCounter = 0;

void setup() {
  servoDown.attach(5);  
  servoRight.attach(3);
  servoLeft.attach(6);
  Serial.begin(9600);

  setColor(255,0,0);
  putFlat(); 
  //marioTheme();
  delay(3000); 

}

void loop() {
  // put your main code here, to run repeatedly: 156 and 8
   idleCounter++;
   if (idleCounter > 250) {
      idleEmotion();
      idleCounter = 0;
   }
   delay(100);
   setColor(0,255,0);
   int irValue=analogRead(irSensor);
   
   if (irValue > 300) {
    delay(2500);
    irValue=analogRead(irSensor);
    if ( irValue >300){
      
      coinSound();
      setColor(255,0,0);
      delay(500);
      
      
      foldClothes();
      //levelClear();
      setColor(0, 0, 255);  //blue while waiting
      delay(1000);
      int freakoutCounter = 0;
      while(checkirAfterDone()){
      if (freakoutCounter > 6) {
        setColor(255,0,255);
        easterEgg();
        setColor(255,0,0);
      }
      delay(1000);
      freakoutCounter++;
      }
      idleCounter = 0;
   } else {
      setColor(255, 255, 153);
      confused();
      idleCounter = 0;
   }
}
}

bool checkirAfterDone(){
  if(analogRead(irSensor)>300){
    delay(500);
    if(analogRead(irSensor)>300){
      return true;
    }
  }else{
    return false;
  }
}

void foldClothes() {
   servoRight.write(rightUp);
   delay(1000);
   servoRight.write(rightFlat);
   delay(1000);
   servoLeft.write(leftUp);
   delay(1000);
   servoLeft.write(leftFlat);
   delay(1000);
   servoDown.write(downUp);
   delay(1000);
   servoDown.write(downFlat);
   delay(1000);
}

void putFlat() {
   servoDown.write(downFlat);
   delay(1000);
   servoRight.write(rightFlat);
   delay(1000);
   servoLeft.write(leftFlat);
   delay(1000);
}

void coinSound() {
  tone(9,1568,100);
  delay(100);
  tone(9,2093,150);
}

void marioTheme() {
   tone(9,660,100);
delay(150);
tone(9,660,100);
delay(300);
tone(9,660,100);
delay(300);
tone(9,510,100);
delay(100);
tone(9,660,100);
delay(300);
tone(9,770,100);
delay(550);
tone(9,380,100);
delay(575);

tone(9,510,100);
delay(450);
tone(9,380,100);
delay(400);
tone(9,320,100);
delay(500);
tone(9,440,100);
delay(300);
tone(9,480,80);
delay(330);
tone(9,450,100);
delay(150);
tone(9,430,100);
delay(300);
tone(9,380,100);
delay(200);
tone(9,660,80);
delay(200);
tone(9,760,50);
delay(150);
tone(9,860,100);
delay(300);
tone(9,700,80);
delay(150);
tone(9,760,50);
delay(350);
tone(9,660,80);
delay(300);
tone(9,520,80);
delay(150);
tone(9,580,80);
delay(150);
tone(9,480,80);
delay(500);
}

//Musical Note Frequencies
unsigned int C6 = 1047;
unsigned int Ab5 = 831;
unsigned int Bb5 = 932;
unsigned int G5 = 784;
unsigned int F5 = 698;
unsigned int E5 = 659;
unsigned int Eb5 = 622;
unsigned int D5 = 587;
unsigned int Db5 = 554;
unsigned int C5 = 523;
unsigned int B4 = 494;
unsigned int Bb4 = 466;
unsigned int nA4 = 440;
unsigned int Ab4 = 415;
unsigned int G4 = 392;
unsigned int Gb4 = 370;
unsigned int F4 = 349;
unsigned int E4 = 330;
unsigned int Eb4 = 311;
unsigned int D4 = 294;
unsigned int Db4 = 277;
unsigned int C4 = 262;
unsigned int B3 = 247;
unsigned int Bb3 = 233;
unsigned int nA3 = 220;
unsigned int G3 = 196;
unsigned int Gb3 = 185;
unsigned int F3 = 175;
unsigned int E3 = 165;

const int note = 9;

//User defined function for the song
void levelClear()               
{
  /*tone(note,G3);
  delay(166);
  tone(note,C4);
  delay(166);
  tone(note,E4);
  delay(166);
  tone(note,G4);
  delay(166);
  tone(note,C5);
  delay(166);
  tone(note,E5);
  delay(166);
  tone(note,G5);
  delay(500);
  tone(note,E5);
  delay(500);*/
 
  tone(note,E3);
  delay(166);
  tone(note,C4);
  delay(166);
  tone(note,Eb4);
  delay(166);
  tone(note,Ab4);
  delay(166);
  tone(note,C5);
  delay(166);
  tone(note,Eb5);
  delay(166);
  tone(note,Ab5);
  delay(500);
  tone(note,Eb5);
  delay(500);
 
  tone(note,Bb3);
  delay(166);
  tone(note,D4);
  delay(166);
  tone(note,F4);
  delay(166);
  tone(note,Bb4);
  delay(166);
  tone(note,D5);
  delay(166);
  tone(note,F5);
  delay(166);
  tone(note,Bb5);
  delay(500);
  noTone(note);
  delay(50);
  tone(note,Bb5);
  delay(166);
  noTone(note);
  delay(50);
  tone(note,Bb5);
  delay(166);
  noTone(note);
  delay(50);
  tone(note,Bb5);
  delay(166);
  tone(note,C6);
  delay(750);
  noTone(note);
}

void setColor(int red, int green, int blue)
{
 
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

void easterEgg(){
  tone(note, 330);
  servoLeft.write(leftWingHigh);
  servoRight.write(rightWingHigh);
  delay(1000);
  tone(note, 350);
  servoLeft.write(leftWingLow);
  servoRight.write(rightWingLow);
  delay(150);
  tone(note, 330);
  delay(150);
  tone(note, 350);
  delay(150);
  tone(note, 330);
  delay(150);
  tone(note, 350);
  servoLeft.write(leftWingHigh);
  servoRight.write(rightWingHigh);
  delay(150);
  tone(note, 330);
  delay(150);
  tone(note, 350);
  delay(150);
  tone(note, 330);
  delay(150);
  tone(note, 350);
  servoLeft.write(leftFlat);
  servoRight.write(rightFlat);
  delay(150);
  noTone(note);
}

void idleEmotion() {
  setColor(255,0,255);
  tone(note, 698);
  delay(150);
  tone(note, 587);
  delay(150);
  tone(note, 698);
  delay(150);
  tone(note, 587);
  setColor(255,0,0);
  delay(150);
  tone(note, 698);
  delay(150);
  tone(note, 587);
  delay(150);
  setColor(255,0,255);
  tone(note, 698);
  delay(300);
  noTone(note);
}

void confused() {
  servoLeft.write(leftWingHigh);
  servoRight.write(rightWingHigh);
  delay(150);
  tone(note, 880);
  delay(150);
  tone(note, 523);
  delay(150);
  tone(note, 880);
  delay(150);
  tone(note, 523);
  servoLeft.write(leftWingLow);
  servoRight.write(rightWingLow);
  delay(150);
  tone(note, 880);
  delay(150);
  tone(note, 523);
  delay(150);
  tone(note, 880);
  delay(150);
  tone(note, 523);
  servoLeft.write(leftWingHigh);
  servoRight.write(rightWingHigh);
  delay(150);
  tone(note, 880);
  delay(150);
  tone(note, 523);
  delay(150);
  tone(note, 880);
  delay(150);
  tone(note, 523);
  servoLeft.write(leftFlat);
  servoRight.write(rightFlat);
  noTone(note);
  delay(500);
}


