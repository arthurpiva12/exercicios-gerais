#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

tAluno* CriaAluno(){
    tAluno* aluno = malloc(sizeof(tAluno));
    
    if(aluno == NULL){
        printf("NULL\n");
        return NULL;
    }

    //zerando os ponteiros
    aluno->nome = NULL;

    //zerando os atributos
    aluno->n1 = -1;
    aluno->n2 = -1;
    aluno->n3 = -1;
    aluno->matricula = -1;

    return aluno;
}

void ApagaAluno(tAluno *aluno){
    if(aluno == NULL){
        return;
    }

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

    else if(aluno1->matricula == aluno2->matricula){
        return 0;
    }

    return -1;
}

int CalculaMediaAluno(tAluno* aluno){
    int media = (aluno->n1 + aluno->n2 + aluno->n3)/3;

    return media;
}

int VerificaAprovacao(tAluno* aluno){
    int media = CalculaMediaAluno(aluno);

    if(media >= 7){
        return 1;
    }

    return 0;
}

void ImprimeAluno(tAluno* aluno){
    if(VerificaAprovacao(aluno) == 1){
        printf("%s", aluno->nome);
        printf("\n");
    }
}

