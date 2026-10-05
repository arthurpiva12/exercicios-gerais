#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pessoa.h"

tPessoa CriaPessoa(){
    tPessoa pessoa;
    pessoa.nome[0] = '\0';
    pessoa.pai = NULL;
    pessoa.mae = NULL;

    return pessoa;
}

void LePessoa(tPessoa *pessoa){
    scanf(" %[^\n]", pessoa->nome);
}

int VerificaSeTemPaisPessoa(tPessoa *pessoa){
    if(pessoa->pai != NULL){
        return 1;
    }
    else if(pessoa->mae != NULL){
        return 1;
    }

    return 0;
}

void ImprimePessoa(tPessoa *pessoa){
    if(VerificaSeTemPaisPessoa(pessoa)){

        if(pessoa->pai != NULL){
            if(pessoa->mae != NULL){
                printf("NOME COMPLETO: %s\n", pessoa->nome);
                printf("PAI: %s\n", pessoa->pai->nome);
                printf("MAE: %s\n", pessoa->mae->nome);

            }

            else{
                printf("NOME COMPLETO: %s\n", pessoa->nome);
                printf("PAI: %s\n", pessoa->pai->nome);
                printf("MAE: NAO INFORMADO\n");
            }

        }

        else{
            printf("NOME COMPLETO: %s\n", pessoa->nome);
            printf("PAI: NAO INFORMADO\n");
            printf("MAE: %s\n", pessoa->mae->nome);
        }
    }

    else{
        printf("NOME COMPLETO: %s\n", pessoa->nome);
        printf("PAI: NAO INFORMADO\n");
        printf("MAE: NAO INFORMADO\n");
    }
    printf("\n");
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas){
    int idM, idP, idF, num;
    scanf("%d", &num);
    int vet[num];

    for(int i=0; i<num; i++){
        scanf(" mae: %d, pai: %d, filho: %d", &idM, &idP, &idF);

        if(idM >= 0){
            pessoas[idF].mae = &pessoas[idM];
        }
        if(idP >=0){
            pessoas[idF].pai = &pessoas[idP];
        }
        vet[i] = idF;
    }

    for(int j=0; j<num; j++){
        int maior=-1, menor=100000, aux=0, pont=0;

        for(int k=j+1; k<num; k++){
            if(vet[k] < vet[j]){
                if(vet[k] < menor){
                    menor = vet[k];
                    pont = k;
                }
            }
        }

        if(menor == 100000){
            continue;
        }
        else{
            aux = vet[j];
            vet[j] = menor;
            vet[pont] = aux;
        }
    }

    for(int i=0; i<num; i++){
        int p = vet[i];
        ImprimePessoa(&pessoas[p]);
    }
   
}