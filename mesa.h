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


#endif