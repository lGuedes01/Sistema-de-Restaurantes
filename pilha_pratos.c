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
    return nova_pilha;
}

void push_novo_prato(Pilha *pilha)
{
    Pratos *novo_prato = (Pratos *)malloc(sizeof(Pratos));
    novo_prato->usando = false;
    novo_prato->id = pilha->prim ? pilha->prim->id + 1 : 1;
    novo_prato->prox = pilha->prim;
    pilha->prim = novo_prato;
}

void push_prato_existente(Pilha *pilha, Pratos *novo_prato)
{
    novo_prato->usando = false;
    novo_prato->prox = pilha->prim;
    pilha->prim = novo_prato;
}

Pratos *pop(Pilha *pilha)
{
    if (pilha->prim == NULL)
    {
        printf("A pilha de pratos está vazia.\n");
        return NULL;
    }
    Pratos *prato_removido = pilha->prim;
    pilha->prim = pilha->prim->prox;
    return prato_removido;
}

Listapratos *insere_na_mesa(Pratos *prato, Listapratos *lista_pratos)
{
    Listapratos *prato_novo = (Listapratos *)malloc(sizeof(Listapratos));

    if (prato_novo == NULL)
    {
        printf("Erro ao alocar memória para o novo prato.\n");
        exit(1); 
    }

    prato_novo->prato = prato;

    prato_novo->prox = lista_pratos;

    return prato_novo;
}

int tam_pilha(Pilha *pilha_pratos){
    int count = 0;
    for (Pratos* p = pilha_pratos->prim; p  != NULL; p = p->prox)
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
                if(tam_pilha(pilha_pratos) < 4)
                {
                    printf("Nao tem a quantidade necessaria de pratos na pilha, reponha os pratos\n");
                    return false;
                }
                else
                {
                    for (int x = 0; x < 4; x++)
                    {
                        Pratos *prato = pop(pilha_pratos);
                        if (prato != NULL)
                        {
                            prato->usando = true;
                            mesas[i][j].pratos_mesa = insere_na_mesa(prato, mesas[i][j].pratos_mesa);
                        }
                    }
                }
            }
        }
    }
    return true;
}

void colocar_pratos(int num_pratos, Pilha *pilha_pratos)
{
    for (int i = 0; i < num_pratos; i++)
    {
        push_novo_prato(pilha_pratos);
    }
}

void repor_pratos(Pilha *pilha_pratos)
{
    int num_pratos = 0;
    printf("Informe o numero de pratos a serem colocados na pilha:");
    scanf("%d", &num_pratos);
    colocar_pratos(num_pratos, pilha_pratos);
}

Pratos *tirar_prato_lista(Listapratos **l)
{
    if (*l == NULL)
    {
        return NULL;
    }

    Listapratos *tirar = *l;  
    Pratos *n = tirar->prato; 

    *l = tirar->prox; 

    free(tirar); 

    return n; 
}

void tirar_pratos(int n_p, Pilha *pilha_pratos, Mesa *mesa)
{
    int pratos_tirar = 0;

    pratos_tirar = MAX_PESSOAS - n_p;

    Pratos *aux;
    for (int i = 0; i < pratos_tirar; i++)
    {
        aux = tirar_prato_lista(&(mesa->pratos_mesa));
        push_prato_existente(pilha_pratos, aux);
    }
}

void imprimir_pilha(Pilha *pilha)
{
    Pratos *atual = pilha->prim;
    int contador = 0;
    if (atual == NULL)
    {
        printf("A pilha de pratos está vazia.\n");
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