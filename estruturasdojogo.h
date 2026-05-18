#ifndef ESTRUTURAS_DO_JOGO_H
#define ESTRUTURAS_DO_JOGO_H

#define TOTAL_PERGUNTAS 9

// Define quais casas serão especiais
#define NORMAL 0
#define PERGUNTA 1
#define AVANCA 2
#define RETORNA 3

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Compatibilidade com windows e unix
#ifdef _WIN32
    #include <windows.h>
    #define pausa(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define pausa(ms) usleep((ms) * 1000)
#endif

// JOGADORES //

// Estrutura dos Jogadores (Lista Encadeada Circular)
typedef struct Jogador {
    char nome[50];
    int posicao;
    tp_no *posicaoAtual;  
    int pontos;
    int acertos;
    int erros;
    struct Jogador *prox; // Ponteiro para o próximo jogador
} Jogador;




Jogador* adicionar_jogador(Jogador *lista, char nome[], tp_tabd *tab) {
    Jogador *novo = (Jogador*) malloc(sizeof(Jogador));
    if (!novo) return lista;
    strcpy(novo->nome, nome);
    novo->pontos = 0;
    novo->acertos = 0;
    novo->erros = 0;
    novo->posicao = 1;
    novo->posicaoAtual = tab->ini; // Faz cada jogador "nascer" na primeira casa real do tabuleiro
    if (lista == NULL) {
        novo->prox = novo; 
        return novo;
    }
    Jogador *aux = lista;
    while (aux->prox != lista) {
        aux = aux->prox;
    }
    aux->prox = novo;
    novo->prox = lista; // Fecha o círculo
    return lista;
}

void moverJogador(Jogador *jogador, int passos){
    int i;

    if(jogador == NULL) return;

    if(jogador->posicaoAtual == NULL) return;

    for(i = 0; i < passos; i++){
        if(jogador->posicaoAtual->prox != NULL){
            jogador->posicaoAtual = jogador->posicaoAtual->prox;
        }

        else{
			break;
        }
    }

    jogador->posicao = jogador->posicaoAtual->info.valor;
}

void desenharJogador(Jogador *jogador)
{
    int x_centro;
    int y_centro;

    if(jogador == NULL) return;

    if(jogador->posicaoAtual == NULL) return;

    x_centro =
        (jogador->posicaoAtual->info.x_inicio + jogador->posicaoAtual->info.x_fim) / 2;

    y_centro =
        (jogador->posicaoAtual->info.y_inicio + jogador->posicaoAtual->info.y_fim) / 2;

    printf("\e[%d;%dH", y_centro, x_centro);

    printf("@");
}

// PERGUNTAS //

// Estrutura para as Perguntas
typedef struct {
    char enunciado[256];
    char alternativa_1[100];
    char alternativa_2[100];
    char alternativa_3[100];
    char alternativa_4[100];
    int alternativa_correta;
    int dificuldade;
} Pergunta;

typedef Pergunta tp_item_2; 

