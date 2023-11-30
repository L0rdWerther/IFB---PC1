#include <stdio.h>
#include <stdlib.h>
#include "../include/leitura.h"  // Inclui o cabeçalho para funções de leitura
#include "../include/saida.h"    // Inclui o cabeçalho para funções de saída

int main(int argc, char *argv[]) {
    // Abre os arquivos de entrada e saída
    FILE *arquivo_usuarios = fopen(argv[1], "r");
    FILE *arquivo_senha = fopen(argv[2], "r");
    FILE *arquivo_saida = fopen(argv[3], "w");

    // Chama a função de leitura
    leiturinha(arquivo_usuarios, arquivo_senha, arquivo_saida);
    
    // Fecha os arquivos abertos
    fclose(arquivo_senha);
    fclose(arquivo_usuarios);
    fclose(arquivo_saida);

    return 0;  // Retorna 0 para indicar que o programa foi executado com sucesso
}