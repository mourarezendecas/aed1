    #include <stdio.h>
    #include <stdbool.h>
     
    bool ehPrimo(int num) {
        int i; 
        if (num < 2) {
            return false;
        }
     
        for (i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
     
        return true;
    }
     
    int main() {
        int n;
        scanf("%d", &n);
        int i;
     
        // Construindo a lista de números primos de 2 até n
        int primos[10000]; // Supomos que n não ultrapasse 10000
        int p = 0;
        for (i = 2; i <= n; i++) {
            if (ehPrimo(i)) {
                primos[p] = i;
                p++;
            }
        }
     
        // Lendo x e y
        int x, y;
        scanf("%d %d", &x, &y);
     
        // Imprimindo os primos na posição x até y
        for (i = x - 1; i < y; i++) {
            printf("%d ", primos[i]);
        }
     
        return 0;
    }