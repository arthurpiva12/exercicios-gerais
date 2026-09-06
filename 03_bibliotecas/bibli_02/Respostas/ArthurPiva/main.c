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

    scanf("%d %d", &rows1, &cols1);
    int matrix1[rows1][cols1];
    matrix_read(rows1, cols1, matrix1);

    scanf("%d %d", &rows2, &cols2);
    int matrix2[rows2][cols2];
    matrix_read(rows2, cols2, matrix2);

    int opcao = 0;

    while(1){
        int possibilidade = 2;
        ImprimeOpcoes();
        scanf("%d", &opcao);

        if(opcao == 6){
            break;
        }

        else if(opcao == 1){
            possibilidade = possible_matrix_sum(rows1, cols1, rows2, cols2);
            if(possibilidade == 1){
                int result[rows1][cols1];
                matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols1, result);
            }
            else{
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        }

        else if(opcao == 2){
            possibilidade = possible_matrix_sub(rows1, cols1, rows2, cols2);
            if(possibilidade == 1){
                int result[rows1][cols1];
                matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols1, result);
            }
            else{
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        }

        else if(opcao == 3){
            possibilidade = possible_matrix_multiply(cols1, rows2);
            if(possibilidade == 1){
                int result[rows1][cols2];
                matrix_multiply(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols2, result);
            }
            else{
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
            }
        }

        else if(opcao == 4){
            int scalar, matrizDesejada;
            scanf("%d %d", &scalar, &matrizDesejada);

            if(matrizDesejada == 1){
                scalar_multiply(rows1, cols1, matrix1, scalar);
                matrix_print(rows1, cols1, matrix1);
            }
            else{
                scalar_multiply(rows2, cols2, matrix2, scalar);
                matrix_print(rows2, cols2, matrix2);
            }
        }

        else if(opcao == 5){
            int result[rows1][cols1];
            int resultado[rows2][cols2];

            transpose_matrix(rows1, cols1, matrix1, result);
            transpose_matrix(rows2, cols2, matrix2, resultado);

            matrix_print(cols1, rows1, result);
            matrix_print(cols2, rows2, resultado);
        }

    }

    return 0;
}   