# Projeto 3 - ATAQUE DE DICIONÁRIO

*Feito por*: João Henrique Rodrigues Lopes

*Matrícula*: 231057600020

## Introdução do projeto:

"O ataque de dicionário é um ataque do tipo força-bruta em que o atacante obtém um
banco de dados com senhas criptografadas e tenta descobrir a senha em claro que gerou
a senha criptografada correspondente através de outro banco de dados de senhas fracas.

Neste projeto deve-se, a partir de um arquivo de usuários com senhas criptografadas
com SHA256 e um arquivo de senhas em claro consideradas fracas, produzir um relatório
de quebra de senhas, que indica quais usuários tiveram a sua senha quebrada."

## Restrições:

-Os caminhos dos arquivos de entrada e saída deverão ser obtidos através da linha de
comando.
• Primeiro argumento: caminho do arquivo de usuários.
• Segundo argumento: caminho do arquivo de senhas fracas.
• Terceiro argumento: caminho do arquivo de relatório de quebra.

-O sistema deverá ser dividido em módulos, cada qual com uma tarefa. Estes módulos
podem ser organizados internamente através de várias funções e eles correspondem aos
seguintes:

• Módulo de leitura: efetua a leitura do arquivo de usuários e do arquivo de senhas fracas e armazena os dados na estrutura adequada.
• Módulo de saída: produz o relatório de quebras.
• Módulo criptográfico: aplica a função SHA256 nas strings.
• Módulo de quebra: responsável pela quebra das senhas.
• Módulo principal: contém a função main e realiza a chamada aos outros módulos.

Os módulos devem ser organizados em arquivos separados, com seus respectivos arquivos de cabeçalho e implementação

-Um Makefile deverá ser produzido para a compilação dos códigos-fontes no executável
e deverá ser distribuído junto ao código.

-A alocação dinâmica de memória deverá ser utilizada para armazenar os dados, uma
vez que não se conhece o número de usuários e senhas, a priori.

-Para criptografar as senhas, o algoritmo SHA256 deve ser utilizado. Ele é providenciado pela biblioteca OpenSSL no Linux.

## Uso do programa:

### Arquivo de usuários
O arquivo de usuários possui os dados dos usuários juntamente com as suas senhas
criptografadas. Cada usuário é descrito por diversas linhas, contendo os seguintes dados:
• Nome completo (até 50 caracteres). Pode haver espaços no nome completo;
• Data de nascimento no formato DD/MM/AAAA (10 caracteres);
• Login (até 20 caracteres);
• Senha criptografada: (64 caracteres);
• Data da última alteração de senha no formato DD/MM/AAAA (10 caracteres).
Após a descrição de cada usuário, há uma linha com o separador ---.
As senhas foram criptografadas utilizando a função de hash SHA256.

### Arquivo de senhas fracas
O arquivo de senhas fracas possui várias linhas, cada uma descrevendo uma provável
senha. Estas senhas estão limitadas a 32 caracteres.

### Arquivo de senhas quebradas
O arquivo de saída deverá imprimir um relatório de quebra. Para cada usuário que
teve a sua senha quebrada, deverá ser impresso, em uma linha:
• Login;
• Senha em claro;
• Nome Completo;
• Data de nascimento.
Após cada usuário que teve a senha quebrada, uma linha com o separador --- deverá
ser impresa.

## Exemplos de Uso:

### Arquivo de usuários
Daniel Saad
01/01/1850
danielsaad
981a16abd878e773ba98c10fd55db367a05f807f2eb5b5c3f2b86efbb218e2e3
03/11/2023
---
Marcus Vinicius
02/02/1950
marquinhos
65e84be33532fb784c48129675f9eff3a682b27168c0ea744b2cf58ee02337c5
20/10/2023
---
Cleidison Santos
24/12/2000
cleidison
d58d736c7a967fb5f307951932734f8b0594725faa5011dbb66a8c538e635fb6
10/5/2021
---

### Arquivo de senhas fracas
swordfish
flamengo
letmein
irobot
qwerty

### Arquivo de Saída
marquinhos
qwerty
Marcus Vinicius
02/02/1950
---
cleidison
flamengo
Cleidison Soares
24/12/2000
---

## Compilação do Código e pré-requisitos:

Será necessário o uso do GCC (GNU Compiler Collection). É possível ver o status do gcc com o comando no terminal:
```C
	gcc --version
```
Após, descompacte o arquivo joaoh_toyassembly.zip

Localize o diretório onde o código-fonte foi baixado e dê 'make' no terminal:
```C
	make
```

Execução:
Após a compilação bem-sucedida, você pode executar o programa com o seguinte comando:
```C
	./main (seu_arquivo_de_usuarios).txt (seu_arquivo_de_senhas_fracas).txt (seu_arquivo_de_saida).txt
```
Limpeza:
Após terminar o uso do programa, você pode executar limpar os arquivos temporários com o seguinte comando:
```C
	make clean
```