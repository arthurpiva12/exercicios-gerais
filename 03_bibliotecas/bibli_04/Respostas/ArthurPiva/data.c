#include "data.h"
#include <stdio.h>

int verificaDataValida(int dia, int mes, int ano){
    if(verificaBissexto(ano)){
        if(mes>=1 && mes<=12){
            if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
                if(dia>=1 && dia<=31){
                    return 1;
                }
                return 0;
            }
            else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
                if(dia>=1 && dia<=30){
                    return 1;
                }
                return 0;
            }
            else{
                if(dia>=1 && dia<=29){
                    return 1;
                }
                return 0;
            }
        }

        else{
            return 0;
        }
    }

    else{
        if(mes>=1 && mes<=12){
            if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
                if(dia>=1 && dia<=31){
                    return 1;
                }
                return 0;
            }
            else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
                if(dia>=1 && dia<=30){
                    return 1;
                }
                return 0;
            }
            else{
                if(dia>=1 && dia<=28){
                    return 1;
                }
                return 0;
            }
        }

        else{
            return 0;
        }
    }
}

void imprimeData(int dia, int mes, int ano){

}

void imprimeMesExtenso(int mes){
    if(mes == 1){
        printf("Janeiro ");
    }

    else if(mes == 2){
        printf("Fevereiro ");
    }

    else if(mes == 3){
        printf("Marco ");
    }

    else if(mes == 4){
        printf("Abril ");
    }

    else if(mes == 5){
        printf("Maio ");
    }

    else if(mes == 6){
        printf("Junho ");
    }

    else if(mes == 7){
        printf("Julho ");
    }

    else if(mes == 8){
        printf("Agosto ");
    }

    else if(mes == 9){
        printf("Setembro ");
    }

    else if(mes == 10){
        printf("Outubro ");
    }

    else if(mes == 11){
        printf("Novembro ");
    }

    else if(mes == 12){
        printf("Dezembro ");
    }
}

void imprimeDataExtenso(int dia, int mes, int ano){
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf("de %d\n", ano);
}

int verificaBissexto(int ano){
    if(ano%4 == 0){
    
        if(ano%100 == 0){
            if(ano%400 == 0){
                return 1;
            }
            else{
                return 0;
            }
        }

        else{
            return 1;
        }
    }
    
    return 0;
}

int numeroDiasMes(int mes, int ano){
     if(verificaBissexto(ano)){
        if(mes>=1 && mes<=12){
            if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
               return 31;
            }
            else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
                return 30;
            }
            else{
                return 29;
            }
        }
    }

    else{
        if(mes>=1 && mes<=12){
            if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
                return 31;
            }
            else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
                return 30;
            }
            else{
                return 28;
            }
        }
    }
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    if(ano1 > ano2){
        return 1;
    }
    else if(ano2 > ano1){
        return -1;
    }

    if(mes1 > mes2){
        return 1;
    }
    else if(mes2 > mes1){
        return -1;
    }

    if(dia1 > dia2){
        return 1;
    }
    else if(dia2 > dia1){
        return -1;
    }

    return 0;
}

int calculaDiasAteMes(int mes, int ano){
    int dias = 0;
    int i;

    for(i=1; i<mes; i++){
        dias += numeroDiasMes(i, ano);
    }

    return dias;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    int qtd1 = 0, qtd2 = 0;
    qtd1 = calculaDiasAteMes(mes1, ano1);
    qtd2 = calculaDiasAteMes(mes2, ano2);

    qtd1 = qtd1 + dia1;
    qtd2 = qtd2 + dia2;

    if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 1){
       int diferenca=0, i=0, j=0, cont=0;
        diferenca = ano1 - ano2;

        //verifica a diferenca entre os anos
        if(diferenca == 0){
            return qtd1 - qtd2;
        }
        
        //verifica se o ano do menor e bissexto, para fazer a cont de quanto falta para o proximo
        if(verificaBissexto(ano2)){
            cont = 366 - qtd2;
        }
        else{
            cont = 365 - qtd2;
        }

        //conta os dias dos anos entre as datas
        for(i=1; i<diferenca; i++){
            j = ano2 + i;
            if(verificaBissexto(j)){
                cont += 366;
            }
            else{
                cont += 365;
            }
        }

        //soma com a data final
        cont += qtd1;

        return cont;
    }

    else if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == -1){
        int diferenca=0, i=0, j=0, cont=0;
        diferenca = ano2 - ano1;

        //verifica a diferenca entre os anos
        if(diferenca == 0){
            return qtd2 - qtd1;
        }
        
        //verifica se o ano do menor e bissexto, para fazer a cont de quanto falta para o proximo
        if(verificaBissexto(ano1)){
            cont = 366 - qtd1;
        }
        else{
            cont = 365 - qtd1;
        }

        //conta os dias dos anos entre as datas
        for(i=1; i<diferenca; i++){
            j = ano1 + i;
            if(verificaBissexto(j)){
                cont += 366;
            }
            else{
                cont += 365;
            }
        }

        //soma com a data final
        cont += qtd2;

        return cont;
    }

    else{
        return 0;
    }
}

void imprimeProximaData(int dia, int mes, int ano){
    int qtd;
    qtd = numeroDiasMes(mes, ano);

    if(dia < qtd){
        dia++;
        printf("%02d/%02d/%04d", dia, mes, ano);
    }

    if(dia == qtd){
        dia = 1;
        if(mes == 12){
            mes = 1;
            ano++;
        }
        else{
            mes++;
        }

        printf("%02d/%02d/%04d", dia, mes, ano);
    }
}