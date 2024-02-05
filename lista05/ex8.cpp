#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int a2[n];
    long acumulado = 1;

    for(int i = 0; i < n; i++) {
        cin >> a[n];
        acumulado = a[n];
    }
    int cont = 1;
    long maior = 1;
    while(1) {
        maior=1;
        for(int i = 0; i < n; i++) {
            maior= cont;
        }



        if(maior > acumulado) {
            break;
        }
        cont++;
    }

    for(int i = 0; i < n; i++) {
        a2[i] = cont;
        cout << a2[i] << " ";
    }
    cout << endl;

    return 0;
}