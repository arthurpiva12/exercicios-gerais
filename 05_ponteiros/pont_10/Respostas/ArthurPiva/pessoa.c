#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"

tPessoa CriaPessoa(){
    tPessoa pessoa;
    pessoa.nome[0] = '\0';
    pessoa.pai = NULL;
    pessoa.mae = NULL;
    pessoa.irmao = NULL;

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
    int i=0;
    
    if(VerificaSeTemPaisPessoa(pessoa)){
        printf("NOME COMPLETO: %s\n", pessoa->nome);

        if(pessoa->pai != NULL){
            printf("PAI: %s\n", pessoa->pai->nome);
        }
        else{
            printf("PAI: NAO INFORMADO\n");
        }

        if(pessoa->mae != NULL){
            printf("MAE: %s\n", pessoa->mae->nome);
        }
        else{
            printf("MAE: NAO INFORMADO\n");
        }

        if(pessoa->irmao != NULL){
            printf("IRMAO: %s\n", pessoa->irmao->nome);
        }
        else{
            printf("IRMAO: NAO INFORMADO\n");
        }

        printf("\n");
    }

}

int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2){
    if(VerificaSeTemPaisPessoa(pessoa1) && VerificaSeTemPaisPessoa(pessoa2)){
        if(pessoa1->mae == pessoa2->mae){
            return 1;
        }
        else if(pessoa1->pai == pessoa2->pai){
            return 1;
        }
        return 0;
    }

    return 0;
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas){
    int idM, idP, idF, num, i=0;
    scanf("%d", &num);
    int vet[num];

    //Relacionando pai e mae
    for(i=0; i<num; i++){
        scanf(" mae: %d, pai: %d, filho: %d", &idM, &idP, &idF);

        if(idM >= 0){
            pessoas[idF].mae = &pessoas[idM];
        }
        if(idP >=0){
            pessoas[idF].pai = &pessoas[idP];
        }
        vet[i] = idF;
    }

    //Checando se tem irmao
    for(i=0; i+1<numPessoas; i++){
        for(int j=i+1; j<numPessoas; j++){
            if(VerificaIrmaoPessoa(&pessoas[i], &pessoas[j])){
                pessoas[i].irmao = &pessoas[j];
                pessoas[j].irmao = &pessoas[i];
            }
        }   
    }

    //Ordenando ordem de impressao
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

}