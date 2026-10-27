#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "conta.h"
#include "banco.h"

struct Banco{
    tConta** conta;
    int qtdContas;
    int capacidade;
};

tBanco *CriaBanco(){
    tBanco* banco = malloc(sizeof(struct Banco));

    if(banco == NULL){
        exit(1);
    }

    //inicializando as variaveis
    banco->conta = malloc(5 * sizeof(tConta*));
    banco->qtdContas = 0;
    banco->capacidade = 5;

    return banco;
}

void DestroiBanco(tBanco *banco){
    for(int i=0; i<banco->qtdContas; i++){
        DestroiConta(banco->conta[i]);
    }

    free(banco->conta);
    free(banco);
}

void AbreContaBanco(tBanco *banco){
    if(banco->qtdContas >= banco->capacidade){
        int novaCapacidade = banco->capacidade + 5;
        tConta** aux = realloc(banco->conta, novaCapacidade * sizeof(tConta*));

        if(aux == NULL){
            exit(1);
        }

        banco->conta = aux;
        banco->capacidade = novaCapacidade;
    }

    banco->conta[banco->qtdContas] = CriaConta();
    LeConta(banco->conta[banco->qtdContas]);
    banco->qtdContas++;

}

void SaqueContaBanco(tBanco *banco){
    int numConta;
    float valor;

    scanf("%d %f\n", &numConta, &valor);
    
    for(int i=0; i<banco->qtdContas; i++){
        if(VerificaConta(banco->conta[i], numConta)){
            SaqueConta(banco->conta[i], valor);
            break;
        }
    }
}

void DepositoContaBanco(tBanco *banco){
    int numConta;
    float valor;

    scanf("%d %f\n", &numConta, &valor);
    
    for(int i=0; i<banco->qtdContas; i++){
        if(VerificaConta(banco->conta[i], numConta)){
            DepositoConta(banco->conta[i], valor);
            break;
        }
    }
}

void TransferenciaContaBanco(tBanco *banco){
    int origem, destino;
    float valor;
    scanf("%d %d %f\n", &destino, &origem, &valor);

    for(int i=0; i<banco->qtdContas; i++){
        if(VerificaConta(banco->conta[i], destino)){

            for(int j=0; j<banco->qtdContas; j++){
                if(VerificaConta(banco->conta[j], origem)){
                    TransferenciaConta(banco->conta[i], banco->conta[j], valor);
                    break;
                }
            }

            break;
        }
    }
}

void ImprimeRelatorioBanco(tBanco *banco){
    printf("===| Imprimindo Relatorio |===\n");
    for(int i=0; i<banco->qtdContas; i++){
        ImprimeConta(banco->conta[i]);
    }
}