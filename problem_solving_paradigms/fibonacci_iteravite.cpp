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

void fibonacci(){
    for(int i = 3; i <= n; i++)
        table[i] = table[i-1] + table[i-2];
}

int main(){
    init();
    fibonacci();
    printf("%d\n", table[n]);
    return 0;
}