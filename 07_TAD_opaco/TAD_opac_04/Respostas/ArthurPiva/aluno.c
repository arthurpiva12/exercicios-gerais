#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"

struct Aluno{
    char* nome;
    int matricula;
    int n1;
    int n2;
    int n3;
};

tAluno* CriaAluno(){
    tAluno* aluno = malloc(sizeof(struct Aluno));

    if(aluno == NULL){
        return NULL;
    }

    //atribuicoes
    aluno->nome = NULL;
    aluno->matricula = 0;
    aluno->n1 = 0;
    aluno->n2 = 0;
    aluno->n3 = 0;

    return aluno;
}

void ApagaAluno(tAluno *aluno){
    free(aluno->nome);
    free(aluno);
}

void LeAluno(tAluno *aluno){
    aluno->nome = malloc(20 * sizeof(char));
    scanf(" %[^\n]", aluno->nome);

    scanf("%d", &aluno->matricula);
    scanf("%d %d %d", &aluno->n1, &aluno->n2, &aluno->n3);
}

int ComparaMatricula(tAluno* aluno1, tAluno* aluno2){
    if(aluno1->matricula > aluno2->matricula){
        return 1;
    }
    if(aluno1->matricula < aluno2->matricula){
        return -1;
    }

    return 0;
}

int CalculaMediaAluno(tAluno* aluno){
    int media = (aluno->n1 + aluno->n2 + aluno->n3)/3;

    return media;
}

int VerificaAprovacao(tAluno* aluno){
    int media = CalculaMediaAluno(aluno);

    if(media>=7){
        return 1;
    }

    return 0;
}

void ImprimeAluno(tAluno* aluno){
    printf("%s\n", aluno->nome);
}