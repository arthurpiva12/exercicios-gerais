#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"

int main(){
    int qtdAlunos;
    scanf("%d", &qtdAlunos);
    tAluno* aluno[qtdAlunos];

    //criacao e leitrua
    for(int i=0; i<qtdAlunos; i++){
        aluno[i] = CriaAluno();
        LeAluno(aluno[i]);
    }

    //ordenar os alunos por matricula
    tAluno* aux;

    for(int i=0; i<qtdAlunos; i++){

        for(int j=i+1; j<qtdAlunos; j++){
            int resultado = ComparaMatricula(aluno[i], aluno[j]);
            if(resultado == 1){
                aux = aluno[i];
                aluno[i] = aluno[j];
                aluno[j] = aux;
            }
        }
    }

    //verifica quem passou e imprime
    for(int i=0; i<qtdAlunos; i++){
        if(VerificaAprovacao(aluno[i])){
            ImprimeAluno(aluno[i]);
        }
    }

    //libera memoria
    for(int i=0; i<qtdAlunos; i++){
        ApagaAluno(aluno[i]);
    }

    return 0;
}