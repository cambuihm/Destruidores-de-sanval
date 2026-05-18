#ifndef EVENTOS_H
#define EVENTOS_H
#include <stdio.h>
#include <stdlib.h>

#include "TabuleiroDE.h"

void gerarCasasEspeciais(tp_tabd *tab)
{
    tp_no *aux = tab->ini;

    while(aux != NULL)
    {
        if(aux->ant != NULL &&
           aux->prox != NULL)
        {
            int sorteio;

            sorteio = rand() % 100;

            if(sorteio < 15)
            {
                aux->info.tipo = PERGUNTA;
            }

            else if(sorteio < 23)
            {
                aux->info.tipo = AVANCA;
            }

            else if(sorteio < 31)
            {
                aux->info.tipo = RETORNA;
            }

            else
            {
                aux->info.tipo = NORMAL;
            }
        }

        aux = aux->prox;
    }
}

#endif