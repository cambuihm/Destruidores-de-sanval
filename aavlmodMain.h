/* Um exemplo de main que fiz para testar as funções da biblioteca aavlmod.h , 
já serve como base para entender como as funções funcionam na main. 
~Fernando*/

#include <stdio.h>
#include <stdlib.h>
#include "aavlmod.h"

// Função para popular a árvore
void popular_ARV (ArvAVL *raiz){
    int i = 0;
    for (i = 1; i <= 59; i++) {
       inserirMOD(raiz, i); 
    }
}

// Função para gerar as estatísticas de visitas nas casas
void create_stats (){
    ArvAVL *raiz = criarAVL();
    popular_ARV (raiz);
// APENAS PARA TESTES
    registrarVisita(raiz, 56);
    registrarVisita(raiz, 5);
    registrarVisita(raiz, 46);
    registrarVisita(raiz, 23);
    registrarVisita(raiz, 3);
    registrarVisita(raiz, 18);
    registrarVisita(raiz, 10);
// -----------------
    printf(RESET NEGRITO VERDE "//----------- ESTATÍSTICAS -----------//\n" RESET);
// RESET, NEGRITO e VERDE estão declarados nos "defines" na biblioteca aavlmod.h 
    relatorio(raiz);
    printf(RESET NEGRITO VERDE "//------------------------------------//\n" RESET);
}

int main (){
    create_stats ();
    
    return 0;
}

