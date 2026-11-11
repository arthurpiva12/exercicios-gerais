#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "relatorio.h"
#include "aluno.h"

int main(){
    int qtd;
    scanf("%d", &qtd);
    Vector* vetor = VectorConstruct();

    for(int i=0; i<qtd; i++){
        tAluno* aluno = CriaAluno();
        LeAluno(aluno);
        VectorPushBack(vetor, aluno);
    }

    ImprimeRelatorio(vetor);
    VectorDestroy(vetor, DestroiAluno);

    return 0;
}
