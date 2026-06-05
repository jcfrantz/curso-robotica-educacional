// ============================================================
//  CONTROLE DE SERVO MOTOR COM DOIS BOTÕES
// ============================================================
//
//  Descrição:
//    Controla a posição de um servo motor usando dois botões
//    push button. O botão 1 move o servo para a posição
//    "aberto" (90°) e o botão 2 retorna para a posição
//    "fechado" (0°). O código usa detecção de transição
//    para garantir que cada aperto seja contado uma única
//    vez, e debounce por software para evitar leituras
//    falsas causadas pela trepidação mecânica dos botões.
//
//  Conceitos abordados:
//    - Biblioteca Servo.h e objeto Servo
//    - servo.attach() e servo.write()
//    - Entrada digital com botão push button
//    - Resistor pull-up interno (INPUT_PULLUP)
//    - Constantes com const int para posições e pinos
//    - Detecção de transição com duas variáveis de estado
//    - Debounce por software com delay()
//
//  Material necessário:
//    - 1x Placa Arduino Uno (ou compatível)
//    - 1x Servo motor SG90 (ou similar)  → pino digital 7
//    - 1x Botão push button (botão 1)    → pino digital 3
//    - 1x Botão push button (botão 2)    → pino digital 4
//    - 1x Protoboard
//    - Jumpers
//
//  Esquema de ligação do servo:
//    Fio marrom  (GND)   → GND do Arduino
//    Fio vermelho (5V)   → 5V do Arduino
//    Fio laranja (sinal) → pino digital 7
//
//  Esquema de ligação dos botões:
//    Um terminal no pino digital (3 ou 4)
//    Outro terminal no GND
//    Sem resistor externo — pull-up interno ativado por software
//
//  Sugestão pedagógica:
//    Comece mostrando o servo se movendo manualmente com
//    servo.write() no setup() para apresentar o conceito
//    de posição em graus. Depois introduza os botões como
//    forma de controle interativo. Isso separa os dois
//    conceitos e facilita a compreensão de cada parte.
//
//  Desafio para os alunos:
//    Adicione um terceiro botão que move o servo para uma
//    posição intermediária (45°). Crie uma variável
//    const int posicaoMeio = 45 seguindo o padrão do código.
//    Para avançados: faça o servo varrer de 0° a 180°
//    automaticamente quando um quarto botão for apertado.
//
//  Compatibilidade:
//    Arduino Uno, Nano, Mega e simuladores como Tinkercad
//
// ------------------------------------------------------------
//  Autor    : Prof. Dr. Julio Cesar Frantz
//  Canal    : Dr. da Robótica
//  YouTube  : https://www.youtube.com/@doutordarobotica
//  Instagram: https://www.instagram.com/doutordarobotica
//  LinkedIn : https://www.linkedin.com/in/julio-frantz
//  GitHub   : https://github.com/jcfrantz/curso-robotica-educacional
//  Versão   : 1.0
//  Data     : Junho/2026
//  Licença  : MIT — use, adapte e compartilhe à vontade!
// ============================================================


// ------------------------------------------------------------
//  BIBLIOTECA
//
//  A biblioteca Servo.h já vem instalada no Arduino IDE.
//  Ela fornece os comandos attach() e write() que usaremos
//  para controlar o servo motor sem precisar calcular
//  nenhum sinal elétrico manualmente.
// ------------------------------------------------------------

#include <Servo.h>


// ------------------------------------------------------------
//  CONFIGURAÇÃO DOS PINOS
//
//  Usamos const int porque esses valores nunca mudam durante
//  a execução. Se você mudou a montagem física, altere
//  apenas aqui — o resto do código se atualiza sozinho.
// ------------------------------------------------------------

const int pinoServo1  = 7;  // sinal do servo motor
const int pinoBotao1  = 3;  // botão 1 → move para posicaoAberto
const int pinoBotao2  = 4;  // botão 2 → move para posicaoFechado


// ------------------------------------------------------------
//  POSIÇÕES DO SERVO (em graus)
//
//  Servos comuns aceitam valores de 0° a 180°.
//  Centralize aqui os ângulos do seu projeto — assim o
//  professor ou aluno ajusta o comportamento sem precisar
//  procurar números espalhados pelo código.
//
//  Dica: troque posicaoAberto para 180 se quiser o curso
//  completo, ou para 45 se quiser um movimento menor.
// ------------------------------------------------------------

