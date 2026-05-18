#ifndef TabuleiroDE_H
#define TabuleiroDE_H

#include <stdio.h>
#include <stdlib.h>

// Definindo Cores ANSI, RESET e NEGRITO
#define RESET   "\e[0m"
#define NEGRITO "\e[1m"
#define VERMELHO "\e[38;2;205;49;49m"
#define VERDE   "\e[38;2;13;188;121m"
#define AMARELO "\e[38;2;229;229;16m"
#define AZUL    "\e[38;2;36;114;200m"
#define CIANO   "\e[38;2;17;168;205m"

// Definindo as casas especiais
#define NORMAL 0
#define PERGUNTA 1
#define AVANCA 2
#define RETORNA 3

// Struct para a casa do Tabuleiro 
typedef struct {
    int valor; // valor da casa (Antigo tp_item)
    int x_inicio, x_fim; // Coordenadas horizontais da casa
    int y_inicio, y_fim; // Coordenadas verticais da casa
// Pega as coordenadas dos cantos da casa usando a diagonal pincipal como referência
    int tipo; // Tipo da Casa (Pode-se definir por números)
} tp_casa;

typedef tp_casa tp_obj; /* tp_item agora é tp_obj (objeto). Tipo do obj agora é tp_casa. A entrada na main agora 
deve incluir as informações da struct tp_casa */

//dado estruturado que representa o descritor
typedef struct tp_no_aux {
    struct tp_no_aux *ant;
    tp_obj info;
    struct tp_no_aux *prox;
} tp_no;

//dado estruturado (struct) que representa o nó do tabuleiro
typedef struct {
    tp_no *ini;
    tp_no *fim;

} tp_tabd;

// Aloca-se memória para o descritor 
tp_tabd *inicializa_tabd(){ //Inicializar descritor
    tp_tabd *tab=(tp_tabd*) malloc(sizeof(tp_tabd));
    tab->ini = NULL;
    tab->fim = NULL;

    return tab;
}

int tabd_vazio(tp_tabd *tab) {
    if ( (tab->ini == NULL) )
        return 1;
    return 0;
}

// Aloca um nó ao tabuleiro

tp_no *aloca_tab() {
    tp_no* pt;
    pt=(tp_no*) malloc(sizeof(tp_no));
    return pt;
}

// Insere novo nó no tabuleiro (NO FIM)
int insere_tabd_no_fim (tp_tabd *tab, tp_obj e){
    tp_no *novo;
    novo=aloca_tab();
    if (!novo) return 0;
    novo->info = e;
    if( tabd_vazio(tab) ){ // Se for o primeiro elemento do tabuleiro
        novo->prox = NULL;
        novo->ant = NULL;
        tab->ini = tab->fim = novo;
    }
else {
    novo->prox = NULL;
    novo->ant = tab->fim;
    tab->fim->prox = novo;
    tab->fim = novo;
    }

    return 1;
}

// remover um elemento do tabuleiro
int remove_tabd (tp_tabd *tab, tp_obj e){
    tp_no *atu;
    atu = tab->ini;
    while ( (atu != NULL) && (atu->info.valor != e.valor) ) {
        atu=atu->prox;
    }
    if (atu == NULL) return 0; // Caso 0: Não tem o elemento no tabuleiro/ elemento não encontrado 
    if (tab->ini == tab->fim) { // 1º Caso: Único nó
        tab->ini = tab->fim = NULL;        
    } else {
        if (tab->ini == atu) { // 2º Caso: Primeiro nó
            tab->ini = atu->prox;
            atu->prox->ant = NULL;
        } else {
            if (tab->fim == atu) { // 3º Caso: Último nó
                tab->fim = atu->ant;
                atu->ant->prox = NULL;
            } else {
                atu->prox->ant = atu->ant; // 4º Caso: Nó no meio do tabuleiro
                atu->ant->prox = atu->prox;
            }
        }
    }
    free (atu);
    return 1;
}

