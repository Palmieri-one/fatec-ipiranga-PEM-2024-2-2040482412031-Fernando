/*------------------------------------------------------------------*
* Disciplina: Programação Estruturada e Modular                     *
*          Prof. Carlos Veríssimo                                   *
*-------------------------------------------------------------------*
* Objetivo do Programa: COMPARAÇÃO DE BUBBLE SORT e INSERÇÃO        *
*                                                                   *
* Data: 10/10/2024                                                  * 
* Autor: Letícia Sudan Gauy , Fernando Palmieri e Lucas Zanin Marum *
*-------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // Incluindo a biblioteca time.h

// Função para ordenar usando Bubble Sort
void bubbleSort(int *numeros, int tamanho) {
    int temporaria;
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) { // Corrigido para evitar comparações desnecessárias
            if (numeros[j] > numeros[j + 1]) {
                temporaria = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temporaria;
            }
        }
    }
}

// Função para ordenar usando Insertion Sort
void insertionSort(int *numeros, int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int elemento = numeros[i];
        int posicao = i - 1;

        while (posicao >= 0 && numeros[posicao] > elemento) {
            numeros[posicao + 1] = numeros[posicao];
            posicao--;
        }
        numeros[posicao + 1] = elemento;
    }
}

// Função para exibir os números
void exibirNumeros(int *numeros, int tamanho) {
    printf("[ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%i ", numeros[i]);
    }
    printf("]\n");
}

int main() {
    int numeros[] = {
        5, 3, 8, 4, 2,
        115, 113, 118, 114, 112,
        125, 123, 128, 124, 122,
        35, 33, 38, 34, 32,
        45, 43, 48, 44, 42,
        55, 53, 58, 54, 52,
        65, 63, 68, 64, 62,
        75, 73, 78, 74, 72,
        85, 83, 88, 84, 82,
        95, 93, 98, 94, 92,
        15, 13, 18, 14, 12,
        25, 23, 28, 24, 22
    };
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    
    // Exibe a ordem inicial
    printf("A ORDEM INICIAL É: \n");
    exibirNumeros(numeros, tamanho);
    
    // Medindo o tempo de execução do Bubble Sort
    clock_t start, end;
    double cpu_time_used;
    
    start = clock(); // Início da medição do tempo
    bubbleSort(numeros, tamanho);
    end = clock(); // Fim da medição do tempo
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Exibe a ordem final do Bubble Sort
    printf("A ORDEM FINAL APÓS BUBBLE SORT É: \n");
    exibirNumeros(numeros, tamanho);
    printf("Tempo de execução do Bubble Sort: %f segundos\n", cpu_time_used);

    // Resetando o array para o Insertion Sort
    int numerosInsercao[] = {
        5, 3, 8, 4, 2,
        115, 113, 118, 114, 112,
        125, 123, 128, 124, 122,
        35, 33, 38, 34, 32,
        45, 43, 48, 44, 42,
        55, 53, 58, 54, 52,
        65, 63, 68, 64, 62,
        75, 73, 78, 74, 72,
        85, 83, 88, 84, 82,
        95, 93, 98, 94, 92,
        15, 13, 18, 14, 12,
        25, 23, 28, 24, 22
    };

    // Medindo o tempo de execução do Insertion Sort
    start = clock(); // Início da medição do tempo
    insertionSort(numerosInsercao, tamanho);
    end = clock(); // Fim da medição do tempo
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Exibe a ordem final do Insertion Sort
    printf("A ORDEM FINAL APÓS INSERTION SORT É: \n");
    exibirNumeros(numerosInsercao, tamanho);
    printf("Tempo de execução do Insertion Sort: %f segundos\n", cpu_time_used);

    return 0;
}
