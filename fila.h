#ifndef FILA_H
#define FILA_H

#include "grupo.h"

struct lista
{
    struct lista* prox;
    Grupo grupo;
};

typedef struct lista Lista;

struct fila
{
    Lista* ini;
    Lista* fim;
};
typedef struct fila Fila;


Fila* cria_fila();
void insere_fila(Fila* f, Grupo gp);
void grupo_espera_fila(Fila* f, Grupo gp);
#endif