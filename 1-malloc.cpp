#include <stdio.h>
#include <stdlib.h>

int main() {
    int quantidade;  // Quantidade de números que o usuário vai informar
    float media = 7.0;  // Média definida (7.0)

    // Solicita a quantidade de números
    printf("Digite a quantidade de números que deseja informar: ");
    scanf("%d", &quantidade);

    // Aloca dinamicamente a memória para o número de elementos
    float *numeros = (float *)malloc(quantidade * sizeof(float));

    if (numeros == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Solicita os números ao usuário
    printf("Informe os %d números:\n", quantidade);
    for (int i = 0; i < quantidade; i++) {
        scanf("%f", &numeros[i]);
    }

    // Exibe os números que estão acima da média
    printf("Números acima da média %.1f:\n", media);
    for (int i = 0; i < quantidade; i++) {
        if (numeros[i] > media) {
            printf("%.2f\n", numeros[i]);
        }
    }

    // Libera a memória alocada dinamicamente
    free(numeros);

    return 0;
}

