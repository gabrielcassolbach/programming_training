// fibonnacci recursivo utilizando programação dinâmica.
#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

int table[MAX];
int n;

void init(){
    scanf("%d", &n);
    for(int i = 0; i < MAX; i++) 
        table[i] = -1;
    table[1] = 0;
    table[2] = 1; 
}

int fibonnacci(int n){
    if(n == 1) return table[1];
    if(n == 2) return table[2];
    if(table[n] == -1)
        return table[n] = fibonnacci(n-1) + fibonnacci(n-2);
}

int main(){
    init();
    printf("%d\n", fibonnacci(n));
    for(int i = 0; i < n; i++) 
        printf("%d ", table[i]);
    return 0;
}