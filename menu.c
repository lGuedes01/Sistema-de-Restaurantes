#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menu.h"
#include "mesa.h"
#include "fila.h"
#include "grupo.h"
#include "pilha_pratos.h"

void escolhe(Mesa **mesas, Quantidade qt_mesas, Fila *fila_espera, Pilha *pilha_pratos)
{
    int option = 1;
    while (option > 0)
    {
        printf("---------------------------------\n");
        printf("Escolha uma das opcoes:\n");
        printf(" 1. ADICIONAR GRUPO:\n");
        printf(" 2. FINALIZAR REFEICAO:\n");
        printf(" 3. DESISTIR DE ESPERAR:\n");
        printf(" 4. ARRUMAR MESA:\n");
        printf(" 5. REPOR PRATOS:\n");
        printf(" 6. IMPRIMIR:\n");
        printf("---------------------------------\n");
        scanf("%d", &option);

        menu(option, mesas, qt_mesas, fila_espera, pilha_pratos);
    }
}

int pega_mesa()
{
    int num = 0;
    printf("Informe o numero da mesa: ");
    scanf("%d", &num);
    return num;
}

void menu(int option, Mesa **mesas, Quantidade qt_mesas, Fila *fila_espera, Pilha *pilha_pratos)
{
    int num;
    int num_pratos;
    switch (option)
    {
    case 1:
        add_grupo(mesas, qt_mesas, fila_espera, pilha_pratos);
        break;
    case 2:
        num = pega_mesa();
        if (liberar_mesa(mesas, qt_mesas,num))
        {
            if (fila_espera->ini != NULL)
            {
                while (!arrumar_mesa(mesas, qt_mesas, pilha_pratos, num))
                {
                    pilha_pratos = repor_pratos(pilha_pratos);
                }
                coloca_grupo_na_mesa(mesas, qt_mesas, fila_espera, pilha_pratos);
                
            }
        }
        break;
    case 3:
        desistir_de_esperar(fila_espera);
        break;
    case 4:
        num = pega_mesa();
        arrumar_mesa(mesas, qt_mesas, pilha_pratos, num);
        break;
    case 5:
        printf("Digite quantos pratos deseja colocar na pilha: ");
        scanf("%d", &num_pratos);
        pilha_pratos = colocar_pratos(num_pratos, pilha_pratos);
        break;
    case 6:
        menu_impressao(mesas, qt_mesas, fila_espera, pilha_pratos);
        break;
    default:
        break;
    }
}

void menu_impressao(Mesa **mesas, Quantidade qt_mesas, Fila *fila_espera, Pilha *pilha_pratos)
{
    int option = 1;
    while (option != -1)
    {
        printf("---------------------------------\n");
        printf("Escolha uma das opcoes:\n");
        printf(" 1. IMPRIMIR MESAS:\n");
        printf(" 2. IMPRIMIR FILA DE ESPERA:\n");
        printf(" 3. IMPRIMIR PILHA DE PRATOS:\n");
        printf(" -1. SAIR:\n");
        printf("---------------------------------\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            imprime_mesas(mesas, qt_mesas);
            break;
        case 2:
            imprime_fila(fila_espera);
            break;
        case 3:
            imprimir_pilha(pilha_pratos);
            break;
        default:
            break;
        }
    }
}
