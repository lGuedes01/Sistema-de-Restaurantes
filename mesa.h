#ifndef MESA_H
#define MESA_H

#define MAX_PESSOAS 4
#include <stdbool.h>

typedef struct mesa Mesa;
typedef struct quantidade Quantidade;

#include "pilha_pratos.h"

struct mesa
{
    int pessoas;
    int comanda;
    int num_mesa;
    bool ocupada;
    bool arrumada;
    Listapratos *pratos_mesa;
};

struct quantidade
{
    int lin;
    int col;
    int n_mesas;
};

#include "menu.h"
#include "fila.h"

#include "grupo.h"

Mesa **aloca_mesas(int lin, int col);
Quantidade quantidade_mesas();
Mesa **cria_mesas(Quantidade qt_mesas);

void imprime_mesas(Mesa **mesas, Quantidade qt_mesas);

Mesa *verifica_mesa_livre(Mesa **mesas, Quantidade qt_mesas);

void reserva_mesa(int pessoas, Mesa *mesa_para_reservar, Pilha *pilha_pratos);

bool liberar_mesa(Mesa **mesas, Quantidade qt_mesas, int num);
void liberar_prato_lista(Listapratos **lista);
int pega_mesa();

#endif