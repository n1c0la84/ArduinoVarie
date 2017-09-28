const int LED0 = 9;
const int LED1 = 11;
const int LED2 = 13;
const int BUZZER = 2;

void setup() {
  // put your setup code here, to run once:
    pinMode(LED0, OUTPUT);
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  randomSeed(analogRead(A0));
  int number = random(1, 7);
  output_number(number);
  tone(BUZZER, 100, 500);
  delay(2000);
}

void output_number(int number) {
  digitalWrite(LED0, number & B001);
  digitalWrite(LED1, number & B010);
  digitalWrite(LED2, number & B100);
}

