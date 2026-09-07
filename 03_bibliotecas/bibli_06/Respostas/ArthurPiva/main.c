#include "temperature_conversor.h"
#include <stdio.h>

int main(){
    float temperatura;
    char padrao, proximo;
    scanf("%f ", &temperatura);
    scanf("%c %c", &padrao, &proximo);

    if(padrao == 'c'){
        if(proximo == 'k'){
            temperatura = converte_celsius_para_kelvin(temperatura);
            printf("Temperatura: %.2f", temperatura);
            printf("K");
        }
        else if(proximo == 'f'){
           temperatura = converte_celsius_para_fahrenheit(temperatura);
           printf("Temperatura: %.2f", temperatura);
           printf("Fº");
        }
    }

    else if(padrao == 'f'){
        if(proximo == 'c'){
            temperatura = converte_fahrenheit_para_celsius(temperatura);
            printf("Temperatura: %.2f", temperatura);
            printf("Cº");
        }
        else if(proximo == 'k'){
            temperatura = converte_fahrenheit_para_kelvin(temperatura);
            printf("Temperatura: %.2f", temperatura);
            printf("K");
        }   
    }

    else if(padrao == 'k'){
        if(proximo == 'c'){
            temperatura = converte_kelvin_para_celsius(temperatura);
            printf("Temperatura: %.2f", temperatura);
            printf("Cº");
        }
        else if(proximo == 'f'){
           temperatura = converte_kelvin_para_fahrenheit(temperatura);
           printf("Temperatura: %.2f", temperatura);
           printf("Fº");
        }
    }

    return 0;
}