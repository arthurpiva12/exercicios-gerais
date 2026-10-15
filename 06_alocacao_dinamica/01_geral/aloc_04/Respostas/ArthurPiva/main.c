#include <stdio.h>
#include "utils_char2.h"

int main(){
    int tamanho = 10;
    char *vetor = CriaVetorTamPadrao();
    vetor = LeVetor(vetor, &tamanho);

    ImprimeString(vetor);
    LiberaVetor(vetor);

    return 0;
}