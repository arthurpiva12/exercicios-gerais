#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int main(){
    int qtdAlunos = 0;
    scanf("%d", &qtdAlunos);
    tAluno* aluno[qtdAlunos];

    //criacao e leitura
    for(int i=0; i<qtdAlunos; i++){
        aluno[i] = CriaAluno();
        LeAluno(aluno[i]);
    }  

    tAluno* aux;

    //ordenacao
    for(int i=0; i<qtdAlunos; i++){

        for(int j=i+1; j<qtdAlunos; j++){
            if(ComparaMatricula(aluno[i], aluno[j]) == 1){
                aux = aluno[i];
                aluno[i] = aluno[j];
                aluno[j] = aux;
            }
        }
    }

    // verifica se passou e impressao
    for(int i=0; i<qtdAlunos; i++){
        if(VerificaAprovacao(aluno[i])){
            ImprimeAluno(aluno[i]);
        }
    }

    for(int i=0; i<qtdAlunos; i++){
        ApagaAluno(aluno[i]);
    }

    return 0;
}