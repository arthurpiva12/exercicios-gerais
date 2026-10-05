#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pessoa.h"

int main(){
    int qtd;
    scanf("%d", &qtd);
    tPessoa pessoa[qtd];

    for(int i=0; i<qtd; i++){
        pessoa[i] = CriaPessoa();
        LePessoa(&pessoa[i]);
    }

    AssociaFamiliasGruposPessoas(pessoa);

    //for(int j=0; j<qtd; j++){
        //ImprimePessoa(&pessoa[j]);
    //}


    return 0;
}