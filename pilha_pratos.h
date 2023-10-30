#ifndef PILHA_P_H
#define PILHA_P_H
#include <stdbool.h>

#include "menu.h"

struct pratos
{
    bool usando;
    int id;
    struct pratos *prox;
};

typedef struct pratos Pratos;

struct pilha
{
    Pratos *prim;
};

typedef struct pilha Pilha;

struct listap
{
    struct listap *prox;
    Pratos *prato;
};
typedef struct listap Listapratos;
#include "mesa.h"

void repor_pratos(Pilha *pilha_pratos);
bool arrumar_mesa(Mesa **mesas, Quantidade qt_mesas, Pilha *pilha_pratos, int num_mesa);
Pilha *criar_pilha();

Listapratos *insere_na_mesa(Pratos *prato, Listapratos *lista_pratos);
void push_novo_prato(Pilha *pilha);
void push_prato_existente(Pilha *pilha, Pratos *novo_prato);
Pratos *pop(Pilha *pilha);
void colocar_pratos(int num_pratos, Pilha *pilha_pratos);
void tirar_pratos(int n_p, Pilha *pilha_pratos, Mesa *mesa);
void imprimir_pilha(Pilha *pilha);
int tam_pilha(Pilha *pilha_pratos);
Pratos *tirar_prato_lista(Listapratos **l);

#endif