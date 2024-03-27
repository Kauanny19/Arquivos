#define led 3
#define buzzer 2
#define botao 8
#define ldr A0

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(botao, INPUT);
  pinMode(ldr, INPUT);

}
void loop() {

  Serial.println(digitalRead(botao));
  bool armado = false;

  // se o botao for apertado, muda estado para armado
  if (digitalRead(botao) == 1) {
    armado = true;
    delay(1000);
  }

  
  //enquanto estiver armado
  while (armado) {
   
    // se luz ligada, dispara alarme
    if (analogRead(ldr) < 500) {
      digitalWrite(led, HIGH);
      digitalWrite(buzzer, HIGH);
    }

    //se luz desligada, não dispara alarme
    else {
      digitalWrite(led, LOW);
      digitalWrite(buzzer, LOW);
    }

    //verifica se botao foi apertado
    if (digitalRead(botao) == 1) {

      //desliga buzzer e pisca o led
      digitalWrite(buzzer, LOW);
      digitalWrite(led, LOW);
      delay(300);
      digitalWrite(led, HIGH);
      delay(300);
      digitalWrite(led, LOW);
      delay(300);
      digitalWrite(led, HIGH);
      delay(300);
      digitalWrite(led, LOW);
      delay(300);
      digitalWrite(led, HIGH);
      delay(300);
      digitalWrite(led, LOW);
      delay(300);
      digitalWrite(led, HIGH);
      delay(300);
      digitalWrite(led, LOW);
      delay(300);
      digitalWrite(led, HIGH);
      delay(300);
      digitalWrite(led, LOW);
      delay(300);
      digitalWrite(led, HIGH);
      delay(300);
      digitalWrite(led, LOW);
      delay(300);
      digitalWrite(led, HIGH);
      delay(300);
      digitalWrite(led, LOW);
      delay(300);
      digitalWrite(led, HIGH);
      delay(300);
      digitalWrite(led, LOW);
      delay(300);
      digitalWrite(led, HIGH);
      delay(300);
      digitalWrite(led, LOW);
      delay(300);
      digitalWrite(led, HIGH);
      delay(300);
      digitalWrite(led, LOW);
      delay(300);

      //muda estado para desarmado
      armado = false;
      delay(1000);
    }
  }
}
