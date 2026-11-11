#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "relatorio.h"
#include "aluno.h"

void ImprimeRelatorio(Vector *alunos){
    int tamanho = VectorSize(alunos);

    //calculando media total
    float mediaTotal = 0.0;

    for(int i=0; i<tamanho; i++){
        tAluno* aluno = (tAluno*) VectorGet(alunos, i);
        float nota = GetNotaAluno(aluno);
        mediaTotal += nota;
    }
    mediaTotal = mediaTotal / tamanho;
    printf("Media das notas: %.2f\n", mediaTotal);

    //calculando porcentagem de aprovados
    int contagem=0;

    for(int i=0; i<tamanho; i++){
        tAluno* aluno = (tAluno*) VectorGet(alunos, i);
        float nota = GetNotaAluno(aluno);

        if(nota>= 6.0){
            contagem++;
        }
    }
    float porcentagemAprovados = (float)contagem/tamanho * 100;
    printf("Porcentagem de alunos aprovados: %.2f%%\n", porcentagemAprovados);


    //calculando porcentagem de cada genero
    printf("Porcentagem de cada genero:\n");

    int homens=0, mulheres=0, outro=0;

    for(int i=0; i<tamanho; i++){
        tAluno* aluno = (tAluno*) VectorGet(alunos, i);
        char genero = GetGeneroAluno(aluno);

        if(genero == 'F'){
            mulheres++;
        }
        else if (genero == 'M'){
            homens++;
        }
        else{
            outro++;
        }
    }

    float porcentagemMulheres = (float)mulheres/tamanho * 100;
    float porcentagemHomens = (float)homens/tamanho * 100;
    float porcentagemOutros = (float)outro/tamanho * 100;

    printf("Masculino: %.2f%%\n", porcentagemHomens);
    printf("Feminino: %.2f%%\n", porcentagemMulheres);
    printf("Outro: %.2f%%\n", porcentagemOutros);
    
}