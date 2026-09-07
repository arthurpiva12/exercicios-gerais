#include "data.h"
#include <stdio.h>

int main(){
    int dia, mes, ano;
    scanf("%02d/%02d/%04d", &dia, &mes, &ano);

    if(verificaDataValida(dia, mes, ano)){

        int qtd=0;
        //printa a data
        printf("Data informada: ");
        imprimeDataExtenso(dia, mes, ano); 

        //printa se e bissexto ou nao
        if(verificaBissexto(ano)){
            printf("O ano informado eh bissexto\n");
        }
        else{
            printf("O ano informado nao eh bissexto\n");
        }

        //printa quantos dias tem o mes
        qtd = numeroDiasMes(mes, ano);
        printf("O mes informado possui %d dias\n", qtd);

        printf("A data seguinte eh: ");
        imprimeProximaData(dia, mes, ano);
    }

    else{
        printf("A data informada eh invalida");
    }

    return 0;
}