#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/CONTROL.h"
#include "../include/LOGIC.h"
#include "../include/MATH.h"
#include "../include/MEMORY.h"
#include "../include/OUTPUT.h"

#define MAX 100

void num_inteiro(char instrucoes[][MAX], int inteiro[], int n) {//Pega números inteiros não concatenados com 'R'
    for (int i = 0; i < n; i++) {
        int tamanho = strlen(instrucoes[i]);
        char caractere_instrucoes[10]; // Declara caractere_instrucoes

        for (int j = 0; j < tamanho; j++) {
            if (instrucoes[i][j] != 'R') {
                int k = 0;

                for (;instrucoes[i][j] != ' ' && instrucoes[i][j] != '\0'; j++, k++) {//Salva os caracteres até o espaço ou fim da linha

                    caractere_instrucoes[k] = instrucoes[i][j];
    
                }
                caractere_instrucoes[k] = '\0';

                inteiro[i] = atoi(caractere_instrucoes);//Salva os números

            } else {
                // ignora números concatenados com 'R'
                for (;instrucoes[i][j] != ' ' && instrucoes[i][j] != '\0'; j++) {
                }
            }
        }
    }
}

void endereco(char instrucoes[][MAX], int RX[], int n, int RY[], int contador_R[], int RZ[]) {//Salva números concatenados com 'R'
    for (int i = 0; i < n; i++) {
        int tamanho = strlen(instrucoes[i]);

        for (int j = 0; j < tamanho; j++) {
            if (contador_R[i] == 0 && instrucoes[i][j] == 'R' && instrucoes[i][j - 1] == ' ') {//Primeiro número de 'R' da linha

                RX[i] = atoi(&instrucoes[i][j + 1]);
                
                contador_R[i] = 1;

            } else if (contador_R[i] == 1 && instrucoes[i][j] == 'R') {//Segundo número de 'R' da linha

                RY[i] = atoi(&instrucoes[i][j + 1]);

                contador_R[i] = 2;
            } else if (contador_R[i] == 2 && instrucoes[i][j] == 'R') {//Terceiro número de 'R' da linha

                RZ[i] = atoi(&instrucoes[i][j + 1]);

                contador_R[i] = 3;
            }
        }
    }
}

void decode(char instrucoes[][MAX], int n, int RX[], int inteiro[], int registrador[], int RY[], int contador_R[], int RZ[], int memoria[]) {
    int out = 0;
    for (int i = 0; i < n; i++) {

        if (out == 100000){
            return;
        } out++;
        if (instrucoes[i][0] == 'A') {
            ADD(RX, i, registrador, RY, RZ);
        } else if (instrucoes[i][0] == 'D') {
            DIV(RX, i, registrador, RY, RZ);
        }  else if (instrucoes[i][0] == 'J') {
            JMP(inteiro, &i);
        } else if (instrucoes[i][0] == 'L') {
            LOAD(RX, i, registrador, RY, memoria);
        } else if (instrucoes[i][0] == 'P') {
            PRINT(RX, registrador, i);
        } else if (instrucoes[i][0] == 'E') {
            return;
        } else if (instrucoes[i][0] == 'S' && instrucoes[i][1] == 'U') {
            SUB(RX, i, registrador, RY, RZ);
        } else if (instrucoes[i][0] == 'S' && instrucoes[i][1] == 'T') {
            STORE(RX, i, registrador, RY, memoria);
        } else if (instrucoes[i][0] == 'M' && instrucoes[i][2] == 'L') {
            MUL(RX, i, registrador, RY, RZ);
        } else if (instrucoes[i][0] == 'M' && instrucoes[i][2] == 'V') {
            MOV(RX, inteiro, i, registrador, RY, contador_R, RZ);
        } else if (instrucoes[i][0] == 'M' && instrucoes[i][2] == 'D') {
            MOD(RX, i, registrador, RY, RZ);
        } else if (instrucoes[i][0] == 'B' && instrucoes[i][1] == 'E') {
            BEQ(RX, &i, registrador, RY, inteiro);
        } else if (instrucoes[i][0] == 'B' && instrucoes[i][1] == 'L') {
            BLT(RX, &i, registrador, RY, inteiro);
        }
    }
}