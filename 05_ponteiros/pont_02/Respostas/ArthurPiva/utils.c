#include "stdio.h"
#include "stdlib.h"
#include "utils.h"

void LeIntervalo(int * m, int * n){
    scanf("%d %d", m, n);
}

int EhPrimo(int n){

    if(n <= 1){
        return 0;
    }

    else{
        int cont=0, aux=n;
        while(aux >= 1){
            if(n % aux == 0){
                cont++;
            }
            aux--;
        }

        if(cont == 2){
            return 1;
        }

        return 0;
    }
}

void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior){
    int aux;
    *menor = 1000000, *maior=0;
    while(m<=n){
        if(EhPrimo(m)){
            aux = m;
            if(aux < *menor){
                *menor = aux;
            }
            if(aux > *maior){
                *maior = aux;
            }
        }
        m++;
    }
}