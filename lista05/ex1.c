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
    int d;
    int num;
    
    for (d = 1; ; ++d) {
        for (num = 0; num <= d; ++num) {
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
    int size = 5000;
    int vetor[size];
    int k;
    int i = 0;
    int j; 
    while (1) {
        scanf("%d", &k);
        if (k == 0) {
            break;
        }
        else{
            vetor[i] = k;
            i++;
        }
    }

    for(j=0;j<i;j++){
        rationalsEnumeration(vetor[j]);
    }

    return 0;
}
