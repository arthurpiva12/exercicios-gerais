#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"
#include "empresa.h"

struct funcionario{
    int id;
    float salario;
};

tFuncionario* CriaFuncionario(){
    tFuncionario* funcionario = malloc(sizeof(tFuncionario));

    if(funcionario == NULL){
        exit(1);
    }

    //inicializando as variaveis
    funcionario->id = -1;
    funcionario->salario = -1;

    return funcionario;
}

void ApagaFuncionario(tFuncionario* funcionario){
    free(funcionario);
}

void LeFuncionario(tFuncionario* funcionario){
    scanf("%d %f", &funcionario->id, &funcionario->salario);
}

int GetIdFuncionario(tFuncionario* funcionario){
    return funcionario->id;
}

void ImprimeFuncionario(tFuncionario* funcionario){
    printf("- Funcionario %d: RS %.2f\n", funcionario->id, funcionario->salario);
}