#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int buscaBinariaRecursiva(int procurado, int *v, int inicio, int fim) {
    if (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (procurado == v[meio]) {
            if(meio-1<0){
                return 1;
            }
            return meio; // Elemento encontrado, retorna a posição
        } else if (procurado < v[meio]) {
            return buscaBinariaRecursiva(procurado, v, inicio, meio - 1);
        } else {
            return buscaBinariaRecursiva(procurado, v, meio + 1, fim);
        }
    }

    return -1; // Elemento não encontrado
}

int main() {
    int i, j;
    int t, u, w;
    int **v;
    int *k;
    int valor;
    int aux;

    scanf("%d", &t);

    v = (int **)malloc(t * sizeof(int *));
    k = (int *)malloc(t * sizeof(int));

    // Vetor para armazenar os resultados da busca binária
    int *resultados = (int *)malloc(t * sizeof(int));

    for (i = 0; i < t; i++) {
        v[i] = (int *)malloc(sizeof(int)); // Começa com um espaço

        scanf("%d", &k[i]); // Valor de k para o caso de teste i

        u = 0; // Número de entradas para o caso de teste i

        while (1) {
            scanf("%d", &valor);

            if (valor == -1) {
                break;
            }

            v[i] = (int *)realloc(v[i], (u + 1) * sizeof(int));
            v[i][u] = valor;
            u++;
        }
        // Aplicar Bubble Sort ao vetor v[i]

        for (j = 0; j < u - 1; j++) {
            for (w = 0; w < u - j - 1; w++) {
                if (v[i][w] > v[i][w + 1]) {
                    // Troca os elementos de lugar
                    aux = v[i][w];
                    v[i][w] = v[i][w + 1];
                    v[i][w + 1] = aux;
                }
            }
        }

        // Aplicar busca binária e armazenar o resultado
        resultados[i] = buscaBinariaRecursiva(k[i], v[i], 0, u - 1);
    }

    // Imprimir os resultados da busca binária
    for (i = 0; i < t; i++) {
        if (resultados[i] != -1) {
            printf("%d\n", resultados[i]);
        } else {
            printf("ausente\n");
        }
    }

    // Liberar memória alocada
    for (i = 0; i < t; i++) {
        free(v[i]);
    }
    free(v);
    free(k);
    free(resultados);

    return 0;
}