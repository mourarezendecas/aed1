#include <stdio.h>

void generateMagicSquare(int n) {
    if (n == 2) {
        printf("nao existe\n");
        return;
    }

    int magicSquare[n][n];
    int i, j;

    // Inicializa a matriz com todos os elementos como 0
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            magicSquare[i][j] = 0;

    // Inicializa as variáveis para a primeira posição
    i = n / 2;
    j = n - 1;
    int num;

    // Preenche a matriz com números de 1 a n^2
    for (num = 1; num <= n * n;) {
        if (i == -1 && j == n) {
            j = n - 2;
            i = 0;
        } else {
            // Wrap around na coluna
            if (j == n)
                j = 0;

            // Wrap around na linha
            if (i < 0)
                i = n - 1;
        }

        if (magicSquare[i][j] != 0) {
            j -= 2;
            i++;
            continue;
        } else
            magicSquare[i][j] = num++;

        j++;
        i--;
    }

    // Imprime a matriz mágica
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", magicSquare[i][j]);
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    generateMagicSquare(n);

    return 0;
}
