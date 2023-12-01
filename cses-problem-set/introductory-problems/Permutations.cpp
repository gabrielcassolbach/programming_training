#include <bits/stdc++.h>
using namespace std;

#define MAX 1123456
int v[MAX];

void answer(int n){
    if(n == 3 || n == 2) printf("NO SOLUTION");
    else{
        for(int i = 1; i <= n; i += 2){
            v[i] = 1;
        }
        for(int i = 1; i <= n; i++){
            if(!v[i])
                printf("%d ", i);
        }
        for(int i = 1; i <= n; i++){
            if(v[i])
                printf("%d ", i);
        }
    }    
    printf("\n");
}

void init(){
    for(int i = 0; i < MAX; i++)
        v[i] = 0;
}

int main(){
    int n;
    scanf("%d", &n);
    answer(n);
    return 0;
}