void carregar_banco_perguntas(Pergunta banco[TOTAL_PERGUNTAS]) {
    // Pergunta 0
    strcpy(banco[0].enunciado, "O que e um algoritmo?");
    strcpy(banco[0].alternativa_1, "Uma linguagem de programacao");
    strcpy(banco[0].alternativa_2, "Uma sequencia finita de passos para resolver um problema");
    strcpy(banco[0].alternativa_3, "Um tipo de dado");
    strcpy(banco[0].alternativa_4, "Um compilador");
    banco[0].alternativa_correta = 2;
    banco[0].dificuldade = 1;
    // Pergunta 1
    strcpy(banco[1].enunciado, "Qual estrutura de controle verifica uma condicao e executa blocos diferentes?");
    strcpy(banco[1].alternativa_1, "Loop while");
    strcpy(banco[1].alternativa_2, "Estrutura if/else");
    strcpy(banco[1].alternativa_3, "Funcao recursiva");
    strcpy(banco[1].alternativa_4, "Vetor");
    banco[1].alternativa_correta = 2;
    banco[1].dificuldade = 1;
    // Pergunta 2
    strcpy(banco[2].enunciado, "Qual e a politica de acesso de uma Pilha (Stack)?");
    strcpy(banco[2].alternativa_1, "FIFO - First In, First Out");
    strcpy(banco[2].alternativa_2, "LIFO - Last In, First Out");
    strcpy(banco[2].alternativa_3, "Acesso aleatorio por indice");
    strcpy(banco[2].alternativa_4, "Acesso pelo menor elemento");
    banco[2].alternativa_correta = 2;
    banco[2].dificuldade = 1;
    // Pergunta 3
    strcpy(banco[3].enunciado, "Em uma Fila (Queue), onde novos elementos sao inseridos?");
    strcpy(banco[3].alternativa_1, "No inicio (frente)");
    strcpy(banco[3].alternativa_2, "No meio");
    strcpy(banco[3].alternativa_3, "No final (fundo)");
    strcpy(banco[3].alternativa_4, "Em qualquer posicao");
    banco[3].alternativa_correta = 3;
    banco[3].dificuldade = 1;
    // Pergunta 4
    strcpy(banco[4].enunciado, "Qual operacao REMOVE o elemento do topo de uma pilha encadeada?");
    strcpy(banco[4].alternativa_1, "remove");
    strcpy(banco[4].alternativa_2, "push");
    strcpy(banco[4].alternativa_3, "pop");
    strcpy(banco[4].alternativa_4, "pushout");
    banco[4].alternativa_correta = 3;
    banco[4].dificuldade = 2;
    // Pergunta 5
    strcpy(banco[5].enunciado, "Qual a vantagem de uma lista encadeada sobre um array?");
    strcpy(banco[5].alternativa_1, "Acesso direto por indice mais rapido");
    strcpy(banco[5].alternativa_2, "Insercao e remocao sem deslocar elementos");
    strcpy(banco[5].alternativa_3, "Menor uso de memoria sempre");
    strcpy(banco[5].alternativa_4, "Maior velocidade de busca");
    banco[5].alternativa_correta = 2;
    banco[5].dificuldade = 2;
    // Pergunta 6
    strcpy(banco[6].enunciado, "Estado da pilha: push(1), push(2), pop(), push(1), push(4), push(2), pop(), push(3)?");
    strcpy(banco[6].alternativa_1, "[1, 2, 1, 2, 3]");
    strcpy(banco[6].alternativa_2, "[1, 1, 4, 3]");
    strcpy(banco[6].alternativa_3, "[2, 4, 2, 3]");
    strcpy(banco[6].alternativa_4, "[1, 1, 4, 2]");
    banco[6].alternativa_correta = 2;
    banco[6].dificuldade = 2;
    // Pergunta 7
    strcpy(banco[7].enunciado, "Qual estrutura de dados e indicada para historico de navegacao?");
    strcpy(banco[7].alternativa_1, "Fila simples");
    strcpy(banco[7].alternativa_2, "Pilha unica");
    strcpy(banco[7].alternativa_3, "Duas pilhas");
    strcpy(banco[7].alternativa_4, "Vetor estatico");
    banco[7].alternativa_correta = 3;
    banco[7].dificuldade = 3;
    // Pergunta 8
    strcpy(banco[8].enunciado, "Qual combinacao de estruturas seria usada para simular uma fila usando pilhas?");
    strcpy(banco[8].alternativa_1, "Uma pilha apenas");
    strcpy(banco[8].alternativa_2, "Duas pilhas");
    strcpy(banco[8].alternativa_3, "Tres filas");
    strcpy(banco[8].alternativa_4, "Um vetor e uma pilha");
    banco[8].alternativa_correta = 2;
    banco[8].dificuldade = 3;
    // pra adicionar mais é só seguir a mesma lógica e mudar o numero [X] e subir o máximo de perguntas lá em cima pra X+1
}
void ativar_ansi() {
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | 0x0004); 
#endif
}

void maximizar_terminal() {
#ifdef _WIN32
    HWND hwnd = GetConsoleWindow();
    if (hwnd != NULL) {
        ShowWindow(hwnd, SW_SHOWMAXIMIZED);
    }
#endif
}
#endif