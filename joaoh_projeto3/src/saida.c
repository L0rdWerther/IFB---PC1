#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/saida.h"
#include "../include/structs.h"  // Inclui o cabeçalho para a struct Usuario

// Função para imprimir dados dimensionais no arquivo de saída
void printar(int num_usuarios, struct Usuario *usuarios, FILE *arquivo_saida) {
    int printado = 0;  // Contador para verificar se algum dado foi impresso

    // Itera sobre os usuários
    for (int i = 0; i < num_usuarios; i++) {
        // Verifica se o login e o login de saída são iguais
        if (strcmp(usuarios[i].login, usuarios[i].login_saida) == 0) {
            // Verifica se já foi impresso algum dado anteriormente
            if (printado > 0) {
                fprintf(arquivo_saida, "\n");  // Adiciona uma nova linha entre conjuntos de dados
            }
            
            // Imprime os dados no arquivo de saída
            fprintf(arquivo_saida, "%s\n", usuarios[i].login_saida);
            fprintf(arquivo_saida, "%s\n", usuarios[i].line_saida);
            fprintf(arquivo_saida, "%s\n", usuarios[i].nome_saida);
            fprintf(arquivo_saida, "%s\n", usuarios[i].data_nascimento_saida);
            fprintf(arquivo_saida, "---");  // Separador entre conjuntos de dados
            printado++;  // Incrementa o contador de dados impressos
        }
    }
}