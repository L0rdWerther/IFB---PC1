
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 1004

void reversor3000(char saida[]) {//essa fun��o inverte a string saida, uma vez que ela � formada de tr�s para frente
    int tam_saida = strlen(saida);
    for (int i = 0, j = tam_saida - 1; i < j; i++, j--) {//realiza a troca digito a digito
        char temporario = saida[i];
        saida[i] = saida[j];
        saida[j] = temporario;
    }
}

// Fun��o de soma
void adicao(char a[], char b[], char saida[]) {
    int num_a, num_b; // variavel que vai receber cada d�gito da string
    int carry = 0; // carrega o d�gito da dezena da soma
    int tam_a = strlen(a); // leitura do tamanho da string
    int tam_b = strlen(b);
    int tam; // tamanho da string de saida

    if (tam_a > tam_b) { // condi��o para descobrir qual string tem tamanho maior
        tam = tam_a;
    } else {
        tam = tam_b;
    }

    for (int i = 0; i < tam; i++) { // far� a leitura, d�gito a d�gito
        if (i < tam_a) {
            num_a = a[tam_a - i - 1] - '0'; //converte d�gito (char) em inteiro (int)
        } else {
            num_a = 0;//adiciona 0 para completar o tamamnho da string quando esta for menor que aquela
        }
        if (i < tam_b) {
            num_b = b[tam_b - i - 1] - '0';
        } else {
            num_b = 0;
        }
        int soma = num_a + num_b + carry; // soma dos d�gitos
        carry = soma / 10; // tira o d�gito da dezena e passa para a pr�xima intera��o
        saida[i] = (soma % 10) + '0'; // finaliza o d�gito
    }

    if (carry > 0) { // caso ao fim sobre algo no carry, ser� concatenado no final da resposta
        saida[tam] = carry + '0';
        saida[tam + 1] = '\0'; // adiciona +1 ao tamanho da resposta para o \0 que encerra a string
    } else {
        saida[tam] = '\0'; // define o �ltimo d�gito como nulo
    }

    // reverte a string
    reversor3000(saida);
}

// Fun��o de subtra��o
void subtracao(char a[], char b[], char saida[]) {
    int num_a, num_b;
    int carry = 0;
    int tam_a = strlen(a);
    int tam_b = strlen(b);
    int tam;

    if (tam_a > tam_b) {
        tam = tam_a;
    } else {
        tam = tam_b;
    }

    int negativo = 0;

    if (tam_a < tam_b || (tam_a == tam_b && strcmp(a, b) < 0)) {//troca 'a' por 'b' quando a subtra��o for negativa, strcmp compara os valores de 'a' e 'b' na tabela ascii
        char temporario[TAM];
        strcpy(temporario, a);//realiza a troca da string 'a' por 'b' para realizar a subtra��o corretamente, tendo que colocar 'a' em uma var tempor�ria antes
        strcpy(a, b);
        strcpy(b, temporario);

        int temporario_tam = tam_a;//troca o tamanho das duas strings
        tam_a = tam_b;
        tam_b = temporario_tam;

        negativo = 1;
    }

    for (int i = 0; i < tam; i++) { //la�o faz a subtra��o digito a digito
        if (i < tam_a) {
            num_a = a[tam_a - i - 1] - '0';//converte d�gito (char) em inteiro (int).
        } else {
            num_a = 0;
        }
        if (i < tam_b) {
            num_b = b[tam_b - i - 1] - '0';
        } else {
            num_b = 0;
        }
        int sub = num_a - num_b - carry;

        if (sub < 0) {// quando a subtra��o resulta em negativo
            sub += 10;//adiciona 10 para ajustar o resultado
            carry = 1;//define carry como 1 para a pr�xima itera��o
        } else {
            carry = 0;//nada muda
        }

        saida[i] = sub + '0';
    }
    // Verifique se o ultimo digito de saida � zero
    while (tam > 1 && saida[tam - 1] == '0') {
        saida[tam - 1] = '\0'; // Define o ultimo digito como nulo
        tam--;//Decrementa o valor de tam em 1
    }

    if (negativo == 1) {
        saida[tam] = '-';//concatena o sinal negativo quando necess�rio
        saida[tam + 1] = '\0';//adiciona 1 de espa�o no tamanho para o \0 que encerra a string
    } else {
        saida[tam] = '\0'; //define o ultimo digito como nulo
    }

    // reverte a string
    reversor3000(saida);
}

// Fun��o de multiplica��o
void multiplicacao(char a[], char b[], char saida[]) {
    int tam_a = strlen(a);
    int tam_b = strlen(b);
    int tam = tam_a + tam_b;

    for (int i = 0; i < tam; i++) {
        saida[i] = '0';//completa tamanho da string com zeros
    }
    saida[tam] = '\0';//finaliza ultimo digito da string

    for (int i = 0; i < tam_a; i++) {
        int num_a = a[tam_a - i - 1] - '0';//nomeia o digito e retira o zero
        int carry = 0;

        for (int j = 0; j < tam_b; j++) {
            int num_b = b[tam_b - j - 1] - '0';
            int mult = (saida[i + j] - '0') + num_a * num_b + carry;
            carry = mult / 10;
            saida[i + j] = (mult % 10) + '0';
        }

        if (carry > 0) {
            saida[i + tam_b] += carry;//caso sobre algo no carry, cria um espaço para concatenar
        }
    }

    // reverte a string
    reversor3000(saida);
}

int main() {
    int n, o;
    int hunter = 0;//hunter � um ca�ador de zeros que ignora zeros irrelevantes do resultado(saida) que podem aparecer � esquerda
    char a[TAM], b[TAM], saida[TAM];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %s %d", a, b, &o);//entrada

        if (o == 1) {
            adicao(a, b, saida);//dados que v�o para o void
        } else if (o == 2) {
            subtracao(a, b, saida);
        } else if (o == 3) {
            multiplicacao(a, b, saida);
        }

         //remove zeros  que podem aparecer no inicio do saida
        while (saida[hunter] == '0' && saida[hunter + 1] != '\0') {
            hunter++;
        }

        printf("%s\n", &saida[hunter]);
        hunter = 0; // Reseta hunter para a pr�xima inteira��o
    }
    return 0;
}
    