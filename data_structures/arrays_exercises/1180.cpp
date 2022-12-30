#include <bits/stdc++.h>
using namespace std;

/* Faça um programa que leia um valor N. Este N será o tamanho de um 
vetor. A seguir leia todos os valores do vetor.

obs: não haverão números repetidos.

Saída: imprima o menor valor e sua posição relativa ao vetor.

N -> (1, 1000)
*/

int main(){
    int n, x; 
    int smaller = (INT_MAX); int pos = -1;
    vector<int> v;
    scanf("%d", &n);
    int i = -1;   
    while(n--){
        i++; 
        scanf("%d", &x);
        v.push_back(x);
        //printf("%d %d \n", v[i], i);
        if(v[i] <= smaller) {smaller = v[i]; pos = i;} 
    }
    printf("Menor valor: %d\n", smaller);
    printf("Posicao: %d\n", pos);
    return 0;
}