#ifndef CRIPTOGRAFIA_H
#define CRIPTOGRAFIA_H

#include "../include/criptografia.h"
#include <openssl/sha.h>

void hasha(const char *line, char hashString[SHA256_DIGEST_LENGTH * 2 + 1]);

#endif