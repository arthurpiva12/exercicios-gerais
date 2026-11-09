#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tadgen.h"

int main(){
    int qtd;
    Type tipo;
    scanf("%d %d", &tipo, &qtd);
    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos: ");

    tGeneric* generico = CriaGenerico(tipo, qtd);
    LeGenerico(generico);
    ImprimeGenerico(generico);
    DestroiGenerico(generico);

    return 0;
}