#ifndef LEITURA_H
#define LEITURA_H

#include "../include/leitura.h"
#include "../include/quebra.h"
#include "../include/structs.h"

void leiturinha(FILE *arquivo_usuarios, FILE *arquivo_senha, FILE *arquivo_saida);
int contarUsuarios(FILE *arquivo_usuarios);
void lerUsuarios(FILE *arquivo_usuarios, struct Usuario *usuarios, int num_usuarios);

#endif