#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/structs.h"
#include "../include/quebra.h"
#include "../include/criptografia.h"

// Função responsável por quebrar senhas criptografadas
void quebradordesenha(FILE *arquivo_senha, int num_usuarios, char hashString[], struct Usuario *usuarios, int *usuariosquebrados) {
    char line[33]; // Array para armazenar cada linha lida do arquivo de senhas

    // Itera sobre cada linha do arquivo de senhas
    while (fscanf(arquivo_senha, "%32s", line) == 1) {
        hasha(line, hashString); // Chama a função para calcular o hash da senha lida

        // Itera sobre cada usuário no sistema
        for (int i = 0; i < num_usuarios; i++) {
            // Compara o hash calculado com a senha criptografada do usuário
            if (strcmp(usuarios[i].senha_criptografada, hashString) == 0) {
                // Se houver correspondência, copia informações relevantes para a saída
                strcpy(usuarios[i].login_saida, usuarios[i].login);
                strcpy(usuarios[i].line_saida, line);
                strcpy(usuarios[i].nome_saida, usuarios[i].nome);
                strcpy(usuarios[i].data_nascimento_saida, usuarios[i].data_nascimento);
                (*usuariosquebrados)++; // Incrementa o contador de usuários que tiveram senhas quebradas
            }
        }
    }
}