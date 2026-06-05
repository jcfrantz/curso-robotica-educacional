<div align="center">

# 🤖 Robótica Educacional com Arduino
### Prof. Dr. Julio Cesar Frantz — Dr. da Robótica

[![YouTube](https://img.shields.io/badge/YouTube-Dr.%20da%20Rob%C3%B3tica-FF0000?style=for-the-badge&logo=youtube&logoColor=white)](https://www.youtube.com/@drdaRobotica)
[![Instagram](https://img.shields.io/badge/Instagram-@drdaRobotica-E4405F?style=for-the-badge&logo=instagram&logoColor=white)](https://www.instagram.com/drdaRobotica)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-juliofrantz-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/juliofrantz)
[![License: MIT](https://img.shields.io/badge/Licen%C3%A7a-MIT-22c55e?style=for-the-badge)](LICENSE)

---

*Repositório oficial dos códigos ensinados no canal Dr. da Robótica.*  
*Material aberto para professores que ensinam robótica educacional nas escolas.*

</div>

---

## 📖 Sobre este repositório

Este repositório reúne todos os códigos Arduino utilizados nas aulas do canal **Dr. da Robótica** no YouTube. O conteúdo foi desenvolvido especialmente para **professores de robótica educacional** que atuam no Ensino Fundamental e Médio e desejam ensinar programação, eletrônica e pensamento computacional de forma prática e progressiva.

Cada arquivo `.ino` é **comentado em português**, com explicações pedagógicas que vão além da sintaxe — o objetivo é que o professor entenda o *porquê* de cada linha antes de levar o código para a sala de aula.

---

## 🗂️ Estrutura do repositório

```
📁 robotica-educacional-arduino/
│
├── 📁 01-semaforo/
│   ├── semaforo_basico.ino          # semáforo com números mágicos
│   └── semaforo_variaveis.ino       # semáforo com variáveis int (versão melhorada)
│
├── 📁 02-botao-led/
│   ├── botao_led_toggle.ino         # botão que liga/desliga LED com detecção de transição
│   └── botao_led_simples.ino        # botão simples sem debounce (para mostrar o problema)
│
├── 📁 03-modo-noturno/
│   └── semaforo_modo_noturno.ino    # semáforo com modo noturno usando variável de controle
│
└── README.md
```

> 💡 **Dica:** Os projetos estão organizados em ordem crescente de complexidade. Siga a sequência para uma progressão pedagógica coerente.

---

## 📚 Progressão pedagógica

Os projetos seguem uma sequência intencional de conceitos, construindo conhecimento de forma gradual:

| # | Projeto | Conceitos ensinados | Vídeo |
|---|---------|--------------------|----|
| 01 | Semáforo básico | `pinMode`, `digitalWrite`, `delay` | [▶ assistir](https://www.youtube.com/@drdaRobotica) |
| 02 | Semáforo com variáveis | `int`, variável global, legibilidade de código | [▶ assistir](https://www.youtube.com/@drdaRobotica) |
| 03 | Modo noturno | `if`, operador `!`, variável de controle | [▶ assistir](https://www.youtube.com/@drdaRobotica) |
| 04 | Botão + LED | `bool`, `digitalRead`, `INPUT_PULLUP`, debounce | [▶ assistir](https://www.youtube.com/@drdaRobotica) |

---

## 🧰 Material necessário

Todos os projetos deste repositório utilizam componentes de baixo custo e fácil acesso:

- **Placa Arduino Uno** (ou compatível — Nano, Mega)
- **Protoboard** (400 ou 830 pontos)
- **LEDs** (vermelho, amarelo, verde)
- **Resistores** 220Ω (para os LEDs)
- **Botão push button** (chave táctil 12x12mm)
- **Jumpers** (fios de conexão macho-macho)

> 🔁 Todos os projetos podem ser simulados gratuitamente no **[Tinkercad](https://www.tinkercad.com)** — sem precisar de nenhum hardware físico.

---

## 🚀 Como usar este repositório

### 1. Clonar o repositório
```bash
git clone https://github.com/juliofrantz/robotica-educacional-arduino.git
```

### 2. Abrir no Arduino IDE
- Instale o [Arduino IDE](https://www.arduino.cc/en/software) (versão 2.x recomendada)
- Abra o arquivo `.ino` desejado via `Arquivo → Abrir`
- Conecte a placa Arduino via USB
- Selecione a porta correta em `Ferramentas → Porta`
- Clique em **Upload** (→)

### 3. Ou simular no Tinkercad
- Acesse [tinkercad.com](https://www.tinkercad.com)
- Crie um novo circuito
- Monte o esquema de ligação descrito no cabeçalho do `.ino`
- Cole o código no editor e clique em **Iniciar Simulação**

---

## 📝 Padrão dos comentários

Todos os arquivos seguem o mesmo padrão de comentários, pensado para facilitar o uso em sala de aula:

```cpp
// ============================================================
//  NOME DO PROJETO
// ============================================================
//  Descrição    : o que o projeto faz
//  Conceitos    : lista dos conceitos de programação abordados
//  Material     : componentes necessários e pinos utilizados
//  Pedagógico   : sugestão de como usar em sala de aula
//  Desafio      : proposta para os alunos avançarem
//  Autor        : Prof. Dr. Julio Cesar Frantz
//  Canal        : Dr. da Robótica
// ============================================================
```

Os comentários **inline** explicam o *porquê* de cada linha, não apenas o *o quê*:

```cpp
// ✅ estilo deste repositório
pinMode(pinoBotao, INPUT_PULLUP); // ativa resistor interno: solto=HIGH, apertado=LOW

// ❌ estilo a evitar
pinMode(pinoBotao, INPUT_PULLUP); // define pino como entrada
```

---

## 🎯 Público-alvo

Este material foi desenvolvido para:

- **Professores de robótica educacional** no Ensino Fundamental e Médio
- **Formadores** que ministram cursos de capacitação em Arduino
- **Educadores maker** que trabalham com cultura maker e STEAM nas escolas
- **Iniciantes em Arduino** que querem aprender com código bem documentado

---

## 📜 Licença

Este projeto está licenciado sob a **Licença MIT** — você pode usar, copiar, modificar e distribuir livremente, inclusive para fins educacionais e comerciais, desde que mantenha os créditos do autor.

Veja o arquivo [LICENSE](LICENSE) para mais detalhes.

---

## 🤝 Contribuições

Sugestões, correções e novos projetos são bem-vindos!

1. Faça um **fork** do repositório
2. Crie uma branch: `git checkout -b minha-sugestao`
3. Commit: `git commit -m 'Adiciona projeto X'`
4. Push: `git push origin minha-sugestao`
5. Abra um **Pull Request**

---

<div align="center">

Feito com ❤️ para professores que transformam escolas com robótica.

**Prof. Dr. Julio Cesar Frantz**  
Professor de Engenharia Mecânica · UNIFEBE & UNIVALI  
Pesquisador · UFSC/GEAR · Pós-Doutorado  
Fundador · Laboratório de Inventores  

[![YouTube](https://img.shields.io/badge/▶-Assistir%20no%20YouTube-FF0000?style=flat-square)](https://www.youtube.com/@drdaRobotica)
[![GitHub](https://img.shields.io/badge/★-Dar%20uma%20estrela-181717?style=flat-square&logo=github)](https://github.com/juliofrantz)

</div>
