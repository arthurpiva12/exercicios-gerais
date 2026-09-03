#include "matrix_utils.h"
#include <stdio.h>


void ImprimeOpcoes(){
    printf("1 - Somar matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Multiplicar matrizes\n");
    printf("4 - Multiplicacao de uma matriz por escalar\n");
    printf("5 - Transposta de uma matriz\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida:\n");
}


int main(){
    int rows1, cols1, rows2, cols2;
    int matrix1[rows1][cols1], matrix2[rows2][cols2];

    matrix_read(rows1, cols1, matrix1[rows1][cols1]);
    matrix_read(rows2, cols2, matrix2[rows2][cols2]);

    int opcao = 0;

    while(opcao != 6){
        int possibilidade = 2;
        scanf("%d", &opcao);
        ImprimeOpcoes();

        if(opcao == 1){
            possibilidade = possible_matrix_sum(rows1, cols1, rows2, cols2);
            if(possibilidade == 1){
                int result[rows1][cols1];
                matrix_add(rows1, cols1, matrix1[rows1][cols1], rows2, cols2, matrix2[rows2][cols2], result[rows1][cols1]);
                matrix_print(rows1, cols1, result[rows1][cols1]);
            }
        }

        if(opcao == 2){
            possibilidade = possible_matrix_sub(rows1, cols1, rows2, cols2);
            if(possibilidade == 1){
                int result[rows1][cols1];
                matrix_sub(rows1, cols1, matrix1[rows1][cols1], rows2, cols2, matrix2[rows2][cols2], result[rows1][cols1]);
            }
        }
    }

    return 0;
}   