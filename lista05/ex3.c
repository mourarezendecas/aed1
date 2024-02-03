    #include <stdio.h>
     
    int main() {
        int T;
        scanf("%d", &T);
        int i;
        int j;
     
        int results[T];
     
        for(j=0;i<T;i++){
            char s[10001];
            scanf(" %[^\n]", s);
     
            int count = 0;
            for (i = 0; s[i] != '\0'; i++) {
                // Check if the current character is a vowel
                if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' ||
                    s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                    count++;
                }
            }
            results[j] = count;
        }
     
        for(i=0;i<T;i++){
            printf("%d\n",results[i]);
        }
     
        return 0;
    }