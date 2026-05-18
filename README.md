# 🎲 Caminho do Conhecimento - AED

Projeto desenvolvido para a disciplina de **Algoritmos e Estruturas de Dados (AED)**.

O jogo simula um percurso acadêmico no estilo “jogo de tabuleiro”, onde jogadores avançam pelo caminho utilizando um dado, respondendo perguntas relacionadas à disciplina e interagindo com casas especiais.

---

# 📚 Objetivo do Projeto

Aplicar conceitos de:

- Listas encadeadas
- Listas duplamente encadeadas
- Listas circulares
- Modularização em C
- Manipulação dinâmica de memória
- Estruturas de dados
- Organização de projetos em múltiplos arquivos `.h`

---

# 🕹️ Como Funciona

- O jogador lança um dado 🎲
- Avança pelo tabuleiro
- Pode cair em:
  - Casas de pergunta ❓
  - Casas de avanço ➕
  - Casas de retorno ➖
- Perguntas corretas geram recompensas
- Respostas erradas geram penalidades
- Vence quem alcançar a última casa do tabuleiro

---

# 🧠 Estruturas Utilizadas

## ✅ Lista Duplamente Encadeada
Utilizada para representar o tabuleiro.

Cada casa possui:
- ponteiro para próxima casa
- ponteiro para casa anterior
- informações visuais e lógicas

---

## ✅ Lista Circular
Utilizada para controle dos jogadores e turnos.

Permite:
- alternância automática entre jogadores
- gerenciamento eficiente das rodadas

---

## ✅ Vetores Estruturados
Utilizados para armazenamento inicial das perguntas.

---

# 🎨 Interface

O projeto utiliza:
- ANSI Escape Codes
- Renderização no terminal
- Tabuleiro visual em ASCII

---

# ⚙️ Funcionalidades

- [x] Tabuleiro visual
- [x] Sistema de dado animado
- [x] Movimentação dos jogadores
- [x] Casas especiais aleatórias
- [x] Sistema de turnos
- [x] Perguntas de AED
- [x] Recompensas e punições
- [x] Lista circular de jogadores
- [x] Lista dupla para o tabuleiro

---

# 📂 Organização do Projeto

```txt
main.c
│
├── TabuleiroDE.h
├── TabuleiroArte.h
├── estruturasdojogo.h
├── Eventos.h
├── Dado.h
```

---

# 🚀 Como Executar

1. Abra o projeto no Dev-C++
2. Abra o arquivo `.dev`
3. Compile o projeto (`F9`)
4. Execute o programa (`F10`)

---

## Requisitos

- Dev-C++
- Terminal com suporte ANSI habilitado
- Sistema Windows

---

# 👨‍💻 Tecnologias

- Linguagem C
- Dev-C++
- ANSI Escape Sequences

---

# 📖 Disciplina

Algoritmos e Estruturas de Dados (AED)

---

# 🏆 Equipe

Projeto acadêmico desenvolvido para fins educacionais.
