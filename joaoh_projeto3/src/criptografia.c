#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#include "../include/structs.h"
#include "../include/quebra.h"
#include "../include/criptografia.h"

// Função para calcular o hash SHA-256 de uma string e armazená-lo em hashString
void hasha(const char *line, char hashString[SHA256_DIGEST_LENGTH * 2 + 1]) {
    
    // Alocar espaço para o hash
    unsigned char *hash = (unsigned char *)malloc(SHA256_DIGEST_LENGTH);
    
    // Calcular o hash SHA-256 da linha fornecida
    SHA256((const unsigned char *)line, strlen(line), hash);

    // Converter o hash binário para uma string hexadecimal em hashString
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hashString[i * 2], "%02x", hash[i]);
    }
    
    // Adicionar o caractere nulo ao final da string
    hashString[SHA256_DIGEST_LENGTH * 2] = '\0';

    // Liberar a memória alocada para o hash
    free(hash);
}