// Com base em um conteúdo, retorna o endereço do nó 
tp_no * busca_tabd (tp_tabd *tab, tp_obj e){
    tp_no *atu;
    atu = tab->ini;
    while ( (atu != NULL) && (atu->info.valor != e.valor) ) {
        atu=atu->prox;
    }
    return atu;
}

// Tamanho do tabuleiro
int tamanho_tabd (tp_tabd *tab){
    int cont = 0;
    tp_no *atu;
    atu = tab->ini;
    while (atu != NULL) {
        atu=atu->prox;
        cont++;
    }
    return cont;
}

// Imprimir elementos do tabuleiro
void imprime_tabd(tp_tabd *tab, int ordem) {
    if (tab==NULL)
        printf("Tabuleiro não inicializado \n");
    else {
        tp_no *atu;
        switch (ordem){
            case 1: atu = tab->ini;
                    while (atu != NULL) {
                        printf("%d \n", atu->info.valor);
                        atu=atu->prox;
                        }
                    break;
            case 2: atu = tab->fim;
                    while (atu != NULL){
                        printf("%d \n", atu->info.valor);
                        atu=atu->ant;
                        }
                    break;
            default: printf ("Código Invalido \n");
        }
    }
    printf("\n");
}

// Retira da memória todos os nós do Tabuleiro e também o descritor
tp_tabd * Destroi_tabd (tp_tabd *tab){
    tp_no *atu;
    atu = tab->ini;
    while (atu != NULL) {
        tab->ini = atu->prox;
        free(atu);
        atu=tab->ini;
        }
    free(tab);
    return NULL;
}

void imprime_tabuleiro_Simples(tp_tabd *tab, int ordem) { // Imprime de forma mais simples. Bom para debugar.
    int cont = 0;
    if (tab==NULL)
        printf("Tabuleiro não inicializado \n");
    else {
        tp_no *atu;
        switch (ordem){
            case 1: atu = tab->ini;
                    printf("\e[8C" ); //Avança 8 caracteres/ casas a direita
                    while (atu != NULL) {
                        printf("\e[1C" NEGRITO CIANO "[" RESET NEGRITO AMARELO "%2d" RESET NEGRITO CIANO "]" RESET, atu->info.valor);
                        cont++;
                        if (cont % 5 == 0){
                            printf("\n");
                            printf("\e[8C" );
                        }
                        atu=atu->prox;
                        }
                    break;
            case 2: atu = tab->fim;
                    printf("\e[8C" );
                    while (atu != NULL){
                        printf("\e[1C"NEGRITO CIANO "[" RESET NEGRITO AMARELO "%2d" RESET NEGRITO CIANO "]" RESET, atu->info.valor);
                        cont++;
                        if (cont % 5 == 0){
                            printf("\n");
                            printf("\e[8C" );
                        }
                        atu=atu->ant;
                        }
                    break;
            default: printf ("Código Invalido \n");
        }
    }
    printf("\n");
}

void imprime_tabuleiro_V2(tp_tabd *tab, int ordem)
{
    if (tab == NULL){
        printf("Tabuleiro não inicializado \n");
    }

    else{
    	tp_no *atu;

        switch (ordem){
            case 1:

                atu = tab->ini;

                while (atu != NULL){
                    printf("\e[%d;%dH",
                           atu->info.y_inicio + 1,
                           atu->info.x_inicio + 1);

                    if (atu->info.tipo == PERGUNTA){
                        printf("[%2d?]",
                               atu->info.valor);
                    }

                    else if (atu->info.tipo == AVANCA){
                        printf("[%2d+]",
                               atu->info.valor);
                    }

                    else if (atu->info.tipo == RETORNA){
                        printf("[%2d-]",
                               atu->info.valor);
                    }

                    else{
                        printf("[%2d ]",
                               atu->info.valor);
                    }

                    atu = atu->prox;
                }

                break;

            default:
                printf("Código Invalido \n");
        }
    }
}

#endif

