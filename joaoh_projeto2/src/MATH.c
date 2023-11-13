#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/MATH.h"

void MOV(int RX[], int inteiro[], int i, int registrador[], int RY[], int contador_R[], int RZ[]) {//realiza afunção MOV
    if (contador_R[i] == 2) {

        registrador[RX[i]] = registrador[RY[i]];

    } else {

        registrador[RX[i]] = inteiro[i];

    }
}

void ADD(int RX[], int i, int registrador[], int RY[], int RZ[]){
    
    registrador[RX[i]] = registrador[RY[i]] + registrador[RZ[i]];//Realiza a função ADD

}

void DIV(int RX[], int i, int registrador[], int RY[], int RZ[]){

    registrador[RX[i]] = registrador[RY[i]] / registrador[RZ[i]];//Realiza a função DIV

}

void SUB(int RX[], int i, int registrador[], int RY[], int RZ[]){

    registrador[RX[i]] = registrador[RY[i]] - registrador[RZ[i]];//Realiza a função SUB

}

void MUL(int RX[], int i, int registrador[], int RY[], int RZ[]){

    registrador[RX[i]] = registrador[RY[i]] * registrador[RZ[i]];//Realiza a função MUL

}

void MOD(int RX[], int i, int registrador[], int RY[], int RZ[]){

    registrador[RX[i]] = registrador[RY[i]] % registrador[RZ[i]];//Realiza a função MOD

    if(registrador[RX[i]] < 0){

        registrador[RX[i]] = (registrador[RY[i]] % registrador[RZ[i]]) + registrador[RZ[i]];
        
    }

}