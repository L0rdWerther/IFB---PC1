#ifndef QUEBRA_H
#define QUEBRA_H

#include "../include/quebra.h"
#include "../include/structs.h"

void quebradordesenha(FILE *arquivo_senha, int num_usuarios, char hashString[], struct Usuario *usuarios, int *usuariosquebrados);

#endif