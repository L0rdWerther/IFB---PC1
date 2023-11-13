#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/LOGIC.h"

void BEQ(int RX[], int* i, int registrador[], int RY[], int inteiro[]){
    if (registrador[RX[*i]] == registrador[RY[*i]]){

        *i = inteiro[*i] - 1;
       
    }
}

void BLT(int RX[], int* i, int registrador[], int RY[], int inteiro[]){
    if (registrador[RX[*i]] < registrador[RY[*i]]){
    
        *i = inteiro[*i] - 1;
        
    }
}

void JMP(int inteiro[], int* i){

    *i = inteiro[*i] - 1;

}