#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"

int main(){
    int qtd;
    scanf("%d", &qtd);
    tPessoa pessoa[qtd];

    for(int i=0; i<qtd; i++){
        pessoa[i] = CriaPessoa();
        LePessoa(&pessoa[i]);
    }

    AssociaFamiliasGruposPessoas(pessoa, qtd);

    for(int j=0; j<qtd; j++){
        ImprimePessoa(&pessoa[j]);
    }

    return 0;
}
