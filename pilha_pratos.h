#ifndef PILHA_P_H
#define PILHA_P_H

#include <stdbool.h>

#define LIMPO true
#define SUJO false

struct pratos
{
    bool estado;
    struct pratos* prox;    
};

typedef struct pratos Pratos;

struct pilha
{
    Pratos* prim;
};

typedef struct pilha Pilha;




#endif