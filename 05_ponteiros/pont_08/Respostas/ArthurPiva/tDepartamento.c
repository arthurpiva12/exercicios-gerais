#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tDepartamento.h"

tDepartamento CriaDepartamento( char *curso1, char *curso2, char *curso3, char *nome, int m1, int m2, int m3, char *diretor ){
    tDepartamento depto;
    strcpy(depto.curso1, curso1);
    strcpy(depto.curso2, curso2);
    strcpy(depto.curso3, curso3);
    strcpy(depto.nome, nome);
    strcpy(depto.diretor, diretor);

    depto.m1 = m1;
    depto.m2 = m2;
    depto.m3 = m3;

    return depto;
}

void ImprimeAtributosDepartamento(tDepartamento depto){
    printf("\n");
    float media = (depto.m1 + depto.m2 + depto.m3)/3.0;

    printf("Departamento: %s\n", depto.nome);
    printf("   Diretor: %s\n", depto.diretor);

    printf("   1o curso: %s\n", depto.curso1);
    printf("   Media do 1o curso: %d\n", depto.m1);

    printf("   2o curso: %s\n", depto.curso2);
    printf("   Media do 2o curso: %d\n", depto.m2);

    printf("   3o curso: %s\n", depto.curso3);
    printf("   Media do 3o curso: %d\n", depto.m3);

    printf("   Media dos cursos: %.2f\n", media);
}

void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos){


}
