// Projeto 2 - Interruptor de luz (Comentário identificando o projeto)

int botao = 7;           // Cria uma variável inteira para o pino do botão (Pino 7)
int led = 13;             // Cria uma variável inteira para o pino do LED (Pino 13)
bool estadoLed = 0;       // Variável tipo "Booleana" (0 ou 1) 
						//que guarda se o LED deve estar aceso ou apagado

void setup()              // Função de configuração (roda apenas uma vez ao ligar)
{
  // Configura o pino 7 como entrada e ativa o resistor interno do Arduino (PULLUP)
  // Isso faz com que o botão leia 1 (HIGH) quando solto e 0 (LOW) quando apertado
  pinMode(botao, INPUT_PULLUP); 
  
  pinMode(led, OUTPUT);   // Configura o pino 13 como saída para enviar energia ao LED
}

void loop()               // Função principal que se repete infinitamente
{
  // Verifica se a leitura digital do botão é igual a LOW (ou seja, se o botão foi pressionado)
  if(digitalRead(botao) == LOW) 
  {
    // A exclamação "!" significa "NÃO" ou inversão. 
    // Se estadoLed era 0 (apagado), vira 1 (aceso). Se era 1, vira 0.
    estadoLed = !estadoLed; 
    
    // Envia o novo valor (0 ou 1) para o pino do LED fisicamente
    digitalWrite(led, estadoLed);
    
    // ESTA LINHA É A CHAVE: O "while" trava o código enquanto o botão estiver apertado.
    // Ele impede que o Arduino mude o LED milhares de vezes por segundo enquanto você segura o dedo.
    while(digitalRead(botao) == LOW); 
    
    // Pequena pausa de 100ms para estabilizar o sinal e evitar ruídos elétricos básicos
    delay(100);      
  }   
}

