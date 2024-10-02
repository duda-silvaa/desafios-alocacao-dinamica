#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanhoInicial, novoTamanho;
    float *vetor;  // Ponteiro para o vetor
    int opcao;

    // Solicita o tamanho inicial do vetor
    printf("Digite o tamanho inicial do vetor: ");
    scanf("%d", &tamanhoInicial);

    // Aloca dinamicamente a mem�ria para o vetor
    vetor = (float *)malloc(tamanhoInicial * sizeof(float));

    if (vetor == NULL) {
        printf("Erro ao alocar mem�ria!\n");
        return 1;
    }

    // Solicita os valores para o vetor
    printf("Informe os %d n�meros reais:\n", tamanhoInicial);
    for (int i = 0; i < tamanhoInicial; i++) {
        scanf("%f", vetor +i);
    }

    // Imprime os valores positivos do vetor
    printf("Valores positivos:\n");
    for (int i = 0; i < tamanhoInicial; i++) {
        if (*(vetor+i) > 0) {
            printf("%.2f\n", *(vetor+i));
        }
    }

    // Pergunta se o usu�rio deseja aumentar o tamanho do vetor
    printf("Deseja aumentar o tamanho do vetor? (sim - 1 nao - 0/n): ");
    scanf(" %d", &opcao);

    if (opcao == 1) {
        // Solicita o novo tamanho do vetor
        printf("Digite o novo tamanho do vetor: ");
        scanf("%d", &novoTamanho);

        // Realoca a mem�ria para o vetor
        vetor = (float *)realloc(vetor, novoTamanho * sizeof(float));

        if (vetor == NULL) {
            printf("Erro ao realocar mem�ria!\n");
            return 1;
        }

        // Solicita os novos valores para completar o vetor
        printf("Informe os novos n�meros reais:\n");
        for (int i = 0; i < novoTamanho; i++) {
            scanf("%f", vetor+i);
        }
    }

    // Imprime todos os valores positivos novamente
    printf("Valores positivos ap�s atualiza��o:\n");
    for (int i = 0; i < novoTamanho; i++) {
        if (*(vetor+i) > 0) {
            printf("%.2f\n", *(vetor+i));
        }
    }

    // Libera a mem�ria alocada dinamicamente
    free(vetor);

    return 0;
}

