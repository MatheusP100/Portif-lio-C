#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main(int argc, char const *argv[]){
    TProduto produto1;
    TCliente cliente1;
    TVendas vendas1;
    TModuloProduto modulo1;
    TModuloCliente modulo2;
    TModuloVendas modulo3;
    IniciarModuloProduto(&modulo1);
    IniciarModuloCliente(&modulo2);
    IniciarModuloVenda(&modulo3);
    int opcao=0;
    do{
        system("cls");
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d",&opcao);

        switch(opcao){
            case 1:
                SubMenuModulo1(&modulo1,produto1);
                break;
            case 2:
                SubMenuModulo2(&modulo2,cliente1);
                break;
            case 3:
                SubMenuModulo3(&modulo3,vendas1,&modulo1,modulo2);
                break;
            case 4:
                printf("\n>>>> MSG: Saindo do Programa...!!! <<<<\n\n");
                system("PAUSE");
                break;
            default:
                printf(">>>> MSG: Digite uma opcao valida...!!! <<<<\n");
                system("PAUSE");
        }
    }while(opcao!=4);

    return 0;
}




