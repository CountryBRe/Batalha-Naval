# Batalha Naval em C

Este é um projeto simples do jogo **Batalha Naval**, feito em linguagem C, desenvolvido passo a passo desde o nível novato até o nível mestre. Ele simula o posicionamento de navios no tabuleiro, permite que o jogador escolha onde atacar e mostra visualmente o resultado das jogadas no console.

## 🧠 O que foi implementado

### 🔹 Nível Novato
- Tabuleiro 10x10 com água (`0`)
- Dois navios fixos (1 horizontal, 1 vertical), ocupando 3 espaços cada
- Representação com valor `3` no tabuleiro

### 🔸 Nível Aventureiro
- Quatro navios: dois horizontais/verticais e dois diagonais
- Validação para evitar sobreposição
- Exibição do tabuleiro usando `printf` e loops aninhados

### 🔺 Nível Mestre
- Habilidades especiais (Cone, Cruz, Octaedro)
- Cada habilidade com área de efeito sobre o tabuleiro
- Exibição clara de água, navio e habilidade com **cores ANSI** (azul e verde)

### 🎨 Cores no Terminal (ANSI)
- **Água** é mostrada com a cor **azul**
- **Navios acertados** são mostrados em **verde**
- Terminal colorido melhora a experiência visual

👨‍💻 Feito por: Rodrigo Gomes

📘 Disciplina: Introdução à Programação de Computadores

🏫 Faculdade: Estácio de Sá

👨‍🏫 Professor: Sérgio Cardoso e Nathan de Freitas Alves


## 🎮 Como jogar

1. Compile o código:

```bash
gcc batalha_naval.c -o batalha_naval
