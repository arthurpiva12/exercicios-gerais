#include "esfera_utils.h"
#include <stdio.h>

int main(){
    float R, volume, area;
    scanf("%f", &R);

    area = calcula_area(R);
    volume = calcula_volume(R);

    printf("Area: %.2f\n", area);
    printf("Volume: %.2f\n", volume);

    return 0;
}