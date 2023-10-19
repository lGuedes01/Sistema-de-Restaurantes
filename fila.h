#ifndef FILA_H
#define FILA_H

typedef struct lista Lista;

struct fila
{
    Lista *ini;
    Lista *fim;
};
typedef struct fila Fila;

#include "menu.h"
#include "mesa.h"
#include "pilha_pratos.h"
#include "grupo.h"

struct lista
{
    struct lista *prox;
    Grupo grupo;
};

Fila *cria_fila();
void insere_fila(Fila *f, Grupo gp);
void grupo_espera_fila(Fila *f, Grupo gp);
void retira_da_fila(Fila *f);
void desistir_de_esperar(Fila *f);
void imprime_fila(Fila *f);
#endif