#ifndef GP_H
#define GP_H

struct grupo
{
    int num_pessoas;
    int senha;

};
typedef struct grupo Grupo;

void add_grupo(Mesa** mesas, Quantidade qt_mesas, Fila* fila_espera);


#endif