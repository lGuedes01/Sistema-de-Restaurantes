#ifndef GP_H
#define GP_H

struct grupo
{
    int num_pessoas;
    int senha;

};
typedef struct grupo Grupo;

#include "menu.h"
#include "mesa.h"
#include "fila.h"
#include "pilha_pratos.h"

void add_grupo(Mesa** mesas, Quantidade qt_mesas, Fila* fila_espera);
void coloca_grupo_na_mesa(Mesa** mesas, Quantidade qt_mesas, Fila* fila_espera);


#endif