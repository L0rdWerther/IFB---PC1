#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/READ.h"
#include "../include/OUTPUT.h"
#include "../include/CONTROL.h"

#define MAX 100

int main() {
    
    int n = 0;
    int registrador[32] = {0};
    int inteiro[MAX] = {0};// inteiros
    int RX[MAX] = {0};//RX
    int RY[MAX] = {0};//RY
    int RZ[MAX] = {0};//RZ
    int memoria[1000] = {0}; //Save para LOAD, STORE 

    linhas(&n);

    char instrucoes[n][MAX];
    int contador_R[MAX] = {0}; // Indica quantas vezes 'R' for encontrado

    
    matrix(n, instrucoes);
    num_inteiro(instrucoes, inteiro, n);
    endereco(instrucoes, RX, n, RY, contador_R, RZ);
    decode(instrucoes, n, RX, inteiro, registrador, RY, contador_R, RZ, memoria);//indica a operação

    return 0;
}