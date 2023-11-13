#ifndef TOY_ASSEMBLY_MATH_H
#define TOY_ASSEMBLY_MATH_H
#include "../include/MEMORY.h"

void MOV(int RX[], int inteiro[], int i, int registrador[], int RY[], int contador_R[], int RZ[]);
void ADD(int RX[], int i, int registrador[], int RY[], int RZ[]);
void DIV(int RX[], int i, int registrador[], int RY[], int RZ[]);
void SUB(int RX[], int i, int registrador[], int RY[], int RZ[]);
void MUL(int RX[], int i, int registrador[], int RY[], int RZ[]);
void MOD(int RX[], int i, int registrador[], int RY[], int RZ[]);

#endif //TOY_ASSEMBLY_MATH_H