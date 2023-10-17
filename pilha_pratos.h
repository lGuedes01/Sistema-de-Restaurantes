#ifndef PILHA_P_H
#define PILHA_P_H

#include <stdbool.h>
struct pratos
{
    bool usando;
    int id;
    struct pratos* prox;    
};

typedef struct pratos Pratos;

struct pilha
{
    Pratos* prim;
};

typedef struct pilha Pilha;




#endif