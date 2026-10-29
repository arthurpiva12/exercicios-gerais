#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vendedor.h"
#include "loja.h"

int main(){
    int qtdLojas=0, cont=0;
    scanf("%d", &qtdLojas);
    tLoja* loja[qtdLojas];

    int opcao;
    scanf("%d", &opcao);

    while(opcao != 0){
        if(opcao == 1){
            int id;
            float aluguel;

            scanf("%d %f", &id, &aluguel);
            loja[cont] = AbreLoja(id, aluguel);

            cont++;
        }

        else if(opcao == 2){
            char nome[100];
            float salario;
            float comissao;
            int id;

            scanf(" %[^ ]", nome);
            scanf("%f %f %d", &salario, &comissao, &id);
            
            for(int i=0; i<qtdLojas; i++){
                if(VerificaIdLoja(loja[i], id)){
                    tVendedor* vendedor = RegistraVendedor(nome, salario, comissao);
                    ContrataVendedor(loja[i], vendedor);
                    break;
                }
            }
        }

        else if(opcao == 3){
            int id;
            scanf("%d", &id);

            for(int i=0; i<qtdLojas; i++){
                if(VerificaIdLoja(loja[i], id)){
                    char nome[100];
                    scanf(" %[^ ]", nome);
                    float valor;
                    scanf("%f", &valor);
                    RegistraVenda(loja[i], nome, valor);
                }
            }
        }

        else if(opcao == 4){
            for(int i=0; i<qtdLojas; i++){
                CalculaLucro(loja[i]);
                ImprimeRelatorioLoja(loja[i]);
            }
        }

        scanf("%d", &opcao);
    }

    for(int i=0; i<qtdLojas; i++){
        ApagaLoja(loja[i]);
    }


    return 0;
}