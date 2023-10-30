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
    l->ant = NULL;
    l->prox = NULL;
    if (f->fim == NULL)
        f->ini = l;
    else
    {
        f->fim->prox = l;
        l->ant = f->fim;
    }
    f->fim = l;
}

void grupo_espera_fila(Fila *f, Grupo gp)
{
    if (f->ini == NULL){
        
        printf("inserindo fila  nula\n");
        gp.senha = 1;
    }
    else{
        printf("inserindo fila nao nula\n");
        gp.senha = f->fim->grupo.senha + 1;
    }
    insere_fila(f, gp);
}

void retira_da_fila(Fila* f)
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

void retira_quem_desistiu_de_esperar(Lista* l){
    Lista* a = l->ant;
    Lista* p = l->prox;
    if (a != NULL)
        a->prox = p;
    if (p != NULL)
        p->ant = a;
}

void desistir_de_esperar(Fila *f)
{
    int pos;
    printf("Qual a posicao da fila que o grupo esta (Ex: 1 = primeiro da fila): ");
    scanf("%d", &pos);
    Lista *l = f->ini;
    int i;
    for (i = 1; i <= pos; i++, l = l->prox)
    {
        if (l == NULL)
        {
            printf("Essa posicao nao existe. Tente novamente\n");
            break;
        }
        else if (i == pos)
        {
            if(pos == 1)
                retira_da_fila(f);
            else
                retira_quem_desistiu_de_esperar(l);
        }
    }
}

void imprime_fila(Fila *f)
{
    int i = 1;
    if (f->ini == NULL)
    {
        printf("A fila esta vazia.\n");
        return;
    }
    for (Lista *l = f->ini; l != NULL; l = l->prox, i++)
    {
        printf("Grupo %d", i);
        printf("\n\t Senha: %d", l->grupo.senha);
        printf("\n\t Numero de pessoas: %d\n\n", l->grupo.num_pessoas);
    }
}