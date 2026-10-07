#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

int Soma(int a, int b){
    return a + b;
}

int Multiplica(int a, int b){
    return a * b;
}

int main(){
    int qtd, soma=0, mult=1;
    Vetor vet;
    LeVetor(&vet);

    soma = AplicarOperacaoVetor(&vet, Soma);
    mult = AplicarOperacaoVetor(&vet, Multiplica);

    printf("Soma: %d\n", soma);
    printf("Produto: %d\n", mult);

    return 0;
}