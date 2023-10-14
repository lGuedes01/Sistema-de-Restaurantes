#ifndef FILA_H
#define FILA_H

#include "grupo.h"

struct fila
{
    struct fila* prox;
    Grupo grupo;
};

typedef struct fila Fila;


#endif