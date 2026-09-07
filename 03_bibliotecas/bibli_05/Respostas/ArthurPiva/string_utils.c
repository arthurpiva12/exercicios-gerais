#include "string_utils.h"
#include <stdio.h>

int string_length(char *str){
    int i=0;

    while(str[i] != '\0'){
        i++;
    }

    return i;
}

void string_copy(char *src, char *dest){
    int i=0;

    while(src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
        dest[i] = src[i];

}

void string_upper(char *str){
    int i=0;

    while(str[i] != '\0'){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] -= 32;
        }
        i++;
    }
}

void string_lower(char *str){
    int i=0;

    while(str[i] != '\0'){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] += 32;
        }
        i++;
    }
}

void string_reverse(char *str){
    int i=0, j=0;
    i = string_length(str) - 1;
    char reverso[100];

    for(; i>=0; j++){
        reverso[j] = str[i];
        i--;
    }

    j--;
    
    for(i=0; i<=j; i++){
        str[i] = reverso[i];
    }

}