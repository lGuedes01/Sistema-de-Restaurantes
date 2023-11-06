#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menu.h"
#include "mesa.h"
#include "fila.h"
#include "pilha_pratos.h"
#include "grupo.h"

Mesa **aloca_mesas(int lin, int col)
{
    Mesa **mesas;
    mesas = (Mesa **)malloc(lin * sizeof(Mesa *));
    for (int i = 0; i < lin; i++)
    {
        mesas[i] = (Mesa *)malloc(col * sizeof(Mesa));
    }
    return mesas;
}

Quantidade quantidade_mesas()
{
    Quantidade mesas;
    printf("Digite o numero de linhas de mesas:");
    scanf("%d", &mesas.lin);
    printf("Digite o numero de colunas de mesas:");
    scanf("%d", &mesas.col);

    mesas.n_mesas = mesas.col * mesas.lin;
    return mesas;
}

Mesa **cria_mesas(Quantidade qt_mesas)
{
    Mesa **mesas = aloca_mesas(qt_mesas.lin, qt_mesas.col);
    int cont = 1;
    for (int i = 0; i < qt_mesas.lin; i++)
    {
        for (int j = 0; j < qt_mesas.col; j++, cont++)
        {
            Mesa *mesa_atual = &mesas[i][j];
            mesa_atual->pessoas = 0;
            mesa_atual->num_mesa = cont;
            mesa_atual->comanda = cont;
            mesa_atual->ocupada = false;
            mesa_atual->pratos_mesa = NULL;
        }
    }
    return mesas;
}

void imprime_mesas(Mesa **mesas, Quantidade qt_mesas)
{

    for (int i = 0; i < qt_mesas.lin; i++)
    {
        for (int j = 0; j < qt_mesas.col; j++)
        {
            printf("\nMesa %d\nComanda %d\n", mesas[i][j].num_mesa, mesas[i][j].comanda);
            switch (mesas[i][j].pessoas)
            {
            case 0:
                printf("\t ____\n\t |oo|\n\t |oo|\n\t ----");
                break;
            case 1:
                printf("\t ____\n\t!|o |\n\t |  |\n\t ----");
                break;
            case 2:
                printf("\t ____\n\t!|oo|!\n\t |  |\n\t ----");
                break;
            case 3:
                printf("\t ____\n\t!|oo|!\n\t!|o |\n\t ----");
                break;
            case 4:
                printf("\t ____\n\t!|oo|!\n\t!|oo|!\n\t ----");
                break;

            default:
                break;
            }
            printf("\n");
            for (Pratos *p = mesas[i][j].pratos_mesa; p != NULL; p = p->prox)
            {
                printf("%d - ", p->id);
            }
        }
    }
}

Mesa *verifica_mesa_livre(Mesa **mesas, Quantidade qt_mesas)
{
    for (int i = 0; i < qt_mesas.lin; i++)
    {
        for (int j = 0; j < qt_mesas.col; j++)
        {
            Mesa *mesa_atual = &mesas[i][j];
            if (mesa_atual->ocupada == false)
            {
                return mesa_atual;
            }
        }
    }
    return NULL;
}

void reserva_mesa(int pessoas, Mesa *mesa_para_reservar, Pilha *pilha_pratos)
{
    mesa_para_reservar->ocupada = true;
    mesa_para_reservar->pessoas = pessoas;
    mesa_para_reservar->pratos_mesa = tirar_pratos(pessoas, pilha_pratos, mesa_para_reservar);
}

Pratos *liberar_prato_lista(Pratos *lista_pratos)
{
    while (lista_pratos != NULL)
    {
        Pratos *p = lista_pratos->prox;
        free(lista_pratos);
        lista_pratos = p;
    }

    return lista_pratos;
}

int proxima_comanda(Mesa **mesas, Quantidade qt_mesas)
{
    int maior = 0;
    for (int i = 0; i < qt_mesas.lin; i++)
    {
        for (int j = 0; j < qt_mesas.col; j++)
        {
            if (mesas[i][j].comanda > maior)
                maior = mesas[i][j].comanda;
        }
    }
    return maior + 1;
}

bool liberar_mesa(Mesa **mesas, Quantidade qt_mesas, int num)
{
    printf("teste 2\n");
    for (int i = 0; i < qt_mesas.lin; i++)
    {
        for (int j = 0; j < qt_mesas.col; j++)
        {
            if (mesas[i][j].num_mesa == num && mesas[i][j].ocupada)
            {
                mesas[i][j].ocupada = false;
                mesas[i][j].pessoas = 0;

                mesas[i][j].pratos_mesa = liberar_prato_lista(mesas[i][j].pratos_mesa);
                mesas[i][j].comanda = proxima_comanda(mesas, qt_mesas);
                printf("Liberou Mesa\n");
                return true;
            }
        }
    }
    printf("Nao Liberou Mesa\n");
    return false;
}
