#ifndef LISTADPEN_H
#define LISTADPEN_H

#include <stdio.h>
#include <stdlib.h>

typedef int tp_item;

// Dados estruturados que representam o nó da lista dupla (ATUALIZADO)
typedef struct tp_no_d {
	struct tp_no_d *ant;
	tp_item info;
	struct tp_no_d *prox;
} tp_no_d;

// Dados estruturados que representam o descritor
typedef struct {
	tp_no_d *ini;
	tp_no_d *fim;
	//int tamanho;
} tp_listad;

// Aloca-se memória para o descritor
tp_listad *inicializa_listad() {
	tp_listad *lista = (tp_listad*) malloc(sizeof(tp_listad));
	lista->ini = NULL;
	lista->fim = NULL;
	//lista->tamanho = 0;
	return lista;
}

int listad_vazia(tp_listad *lista) {
	if (lista->ini == NULL) {
		return 1;
	}
	return 0;
}

// Aloca um nó da lista dupla (ATUALIZADO)
tp_no_d *aloca() {
	tp_no_d* pt;
	pt = (tp_no_d*) malloc(sizeof(tp_no_d));
	return pt;
}

// Insere um novo nó na lista no fim (ATUALIZADO)
int insere_listad_no_fim(tp_listad *lista, tp_item e) {
	tp_no_d *novo;
	novo = aloca();
	if (!novo) return 0;
	novo->info = e;
	if (listad_vazia(lista)) {
		novo->prox = NULL;
		novo->ant = NULL;
		lista->ini = lista->fim = novo;
	}
	else {
		novo->prox = NULL;
		novo->ant = lista->fim;
		lista->fim->prox = novo;
		lista->fim = novo;
	}
	//lista->tamanho++;
	return 1;
}

// Remove um elemento da lista (ATUALIZADO)
int remove_listad(tp_listad *lista, tp_item e) {
	tp_no_d *atu;
	atu = lista->ini;
	while ((atu != NULL) && (atu->info != e)) {
		atu = atu->prox;
	}
	if (atu == NULL) return 0;
	if (lista->ini == lista->fim) {
		lista->ini = lista->fim = NULL;
	}
	else {
		if (lista->ini == atu) { // Se for o primeiro nó da lista
			lista->ini = atu->prox;
			atu->prox->ant = NULL;
		}
		else {
			if (lista->fim == atu) { // Se for o último nó da lista
				lista->fim = atu->ant;
				atu->ant->prox = NULL;
			}
			else {
				atu->prox->ant = atu->ant;
				atu->ant->prox = atu->prox;
			}
		}
	}
	free(atu);
	//lista->amanho--;
	return 1;
}

// Imprime os elementos da lista do início ao fim (ATUALIZADO)
void imprime_listad(tp_listad *lista) {
    if (lista == NULL || listad_vazia(lista)) {
        printf("A lista esta vazia.\n");
        return;
    }

    tp_no_d *atu = lista->ini;
    printf("Lista: ");
    while (atu != NULL) {
        printf("%d ", atu->info);
        atu = atu->prox;
    }
    printf("\n");
}

// Imprime os elementos da lista do fim para o início (ATUALIZADO)
void imprime_listad_reverso(tp_listad *lista) {
    if (lista == NULL || listad_vazia(lista)) {
        printf("A lista esta vazia.\n");
        return;
    }

    tp_no_d *atu = lista->fim;
    printf("Lista (reversa): ");
    while (atu != NULL) {
        printf("%d ", atu->info);
        atu = atu->ant;
    }
    printf("\n");
}

// Busca um elemento na lista dupla (ATUALIZADO)
tp_no_d *busca_listade(tp_listad *lista, tp_item e) {
    tp_no_d *atu;
    atu = lista->ini;
    while ((atu != NULL) && (atu->info != e)) {
        atu = atu->prox;
    }
    return atu;
}

// Destrói a lista e limpa a memória (ATUALIZADO)
tp_listad *Destroi_listad(tp_listad *lista) {
    tp_no_d *atu;
    atu = lista->ini;
    while (atu != NULL) {
        lista->ini = atu->prox;
        free(atu);
        atu = lista->ini;
    }
    free(lista);
    return NULL;
}

#endif