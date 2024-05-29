//Pinos Botões
#define b1 2
#define b2 3
#define b3 4

//Pinos Heróis
#define h1 5
#define h2 6
#define h3 7
#define h4 8

//Pinos Vilões
#define v1 9
#define v2 10
#define v3 11
#define v4 12

int cont_b1 = 0;
int cont_b2 = 0;
int cont_b3 = 0;

bool continuar = true;

void setup() {
  Serial.begin(9600);
  delay(1000);

  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);

  pinMode(h1, OUTPUT);
  pinMode(h2, OUTPUT);
  pinMode(h3, OUTPUT);
  pinMode(h4, OUTPUT);
  pinMode(v1, OUTPUT);
  pinMode(v2, OUTPUT);
  pinMode(v3, OUTPUT);
  pinMode(v4, OUTPUT);

}

void loop() {
  //Seleção dos personagens
  if(continuar){
    //Acender leds Heróis com descrição
    if (digitalRead(b1) == 1){ //Se o Botão 1 for apertado
      cont_b1 += 1; 
      delay(300);
    
      if(cont_b1 > 4){ //Se apertar o Botão mais de 4 vezes
      cont_b1 = 1;
      }
      digitalWrite(h1, LOW);
      digitalWrite(h2, LOW);
      digitalWrite(h3, LOW);
      digitalWrite(h4, LOW);
    
      
      if (cont_b1 == 1) {
        digitalWrite(h1, HIGH);
        Serial.println("BARDO:");
        Serial.println("Auxilia seus aliados com a cura.");
        Serial.println("ATAQUE: 6");
        Serial.println("DEFESA: 7");
        Serial.println();
        delay(1000);
      }
   
      else if (cont_b1 == 2) {
        digitalWrite(h2, HIGH);
        Serial.println("GUERREIRO:");
        Serial.println("Aniquila seus inimigos com habilidade e vigor.");
        Serial.println("ATAQUE: 10");
        Serial.println("DEFESA: 5");
        Serial.println();
        delay(1000);
      } 
      else if (cont_b1 == 3) {
        digitalWrite(h3, HIGH);
        Serial.println("BRUXO:");
        Serial.println("Conjura poderes sombrios para moldar o destino conforme sua vontade.");
        Serial.println("ATAQUE: 8");
        Serial.println("DEFESA: 7");
        Serial.println();
        delay(1000);
      } 
      else if (cont_b1 == 4) {
        digitalWrite(h4, HIGH);
        Serial.println("FEITICEIRO:");
        Serial.println("Desencadeia magia natural de forma intuitiva e poderosa.");
        Serial.println("ATAQUE: 7");
        Serial.println("DEFESA: 8");
        Serial.println();
        delay(1000);
      }
    }
//------------------------------------------------------------------------------------------//
  //Acender leds Vilões com descrição
    if (digitalRead(b2) == 1){
      cont_b2 += 1;
      delay(300);

      if(cont_b2 > 4){
        cont_b2 = 1;
      }
      digitalWrite(v1, LOW);
      digitalWrite(v2, LOW);
      digitalWrite(v3, LOW);
      digitalWrite(v4, LOW);
    
      if (cont_b2 == 1) {
        digitalWrite(v1, HIGH);
        Serial.println("DRAGAO:");
        Serial.println("Sopro de fogo, capacidade de voar e lancar conjuros poderosos.");
        Serial.println("ATAQUE: 10");
        Serial.println("DEFESA: 6");
        Serial.println();
        delay(1000);
      } 
      else if (cont_b2 == 2) {
        digitalWrite(v2, HIGH);
        Serial.println("GENERAL:");
        Serial.println("Comanda uma tropa de soldados de metal, temido por sua crueldade.");
        Serial.println("ATAQUE: 9");
        Serial.println("DEFESA: 7");
        Serial.println();
        delay(1000);
      } 
      else if (cont_b2 == 3) {
        digitalWrite(v3, HIGH);
        Serial.println("MORTE:");
        Serial.println("Cavalga entre a vida e a morte, manipulando as trevas para subjugar seus inimigos.");
        Serial.println("ATAQUE: 9");
        Serial.println("DEFESA: 8");
        Serial.println();
        delay(1000);
      } 
      else if (cont_b2 == 4) {
        digitalWrite(v4, HIGH);
        Serial.println("BRUXA:");
        Serial.println("Mestra das sombras, cria e utiliza magias sinistras para espalhar medo e concretizar objetivos sombrios.");
        Serial.println("ATAQUE: 10");
        Serial.println("DEFESA: 10");
        Serial.println();
        delay(1000);
      }
    }

//------------------------------------------------------------------------------------------//
  //Seleção dos Heróis
    if (digitalRead(b3) == 1){
      cont_b3 += 1;
      delay(300);

      if(cont_b3 == 1){
      //Piscar o led do herói selecionado
      if(cont_b1 == 1){
        piscarLED(h1);
        Serial.println("BARDO!!");
      } else if (cont_b1 == 2){
        piscarLED(h2);
        Serial.println("GUERREIRO!!");
      } else if(cont_b1 == 3){
        piscarLED(h3);
        Serial.println("BRUXO!!");
      } else if (cont_b1 == 4){
        piscarLED(h4);
        Serial.println("FEITICEIRO!!");
      }
    }
      //Seleção Vilões
      if(cont_b3 == 2){
        //Piscar o led do vilão selecionado
        if(cont_b2 == 1){
        piscarLED(v1);
        Serial.println("DRAGÃO!!");
        } else if(cont_b2 == 2){
        piscarLED(v2);
        Serial.println("GENERAL!!");
        } else if(cont_b2 == 3){
        piscarLED(v3);
        Serial.println("MORTE!!");
        } else if(cont_b2 == 4){
        piscarLED(v4);
        Serial.println("BRUXA!!");

        }

        Serial.println("Digite 1 para sair da selecao dos persongens ou 2 para continuar: ");
        while (Serial.available() == 0) {
        //Aguarda a entrada de valores do usuário
        }
        int exit = Serial.parseInt();
    
        if(exit == 1){
          continuar = false;
        }
        else{
          cont_b3 = 0;
        }
      }
    }
  }
  //Rola o dado após a escolha dos personagens
  if(digitalRead(b3) == 1){
    delay(300);
    dado(20);
  }
  
}

//Função para piscar o led do personagem escolhido
void piscarLED(int pino){
  Serial.print("Personagem Selecionado:");
  for (int i = 0; i < 5; i++){
    digitalWrite(pino, HIGH);
    delay(100);
    digitalWrite(pino, LOW);
    delay(100);
  }  
}

//Função para sortear um número
void dado(int numero){
  int randomNumber = random(0, 20);
  Serial.println(randomNumber);
}