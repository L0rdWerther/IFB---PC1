#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/MEMORY.h"

void STORE(int RX[], int i, int registrador[], int RY[], int memoria[]){

    memoria[RY[i]] = registrador[RX[i]];//Realiza a função STORE

}

void LOAD(int RX[], int i, int registrador[], int RY[], int memoria[]){

    registrador[RX[i]] = memoria[RY[i]];//Realiza a função LOAD

}