// ============================================================
//  BOTÃO QUE LIGA E DESLIGA LED — Detecção de Transição
// ============================================================
//
//  Descrição:
//    Cada vez que o botão push button é apertado, o LED
//    troca de estado: se estava apagado, acende; se estava
//    aceso, apaga. O código usa detecção de transição para
//    garantir que um único aperto seja contado uma única vez,
//    e debounce por software para evitar leituras falsas
//    causadas pela trepidação mecânica do botão.
//
//  Conceitos abordados:
//    - Entrada digital com botão push button
//    - Resistor pull-up interno (INPUT_PULLUP)
//    - Variável bool para guardar estado (ligado/desligado)
//    - Detecção de transição com duas variáveis de estado
//    - Operador lógico && (E)
//    - Operador de inversão ! (NÃO)
//    - Debounce por software com delay()
//
//  Material necessário:
//    - 1x Placa Arduino Uno (ou compatível)
//    - 1x Botão push button    → pino digital 7
//    - 1x LED                  → pino digital 12
//    - 1x Resistor 220Ω        (em série com o LED)
//    - 1x Protoboard
//    - Jumpers
//
//  Esquema de ligação:
//    Botão: um terminal no pino 7, outro terminal no GND.
//    Não é necessário resistor externo — o pull-up interno
//    do Arduino é ativado por software (INPUT_PULLUP).
//    LED: anodo (+) no pino 12 → resistor 220Ω → GND.
//
//  Sugestão pedagógica:
//    Antes de mostrar o código, ligue o circuito sem o
//    debounce (remova o delay) e mostre o LED "enlouquecendo"
//    ao apertar o botão. Depois adicione o delay(50) e mostre
//    o comportamento correto. Isso torna o problema concreto
//    e a solução memorável.
//
//  Desafio para os alunos:
//    Adicione um segundo LED no pino 8. Quando o LED do pino
//    12 acender, o do pino 8 deve apagar — e vice-versa.
//    Dica: use uma segunda variável bool ou aproveite o
//    valor de ledLigado com o operador !
//
//  Compatibilidade:
//    Arduino Uno, Nano, Mega e simuladores como Tinkercad
//
// ------------------------------------------------------------
//  Autor    : Prof. Dr. Julio Cesar Frantz
//  Canal    : Dr. da Robótica
//  YouTube  : https://www.youtube.com/@doutordaRobotica
//  Instagram: https://www.instagram.com/doutordaRobotica
//  LinkedIn : https://www.linkedin.com/in/juliofrantz
//  GitHub   : https://github.com/jcfrantz
//  Versão   : 1.0
//  Data     : Junho/2026
//  Licença  : MIT — use, adapte e compartilhe à vontade!
// ============================================================


// ------------------------------------------------------------
//  CONFIGURAÇÃO DOS PINOS
//
//  Usamos const int porque esses valores nunca mudam durante
//  a execução — o compilador não precisa reservar RAM para
//  eles. Se você mudou a montagem física, altere apenas aqui.
// ------------------------------------------------------------

const int pinoBotao = 7;   // pino do botão push button
const int pinoLed   = 12;  // pino do LED


// ------------------------------------------------------------
//  VARIÁVEIS DE CONTROLE DO BOTÃO
//
//  Para detectar apenas o MOMENTO EXATO do aperto — e não
//  todos os milhares de leituras enquanto o botão fica
//  pressionado — precisamos de duas variáveis:
//
//  estadoBotao      → o que o botão está fazendo AGORA
//  ultimoEstadoBotao → o que o botão fazia NO LOOP ANTERIOR
//
//  Quando estadoBotao muda de HIGH para LOW, sabemos que
//  o botão acabou de ser apertado neste exato instante.
//
//  Importante: começa em HIGH porque o INPUT_PULLUP mantém
//  o pino em HIGH enquanto o botão está solto.
// ------------------------------------------------------------

int estadoBotao;                  // leitura atual do botão
int ultimoEstadoBotao = HIGH;     // leitura anterior (inicia solto = HIGH)


// ------------------------------------------------------------
//  VARIÁVEL DE ESTADO DO LED
//
//  bool só aceita dois valores: true (ligado) ou false
//  (desligado). É mais claro que usar int com 0 e 1,
//  porque o nome já comunica que é um estado sim/não.
// ------------------------------------------------------------

bool ledLigado = false;  // começa apagado


// ------------------------------------------------------------
//  SETUP — executa UMA vez quando o Arduino é ligado.
//  Configuramos os pinos: LED como saída e botão como entrada
//  com pull-up interno ativado.
//
//  INPUT_PULLUP conecta um resistor interno entre o pino e
//  o 5V, estabilizando a leitura quando o botão está solto.
//  Efeito: botão SOLTO → HIGH | botão APERTADO → LOW
// ------------------------------------------------------------

void setup()
{
  pinMode(pinoLed,    OUTPUT);        // LED envia sinal → saída
  pinMode(pinoBotao,  INPUT_PULLUP);  // botão recebe sinal → entrada com pull-up
}


// ------------------------------------------------------------
//  LOOP — executa REPETIDAMENTE enquanto o Arduino estiver
//  ligado. A cada volta:
//    1. Lê o estado atual do botão
//    2. Verifica se acabou de ser apertado (transição HIGH→LOW)
//    3. Se sim: inverte o LED e aguarda o debounce
//    4. Guarda o estado atual para comparar na próxima volta
// ------------------------------------------------------------

void loop()
{
  // --- PASSO 1: leitura do botão ---
  // digitalRead retorna HIGH (solto) ou LOW (apertado),
  // graças ao INPUT_PULLUP configurado no setup().
  estadoBotao = digitalRead(pinoBotao);


  // --- PASSO 2: detecção de transição ---
  // A condição só é verdadeira no exato momento em que
  // o botão PASSOU de solto (HIGH) para apertado (LOW).
  // Se o botão continuar pressionado nas próximas voltas,
  // ultimoEstadoBotao já será LOW e a condição falha —
  // garantindo que a ação execute uma única vez por aperto.
  if (estadoBotao == LOW && ultimoEstadoBotao == HIGH) {


    // --- PASSO 3a: inverter o estado do LED ---
    // O operador ! (NÃO) inverte o valor bool:
    // se ledLigado era false → vira true
    // se ledLigado era true  → vira false
    ledLigado = !ledLigado;


    // --- PASSO 3b: aplicar o novo estado ao pino do LED ---
    // if (ledLigado) é equivalente a if (ledLigado == true)
    if (ledLigado) {
      digitalWrite(pinoLed, HIGH);  // acende o LED
    } else {
      digitalWrite(pinoLed, LOW);   // apaga o LED
    }


    // --- PASSO 3c: debounce por software ---
    // O botão mecânico "quica" internamente por ~5 a 20ms
    // ao ser apertado, gerando múltiplos sinais LOW e HIGH.
    // O delay de 50ms pausa o código enquanto esses quiques
    // acontecem, evitando que sejam interpretados como
    // apertos extras. 50ms é imperceptível para o usuário.
    delay(50);

  }  // fim da detecção de transição


  // --- PASSO 4: atualizar o histórico ---
  // Guardamos o estado atual para que na próxima volta do
  // loop ele seja o "estado anterior" a ser comparado.
  // Sem essa linha, a detecção de transição não funciona.
  ultimoEstadoBotao = estadoBotao;

}
