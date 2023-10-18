#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menu.h"
#include "mesa.h"
#include "fila.h"
#include "pilha_pratos.h"
#include "grupo.h"




Fila* cria_fila(){
    Fila* f;
    f = (Fila*)malloc(sizeof(Fila));

    f->ini = NULL;
    f->fim = NULL;
    return f;
}

void insere_fila(Fila* f, Grupo gp){
    Lista* l;
    l = (Lista*)malloc(sizeof(Lista));
    l->grupo = gp;
    l->prox = NULL;
    if (f->fim == NULL)
        f->ini = l;
    else
        f->fim->prox = l;
    f->fim = l;
}

void grupo_espera_fila(Fila* f, Grupo gp){
    if (f->ini == NULL)
        gp.senha = 1;
    else
        gp.senha = f->fim->grupo.senha + 1;
    insere_fila(f,gp);
}