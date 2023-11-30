#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX_NAME_LENGTH 51
#define MAX_DATE_LENGTH 11
#define MAX_LOGIN_LENGTH 21
#define MAX_PASSWORD_LENGTH 65
#define MAX_LINE_LENGTH 33

struct Usuario {
    char nome[MAX_NAME_LENGTH];
    char data_nascimento[MAX_DATE_LENGTH];
    char login[MAX_LOGIN_LENGTH];
    char senha_criptografada[MAX_PASSWORD_LENGTH];
    char data_ultima_alteracao[MAX_DATE_LENGTH];
    char pula[4];
    char nome_saida[MAX_NAME_LENGTH];
    char data_nascimento_saida[MAX_DATE_LENGTH];
    char login_saida[MAX_LOGIN_LENGTH];
    char line_saida[MAX_LINE_LENGTH];
};

#endif