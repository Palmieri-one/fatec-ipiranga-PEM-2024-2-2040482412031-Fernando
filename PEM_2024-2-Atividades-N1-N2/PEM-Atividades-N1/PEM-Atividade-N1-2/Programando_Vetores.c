#include <stdio.h>

#define Total_Max_Notas 9 
#define Total_Max_Testes 9 
//Fernando palmieri Lucas Marum
// Fatec ads tarde segundo semestre tarde
int main () {
    int N,i,min_index,max_index,continuar;
    float notas[Total_Max_Notas],nota,min,max,total_teste,totais_testes[Total_Max_Testes];
    float total_geral = 0;
    int num_testes = 0;
do {
        // Inicializa variáveis para o novo teste
        total_teste = 0;
        min_index = max_index = -1;    
    
    do { 
            printf("\nInsira a quantidade de notas:");
            scanf("%d", &N);

            if (N <= 2) {
                printf("A quantidade de notas deve ser maior que 2\n");
            }
        } while (N <= 2);
            // Coleta as notas que foram inseridas pelo usuario
        for (i = 0; i < N; i++) {
            while (1) { // Loop de garantia para que a nota digitada esteja entre os parametros
                printf("Insira a %dª nota: ", i + 1);
                scanf("%f", &nota);

                if (nota >= 0 && nota <= 10) {
                    break; // Nota válida, sai do loop
                } else {
                    printf("Nota inválida, por favor insira uma nota válida (entre 0 e 10)\n");
                }
            }
            notas[i] = nota;
        }
        // Imprime as notas
        printf("\nNotas que foram inseridas:\n");
        for (i = 0; i < N; i++) {
            printf("%.2f ", notas[i]); 
        }
        printf("\n");

        // Inicializa min e max com o primeiro valor do array
        if (N > 0) {
            min = max = notas[0];
            min_index = max_index = 0;

            // Encontra a menor e a maior nota
            for (i = 1; i < N; i++) {
                if (notas[i] < min) {
                    min = notas[i];
                    min_index = i;
                }
                if (notas[i] > max) {
                    max = notas[i];
                    max_index = i;
                }
            }

            // Verifica se a menor e maior nota foram encontrados
            if (min_index == -1 || max_index == -1) {
                printf("Erro: Não foi possível encontrar a menor ou a maior nota.\n");
                return 1; // Código de erro
            }

            // Cria um novo array para armazenar as notas restantes
            float notas_restantes[Total_Max_Notas];
            int j = 0;

            // Copia as notas, excluindo a menor e a maior
            for (i = 0; i < N; i++) {
                if (i != min_index && i != max_index) {
                    notas_restantes[j++] = notas[i];
                }
            }

            // Atualiza o número de notas restantes
            int N_restantes = j;
            
            // Imprime as notas restantes
            printf("\nNotas restantes (sem a menor e a maior nota):\n");
            for (i = 0; i < N_restantes; i++) {
                printf("%.2f ", notas_restantes[i]);
            }
            printf("\n");
            
            // Calcula o total do teste
            for (i = 0; i < N_restantes; i++) {
                total_teste += notas_restantes[i]; // Adiciona as notas restantes ao total do teste
            }
            
            printf("\nTotal do Teste: %.2f", total_teste);
            
            // Atualiza o total geral e armazena o total do teste
            total_geral += total_teste;
            totais_testes[num_testes] = total_teste;
            num_testes++;

            // Pergunta ao usuário se deseja continuar
            printf("\n\nDeseja realizar outro teste? (1 - Sim, 0 - Não): ");
            scanf("%d", &continuar);


        } else {
            printf("Erro: O array de notas está vazio.\n");
            return 1; // Código de erro
        }
     }while (continuar);

    printf("\n\n===========================================================");
    printf("\n=================== PROGRAMA ENCERRADO ====================");
    printf("\n===========================================================\n");

    // Exibe os totais finais quando o usuário decide parar
    for (i = 0; i < num_testes; i++) {
        printf("Final do teste %d: %.2f\n", i + 1, totais_testes[i]);
    }
    printf("Total Geral: %.2f\n", total_geral);
    printf("Número de Testes: %d\n", num_testes);

    return 0;
}