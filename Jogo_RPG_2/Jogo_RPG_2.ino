//Pinos Botões
#define b1 2
#define b2 3
#define b3 4

//Pinos Heróis
byte ledHerois[4] = {5, 6, 7, 8};

//Pinos Vilões
byte ledViloes[4] = {9, 10, 11, 12};

//Variáveis de controle
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

  for (byte i = 0; i < 4; i++) {
    pinMode(ledHerois[i], OUTPUT);
    digitalWrite(ledHerois[i], LOW);
  }

  for (byte i = 0; i < 4; i++) {
    pinMode(ledViloes[i], OUTPUT);
    digitalWrite(ledViloes[i], LOW);
  }
  Serial.println("Seja bem-vindo jogador! Clique nos botoes para selecionar seu personagem e iniciar sua batalha!!");
  Serial.println();
  Serial.println();
  Serial.println();
  delay(300);
}//void setup

void loop() {
  //Seleção dos personagens
  if(continuar){
    //Acender leds Heróis com descrição
    if (digitalRead(b1) == 1){ //Se o Botão 1 for apertado
      cont_b1 += 1; 
      delay(300);
    
      if(cont_b1 > 4){ //Se apertar o Botão mais de 4 vezes volta para o 1
      cont_b1 = 1;
      }    

      for (byte i = 0; i < 4; i++) {
      digitalWrite(ledHerois[i], LOW); //Desliga os Leds quando não estiver selecionado
      }

      if (cont_b1 == 1) {
        digitalWrite(ledHerois[0], HIGH);
        Serial.println("BARDO:");
        Serial.println("Auxilia seus aliados com a cura.");
        Serial.println("ATAQUE: 6");
        Serial.println("DEFESA: 7");
        Serial.println();
        delay(1000);
      }
      else if (cont_b1 == 2) {
        digitalWrite(ledHerois[1], HIGH);
        Serial.println("GUERREIRO:");
        Serial.println("Aniquila seus inimigos com habilidade e vigor.");
        Serial.println("ATAQUE: 10");
        Serial.println("DEFESA: 5");
        Serial.println();
        delay(1000);
      } 
      else if (cont_b1 == 3) {
        digitalWrite(ledHerois[2], HIGH);
        Serial.println("BRUXO:");
        Serial.println("Conjura poderes sombrios para moldar o destino conforme sua vontade.");
        Serial.println("ATAQUE: 8");
        Serial.println("DEFESA: 7");
        Serial.println();
        delay(1000);
      } 
      else if (cont_b1 == 4) {
        digitalWrite(ledHerois[3], HIGH);
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

      for (byte i = 0; i < 4; i++) {
        digitalWrite(ledViloes[i], LOW);
      }
      
      if (cont_b2 == 1) {
        digitalWrite(ledViloes[0], HIGH);
        Serial.println("DRAGAO:");
        Serial.println("Sopro de fogo, capacidade de voar e lancar conjuros poderosos.");
        Serial.println("ATAQUE: 10");
        Serial.println("DEFESA: 6");
        Serial.println();
        delay(1000);
      } 
      else if (cont_b2 == 2) {
        digitalWrite(ledViloes[1], HIGH);
        Serial.println("GENERAL:");
        Serial.println("Comanda uma tropa de soldados de metal, temido por sua crueldade.");
        Serial.println("ATAQUE: 9");
        Serial.println("DEFESA: 7");
        Serial.println();
        delay(1000);
      } 
      else if (cont_b2 == 3) {
        digitalWrite(ledViloes[2], HIGH);
        Serial.println("MORTE:");
        Serial.println("Cavalga entre a vida e a morte, manipulando as trevas para subjugar seus inimigos.");
        Serial.println("ATAQUE: 9");
        Serial.println("DEFESA: 8");
        Serial.println();
        delay(1000);
      } 
      else if (cont_b2 == 4) {
        digitalWrite(ledViloes[3], HIGH);
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
    if (digitalRead(b3) == 1 && cont_b3 < 2){
      cont_b3 += 1;
      delay(200);

      if(cont_b3 == 1){
      //Piscar o led do herói selecionado
        if(cont_b1 == 1){
          piscarLED(ledHerois[0]);
          Serial.println("BARDO!!");
        } else if (cont_b1 == 2){
          piscarLED(ledHerois[1]);
          Serial.println("GUERREIRO!!");
        } else if(cont_b1 == 3){
          piscarLED(ledHerois[2]);
          Serial.println("BRUXO!!");
        } else if (cont_b1 == 4){
          piscarLED(ledHerois[3]);
          Serial.println("FEITICEIRO!!");
        }
      }
      //Seleção Vilões
      if(cont_b3 == 2){
        //Piscar o led do vilão selecionado
        if(cont_b2 == 1){
          piscarLED(ledViloes[0]);
          Serial.println("DRAGÃO!!");
        } else if(cont_b2 == 2){
          piscarLED(ledViloes[1]);
          Serial.println("GENERAL!!");
        } else if(cont_b2 == 3){
          piscarLED(ledViloes[2]);
          Serial.println("MORTE!!");
        } else if(cont_b2 == 4){
          piscarLED(ledViloes[3]);
          Serial.println("BRUXA!!");

        }

        Serial.println("Digite 1 para sair da selecao dos persongens ou 2 para continuar: ");
        serialCount = Serial.available();
        while ((Serial.available() == 0 || serialCount == 1 || serialCount == 2 || serialCount == 3) && continuar!=false) {  
        //Aguarda a entrada de valores do usuário
        }
        
        int exit = Serial.parseInt();
        Serial.println(exit);
        delay(200);
        if(exit == 1){
          continuar = false;
          Serial.println();
          Serial.println("Role o dado!!");
          Serial.println();
        }
        else{
          cont_b3 = 0;
          Serial.println();
          Serial.println("Continue selecionando os personagens!!");
          Serial.println();
        }
      
      }
    }
  }
  //Rola o dado após a escolha dos personagens
  if(digitalRead(b3) == 1 && cont_b3 == 2){
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
