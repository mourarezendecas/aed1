#include <stdio.h>
#include <stdlib.h>

// Função para comparar elementos para a função qsort
int compara(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, q;
    scanf("%d", &n);

    int *precos = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &precos[i]);
    }

    // Ordena o array de preços
    qsort(precos, n, sizeof(int), compara);

    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int m;
        scanf("%d", &m);

        int lanchonetes_possiveis = 0;
        int *lanchonetes = (int *)malloc(n * sizeof(int));

        // Verifica em quantas lanchonetes John Byte pode comprar
        for (int j = 0; j < n; j++) {
            if (precos[j] <= m) {
                lanchonetes[lanchonetes_possiveis] = j + 1;
                lanchonetes_possiveis++;
            }
        }

        // Imprime o resultado
        printf("%d", lanchonetes_possiveis);
        for (int j = 0; j < lanchonetes_possiveis; j++) {
            printf(" %d", lanchonetes[j]);
        }
        printf("\n");

        free(lanchonetes);
    }

    free(precos);

    return 0;
}
