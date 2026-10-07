#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculadora.h"

float Soma(float a, float b){
    return a + b;
}

float Subtrai(float a, float b){
    return a - b;
}

float Multiplica(float a, float b){
    return a * b;
}

float Divide(float a, float b){
    return a / b;
}

int main(){
    char operacao;
    scanf(" %c", &operacao);

    while(operacao != 'f'){
        float num1, num2, resultado=0;
        scanf("%f %f", &num1, &num2);
        
        

        if(operacao == 'a'){
            resultado = Calcular(num1, num2, Soma);
            printf("%.2f + %.2f = %.2f\n", num1, num2, resultado);
        }
        else if(operacao == 's'){
            resultado = Calcular(num1, num2, Subtrai);
            printf("%.2f - %.2f = %.2f\n", num1, num2, resultado);
        }
        else if(operacao == 'm'){
            resultado = Calcular(num1, num2, Multiplica);
            printf("%.2f x %.2f = %.2f\n", num1, num2, resultado);
        }
        else if(operacao == 'd'){
            resultado = Calcular(num1, num2, Divide);
            printf("%.2f / %.2f = %.2f\n", num1, num2, resultado);
        }
        
        scanf(" %c", &operacao);
    }
    
    return 0;
}