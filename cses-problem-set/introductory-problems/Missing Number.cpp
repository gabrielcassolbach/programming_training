#include <bits/stdc++.h>
using namespace std;

#define MAX 212345

int v[MAX], n;

void init(){
    scanf("%d", &n);
    for(int i = 0; i <= n; i++)
        v[i] = 0;
}

int main(){
    init();
    for(int i = 0; i < n; i++){
        int value; scanf("%d", &value);
        v[value] = 1;
    }
    for(int i = 1; i <= n; i++)
        if (v[i] == 0)
            printf("%d\n", i);
    return 0;
}