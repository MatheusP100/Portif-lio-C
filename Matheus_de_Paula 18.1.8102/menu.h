#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "vendas.h"

void MSG_MENU();
void MSG_SUBMENU(int numero_modulo);
void SubMenuModulo1(TModuloProduto *modulo,TProduto produto);
void SubMenuModulo2(TModuloCliente *modulo,TCliente cliente);

#endif // MENU_H_INCLUDED
