#include "string_utils.h"
#include <stdio.h>

void imprimeOpcoes(){
    printf("1 - Tamanho da string\n");
    printf("2 - Copiar string\n");
    printf("3 - Converter string para letras maiusculas\n");
    printf("4 - Converter string para letras minusculas\n");
    printf("5 - Imprimir string ao contrario\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida:\n");
}

int main(){
    char string[100];
    scanf("%[^\n]", string);

    while(1){
        int opcao=0;
        imprimeOpcoes();
        scanf("%d", &opcao);

        if(opcao == 6){
            break;
        }

        else if(opcao == 1){
            int tamanho=0;
            tamanho = string_length(string);
            printf("Tamanho da string: %d\n", tamanho);
        }

        else if(opcao == 2){
            char destino[100];
            printf("String copiada: ");
            string_copy(string, destino);
            printf("%s\n", destino);
        }

        else if(opcao == 3){
            printf("String convertida para maiusculas: ");
            string_upper(string);
            printf("%s\n", string);
        }

        else if(opcao == 4){
            printf("String convertida para minusculas: ");
            string_lower(string);
            printf("%s\n", string);
        }

        else if(opcao == 5){
            printf("String invertida: ");
            string_reverse(string);
            printf("%s\n", string);
        }

        printf("\n");
    }
    return 0;
}