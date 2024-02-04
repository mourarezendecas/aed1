#include <stdio.h>
#include <stdlib.h>

// Função para comparar elementos (necessária para a função qsort)
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, q;
    int i;
    int j;
    scanf("%d", &n);

    int xi[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &xi[i]);
    }

    // Ordena os preços das lanchonetes em ordem crescente
    qsort(xi, n, sizeof(int), compare);

    scanf("%d", &q);

    for (i = 0; i < q; i++) {
        int mi;
        scanf("%d", &mi);

        int count = 0;
        int lanchonetes_compraveis[n];

        // Verifica quantas lanchonetes podem ser compradas com o valor mi
        for (j = 0; j < n; j++) {
            if (xi[j] <= mi) {
                lanchonetes_compraveis[count++] = j + 1;
                mi -= xi[j];
            }
        }

        // Imprime o resultado para o i-ésimo dia
        printf("%d", count);
        for (j = 0; j < count; j++) {
            printf(" %d", lanchonetes_compraveis[j]);
        }
        printf("\n");
    }

    return 0;
}
