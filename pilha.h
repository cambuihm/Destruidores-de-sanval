#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#define MAX 100

typedef int tp_item;

typedef struct {
    int topo;
    tp_item item[MAX];
} tp_pilha;

void inicializa_pilha(tp_pilha *p) {
    p->topo = -1;
}

int pilha_vazia(tp_pilha *p) {
    return (p->topo == -1);
}

int pilha_cheia(tp_pilha *p) {
    return (p->topo == MAX - 1);
}

int push(tp_pilha *p, tp_item e) {
    if (pilha_cheia(p)) return 0;
    p->topo++;
    p->item[p->topo] = e;
    return 1;
}

int pop(tp_pilha *p, tp_item *e) {
    if (pilha_vazia(p)) return 0;
    *e = p->item[p->topo];
    p->topo--;
    return 1;
}

void imprimir_pilha(tp_pilha p) {
    tp_item e;
    while (pop(&p, &e)) {
        printf("%d ", e);
    }
}

int altura_pilha(tp_pilha *p) {
    return p->topo + 1;
}

// Remove ímpares mantendo a ordem original dos pares
void remover_impares(tp_pilha *p) {
    tp_pilha auxiliar;
    tp_item e;
    inicializa_pilha(&auxiliar);

    while (pop(p, &e)) {
        if (e % 2 == 0) push(&auxiliar, e);
    }
    // Devolve para a pilha original para manter a ordem
    while (pop(&auxiliar, &e)) {
        push(p, e);
    }
}

#endif