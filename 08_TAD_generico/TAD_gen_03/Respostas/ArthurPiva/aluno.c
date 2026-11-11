#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"

struct Aluno{
    char nome[50];
    float nota;
    char genero;
};

tAluno *CriaAluno(){
    tAluno* aluno = malloc(sizeof(tAluno));

    if(aluno == NULL){
        return NULL;
    }

    //inicializando as variaveis
    aluno->nota = 0.0;

    return aluno;
}

void DestroiAluno(data_type aluno){
    free(aluno);
}

void LeAluno(tAluno *aluno){
    scanf("%[^;]", &aluno->nome);
    scanf(";%c", &aluno->genero);
    scanf(";%f", &aluno->nota);
}

char GetGeneroAluno(tAluno *aluno){
    return aluno->genero;
}

float GetNotaAluno(tAluno *aluno){
    return aluno->nota;
}