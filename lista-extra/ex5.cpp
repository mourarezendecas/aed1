    #include <stdio.h>
     
    int contarDigitosIguaisK(int n, int k) {
        if (n == 0) {
            return 0;
        }
     
        int ultimoDigito = n % 10;
        int contagemAtual = (ultimoDigito == k) ? 1 : 0;
     
        return contagemAtual + contarDigitosIguaisK(n / 10, k);
    }
     
    int main() {
        int t;
        scanf("%d", &t);
     
        for (int i = 0; i < t; ++i) {
            int k;
            scanf("%d", &k);
     
            int n;
            int contagem;
     
            while (scanf("%d", &n) != EOF) {
                contagem = contarDigitosIguaisK(n, k);
                printf("%d ", contagem);
            }
     
            printf("\n");
        }
     
        return 0;
    }