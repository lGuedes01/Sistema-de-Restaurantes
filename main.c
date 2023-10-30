#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menu.h"
#include "mesa.h"
#include "fila.h"
#include "pilha_pratos.h"
#include "grupo.h"

int main()
{
    Fila *fila_espera;
    fila_espera = cria_fila();
    Mesa **mesas;
    Quantidade qt_mesas;
    Pilha *pilha_pratos;
    qt_mesas = quantidade_mesas();
    mesas = cria_mesas(qt_mesas);
    pilha_pratos = criar_pilha();
    pilha_pratos = colocar_pratos(qt_mesas.n_mesas * 4, pilha_pratos);
    for (int i = 1; i < qt_mesas.n_mesas + 1; i++)
    {
        arrumar_mesa(mesas, qt_mesas, pilha_pratos, i);
    }
    escolhe(mesas, qt_mesas, fila_espera, pilha_pratos);
    return 0;
}
