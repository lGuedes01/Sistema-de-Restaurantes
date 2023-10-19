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
    qt_mesas = quantidade_mesas();
    mesas = cria_mesas(qt_mesas);
    escolhe(mesas, qt_mesas, fila_espera);
    return 0;
}
