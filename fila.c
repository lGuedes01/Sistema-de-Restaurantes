#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "menu.h"
#include "mesa.h"
#include "fila.h"
#include "pilha_pratos.h"
#include "grupo.h"

Fila *cria_fila()
{
    Fila *f;
    f = (Fila *)malloc(sizeof(Fila));

    f->ini = NULL;
    f->fim = NULL;
    return f;
}

void insere_fila(Fila *f, Grupo gp)
{
    Lista *l;
    l = (Lista *)malloc(sizeof(Lista));
    l->grupo = gp;
    l->prox = NULL;
    if (f->fim == NULL)
        f->ini = l;
    else
        f->fim->prox = l;
    f->fim = l;
}

void grupo_espera_fila(Fila *f, Grupo gp)
{
    if (f->ini == NULL)
        gp.senha = 1;
    else
        gp.senha = f->fim->grupo.senha + 1;
    insere_fila(f, gp);
}

void retira_da_fila(Fila *f)
{
    if (f->fim != NULL)
    {
        Lista *l = f->ini;
        if (f->ini == f->fim)
            f->ini = f->fim = NULL;
        else
            f->ini = f->ini->prox;
        free(l);
    }
}

void desistir_de_esperar(Fila *f)
{
    int pos;
    printf("Qual a posicao da fila que o grupo esta (Ex: 1 = primeiro da fila): ");
    scanf("%d", &pos);
    Fila *f1 = f;
    int i;
    for (i = 1; i <= pos; i++, f1->ini = f1->ini->prox)
    {
        if (f1->ini == NULL)
        {
            printf("Essa posicao nao existe. Tente novamente\n");
            break;
        }
        else if (i == pos)
        {
            retira_da_fila(f1);
        }
    }
}

void imprime_fila(Fila *f)
{
    int i = 1;
    if (f->ini == NULL)
    {
        printf("A fila está vazia.\n");
        return;
    }
    for (Lista *l = f->ini; l != NULL; l = l->prox, i++)
    {
        printf("Grupo %d", i);
        printf("\n\t Senha: %d", l->grupo.senha);
        printf("\n\t Numero de pessoas: %d\n\n", l->grupo.num_pessoas);
    }
}