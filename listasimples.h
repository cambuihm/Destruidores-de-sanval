#ifndef LISTASE_H
#define LISTASE_H
#include <stdio.h>
#include <stdlib.h>

typedef int tp_item;

typedef struct tp_no{
  tp_item info;
  struct tp_no *prox;
}tp_listase;


// Exemplo de uso: tp_listase *lista1 = inicializa_listase();
tp_listase * inicializa_listase(){
        return NULL;
    }

    
// Exemplo de uso: if (listase_vazia(lista1)) { ... }
int listase_vazia(tp_listase *lista){
    if(lista==NULL) return 1;
    return 0;
}

// Exemplo de uso: tp_listase *novo = aloca_listase(); 
// (Nota: Esta função costuma ser de uso interno da própria biblioteca)
tp_listase * aloca_listase(){ // ela irá alocar um espaço na memória;
    tp_listase *novo_no;
    novo_no=(tp_listase*) malloc(sizeof(tp_listase));
    return novo_no;
}

/* Esse **l é um ponteiro que está apontando para outro ponteiro
para o endereço de memória original da listase*, 
o que está apontando para o NULL */

// Exemplo de uso: insere_em_ordem_listase(&lista1, 10);
int insere_em_ordem_listase(tp_listase **l, tp_item e) {
    tp_listase *novo_no, *atu, *ant;  
    novo_no = aloca_listase();
    if(novo_no == NULL) return 0;
    novo_no->info = e;
    atu = *l;
    ant = NULL;

    while((atu != NULL) && (atu->info < novo_no->info)) {
        ant = atu;
        atu = atu->prox;
    }
    if (ant == NULL) {
        *l = novo_no;
    }
    else {
        ant->prox = novo_no;
    }
    novo_no->prox = atu;
    return 1;
}

// Exemplo de uso: insere_listase_no_fim(&lista1, 20);
int insere_listase_no_fim(tp_listase **l, tp_item e){ 
tp_listase *novo_no, *atu;
novo_no=aloca_listase(); // aqui está pegando o novo nó e apontando para o NULL;
if(novo_no==NULL) return 0; // Não alocou memória

// atribuir os valores para o novo nó;
novo_no->info= e;
novo_no->prox=NULL;

//finaliza o encadeamento do nó
if(listase_vazia(*l)){// se for o primeiro nó entra aqui
    *l=novo_no;
} else{
    atu = *l;
    while(atu->prox!=NULL){ 
      atu=atu->prox; // aponta para o ultimo nó
    }
    atu->prox=novo_no;  
}
return 1;}

// Exemplo de uso: imprime_listase(lista1);
void imprime_listase(tp_listase *lista){
    tp_listase *atu;
    atu=lista;
    while (atu!=NULL){
        printf("%d\n", atu->info);
        atu=atu->prox;
    }
}


// Exemplo de uso: remove_listase(&lista1, 10);
int remove_listase(tp_listase **lista,tp_item e){
    tp_listase * ant, *atu;
    atu=*lista;
    ant=NULL;
    while ((atu!=NULL)&&(atu->info!=e)){
        ant=atu;
        atu=atu->prox;  
        }
    if (atu==NULL) return 0; // não foi encontrado o elemento
    if (ant==NULL){// se for retirado o primeiro termo
        *lista=atu->prox; // fazendo a lista apontar para o termo subsequente que foi retirado
    }
    else{
        ant->prox=atu->prox; //fazendo a interligação entre o termo anterior e o termo subsequente ao termo retirado
    }
    free(atu);
    atu=NULL;
    return 1;
}


// Exemplo de uso: tp_listase *no_encontrado = busca_listase(lista1, 20);
tp_listase *busca_listase(tp_listase *lista, tp_item e){
    tp_listase *atu;
    atu=lista;
    while((atu!=NULL)&&(atu->info!=e)){
        atu=atu->prox;
    }
    if (atu==NULL) return NULL;
    return atu;
}


// Exemplo de uso: int tam = tamanho_listase(lista1);
int tamanho_listase(tp_listase *lista){
    int cont=0;        
    tp_listase *atu;
    atu=lista;
    while(atu!=NULL){
        cont++;
        atu=atu->prox;
    }
    return cont;
}


// Exemplo de uso: destroi_listase(&lista1);
void destroi_listase(tp_listase **l){
    tp_listase *atu;
    atu=*l;
    while (atu!=NULL){
        *l=atu->prox;
        free(atu);
        atu=*l;
    }
    *l=NULL;
}

// Retorna o número de nós com valores maiores do que 'n'
// Exemplo de uso: int maiores_que_cinco = conta_maiores_que_n(lista1, 5);
int conta_maiores_que_n(tp_listase *lista, int n) {
    int cont = 0;
    tp_listase *atu = lista;
    
    while (atu != NULL) {
        if (atu->info > n) {
            cont++;
        }
        atu = atu->prox;
    }
    return cont;
}

// Recebe duas listas e retorna 1 se forem idênticas ou 0 se não forem
// Exemplo de uso: int sao_iguais = listas_identicas(lista1, lista2);
int listas_identicas(tp_listase *l1, tp_listase *l2) {
    while (l1 != NULL && l2 != NULL) {
        if (l1->info != l2->info) {
            return 0; // Encontrou elementos diferentes
        }
        l1 = l1->prox;
        l2 = l2->prox;
    }
    
    // Se ambas chegaram ao final juntas (NULL), são idênticas.
    // Se uma terminou antes da outra, os tamanhos são diferentes.
    if (l1 == NULL && l2 == NULL) return 1;
    
    return 0;
}

// Destrói todos os nós que contenham valores ímpares
// Exemplo de uso: destroi_impares(&lista1);
void destroi_impares(tp_listase **lista) {
    tp_listase *atu = *lista;
    tp_listase *ant = NULL;
    tp_listase *temp;

    while (atu != NULL) {
        if (atu->info % 2 != 0) { // É ímpar
            temp = atu; 
            
            if (ant == NULL) {
                // Se for o primeiro elemento da lista
                *lista = atu->prox;
                atu = *lista;
            } else {
                // Se for no meio ou no fim
                ant->prox = atu->prox;
                atu = atu->prox;
            }
            free(temp); // Libera a memória do nó ímpar
        } else {
            // Só avança o 'ant' se não houve remoção
            ant = atu;
            atu = atu->prox;
        }
    }
}

// Une duas listas e transforma em uma lista encadeada circular
// Exemplo de uso: une_em_circular(&lista1, &lista2);
void une_em_circular(tp_listase **l1, tp_listase **l2) {
    // Se alguma das listas for vazia, não há como fazer a união circular proposta
    if (*l1 == NULL || *l2 == NULL) return; 

    tp_listase *ultimo_l1 = *l1;
    // Encontra o último elemento da L1
    while (ultimo_l1->prox != NULL) {
        ultimo_l1 = ultimo_l1->prox;
    }

    tp_listase *ultimo_l2 = *l2;
    // Encontra o último elemento da L2
    while (ultimo_l2->prox != NULL) {
        ultimo_l2 = ultimo_l2->prox;
    }

    // Último da L1 aponta para o primeiro da L2
    ultimo_l1->prox = *l2;
    
    // Último da L2 aponta para o primeiro da L1
    ultimo_l2->prox = *l1;
    
    // O ponteiro da L2 passa a referenciar o primeiro elemento da L1
    *l2 = *l1;
}
#endif