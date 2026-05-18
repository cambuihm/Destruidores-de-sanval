#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#define MAX 100

typedef int tp_item;

typedef struct {
    tp_item item[MAX];
    int frente, fim; // Mudei de 'ini' para 'frente' para bater com as funções
} tp_fila;

void inicializar_fila(tp_fila *f) {
    f->frente = f->fim = MAX - 1;
}

int fila_vazia(tp_fila *f) {
    return (f->frente == f->fim);
}

int proxima_posicao(int pos) {
    if (pos == MAX - 1) return 0;
    return ++pos;
}

int fila_cheia(tp_fila *f) {
    return (proxima_posicao(f->fim) == f->frente);
}

int enfileirar(tp_fila *f, tp_item e) {
    if (fila_cheia(f)) return 0;
    f->fim = proxima_posicao(f->fim);
    f->item[f->fim] = e;
    return 1;
}

int desenfileirar(tp_fila *f, tp_item *e) {
    if (fila_vazia(f)) return 0;
    f->frente = proxima_posicao(f->frente); // Agora usa 'frente' corretamente
    *e = f->item[f->frente];
    return 1;
}

void imprimir_fila(tp_fila f) {
    tp_item e;
    while (desenfileirar(&f, &e)) {
        printf("%d ", e);
    }
}

int tamanho_fila(tp_fila *f) {
    if (f->fim >= f->frente) {
        return f->fim - f->frente;
    }
    return (MAX - f->frente) + f->fim;
}

int comparar_filas(tp_fila f1, tp_fila f2) {
    tp_item e1, e2;

    if (tamanho_fila(&f1) != tamanho_fila(&f2)) {
        return 0;
    }

    // 2. 
    while (!fila_vazia(&f1)) {
       
        desenfileirar(&f1, &e1);
        desenfileirar(&f2, &e2);

        if (e1 != e2) {
            return 0; 
        }
    }

    return 1; 
}

#endif