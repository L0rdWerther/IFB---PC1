#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/OUTPUT.h"

void PRINT(int RX[], int registrador[], int i) {

    printf("%d\n", registrador[RX[i]]); // Imprime os valores salvos no registrador RX[i]

}