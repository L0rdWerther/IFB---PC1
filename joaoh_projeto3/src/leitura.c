#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#include "../include/leitura.h"
#include "../include/quebra.h"
#include "../include/structs.h"
#include "../include/saida.h"

// Função principal para processar a leitura de arquivos de usuários e senhas
void leiturinha(FILE *arquivo_usuarios, FILE *arquivo_senha, FILE *arquivo_saida) {
    // Contagem do número de usuários no arquivo
    int num_usuarios = contarUsuarios(arquivo_usuarios);
    rewind(arquivo_usuarios);

    // Alocação dinâmica para armazenar dados dos usuários
    struct Usuario *usuarios = (struct Usuario *)calloc(num_usuarios, sizeof(struct Usuario));

    // Leitura dos dados dos usuários a partir do arquivo
    lerUsuarios(arquivo_usuarios, usuarios, num_usuarios);

    // String para armazenar a hash da senha
    char hashString[SHA256_DIGEST_LENGTH * 2 + 1];
    int usuariosquebrados = 0;

    // Quebra de senhas e armazenamento da hash resultante
    quebradordesenha(arquivo_senha, num_usuarios, hashString, usuarios, &usuariosquebrados);

    // Impressão dos dados dos usuários no arquivo de saída
    printar(num_usuarios, usuarios, arquivo_saida);

    // Liberação de memória alocada dinamicamente
    free(usuarios);
}

// Função para contar o número de usuários no arquivo
int contarUsuarios(FILE *arquivo_usuarios) {
    int num_usuarios = 0;
    char line[65];

    // Contagem dos usuários no arquivo
    while (fscanf(arquivo_usuarios, "%64[^\n]\n", line) == 1) {
        num_usuarios++;
    }

    // Cada usuário é composto por 6 linhas no arquivo
    return num_usuarios /= 6;
}

// Função para ler os dados dos usuários do arquivo
void lerUsuarios(FILE *arquivo_usuarios, struct Usuario *usuarios, int num_usuarios) {
    // Leitura dos dados de cada usuário no arquivo
    for (int i = 0; i < num_usuarios; i++) {
        fscanf(arquivo_usuarios, " %[^\n]\n", usuarios[i].nome);
        fscanf(arquivo_usuarios, " %10s\n", usuarios[i].data_nascimento);
        fscanf(arquivo_usuarios, " %20s\n", usuarios[i].login);
        fscanf(arquivo_usuarios, " %64s\n", usuarios[i].senha_criptografada);
        fscanf(arquivo_usuarios, " %10s\n", usuarios[i].data_ultima_alteracao);
        fscanf(arquivo_usuarios, " %4s\n", usuarios[i].pula);
    }
}