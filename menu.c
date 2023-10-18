#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menu.h"
#include "mesa.h"
#include "fila.h"
#include "pilha_pratos.h"
#include "grupo.h"


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
    
    default:
        break;
    }
}