#include <stdio.h>

int main() {
    int T;  // Número de casos de teste
    scanf("%d", &T);

    while (T--) {
        int n, k;
        scanf("%d %d", &n, &k);

        char minimundo[n][n];
        int maxL = 0;

        // Leitura do minimundo
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf(" %c", &minimundo[i][j]);
            }
        }

        // Verificação do número máximo de ladrões presos
        for (int i = 0; i < n; i++) {
            int policialIndex = -1;
            for (int j = 0; j < n; j++) {
                if (minimundo[i][j] == 'P') {
                    policialIndex = j;
                } else if (minimundo[i][j] == 'L' && policialIndex != -1 && j - policialIndex <= k) {
                    maxL++;
                    break;
                }
            }
        }

        // Impressão da saída
        printf("%d\n", maxL+1);
    }

    return 0;
}
