#include "temperature_conversor.h"
#include <stdio.h>

float converte_celsius_para_kelvin(float temperatura){
    temperatura += 273.15;
    return temperatura;
}

float converte_celsius_para_fahrenheit(float temperatura){
    temperatura = (temperatura*1.8) +32;
    return temperatura;
}

float converte_kelvin_para_celsius(float temperatura){
    temperatura -= 273.15;
    return temperatura;
}

float converte_kelvin_para_fahrenheit(float temperatura){
    temperatura = (temperatura*1.8) - 459.67;
    return temperatura;
}

float converte_fahrenheit_para_celsius(float temperatura){
    temperatura = (temperatura - 32)/1.8;
    return temperatura;
}

float converte_fahrenheit_para_kelvin(float temperatura){
    temperatura = (temperatura - 32)*5/9 + 273.15;
    return temperatura;
}