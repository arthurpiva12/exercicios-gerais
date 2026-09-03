#include "matrix_utils.h"
#include <stdio.h>

void matrix_read(int rows, int cols, int matrix[rows][cols]){
    int i=0, j=0;
    scanf("%d %d", &rows, &cols);

    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
            scanf("%d", matrix[i][j]);
        }
    }

    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
            scanf("%d", matrix[i][j]);
        }
    }

    return matrix[rows][cols];
}

void matrix_print(int rows, int cols, int matrix[rows][cols]){
    int i=0, j=0;

    for(i=0; i<rows; i++){
        printf("|");
        for(j=0; j<cols; j++){
            if(j <= cols-2){
                printf("%d ", matrix[i][j]);
            }
            else{
                printf("%d ", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

int possible_matrix_sum(int rows1, int cols1, int rows2, int cols2){
    if(rows1 == rows2){
        if(cols2 == cols2){
            return 1;
        }
        else{
            return 0;
        }
    }

    else{
        return 0;
    }
}

int possible_matrix_sub(int rows1, int cols1, int rows2, int cols2){
    if(rows1 == rows2){
        if(cols2 == cols2){
            return 1;
        }
        else{
            return 0;
        }
    }

    else{
        return 0;
    }
}

int possible_matrix_multiply(int cols1, int rows2){
    if(cols1 == rows2){
        return 1;
    }
    else{
        return 0;
    }
}

void matrix_add(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]){
    int i=0, j=0;

    for(i=0; i<rows1; i++){
        for(j=0; j<cols1; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrix_sub(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]){
    int i=0, j=0;

    for(i=0; i<rows1; i++){
        for(j=0; j<cols1; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrix_multiply(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]){

}

void transpose_matrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows]){

}

void scalar_multiply(int rows, int cols, int matrix[rows][cols], int scalar){

}

