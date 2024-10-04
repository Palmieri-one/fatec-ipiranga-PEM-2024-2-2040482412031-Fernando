#include <stdio.h>

void ordenarBubble(int vetor[], int tamanho) {
    int indiceExterno, indiceInterno, temporario;
    int houveTroca;
    for (indiceExterno = 0; indiceExterno < tamanho-1; indiceExterno++) {
        houveTroca = 0;
        for (indiceInterno = 0; indiceInterno < tamanho-indiceExterno-1; indiceInterno++) {
            if (vetor[indiceInterno] > vetor[indiceInterno+1]) {
                temporario = vetor[indiceInterno];
                vetor[indiceInterno] = vetor[indiceInterno+1];
                vetor[indiceInterno+1] = temporario;
                houveTroca = 1;
            }
        }
        if (houveTroca == 0)
            break;
    }
}

void imprimirArray(int arr[], int tamanho) {
    printf("Elementos do array: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void inserirDados(int arr[], int tamanho) {
    printf("Digite %d números:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &arr[i]);
    }
}

int main() {
    int tamanho;
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int arr[tamanho];
    inserirDados(arr, tamanho);

    printf("Array original: \n");
    imprimirArray(arr, tamanho);

    ordenarBubble(arr, tamanho);

    printf("Array ordenado: \n");
    imprimirArray(arr, tamanho);

    return 0;
}
