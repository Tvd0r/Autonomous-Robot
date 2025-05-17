int inainteStanga = 11; 
int inapoiStanga = 12; 
int inainteDreapta = 9; 
int inapoiDreapta = 10; 
int stangaViteza = 6; 
int dreaptaViteza = 5; 
 
const int triggerPin = 8; 
const int echoPin = 7; 
long duration; 
long cm; 
 
const int distantaPrag = 50; 
 
int senzor1; 
int senzor2; 
 
const int senzor1Pin = A1; 
const int senzor2Pin = A0; 
 
void setup() 
{  
  pinMode(inainteStanga, OUTPUT); 
  pinMode(inapoiStanga, OUTPUT); 
  pinMode(inainteDreapta, OUTPUT); 
  pinMode(inapoiDreapta, OUTPUT); 
  pinMode(stangaViteza, OUTPUT); 
  pinMode(dreaptaViteza, OUTPUT); 
  
  pinMode(triggerPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
 
   
 
  5 
 
  pinMode(senzor1Pin, INPUT); 
  pinMode(senzor2Pin, INPUT); 
 
} 
 
void loop() 
{ 
   
  //senzor ultrasonic 
  digitalWrite(triggerPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(triggerPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(triggerPin, LOW); 
   
  duration = pulseIn(echoPin, HIGH); 
  cm = duration/58; 
   
  Serial.print(cm); 
  Serial.print("cm"); 
  Serial.println(); 
   
  if(cm < distantaPrag) 
    opreste(1000); 
  else 
    mergiInainte(10, 255, 255); 
   
  //senzor IR 
  senzor1 = digitalRead(senzor1Pin); 
  senzor2 = digitalRead(senzor2Pin); 
   
  if((senzor1 == LOW) && (senzor2 == LOW)) 
    mergiInainte(10, 255, 255); 
  else if((senzor1 == HIGH) && (senzor2 == LOW)) 
    mergiDreapta(10, 255, 255); 
  else if((senzor1 == LOW) && (senzor2 == HIGH)) 
    mergiStanga(10, 255, 255); 
  else 
    opreste(10); 
} 
 
void mergiInainte(int t, int vSt, int vDr) 
{ 
  analogWrite(stangaViteza, vSt); 
   
 
  6 
 
  analogWrite(dreaptaViteza, vDr); 
  digitalWrite(inainteStanga, HIGH); 
  digitalWrite(inapoiStanga, LOW); 
  digitalWrite(inainteDreapta, LOW); 
  digitalWrite(inapoiDreapta, HIGH); 
  delay(t); 
} 
 
void mergiInapoi(int t, int vSt, int vDr) 
{ 
  analogWrite(stangaViteza, vSt); 
  analogWrite(dreaptaViteza, vDr); 
  digitalWrite(inainteStanga, LOW); 
  digitalWrite(inapoiStanga, HIGH); 
  digitalWrite(inainteDreapta, HIGH); 
  digitalWrite(inapoiDreapta, LOW); 
  delay(t); 
} 
 
void mergiStanga(int t, int vSt, int vDr) 
{ 
  analogWrite(stangaViteza, vSt); 
  analogWrite(dreaptaViteza, vDr); 
  digitalWrite(inainteStanga, LOW); 
  digitalWrite(inapoiStanga, HIGH); 
  digitalWrite(inainteDreapta, HIGH); 
  digitalWrite(inapoiDreapta, LOW); 
  delay(t); 
} 
 
void mergiDreapta(int t, int vSt, int vDr) 
{ 
  analogWrite(stangaViteza, vSt); 
  analogWrite(dreaptaViteza, vDr); 
  digitalWrite(inainteStanga, HIGH); 
  digitalWrite(inapoiStanga, LOW); 
  digitalWrite(inainteDreapta, HIGH); 
  digitalWrite(inapoiDreapta, LOW); 
  delay(t); 
} 
 
 
void opreste(int t) 
{ 
digitalWrite(inainteStanga, LOW); 
digitalWrite(inapoiStanga, LOW); 
digitalWrite(inainteDreapta, LOW); 
digitalWrite(inapoiDreapta, LOW); 
delay(t); 
} 