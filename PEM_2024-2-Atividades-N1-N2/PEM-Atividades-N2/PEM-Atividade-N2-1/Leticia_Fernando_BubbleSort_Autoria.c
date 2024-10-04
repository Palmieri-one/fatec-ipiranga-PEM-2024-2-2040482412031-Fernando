/*-------------------------------------------------------------*
* Disciplina: Programação Estruturada e Modular                *
*          Prof. Carlos Veríssimo                              *
*--------------------------------------------------------------*
* Objetivo do Programa: BUBBLE SORT                            *
*                                                              *
* Data: 27/09/2024                                             * 
* Autor: Letícia Sudan Gauy e Fernando Palmieri                *
*--------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>  

// Função para ler números
void lerNumeros(int *numeros, int tamanho){
    printf("Digite %d números: ", tamanho);
    for (int i = 0; i < tamanho; i++) {
        scanf("%i", &numeros[i]);
    }
}

// Função para exibir os números
void exibirNumeros(int *numeros, int tamanho){
    printf("[ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%i ", numeros[i]);
    }
    printf("]\n");
}

// Função para ordenar os números usando Bubble Sort
void bubbleSort(int *numeros, int tamanho){
    int temporaria;
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1; j++) {
            if (numeros[j] > numeros[j + 1]) {
                // Faz a comparação dos números
                temporaria = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temporaria;
            }
        }
    }
}

int main() {
    int tamanho;
    
    // Lê o tamanho do array inserido pelo usuário
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);
    
    // Aloca memória para o array
    int *numeros = malloc(tamanho * sizeof(int));
    if (numeros == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;  
    }
    
    // Lê os números inseridos pelo usuário
    lerNumeros(numeros, tamanho);
    
    // Exibe a ordem inicial
    printf("\nA ORDEM INICIAL É: ");
    exibirNumeros(numeros, tamanho);
    
    // Ordena os números
    bubbleSort(numeros, tamanho);
    
    // Exibe a ordem final
    printf("A ORDEM FINAL É: ");
    exibirNumeros(numeros, tamanho);

    // Libera a memória alocada
    free(numeros);
    
    return 0;
}
