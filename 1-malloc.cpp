#include <stdio.h>
#include <stdlib.h>

int main() {
    int quantidade;  // Quantidade de n�meros que o usu�rio vai informar
    float media = 7.0;  // M�dia definida (7.0)

    // Solicita a quantidade de n�meros
    printf("Digite a quantidade de n�meros que deseja informar: ");
    scanf("%d", &quantidade);

    // Aloca dinamicamente a mem�ria para o n�mero de elementos
    float *numeros = (float *)malloc(quantidade * sizeof(float));

    if (numeros == NULL) {
        printf("Erro ao alocar mem�ria!\n");
        return 1;
    }

    // Solicita os n�meros ao usu�rio
    printf("Informe os %d n�meros:\n", quantidade);
    for (int i = 0; i < quantidade; i++) {
        scanf("%f", &numeros[i]);
    }

    // Exibe os n�meros que est�o acima da m�dia
    printf("N�meros acima da m�dia %.1f:\n", media);
    for (int i = 0; i < quantidade; i++) {
        if (numeros[i] > media) {
            printf("%.2f\n", numeros[i]);
        }
    }

    // Libera a mem�ria alocada dinamicamente
    free(numeros);

    return 0;
}

