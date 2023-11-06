#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menu.h"
#include "mesa.h"
#include "pilha_pratos.h"

Pilha *criar_pilha()
{
    Pilha *nova_pilha = (Pilha *)malloc(sizeof(Pilha));
    nova_pilha->prim = NULL;
    nova_pilha->idp = 0;
    return nova_pilha;
}

Pilha *push_novo_prato(Pilha *pilha)
{
    Pratos *novo_prato = (Pratos *)malloc(sizeof(Pratos));
    novo_prato->id = pilha->idp++;
    novo_prato->prox = pilha->prim;
    pilha->prim = novo_prato;
    return pilha;
}

Pratos *push_prato_existente(Pilha *pilha, Pratos *novo_prato)
{
    novo_prato->prox = pilha->prim;
    return novo_prato;
}

Pratos *pop(Pilha *pilha)
{
    if (pilha->prim == NULL)
    {
        printf("A pilha de pratos esta vazia.\n");
        return NULL;
    }
    Pratos *prato_removido = pilha->prim;
    pilha->prim = pilha->prim->prox;
    return prato_removido;
}

Pratos *insere_na_mesa(Pratos *prato, Pratos *lista_pratos_na_mesa)
{
    prato->prox = lista_pratos_na_mesa;
    return prato;
}

int tam_pilha(Pilha *pilha_pratos)
{
    int count = 0;
    for (Pratos *p = pilha_pratos->prim; p != NULL; p = p->prox)
    {
        count++;
    }
    return count;
}

bool arrumar_mesa(Mesa **mesas, Quantidade qt_mesas, Pilha *pilha_pratos, int num_mesa)
{
    for (int i = 0; i < qt_mesas.lin; i++)
    {
        for (int j = 0; j < qt_mesas.col; j++)
        {
            if (mesas[i][j].num_mesa == num_mesa)
            {
                if (tam_pilha(pilha_pratos) < 4)
                {
                    printf("Nao tem a quantidade necessaria de pratos na pilha, reponha os pratos\n");
                    return false;
                }
                else
                {
                    if (mesas[i][j].pratos_mesa != NULL)
                    {
                        printf("A mesa já está arrumada");
                        break;
                    }
                    for (int x = 0; x < 4; x++)
                    {
                        Pratos *prato = pop(pilha_pratos);
                        if (prato != NULL)
                        {
                            mesas[i][j].pratos_mesa = insere_na_mesa(prato, mesas[i][j].pratos_mesa);
                        }
                    }
                }
            }
        }
    }
    return true;
}

Pilha *colocar_pratos(int num_pratos, Pilha *pilha_pratos)
{
    for (int i = 0; i < num_pratos; i++)
    {
        pilha_pratos = push_novo_prato(pilha_pratos);
    }
    return pilha_pratos;
}

Pilha *repor_pratos(Pilha *pilha_pratos)
{
    while (tam_pilha(pilha_pratos) < 4)
    {
        int num_pratos = 0;
        printf("Para arrumar a mesa, eh necessario, pelo menos, 4 pratos na pilha.\nNo momento, ha %d pratos na pilha.\n", tam_pilha(pilha_pratos));
        printf("Digite quantos pratos deseja colocar na pilha: ");
        scanf("%d", &num_pratos);
        pilha_pratos = colocar_pratos(num_pratos, pilha_pratos);
    }
    return pilha_pratos;
}

Pratos *tirar_prato_lista(Mesa *mesa)
{
    Pratos *p = mesa->pratos_mesa;
    mesa->pratos_mesa = mesa->pratos_mesa->prox;
    p->prox = NULL;
    return p;
}

Pratos *tirar_pratos(int num_pessoas, Pilha *pilha_pratos, Mesa *mesa)
{
    if (mesa->pratos_mesa == NULL)
    {
        printf("Nao tem como colocar pessoas na mesa sem estar arrumada.\n");
        repor_pratos(pilha_pratos);
        for (int x = 0; x < 4; x++)
        {
            Pratos *prato = pop(pilha_pratos);
            if (prato != NULL)
                mesa->pratos_mesa = insere_na_mesa(prato, mesa->pratos_mesa);
        }
    }
    int num_pratos_para_retirar = MAX_PESSOAS - num_pessoas;
    for (int i = 0; i < num_pratos_para_retirar; i++)
    {
        Pratos *prato_retirado = tirar_prato_lista(mesa);
        pilha_pratos->prim = push_prato_existente(pilha_pratos, prato_retirado);
    }
    return mesa->pratos_mesa;
}

void imprimir_pilha(Pilha *pilha)
{
    Pratos *atual = pilha->prim;
    int contador = 0;
    if (atual == NULL)
    {
        printf("A pilha de pratos esta vazia.\n");
        return;
    }

    printf("Pilha de pratos:\n");

    while (atual != NULL)
    {
        printf("ID: %d\n", atual->id);
        contador++;
        atual = atual->prox;
    }
    printf("Quantidade de pratos: %d\n", contador);
}