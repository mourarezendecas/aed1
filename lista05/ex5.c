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
            int caoIndex = -1;

            // Verifica na linha i
            for (int j = 0; j < n; j++) {
                if (minimundo[i][j] == 'D') {
                    policialIndex = j;
                } else if (minimundo[i][j] == 'L' && policialIndex != -1 && j - policialIndex <= k) {
                    maxL++;
                    break;
                }
            }

            // Verifica na coluna i
            for (int j = 0; j < n; j++) {
                if (minimundo[j][i] == 'D') {
                    caoIndex = j;
                } else if (minimundo[j][i] == 'L' && caoIndex != -1 && j - caoIndex <= k) {
                    maxL++;
                    break;
                }
            }
        }

        // Impressão da saída
        printf("%d\n", maxL-1);
    }

    return 0;
}
