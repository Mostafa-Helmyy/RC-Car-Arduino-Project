char t;

const int trigPin = 7;
const int echoPin = 6;

const int buzzerPin = 5;

long duration;
int distance;

void setup() {

  pinMode(13, OUTPUT);  // Left motors forward
  pinMode(12, OUTPUT);  // Left motors reverse
  pinMode(11, OUTPUT);  // Right motors forward
  pinMode(10, OUTPUT);  // Right motors reverse

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t);
  }

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= 30 && distance > 20) {

    tone(buzzerPin, 500);
    delay(300);
    noTone(buzzerPin);
    delay(300);
  }

  else if (distance <= 20 && distance > 10) {

    tone(buzzerPin, 700);
    delay(150);
    noTone(buzzerPin);
    delay(150);
  }

  else if (distance <= 10) {

    tone(buzzerPin, 1000);
  }

  else {

    noTone(buzzerPin);
  }

  if (t == '1') {

    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
  }

  else if (t == '2') {

    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
  }

  else if (t == '3') {

    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
  }

  else if (t == '4') {

    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
  }

  else if (t == '5') {

    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
  }

  delay(100);
}