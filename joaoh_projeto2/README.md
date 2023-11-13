# Projeto 2 - TOY ASSEMBLY

*Feito por*: João Henrique Rodrigues Lopes

*Matrícula*: 231057600020

## Introdução do projeto:

"Se denominam linguagens assembly aquelas linguagens de baixo nível, que estão em
um nível de abstração bem próximo a da arquitetura da máquina programada.

O objetivo deste projeto é construir um interpretador de uma linguagem assembly
simples (toy assembly)."

## Restrições:

- N (1 ≤ N ≤ 100)
- O assembly possui acesso a 32 registradores de inteiros de 32-bits, identificados de R0 a R31, que devem ser inicializados com zero na execução de um programa.
- O resultado RX da operação de mod é sempre 0 ≤ RX < RZ.
- Se após executar 10^5 instruções e o programa não tiver alcançado a instrução EXIT, ele deverá ser encerrado mesmo assim.

## Uso do programa:

A primeira entrada é a quantidade de linhas do programa assembly.
Após, a máquina esperará a entrada das instruções, até que a quantidade de linhas indicadas seja alcaçada, porém, caso a instrução 'EXIT' seja encontrada, o programa será encerrado.  

As instruções possíveis são:

- MOV RX INTEIRO: atribui a RX o valor do INTEIRO
- MOV RX RY: atribui a RX o valor de RY.
- ADD RX RY RZ: soma os valores de RY e RZ e armazena o resultado em RX.
- SUB RX RY RZ: subtrai RZ de RY e armazena o resultado em RX.
- MUL RX RY RZ: multiplica RY por RZ e armazena o resultado em RX.
- DIV RX RY RZ: divide RY por RZ e armazena o resultado em RX. A divisão é inteira, isto é, a parte fracionária é desprezada.
- MOD RX RY RZ: toma o resultado de RY mod RZ e armazena o resultado em RX. O resultado RX da operação de mod é sempre 0 ≤ RX < RZ.
- BEQ RX RY ENDERECO: o fluxo do programa é direcionado para a instrução que ocupa a linha de número ENDERECO caso RX seja igual a RY.
- BLT RX RY ENDERECO: o fluxo do programa é direcionado para a instrução que ocupa a linha de número ENDERECO caso RX seja menor que RY.
- JMP ENDERECO: o fluxo do programa é direcionado para a instrução que ocupa a linha de número ENDERECO.
- LOAD RX RY: carrega o conteúdo de memoria[RY] para o registrador RX.
- STORE RX RY: carrega o conteúdo de RX para memoria[RY].
- PRINT RX: imprime uma linha na tela com o o valor de RX.
- EXIT: encerra o programa.

## Exemplos de Uso:

Aqui estão alguns exemplos de uso do programa:

- Entrada:
5
MOV R0 1
MOV R1 1
ADD R0 R1 R1
PRINT R0
EXIT

- Saída:
2

O programa abaixo imprime os 10 primeiros números da sequência de Fibonacci:

- Entrada:
16
MOV R0 1
MOV R1 1
MOV R2 2
MOV R3 2
MOV R4 10
MOV R5 1
PRINT R0
PRINT R1
BEQ R3 R4 15
ADD R2 R1 R0
PRINT R2
MOV R0 R1
MOV R1 R2
ADD R3 R3 R5
JMP 8
EXIT

- Saída:
1
1
2
3
5
8
13
21
34
55

O programa abaixo insere os valores 1 e 2 nas posições 0 e 1, imprime o conteúdo
destas posições, troca os conteúdos destas posições (swap), e os imprime novamente.

- Entrada:
15
MOV R4 0
MOV R5 1
MOV R0 1
MOV R1 2
STORE R0 R4
STORE R1 R5
PRINT R0
PRINT R1
LOAD R0 R5
LOAD R1 R4
STORE R0 R4
STORE R1 R5
PRINT R0
PRINT R1
EXIT

- Saída:
1
2
2
1

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
	make run
```
Limpeza:
Após terminar o uso do programa, você pode executar limpar os arquivos temporários com o seguinte comando:
```C
	make clean
```
O programa solicitará entradas para realizar as operação desejadas.