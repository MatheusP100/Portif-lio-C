#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void MSG_MENU(){
    printf("\n>>>>>>>>>>>>>>> MENU: <<<<<<<<<<<<<<<\n");
    printf("\n\t1. MODULO 1 - PRODUTO");
    printf("\n\t2. MODULO 2 - CLIENTE");
    printf("\n\t3. MODULO 3 - VENDAS");
    printf("\n\t4. SAIR");
}

void MSG_SUBMENU(int numero_modulo){
    system("cls");
    printf("\n>>>>>>>>>>>>>>> MODULO %d: <<<<<<<<<<<<<<<\n",numero_modulo);
    printf("\n\t1. INSERIR");
    printf("\n\t2. PESQUISAR");
    printf("\n\t3. ALTERAR");
    printf("\n\t4. EXCLUIR");
    printf("\n\t5. IMPRIMIR TODOS");
    printf("\n\t6. SAIR");
}

void SubMenuModulo1(TModuloProduto *modulo,TProduto produto){
    int opcao=0;
    do{
       MSG_SUBMENU(1);
       printf("\n\nDigite uma opcao: ");
       fflush(stdin);
       scanf("%d",&opcao);

       switch(opcao){
           case 1:
               system("cls");
               printf("\n>>>>>>>>>> MSG: Inserindo um produto! <<<<<<<<<<");
               LerProduto(&produto);
               InserirProduto(modulo,produto);
               system("PAUSE");
               break;
           case 2:
               system("cls");
               printf("\n>>>>>>>>>> MSG: Pesquisando um produto! <<<<<<<<<<");
               printf("\nDigite o ID do Produto que deseja pesquisar: ");
               fflush(stdin);
               scanf("%d",&produto.codigo);
               int i =PesquisarProduto(*modulo,produto);
               if(i!=-1){
                printf("\nProduto encontrado!");
                ImprimirProduto(modulo->vetor[i]);
                system("PAUSE");
               }else{
                printf("\nProduto não Encontrado!");
                system("PAUSE");
               }break;
           case 3:
               system("cls");
               printf("\n>>>>>>>>>> MSG: Alterando um produto! <<<<<<<<<<");
               printf("\nDigite o ID do Produto que deseja Alterar: ");
               fflush(stdin);
               scanf("%d",&produto.codigo);
               AlterarProduto(modulo,produto);
               system("PAUSE");
               break;
           case 4:
               system("cls");
               printf("\n>>>>>>>>>> MSG: Excluindo um produto! <<<<<<<<<<");
               printf("\nDigite o ID do Produto que deseja Excluir: ");
               fflush(stdin);
               scanf("%d",&produto.codigo);
               ExcluirProduto(modulo,produto);
               system("PAUSE");
               break;
           case 5:
               system("cls");
               printf("\n>>>>>>>>>> MSG: Imprimindo Todos os produtos! <<<<<<<<<<");
               ImprimirTodosProdutos(*(modulo));
               system("PAUSE");
               break;
           case 6:
               printf("\n>>>>>>>>>> MSG: Saindo do Modulo <<<<<<<<<<\n");
               system("PAUSE");
               break;
           default:
               printf("\n>>>>>>>>>> MSG: Digite uma opcao valida <<<<<<<<<<\n");
               system("PAUSE");
       }
    }while(opcao!=6);
}

void SubMenuModulo2(TModuloCliente *modulo,TCliente cliente){
    int opcao=0;
    do{
       MSG_SUBMENU(2);
       printf("\n\nDigite uma opcao: ");
       fflush(stdin);
       scanf("%d",&opcao);

       switch(opcao){
           case 1:
               system("cls");
               printf("\n>>>>>>>>>> MSG: Inserindo um Cliente! <<<<<<<<<<");
               LerCliente(&cliente);
               InserirCliente(modulo,cliente);
               system("PAUSE");
               break;
           case 2:
               system("cls");
               printf("\n>>>>>>>>>> MSG: Pesquisando um Cliente! <<<<<<<<<<");
               printf("\nDigite o ID do Cliente que deseja pesquisar: ");
               fflush(stdin);
               fgets(cliente.id,TAM,stdin);
               int i =PesquisarCliente(*modulo,cliente);
               if(i!=-1){
                printf("\n>>>>>>>>>> MSG: Cliente encontrado! <<<<<<<<<<");
                ImprimirCliente(modulo->vetor[i]);
                system("PAUSE");
               }else{
                printf("\n>>>>>>>>>> MSG: Cliente não encontrado! <<<<<<<<<<");
                system("PAUSE");
               }break;
           case 3:
               system("cls");
               printf("\n>>>>>>>>>> MSG: Alterando um Cliente! <<<<<<<<<<");
               printf("\nDigite o ID do Cliente que deseja Alterar: ");
               fflush(stdin);
               fgets(cliente.id,TAM,stdin);
               AlterarCliente(modulo,cliente);
               system("PAUSE");
               break;
           case 4:
               system("cls");
               printf("\n>>>>>>>>>> MSG: Excluindo um Cliente! <<<<<<<<<<");
               printf("\nDigite o ID do Cliente que deseja Excluir: ");
               fflush(stdin);
               fgets(cliente.id,TAM,stdin);
               ExcluirCliente(modulo,cliente);
               system("PAUSE");
               break;
           case 5:
               system("cls");
               printf("\n>>>>>>>>>> MSG: Imprimindo Todos os Clientes! <<<<<<<<<<");
               ImprimirTodosClientes(*(modulo));
               system("PAUSE");
               break;
           case 6:
               printf("\n>>>>>>>>>> MSG: Saindo do Modulo <<<<<<<<<<\n");
               system("PAUSE");
               break;
           default:
               printf("\n>>>>>>>>>> MSG: Digite uma opcao valida <<<<<<<<<<\n");
               system("PAUSE");
       }
    }while(opcao!=6);
}

