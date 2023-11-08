#include <bits/stdc++.h>
using namespace std;

// o peso máximo da mochila é igual a 50kg.

#define MAX 101
#define WEIGHT 51

int v[MAX], p[MAX], m[MAX][WEIGHT];

void initMatrix(){
    for(int i = 0; i <= MAX; i++)
        for(int j = 0; j <= 50; j++)
            m[i][j] = -1;
}

int mochila(int i, int j){
    if(!i || !j) 
        {m[i][j] = 0; return m[i][j];}
    if(m[i][j] != -1) 
        return m[i][j];
    if(j < p[i-1])
        m[i][j] = mochila(i-1, j);
    else 
        m[i][j] = max(mochila(i-1, j), mochila(i-1, j-p[i-1]) + v[i-1]);
    return m[i][j];
}
    
void printAns(int i, int j){
    int valor = mochila(i, j);  
    printf("%d brinquedos\n", valor);
    printf("Peso: %d kg\n", 0);
    printf("sobra(m) %d pacote(s)\n\n", 0);
}

int main(){
    int n; scanf("%d", &n);
    while(n--){
        initMatrix();
        int pac; scanf("%d", &pac);
        for(int i = 0; i < pac; i++)
            scanf("%d %d", &v[i], &p[i]);
        printAns(pac, 50);
    }   
    return 0;
}
