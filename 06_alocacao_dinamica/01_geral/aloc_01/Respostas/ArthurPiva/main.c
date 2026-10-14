#include <stdio.h>
#include "utils.h"

int main(){
    int tamanho;
    scanf("%d", &tamanho);

    int *vetor = CriaVetor(tamanho);
    LeVetor(vetor, tamanho);
    float media = CalculaMedia(vetor, tamanho);

    printf("%.2f", media);
    LiberaVetor(vetor);

    return 0;
}
