#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

void LerProduto(TProduto *produto1){
    printf("\nDigite o nome do Produto: ");
    fflush(stdin);
    fgets(produto1->nome,TAM,stdin);
    printf("Digite o codigo do Produto: ");
    fflush(stdin);
    scanf("%d",&produto1->codigo);
    printf("Digite a descricao do produto: ");
    fflush(stdin);
    fgets(produto1->descricao,TAM,stdin);
    printf("Digite a Data de Fabricacao: \nDia: ");
    fflush(stdin);
    scanf("%d",&produto1->data_fabricacao.dia);
    printf("Mes: ");
    fflush(stdin);
    scanf("%d",&produto1->data_fabricacao.mes);
    printf("Ano: ");
    fflush(stdin);
    scanf("%d",&produto1->data_fabricacao.ano);
    printf("Digite o lote do produto: ");
    fflush(stdin);
    fgets(produto1->lote,TAM,stdin);
    printf("Digite o preco do produto: ");
    fflush(stdin);
    scanf("%f",&produto1->preco);
    printf("Digite a quantidade do produto: ");
    fflush(stdin);
    scanf("%d",&produto1->quantidade);
}

void ImprimirProduto(TProduto produto1){
    printf("\nNome do Produto: %s",produto1.nome);
    printf("Codigo: %d\n",produto1.codigo);
    printf("Descricao: %s",produto1.descricao);
    printf("Data de Fabricacao: %d/%d/%d\n",produto1.data_fabricacao.dia,produto1.data_fabricacao.mes,produto1.data_fabricacao.ano);
    printf("Lote: %s",produto1.lote);
    printf("Preco: %.2f\n",produto1.preco);
    printf("Quantidade: %d\n",produto1.quantidade);
}

void IniciarModuloProduto(TModuloProduto *modulo){
    modulo->indice=0;
}

void InserirProduto(TModuloProduto *modulo,TProduto produto){
    if(modulo->indice<TAM){
        modulo->vetor[modulo->indice]=produto;
        modulo->indice++;
        printf("\nProduto Cadastrado com Sucesso!\n");
    }else{
        printf("\nNão é possível cadastrar!\n");
    }
}

int PesquisarProduto(TModuloProduto modulo,TProduto produto1){
    int i;
    for(i=0;i<modulo.indice;i++){
        if(modulo.vetor[i].codigo==produto1.codigo){
            return i;
        }
    }
    return -1;
}

void ImprimirTodosProdutos(TModuloProduto modulo){
    int i;
    for(i=0;i<modulo.indice;i++){
        ImprimirProduto(modulo.vetor[i]);
    }
}

void AlterarProduto(TModuloProduto *modulo,TProduto produto1){
    int i = PesquisarProduto(*modulo,produto1);
    if(i!=-1){
        LerProduto(&modulo->vetor[i]);
        printf("\nProduto cadastrado com sucesso!\n");
    }else{
        printf("\nProduto nao encontrado!\n");
    }
}

void ExcluirProduto(TModuloProduto *modulo,TProduto produto1){
    int i = PesquisarProduto(*modulo,produto1);
    int j;
    if(i!=-1){
        for(j=i;j<modulo->indice;j++){
            modulo->vetor[j]=modulo->vetor[j+1];
        }
        modulo->indice--;
    }else{
        printf("\nImpossivel excluir! Produto nao encontrado!\n");
    }
}


