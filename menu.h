#ifndef MENU_H
#define MENU_H

#include "mesa.h"
#include "fila.h"
#include "pilha_pratos.h"
#include "grupo.h"

void escolhe(Mesa** mesas, Quantidade qt_mesas,Fila* fila_espera, Pilha *pratos);
void menu(int option, Mesa** mesas, Quantidade qt_mesas,  Fila* fila_espera, Pilha *pilha_pratos);
void menu_impressao(Mesa **mesas, Quantidade qt_mesas, Fila *fila_espera, Pilha *pilha_pratos);


#endif