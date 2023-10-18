#ifndef MESA_H
#define MESA_H

#define MAX_PESSOAS 4
#include <stdbool.h>

struct mesa
{
    int pessoas;
    int comanda;
    int num_mesa;
    bool ocupada;
};
typedef struct mesa Mesa;

struct quantidade
{
    int lin;
    int col;
    int n_mesas;
};
typedef struct quantidade Quantidade;

#include "menu.h"
#include "fila.h"
#include "pilha_pratos.h"
#include "grupo.h"


Mesa** aloca_mesas(int lin, int col);
Quantidade quantidade_mesas();
Mesa** cria_mesas(Quantidade qt_mesas);

void imprime_mesas(Mesa** mesas, Quantidade qt_mesas);

Mesa* verifica_mesa_livre(Mesa** mesas, Quantidade qt_mesas);

void reserva_mesa(int pessoas, Mesa* mesa_para_reservar);

bool liberar_mesa(Mesa** mesas, Quantidade qt_mesas);


#endif