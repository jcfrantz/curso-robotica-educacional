// ============================================================
//  SEMÁFORO COM ARDUINO — Usando Variáveis Inteiras (int)
// ============================================================
//
//  Descrição:
//    Simulação do funcionamento de um semáforo de trânsito
//    utilizando três LEDs (vermelho, amarelo e verde) conectados
//    ao Arduino. O código apresenta o uso de variáveis inteiras
//    (int) para organizar os tempos e os números dos pinos,
//    tornando o programa mais legível e fácil de modificar
//    em sala de aula.
//
//  Conceitos abordados:
//    - Variáveis inteiras (int)
//    - Funções setup() e loop()
//    - Saída digital com pinMode() e digitalWrite()
//    - Controle de tempo com delay()
//
//  Material necessário:
//    - 1x Placa Arduino Uno (ou compatível)
//    - 1x LED vermelho  → pino digital 12
//    - 1x LED amarelo   → pino digital 8
//    - 1x LED verde     → pino digital 4
//    - 3x Resistor 220Ω (um para cada LED)
//    - 1x Protoboard
//    - Jumpers
//
//  Sugestão pedagógica:
//    Peça aos alunos que alterem os valores de
//    tempoAguardoVermVerde e tempoAguardoAmarelo e observem
//    o comportamento do semáforo. Isso demonstra na prática
//    o poder das variáveis: basta mudar um número no topo
//    do código para alterar o comportamento do sistema inteiro.
//
//  Compatibilidade:
//    Arduino Uno, Nano, Mega e simuladores como Tinkercad
//
// ------------------------------------------------------------
//  Autor  : Prof. Dr. Julio Cesar Frantz
//  Canal  : Dr. da Robótica
//  YouTube: https://www.youtube.com/@drdaRobotica
//  Instagram: https://www.instagram.com/DoutordaRobotica
//  LinkedIn : https://www.linkedin.com/in/juliofrantz
//  GitHub   : https://github.com/jcfrantz
//  Versão : 1.0
//  Data   : Junho/2026
//  Licença: MIT — use, adapte e compartilhe à vontade!
// ============================================================


// ------------------------------------------------------------
//  VARIÁVEIS DE CONFIGURAÇÃO DOS PINOS
//  Cada variável guarda o número do pino digital do Arduino
//  onde o LED correspondente está conectado.
//  Se você mudou a montagem física, basta alterar o número
//  aqui — não precisa mexer em nenhuma outra linha do código.
// ------------------------------------------------------------

int pinoVermelho = 12;  // pino do LED vermelho
int pinoVerde    = 4;   // pino do LED verde
int pinoAmarelo  = 8;   // pino do LED amarelo


// ------------------------------------------------------------
//  VARIÁVEIS DE TEMPO (em milissegundos)
//  1000 ms = 1 segundo
//
//  tempoAguardoVermVerde → duração do sinal vermelho E verde
//  tempoAguardoAmarelo   → duração do sinal amarelo (atenção)
//
//  Dica para o professor: proponha ao aluno que troque
//  tempoAguardoVermVerde para 5000 e observe a diferença.
//  Isso reforça o conceito de variável de forma visual!
// ------------------------------------------------------------

int tempoAguardoVermVerde = 3000;  // 3 segundos para vermelho e verde
int tempoAguardoAmarelo   = 1500;  // 1,5 segundo para amarelo
int pausaEntreSinais      = 15;    // pausa mínima entre trocas de sinal (ms)


// ------------------------------------------------------------
//  SETUP — executa UMA vez quando o Arduino é ligado ou
//  resetado. Usamos para configurar os pinos como SAÍDA,
//  pois vamos enviar sinal para acender os LEDs.
// ------------------------------------------------------------

void setup()
{
  pinMode(pinoVermelho, OUTPUT);  // configura o pino do LED vermelho como saída
  pinMode(pinoVerde,    OUTPUT);  // configura o pino do LED verde como saída
  pinMode(pinoAmarelo,  OUTPUT);  // configura o pino do LED amarelo como saída
}


// ------------------------------------------------------------
//  LOOP — executa REPETIDAMENTE enquanto o Arduino estiver
//  ligado. Aqui está a sequência do semáforo:
//
//  1. Vermelho acende → aguarda → apaga
//  2. Verde acende    → aguarda → apaga
//  3. Amarelo acende  → aguarda → apaga
//  ...e recomeça do passo 1 automaticamente.
// ------------------------------------------------------------

void loop()
{
  // --- FASE VERMELHA ---
  digitalWrite(pinoVermelho, HIGH);      // acende o LED vermelho
  delay(tempoAguardoVermVerde);          // aguarda o tempo configurado
  digitalWrite(pinoVermelho, LOW);       // apaga o LED vermelho
  delay(pausaEntreSinais);               // pequena pausa antes do próximo sinal

  // --- FASE VERDE ---
  digitalWrite(pinoVerde, HIGH);         // acende o LED verde
  delay(tempoAguardoVermVerde);          // aguarda o mesmo tempo do vermelho
  digitalWrite(pinoVerde, LOW);          // apaga o LED verde
  delay(pausaEntreSinais);               // pequena pausa antes do próximo sinal

  // --- FASE AMARELA ---
  digitalWrite(pinoAmarelo, HIGH);       // acende o LED amarelo (atenção!)
  delay(tempoAguardoAmarelo);            // aguarda tempo menor — sinal de atenção
  digitalWrite(pinoAmarelo, LOW);        // apaga o LED amarelo
  // o loop() reinicia automaticamente → volta para a fase vermelha
}
