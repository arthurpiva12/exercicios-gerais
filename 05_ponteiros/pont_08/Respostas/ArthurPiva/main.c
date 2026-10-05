#include <stdio.h>
#include <stdlib.h>
#include "tDepartamento.h"

int main(){
    printf("\n");
    int qtdDepartamentos;
    scanf("%d", &qtdDepartamentos);
    tDepartamento departamento[qtdDepartamentos];

    for(int i=0; i<qtdDepartamentos; i++){
        char curso1[STRING_MAX];
        char curso2[STRING_MAX];
        char curso3[STRING_MAX];
        char diretor[STRING_MAX];
        char nome[STRING_MAX];
        int m1=0, m2=0, m3=0;

        do{
            if(m1<0 || m2<0 || m3<0){
                printf("Digite um departamento com médias válidas\n");
            }
            scanf("%s %s %s %s %s", nome, diretor, curso1, curso2, curso3);
            scanf("%d %d %d", &m1, &m2, &m3);

        }while(m1<0 || m2<0 || m3<0);
        departamento[i] = CriaDepartamento(&curso1, &curso2, &curso3, &nome, m1, m2, m3, &diretor);
    }

    OrdenaDepartamentosPorMedia(departamento, qtdDepartamentos);

    for(int j=0; j<qtdDepartamentos; j++){
        ImprimeAtributosDepartamento(departamento[j]);
    }
    printf("\n");

    return 0;
}