#include <stdio.h>

// Função para calcular o máximo divisor comum (MDC)
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Função para realizar a enumeração de números racionais
void rationalsEnumeration(int n) {
    int count = 0;
    
    for (int d = 1; ; ++d) {
        for (int num = 0; num <= d; ++num) {
            if (gcd(num, d) == 1) {
                ++count;
                if (count == n) {
                    printf("%d/%d\n", num, d);
                    return; // Encerra a enumeração após encontrar o número desejado
                }
            }
        }
    }
}

int main() {
    int k;
    while (1) {
        scanf("%d", &k);
        if (k == 0) {
            break;
        }
        rationalsEnumeration(k);
    }

    return 0;
}
