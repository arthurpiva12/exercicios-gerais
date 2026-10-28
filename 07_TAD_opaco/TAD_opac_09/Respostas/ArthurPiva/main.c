#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"
#include "empresa.h"

int main(){
    int qtdEmpresa;
    scanf("%d", &qtdEmpresa);
    tEmpresa* empresa[qtdEmpresa];

    for(int i=0; i<qtdEmpresa; i++){
        empresa[i] = CriaEmpresa();
        LeEmpresa(empresa[i]);
    }

    for(int i=0; i<qtdEmpresa; i++){
        ImprimeEmpresa(empresa[i]);
    }

    for(int i=0; i<qtdEmpresa; i++){
        ApagaEmpresa(empresa[i]);
    }


    return 0;
}