void SubMenuModulo3(TModuloVendas *modulo3,TVendas vendas,TModuloProduto *modulo1,TModuloCliente modulo2){
    int opcao=0;
    do{
       MSG_SUBMENU(3);
       printf("\n\nDigite uma opcao: ");
       fflush(stdin);
       scanf("%d",&opcao);

       switch(opcao){
           case 1:
               system("cls");
               printf("\n>>>>>>>>>> MSG: Inserindo uma venda! <<<<<<<<<<");
               LerVendas(&vendas);
               InserirVenda(modulo3,vendas,modulo1,modulo2);
               system("PAUSE");
               break;
           case 2:
               system("cls");
               printf("\n>>>>>>>>>> MSG: Pesquisando uma Venda! <<<<<<<<<<");
               printf("\nDigite o codigo do produto: ");
               fflush(stdin);
               scanf("%d",&vendas.codigo);
               printf("\nDigite o ID do cliente: ");
               fflush(stdin);
               fgets(vendas.id,TAM,stdin);
               printf("\nDigite a data da venda: ");
               printf("Dia: ");
               fflush(stdin);
               scanf("%d",&vendas.data_venda.dia);
               printf("Mes: ");
               fflush(stdin);
               scanf("%d",&vendas.data_venda.mes);
               printf("Ano: ");
               fflush(stdin);
               scanf("%d",&vendas.data_venda.ano);
               int i =PesquisarVenda(*modulo3,vendas);
               if(i!=-1){
                printf("\n>>>>>>>>>> MSG: Venda encontrada! <<<<<<<<<<\n");
                ImprimirVendas(modulo3->vetor[i]);
                system("PAUSE");
               }else{
                printf("\n>>>>>>>>>> MSG: Venda nao encontrado! <<<<<<<<<<\n");
                system("PAUSE");
               }break;
           case 3:
               system("cls");
               printf("\n>>>>>>>>>> MSG: Alterando um Venda! <<<<<<<<<<");
               printf("\nDigite o codigo do produto: ");
               fflush(stdin);
               scanf("%d",&vendas.codigo);
               printf("\nDigite o ID do cliente: ");
               fflush(stdin);
               printf("\nDigite a data da venda: ");
               printf("\nDia: ");
               fflush(stdin);
               scanf("%d",&vendas.data_venda.dia);
               printf("\nMes: ");
               fflush(stdin);
               scanf("%d",&vendas.data_venda.mes);
               printf("\nAno: ");
               fflush(stdin);
               scanf("%d",&vendas.data_venda.ano);
               printf("\nDigite os novos valores desejados!\n");
               AlterarVenda(modulo3,vendas);
               system("PAUSE");
               break;
           case 4:
               system("cls");
               printf("\n>>>>>>>>>> MSG: Excluindo uma Venda! <<<<<<<<<<");
                printf("\nDigite o codigo do produto: ");
               fflush(stdin);
               scanf("%d",&vendas.codigo);
               printf("\nDigite o ID do cliente: ");
               fflush(stdin);
               printf("\nDigite a data da venda: ");
               printf("\nDia: ");
               fflush(stdin);
               scanf("%d",&vendas.data_venda.dia);
               printf("\nMes: ");
               fflush(stdin);
               scanf("%d",&vendas.data_venda.mes);
               printf("\nAno: ");
               fflush(stdin);
               scanf("%d",&vendas.data_venda.ano);
               ExcluirVenda(modulo3,vendas);
               system("PAUSE");
               break;
           case 5:
               system("cls");
               printf("\n>>>>>>>>>> MSG: Imprimindo Todos os Clientes! <<<<<<<<<<\n");
               ImprimirTodasVendas(*(modulo3));
               system("PAUSE");
               break;
           case 6:
               printf("\n>>>>>>>>>> MSG: Saindo do Modulo <<<<<<<<<<\n");
               system("PAUSE");
               break;
           default:
               printf("\n>>>>>>>>>> MSG: Digite uma opcao valida <<<<<<<<<<\n");
               system("PAUSE");
       }
    }while(opcao!=6);
}



