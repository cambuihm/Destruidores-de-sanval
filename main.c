#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "Eventos.h"
#include "TabuleiroDE.h"
#include "estruturasdojogo.h"
#include "Dado.h"
#include "tabuleiroarte.h"
#include "fila.h"
#include "pilha.h"
#include "listasimples.h" 
#include "listadupla.h"


void testar_tamanho_terminal() {
    // Definições baseadas no seu teste anterior
    int colunas = 201;
    int linhas = 43;
    
    // String com 36 caracteres para ficar repetindo (Letras e Números)
    char padrao[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int indice_padrao = 0;

    // Limpa a tela antes de começar
    printf("\x1b[2J\x1b[H");

    for (int l = 0; l < linhas; l++) {
        for (int c = 0; c < colunas; c++) {
            // Imprime o caractere atual do padrão
            putchar(padrao[indice_padrao]);
            
            // Avança para o próximo caractere do padrão (e reseta se chegar ao fim)
            indice_padrao++;
            if (padrao[indice_padrao] == '\0') {
                indice_padrao = 0;
            }
        }
        // Quando chega no limite de colunas (201), quebra a linha
        putchar('\n');
    }
}

// Vetor com as informações das 59 do tabuleiro. Organização: {valor, x_inicio, x_fim, y_inicio, y_fim, tipo}
tp_casa base_tabuleiro[59] = {
    {1, 171, 196, 75, 90, 0},
    {2, 157, 168, 84, 90, 0},
    {3, 143, 154, 84, 90, 0},
    {4, 143, 154, 75, 82, 0},
    {5, 143, 154, 67, 73, 0},
    {6, 143, 154, 59, 65, 0},
    {7, 143, 154, 51, 57, 0},
    {8, 143, 154, 43, 49, 0},
    {9, 143, 154, 35, 41, 0},
    {10, 143, 154, 26, 33, 0},
    {11, 143, 154, 18, 24, 0},
    {12, 143, 154, 10, 16, 0},
    {13, 157, 168, 10, 16, 0},
    {14, 171, 182, 10, 16, 0},
    {15, 185, 196, 10, 16, 0},
    {16, 199, 210, 10, 16, 0},
    {17, 213, 224, 10, 16, 0},
    {18, 227, 238, 10, 16, 0},
    {19, 227, 238, 18, 24, 0},
    {20, 227, 238, 26, 33, 0},
    {21, 227, 238, 35, 41, 0},
    {22, 213, 224, 35, 41, 0},
    {23, 199, 210, 35, 41, 0},
    {24, 199, 210, 26, 33, 0},
    {25, 185, 196, 26, 33, 0},
    {26, 171, 182, 26, 33, 0},
    {27, 171, 182, 35, 41, 0},
    {28, 171, 182, 43, 49, 0},
    {29, 171, 182, 51, 57, 0},
    {30, 171, 182, 59, 65, 0},
    {31, 185, 196, 59, 65, 0},
    {32, 199, 210, 59, 65, 0},
    {33, 199, 210, 51, 57, 0},
    {34, 213, 224, 51, 57, 0},
    {35, 213, 224, 59, 65, 0},
    {36, 213, 224, 67, 73, 0},
    {37, 213, 224, 75, 82, 0},
    {38, 227, 238, 75, 82, 0},
    {39, 241, 252, 75, 82, 0},
    {40, 241, 252, 67, 73, 0},
    {41, 241, 252, 59, 65, 0},
    {42, 241, 252, 51, 57, 0},
    {43, 255, 266, 51, 57, 0},
    {44, 255, 266, 59, 65, 0},
    {45, 255, 266, 67, 73, 0},
    {46, 255, 266, 75, 82, 0},
    {47, 269, 280, 75, 82, 0},
    {48, 283, 294, 75, 82, 0},
    {49, 283, 294, 67, 73, 0},
    {50, 283, 294, 59, 65, 0},
    {51, 283, 294, 51, 57, 0},
    {52, 283, 294, 43, 49, 0},
    {53, 283, 294, 35, 41, 0},
    {54, 269, 280, 35, 41, 0},
    {55, 255, 266, 35, 41, 0},
    {56, 255, 266, 26, 33, 0},
    {57, 255, 266, 18, 24, 0},
    {58, 269, 280, 18, 24, 0},
    {59, 283, 308, 10, 24, 0}
};



void popular_Tabuleiro (tp_tabd *tab){
    int i = 0;
    for (i = 0; i < 59; i++) {
       insere_tabd_no_fim(tab, base_tabuleiro[i]); 
    }
}



int main()
{
	
	int dado;
	dado = rolar_dado_animado();
	
    srand(time(NULL));

    desenhar_asdasdsad();

    maximizar_terminal();

    ativar_ansi();

    tp_tabd *tab;

    tab = inicializa_tabd();

    popular_Tabuleiro(tab);

    gerarCasasEspeciais(tab);

    Jogador *jogadores = NULL;
    
	// CADASTRO DOS JOGADORES 
    int qtdJogadores;
	int i;

	char nome[50];

	printf("Insira a quantidade de jogadores (2-4): ");
	scanf("%d", &qtdJogadores);

	while(qtdJogadores < 2 || qtdJogadores > 4){
    printf("Quantidade invalida!\n");
	printf("Digite entre 2 e 4: ");
	scanf("%d", &qtdJogadores);
}

	for(i = 0; i < qtdJogadores; i++){
    printf("\nNome do jogador %d: ", i + 1);

    scanf("%s", nome);

    jogadores = adicionar_jogador(jogadores, nome, tab);
}

	// LOOP DO JOGO
    Jogador *atual;

atual = jogadores;

while(1)
{
    int dado;

    system("cls");

    desenhar_asdasdsad();

    imprime_tabuleiro_V2(tab, 1);

    // DESENHAR TODOS OS JOGADORES

    Jogador *aux;

    aux = jogadores;

    do{
    desenharJogador(aux);
		aux = aux->prox;
	}
	while(aux != jogadores);

    printf("\n\nVez de %s",atual->nome);

    printf("\nPressione ENTER para rolar o dado...");

    getchar();
    getchar();

    dado = rolar_dado_animado();

    moverJogador(atual, dado);

    printf("\n%s tirou %d", atual->nome, dado);

    printf("\n%s esta na casa %d\n", atual->nome, atual->posicao);

    // VERIFICA VITORIA
    

    if(atual->posicaoAtual->prox == NULL){
    	printf("\n%s venceu o jogo!\n", atual->nome);
	
	break;
    }

    printf("\nPressione ENTER...");
    getchar();

    atual = atual->prox;
}
    return 0;
}