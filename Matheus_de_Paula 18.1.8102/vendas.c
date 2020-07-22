#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vendas.h"

void LerVendas(TVendas *vendas1){
    printf("\nDigite o codigo do produto: ");
    fflush(stdin);
    scanf("%d",&vendas1->codigo);
    printf("\nDigite o ID do Comprador: ");
    fflush(stdin);
    fgets(vendas1->id,TAM,stdin);
    printf("\nDigite a quantidade desejada: ");
    fflush(stdin);
    scanf("%d",&vendas1->quantidade);
    printf("Digite a Data da Venda: \nDia: ");
    fflush(stdin);
    scanf("%d",&vendas1->data_venda.dia);
    printf("Mes: ");
    fflush(stdin);
    scanf("%d",&vendas1->data_venda.mes);
    printf("Ano: ");
    fflush(stdin);
    scanf("%d",&vendas1->data_venda.ano);
    printf("Digite o tipo de Pagamento: 0 para pagamento a vista e 1 para prazo: ");
    fflush(stdin);
    scanf("%d",&vendas1->pagamento);
    if(vendas1->pagamento==1){
        printf("Digite a data do Pagamento: \nDia: ");
        fflush(stdin);
        scanf("%d",&vendas1->data_pagamento.dia);
        printf("Mes: ");
        fflush(stdin);
        scanf("%d",&vendas1->data_pagamento.mes);
        printf("Ano: ");
        fflush(stdin);
        scanf("%d",&vendas1->data_pagamento.ano);
    }

}

void ImprimirVendas(TVendas vendas1){
    printf("\nID do comprador: %s",vendas1.id);
    printf("Codigo do produto: %d\n",vendas1.codigo);
    printf("Data da Venda: %d/%d/%d\n",vendas1.data_venda.dia,vendas1.data_venda.mes,vendas1.data_venda.ano);
    printf("Quantidade vendida: %d",vendas1.quantidade);
    printf("\nValor total da venda: %d\n",vendas1.valor_total_venda);
    if(vendas1.pagamento==1){
        printf("Data do Pagamento: %d/%d/%d\n",vendas1.data_pagamento.dia,vendas1.data_pagamento.mes,vendas1.data_pagamento.ano);
    }
}

void IniciarModuloVenda(TModuloVendas *modulo){
    modulo->indice=0;
}

void InserirVenda(TModuloVendas *modulo3,TVendas venda,TModuloProduto *modulo1,TModuloCliente modulo2){
    int i,j;
    TProduto produto;
    TCliente cliente;
    produto.codigo=venda.codigo;
    i=PesquisarProduto(*modulo1,produto);
    strcpy(cliente.id,venda.id);
    j=PesquisarCliente(modulo2,cliente);
    if(i==-1){
        printf("\nProduto nao encontrado!\n");
    }else if(j==-1){
         printf("\nCliente nao encontrado!\n");
    }else if(modulo1->vetor[i].quantidade<venda.quantidade){
        printf("\nImpossivel Cadastrar Quantidade insuficiente!");
    }else if(modulo3->indice>=TAM){
        printf("Impossivel Cadastrar lista cheia!");
    }else{
        venda.valor_total_venda=modulo1->vetor[i].preco*(float)(venda.quantidade);
        modulo3->vetor[modulo3->indice]=venda;
        modulo3->indice++;
        modulo1->vetor[i].quantidade-=venda.quantidade;
        printf("\nVenda Cadastrada com Sucesso!\n");
    }
}

int PesquisarVenda(TModuloVendas modulo,TVendas vendas){
    int i;
    for(i=0;i<modulo.indice;i++){
        if((modulo.vetor[i].codigo==vendas.codigo)&&(strcmp(modulo.vetor[i].id,vendas.id)==0)&&(modulo.vetor[i].data_venda.ano==vendas.data_venda.ano)&&(modulo.vetor[i].data_venda.mes==vendas.data_venda.mes)&&(modulo.vetor[i].data_venda.dia==vendas.data_venda.dia)){
            return i;
        }
    }
    return -1;
}

void ImprimirTodasVendas(TModuloVendas modulo){
    int i;
    for(i=0;i<modulo.indice;i++){
        ImprimirVendas(modulo.vetor[i]);
    }
}

void AlterarVenda(TModuloVendas *modulo,TVendas venda1){
    int i = PesquisarVenda(*modulo,venda1);
        LerVendas(&(*modulo).vetor[i]);
}

void ExcluirVenda(TModuloVendas *modulo,TVendas venda1){
    int j;
    int i = PesquisarVenda(*modulo,venda1);
    for(j=i;j<modulo->indice;j++){
        modulo->vetor[j]=modulo->vetor[j+1];
    }
    modulo->indice--;
}