const int posicaoFechado = 0;    // posição inicial — servo recolhido
const int posicaoAberto  = 90;   // posição ao apertar o botão 1


// ------------------------------------------------------------
//  OBJETO SERVO
//
//  Servo é um tipo especial de variável (objeto) que
//  representa o servo motor no código. O nome "servo1"
//  é escolha do programador — poderia ser "portaGaragem"
//  ou qualquer nome descritivo do seu projeto.
// ------------------------------------------------------------

Servo servo1;


// ------------------------------------------------------------
//  VARIÁVEIS DE LEITURA DOS BOTÕES
//
//  Para detectar apenas o MOMENTO EXATO do aperto usamos
//  duas variáveis por botão: uma guarda o estado atual e
//  a outra guarda o estado da volta anterior do loop().
//
//  Quando o estado muda de HIGH para LOW, sabemos que o
//  botão acabou de ser apertado — e executamos a ação
//  uma única vez, não milhares de vezes por segundo.
//
//  Iniciam em HIGH porque o INPUT_PULLUP mantém os pinos
//  em HIGH enquanto os botões estão soltos.
// ------------------------------------------------------------

int estadoBotao1;                   // leitura atual do botão 1
int estadoBotao2;                   // leitura atual do botão 2
int ultimoEstadoBotao1 = HIGH;      // leitura anterior do botão 1
int ultimoEstadoBotao2 = HIGH;      // leitura anterior do botão 2


// ------------------------------------------------------------
//  SETUP — executa UMA vez quando o Arduino é ligado.
//
//  attach() associa o objeto servo1 ao pino físico do Arduino.
//  write() envia o servo para a posição inicial conhecida —
//  sem isso, o servo pode estar em qualquer posição ao ligar.
// ------------------------------------------------------------

void setup()
{
  servo1.attach(pinoServo1);          // conecta o objeto ao pino 7
  servo1.write(posicaoFechado);       // garante posição inicial definida

  pinMode(pinoBotao1, INPUT_PULLUP);  // botão 1: entrada com pull-up interno
  pinMode(pinoBotao2, INPUT_PULLUP);  // botão 2: entrada com pull-up interno
}


// ------------------------------------------------------------
//  LOOP — executa REPETIDAMENTE enquanto o Arduino estiver
//  ligado. A cada volta:
//    1. Lê os dois botões
//    2. Verifica se cada um acabou de ser apertado
//    3. Move o servo conforme o botão detectado
//    4. Guarda os estados para comparar na próxima volta
// ------------------------------------------------------------

void loop()
{
  // --- PASSO 1: leitura dos botões ---
  // INPUT_PULLUP inverte a lógica: solto = HIGH, apertado = LOW
  estadoBotao1 = digitalRead(pinoBotao1);
  estadoBotao2 = digitalRead(pinoBotao2);


  // --- BOTÃO 1: move para posição aberto ---
  // A condição detecta a transição HIGH → LOW (momento do aperto).
  // Enquanto o botão continuar pressionado, ultimoEstadoBotao1
  // já será LOW e a condição falha — o servo não recebe comandos
  // repetidos desnecessariamente.
  if (estadoBotao1 == LOW && ultimoEstadoBotao1 == HIGH) {
    servo1.write(posicaoAberto);  // move o servo para o ângulo definido
    delay(50);                    // debounce: aguarda a trepidação do botão passar
  }


  // --- BOTÃO 2: retorna para posição fechado ---
  // Mesma lógica de detecção de transição do botão 1.
  if (estadoBotao2 == LOW && ultimoEstadoBotao2 == HIGH) {
    servo1.write(posicaoFechado); // retorna o servo para a posição inicial
    delay(50);                    // debounce: aguarda a trepidação do botão passar
  }


  // --- PASSO 4: atualizar histórico ---
  // Guardamos os estados atuais para que na próxima volta
  // sejam os "estados anteriores" a serem comparados.
  // Sem essas duas linhas, a detecção de transição não funciona.
  ultimoEstadoBotao1 = estadoBotao1;
  ultimoEstadoBotao2 = estadoBotao2;
}
