#ifndef TOY_ASSEMBLY_CONTROL_H
#define TOY_ASSEMBLY_CONTROL_H

#define MAX 100
#include "../include/CONTROL.h"      

void num_inteiro(char instrucoes[][MAX], int inteiro[], int n);
void endereco(char instrucoes[][MAX], int RX[], int n, int RY[], int contador_R[], int RZ[]);
void decode(char instrucoes[][MAX], int n, int RX[], int inteiro[], int registrador[], int RY[], int contador_R[], int RZ[], int memoria[]);

#endif //TOY_ASSEMBLY_CONTROL_H