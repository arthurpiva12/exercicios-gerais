#include <stdio.h> 
#include <stdlib.h> 
#include "data.h"

void InicializaDataParam(int dia, int mes, int ano, tData *data){
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
}

void LeData(tData *data ){
    scanf("%d %d %d", &data->dia, &data->mes, &data->ano);
}

void ImprimeData(tData *data ){
    int qtd;
    qtd = InformaQtdDiasNoMes(data);

    if(data->dia > qtd){
        data->dia = qtd;
    }

    if(data->mes > 12){
        data->mes = 12;
    }

    printf("'%02d/%02d/%04d'", data->dia, data->mes, data->ano);
}

int EhBissexto(tData *data ){
    if(data->ano % 4 == 0){
        if(data->ano % 100 == 0){
            if(data->ano % 400 == 0){
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

int InformaQtdDiasNoMes(tData *data ){
    if(EhBissexto(data)){
        if(data->mes == 1 || data->mes == 3 || data->mes == 5 || data->mes == 7 || data->mes == 8 || data->mes == 10 || data->mes == 12){
            return 31;
        }
        else if(data->mes == 2){
            return 29;
        }
        else{
            return 30;
        }
    }

    else{
        if(data->mes == 1 || data->mes == 3 || data->mes == 5 || data->mes == 7 || data->mes == 8 || data->mes == 10 || data->mes == 12){
            return 31;
        }
        else if(data->mes == 2){
            return 28;
        }
        else{
            return 30;
        }
    }
}

void AvancaParaDiaSeguinte(tData *data ){
    int qtd;
    qtd = InformaQtdDiasNoMes(data);

    if(data->dia == qtd){
        if(data->mes == 12){
            data->dia = 1;
            data->mes = 1;
            data->ano++;
        }
        else{
            data->dia = 1;
            data->mes++;
        }
    }

    else{
        data->dia++;
    }
}

int EhIgual(tData *data1, tData *data2 ){
    if(data1->ano == data2->ano){
        if(data1->mes == data2->mes){
            if(data1->dia == data2->dia){
                return 1;
            }
            return 0;
        }
        return 0;
    }

    return 0;
}