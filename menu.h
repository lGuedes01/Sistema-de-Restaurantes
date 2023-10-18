#ifndef MENU_H
#define MENU_H

#include "mesa.h"
#include "fila.h"
#include "pilha_pratos.h"
#include "grupo.h"

void escolhe(Mesa** mesas, Quantidade qt_mesas,Fila* fila_espera);
void menu(int option, Mesa** mesas, Quantidade qt_mesas,  Fila* fila_espera);



#endif