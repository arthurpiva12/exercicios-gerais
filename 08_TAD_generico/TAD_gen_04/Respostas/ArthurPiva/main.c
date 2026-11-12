#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "banco.h"
#include "conta.h"

int main(){
    tBanco* banco = CriaBanco();
    LeBanco(banco);

    char escolha;
    scanf("%c\n", &escolha);

    while(1){
        if(escolha == 'A'){
            tAgencia* agencia = CriaAgencia();
            LeAgencia(agencia);
            AdicionaAgencia(banco, agencia);
        }

        else if(escolha == 'C'){
            int numero;
            tConta* conta = CriaConta();
            LeConta(conta);

            scanf("%d", &numero);
            InsereContaBanco(banco, numero, conta);
        }

        else if(escolha == 'F'){
            break;
        }

        scanf("%c\n", &escolha);
    }

    ImprimeRelatorioBanco(banco);
    DestroiBanco(banco);

    return 0;
}