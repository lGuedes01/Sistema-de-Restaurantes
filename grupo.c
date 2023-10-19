#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menu.h"
#include "mesa.h"
#include "fila.h"
#include "pilha_pratos.h"
#include "grupo.h"
void add_grupo(Mesa** mesas, Quantidade qt_mesas, Fila* fila_espera){
    Grupo gp;
    Mesa* mesa_do_gp;
    printf("Quantas pessoas tem o grupo:");
    scanf("%d", &gp.num_pessoas);
    while (gp.num_pessoas > 0)
    {
        mesa_do_gp = verifica_mesa_livre(mesas, qt_mesas);
        if (mesa_do_gp == NULL)
        {
            grupo_espera_fila(fila_espera,gp);
            break;
        }
        else
        {
            if (gp.num_pessoas <= MAX_PESSOAS)
            {
                reserva_mesa(gp.num_pessoas, mesa_do_gp);
            }
            else
            {
                reserva_mesa(MAX_PESSOAS, mesa_do_gp);
            }
        }
        gp.num_pessoas -= MAX_PESSOAS;
    }
    
}


void coloca_grupo_na_mesa(Mesa** mesas, Quantidade qt_mesas, Fila* fila_espera){
    for (int i = 0; i < qt_mesas.lin; i++)
    {
        for (int j = 0; j < qt_mesas.col; j++)
        {
            if (mesas[i][j].ocupada == false)
            {
                Mesa* mesa_do_gp = &mesas[i][j];
                if (fila_espera->ini->grupo.num_pessoas <= MAX_PESSOAS)
                {
                    reserva_mesa(fila_espera->ini->grupo.num_pessoas, mesa_do_gp);
                }
                else
                {
                    reserva_mesa(MAX_PESSOAS, mesa_do_gp);
                }
                fila_espera->ini->grupo.num_pessoas -= MAX_PESSOAS;
                if (fila_espera->ini->grupo.num_pessoas <= 0)
                {
                    retira_da_fila(fila_espera);
                }
                

            }
        }
    }
}