#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vendedor.h"
#include "loja.h"

struct Loja{
    int id;
    tVendedor** vendedor;
    int qtdVendedores;
    float aluguel;
    float faturamento;
    float lucro;
};

tLoja* AbreLoja(int id, float aluguel){
    tLoja* loja = malloc(sizeof(tLoja));

    if(loja == NULL){
        return NULL;
    }

    //inicializando as variaveis
    loja->vendedor = NULL;
    loja->qtdVendedores = 0;
    loja->faturamento = 0;
    loja->lucro = 0;
    loja->id = id;
    loja->aluguel = aluguel;

    return loja;
}

void ApagaLoja(tLoja* loja){
    for(int i=0; i<loja->qtdVendedores; i++){
        ApagaVendedor(loja->vendedor[i]);
    }
    free(loja->vendedor);

    free(loja);
}

int VerificaIdLoja(tLoja* loja, int id){
    int identidade = loja->id;

    if(identidade == id){
        return 1;
    }

    return 0;
}

void ContrataVendedor(tLoja* loja, tVendedor* vendedor){
    loja->vendedor = realloc(loja->vendedor, (loja->qtdVendedores +1) * sizeof(tVendedor*));
    loja->vendedor[loja->qtdVendedores] = vendedor;
    loja->qtdVendedores++;
}

void RegistraVenda(tLoja* loja, char* nome, float valor){
    loja->faturamento += valor;

    for(int i=0; i<loja->qtdVendedores; i++){
        if(VerificaNomeVendedor(loja->vendedor[i], nome)){
            ContabilizaVenda(loja->vendedor[i], valor);
            break;
        }
    }

}

void CalculaLucro(tLoja* loja){
    float gastos=0;
    gastos += loja->aluguel;

    for(int i=0; i<loja->qtdVendedores; i++){
        float recebido = GetTotalRecebido(loja->vendedor[i]);
        gastos += recebido;
    }

    loja->lucro = loja->faturamento - gastos;
}

void ImprimeRelatorioLoja(tLoja* loja){
    printf("Loja %d: Lucro total: R$ %.2f\n", loja->id, loja->lucro);
    for(int i=0; i<loja->qtdVendedores; i++){
        ImprimeRelatorioVendedor(loja->vendedor[i]);
    }
}