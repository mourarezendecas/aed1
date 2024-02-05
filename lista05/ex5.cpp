#include <iostream>
 
using namespace std;
 
int main() {
    int T;
    cin >> T;
 
    while (T--) {
        int n, k;
        cin >> n >> k;
 
        char mapa[1000][1000];
 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> mapa[i][j];
            }
        }
 
        int maxL = 0;
 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mapa[i][j] == 'D') {
 
                    bool capturado = false; 
                    for (int l = max(0, j - k); l <= min(n - 1, j + k); ++l) {
                        if (mapa[i][l] == 'L' && l != j) {
                            mapa[i][l] = 'C';
                            maxL++;
                            capturado = true;
                            break;
                        }
                    }
 
                    if (capturado) {
                        continue;
                    }
 
                    for (int l = max(0, i - k); l <= min(n - 1, i + k); ++l) {
                        if (mapa[l][j] == 'L' && l != i) {
                            mapa[l][j] = 'C';
                            maxL++;
                            break;
                        }
                    }
                }
            }
        }
 
        cout << maxL << endl;
    }
 
    return 0;
}