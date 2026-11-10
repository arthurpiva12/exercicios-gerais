#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gerenciadorpacotes.h"

int main(){
    printf("\n");
    int opcao = 0;
    tGerenciador* gerenciador = CriaGerenciador();

    while(1){

        //imprimindo cabecalho
        printf("Escolha uma opcao:\n");
        printf("    (1) Cadastrar um novo pacote\n");
        printf("    (2) Imprimir um pacote especifico\n");
        printf("    (3) Imprimir todos os pacotes e sair\n");

        scanf("%d\n", &opcao);

        if(opcao == 1){
            printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem: \n");

            Type tipo = 0;
            int numElem = 0;
            scanf("%d %d\n", &tipo, &numElem);

            tPacote* pacote = CriaPacote(tipo, numElem);

            if(pacote == NULL){
                continue;
            }

            LePacote(pacote);
            CalculaSomaVerificacaoPacote(pacote);

            AdicionaPacoteNoGerenciador(gerenciador, pacote);
        }

        else if(opcao == 2){
            int indice = 0;
            scanf("%d\n", &indice);
            ImprimirPacoteNoIndice(gerenciador, indice);
        }

        else if(opcao == 3){
            ImprimirTodosPacotes(gerenciador);
            DestroiGerenciador(gerenciador);
            break;
        }
    }

    return 0;
}

