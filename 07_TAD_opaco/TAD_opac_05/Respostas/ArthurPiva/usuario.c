#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "banco.h"
#include "conta.h"

struct Usuario{
    char* nome;
    int cpf;
};

tUsuario *CriaUsuario(){
    tUsuario* usuario = malloc(sizeof(struct Usuario));

    if(usuario == NULL){
        return NULL;
    }

    //inicializando as variaveis
    usuario->nome = NULL;
    usuario->cpf = -1;

    return usuario;
}

void DestroiUsuario(tUsuario *user){
    free(user->nome);
    free(user);
}

void LeUsuario(tUsuario *user){
    user->nome = malloc(20 * sizeof(char));
    scanf(" %[^ ] %d", user->nome, &user->cpf);
}

void ImprimeUsuario(tUsuario *user){
    printf("Nome: %s\n", user->nome);
    printf("CPF: %d\n", user->cpf);
}
