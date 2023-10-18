#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menu.h"



void escolhe(Mesa** mesas, Quantidade qt_mesas, Fila* fila_espera){
    int option = 1;
    while (option > 0)
    {
        printf("Escolha uma das opcoes:\n");
        printf(" 1. ADICIONAR GRUPO:\n");


        scanf("%d", &option);

        menu(option, mesas, qt_mesas, fila_espera);
    }
    
}

void menu(int option, Mesa** mesas, Quantidade qt_mesas, Fila* fila_espera){
    switch (option)
    {
    case 1:
        add_grupo(mesas, qt_mesas, fila_espera);
        break;
    case 2:
        if(liberar_mesa(mesas, qt_mesas))
        {
            coloca_grupo_na_mesa(mesas, qt_mesas,fila_espera);
        }
        
        break;
    case 3:
        desistir_de_esperar(fila_espera);
        break;
    
    default:
        break;
    }
}