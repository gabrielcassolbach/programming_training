#include <bits/stdc++.h>
using namespace std;

#define MAX 1123

int n, v[MAX], table[MAX];

void read(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
}

void initMemory(){
    for(int i = 0; i <= n; i++)
        table[i] = -1;
}

int mostCoins(int k){
    if(!k) // caso base -> definição de parada.
        {table[k] = 0; return table[k];}
    if(table[k] != -1) // se já foi computado, utilize a memória.
        return table[k];
    table[k] = max(mostCoins(k-1), mostCoins(k-2) + v[k]); // escolha à cada iteração.
    return table[k];
}

int main(){
    read();
    initMemory();
    printf("%d\n", mostCoins(n));
    return 0;
}

