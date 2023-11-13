#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/READ.h"

#define MAX 100

void matrix(int n, char instrucoes[][MAX]){
    
    for (int i = 0; i < n; i++) {

        scanf(" %[^\n]s", instrucoes[i]);//Recebe as linhas de instrução

    }
}

void linhas(int* n){

    scanf("%d", &*n);//leitura de quantas linhas de instrução terá o código

}