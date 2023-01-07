#include "bits/stdc++.h"
using namespace std;
#define MAX 20

/*
t -> número de casos de teste.
n -> tamanho da barra. 
p -> número de barras.
v -> vetor de barras.
*/

bool bars_check(int n, int p, int* v){
    int sum = 0;
    for(int i = 0; i < p; i++){
        
    }


}   

int main(){
    int t, n, p;
    int v[MAX];
    scanf("%d", &t);
    while(t--){
        scanf("%d\n%d", &n, &p);
        for(int i = 0; i < p; i++)
            scanf("%d", &v[i]);
        if(bars_check(n, p, v)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}