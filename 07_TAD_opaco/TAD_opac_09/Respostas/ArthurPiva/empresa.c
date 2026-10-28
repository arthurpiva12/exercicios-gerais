#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"
#include "empresa.h"

struct empresa{
    int id;
    tFuncionario** funcionario;
    int qtdFuncionarios;
};

tEmpresa* CriaEmpresa(){
    tEmpresa* empresa = malloc(sizeof(tEmpresa));

    if(empresa == NULL){
        exit(1);
    }

    //incializando as variaveis
    empresa->id = -1;
    empresa->qtdFuncionarios = -1;
    empresa->funcionario = malloc(sizeof(tFuncionario*));

    if(empresa->funcionario == NULL){
        exit(1);
    }

    return empresa;
}

void LeEmpresa(tEmpresa* empresa){
    int qtd;
    scanf("%d %d\n", &empresa->id, &qtd);
    empresa->qtdFuncionarios = 0;

    if(empresa->funcionario == NULL){
        exit(1);
    }

    for(int i = 0; i < qtd; ++i){
        tFuncionario *f = CriaFuncionario();
        LeFuncionario(f);

        ContrataFuncionarioEmpresa(empresa,f);
    }

}

void ApagaEmpresa(tEmpresa* empresa){
    for(int i=0; i<empresa->qtdFuncionarios; i++){
        ApagaFuncionario(empresa->funcionario[i]);
    }

    free(empresa->funcionario);
    free(empresa);
}

void ContrataFuncionarioEmpresa(tEmpresa* empresa, tFuncionario* funcionario){
    //verificacao se ja tem algum funcionario com o mesmo ID
    int identidade = GetIdFuncionario(funcionario);
    int valeu = 1;

    for(int i=0; i<empresa->qtdFuncionarios; i++){
        int comparado = GetIdFuncionario(empresa->funcionario[i]);

        if(identidade == comparado){
            printf("A empresa %d ja possui um funcionario com o id %d\n", empresa->id, identidade);
            ApagaFuncionario(funcionario);
            valeu = 0;
            break;
        }
    }

    if(valeu){
        empresa->funcionario = realloc(empresa->funcionario, (empresa->qtdFuncionarios+1)*sizeof(tFuncionario*));
        empresa->funcionario[empresa->qtdFuncionarios] = funcionario;
        empresa->qtdFuncionarios++;
    }
    
}

void ImprimeEmpresa(tEmpresa *empresa){
    printf("Empresa %d:\n", empresa->id);

    for(int i=0; i<empresa->qtdFuncionarios; i++){
        ImprimeFuncionario(empresa->funcionario[i]);
    }
    printf("\n");
}