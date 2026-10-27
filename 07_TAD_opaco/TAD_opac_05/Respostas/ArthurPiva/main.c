#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "conta.h"
#include "banco.h"

int main(){
    char opcao;
    scanf("%c\n", &opcao);
    tBanco* banco = CriaBanco();


    while(opcao != 'F'){
        if(opcao == 'A'){
            AbreContaBanco(banco);

        }
        else if(opcao == 'D'){
            DepositoContaBanco(banco);
        }
        else if(opcao == 'S'){
            SaqueContaBanco(banco);
        }
        else if(opcao == 'T'){
            TransferenciaContaBanco(banco);
        }
        else if(opcao == 'R'){
            ImprimeRelatorioBanco(banco);
        }

        scanf("%c\n", &opcao);
    }

    DestroiBanco(banco);
    
    return 0;
}