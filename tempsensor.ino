const int tempsensor = A0; 
const int buzzer = 7;
const int ledred = 8;
const int ledgreen = 9;

void setup(){
  pinMode(tempsensor , INPUT);
  pinMode(buzzer , OUTPUT);
  pinMode(ledred , OUTPUT);
  pinMode(ledgreen , OUTPUT);
  Serial.begin(9600);
}

void loop(){  
  int tempsensorvalue = analogRead(tempsensor);
  if (tempsensorvalue >= 309) {
    digitalWrite(ledgreen, LOW);
    digitalWrite(ledred, HIGH);
    tone(buzzer, 750);
    delay(300);
    digitalWrite(ledred, LOW);
    noTone(buzzer);
    delay(300);
    digitalWrite(ledred, HIGH);
  } else {
    noTone(buzzer);
    digitalWrite(ledgreen, HIGH);
    digitalWrite(ledred, LOW);

  }

  if (tempsensorvalue >= 284 && tempsensorvalue <= 309){
    digitalWrite(ledgreen, LOW);
    digitalWrite(ledred, HIGH);
    tone(buzzer, 700);
    delay(500);
    noTone(buzzer);
    delay(500);
  } else {
    noTone(buzzer);
  }
}

void checktempvalue(){
  int tempsensorvalue = analogRead(tempsensor);
  Serial.print("Temp value is : ");
  Serial.println(tempsensorvalue);
  delay(500);
}
