#include "esfera_utils.h"
#include <math.h>
#include <stdio.h>

float calcula_volume (float R){
    float volume;
    volume = (4.0/3.0*PI*R*R*R);

    return volume;
}

float calcula_area (float R){
    float area;
    area = (4*PI*R*R);

    return area;
}