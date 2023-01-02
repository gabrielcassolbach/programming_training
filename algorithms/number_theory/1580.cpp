#include <bits/stdc++.h>
using namespace std;
// Resolução do prof LMZ - Hora Júnior 11.
/*-> (**) A partir de teoremas da teoria dos números, chega-se na função expbin.*/

/* Conteúdos deste problema.
1 - Aritmética Modular.
2 - Inversos multiplicativos módulo primo (PEQUENO TEOREMA DE FERMAT.)
 2.1 - Exponenciação Binária. 
*/

#define MAX 1123 // tamanho máximo da palavra.
#define p 1000000007 

typedef long long ll;

ll expbin(int a, int e){
    if(e == 0) return 1;
    if(e & 1) return (a * expbin(a, e - 1)) % p;
    ll b = expbin(a, e / 2);
    return (b * b) % p;
}

int main(){
    ll fact[MAX], a, b;
    char s[MAX];
    int n, freq[26];// freq 26 -> vetor que armazena a frequência de cada letra.
    fact[0] = 1;
    for(int i = 1; i < MAX; i++) fact[i] = (fact[i - 1] * i) % p;
    while(scanf(" %s", s) != EOF){
        n = strlen(s);
        memset(freq, 0, sizeof(freq)); // "seta todas as posições de freq com zero."
        for(int i = 0; i < n; i++) freq[s[i] - 'A']++; // seto a freq de cada letra.
        a = fact[n]; b = 1;
        for(int i = 0; i < 26; i++) {b *= fact[freq[i]]; b %= p;};
        b = expbin(b, p - 2); // inverso multiplicativo**.
        printf("%lld\n", (a * b) % p); 
    }
    return 0;
}