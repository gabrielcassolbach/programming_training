#include <bits/stdc++.h>
using namespace std;

// o peso máximo da mochila é igual a 50kg.

#define MAX 101
#define WEIGHT 51

typedef struct {
    int peso;
    int items_r;
} Par;

int v[MAX], p[MAX], m[MAX][WEIGHT];

void printMatrix(int i,int j){
    for(int k = 0; k <= i; k++){
        for(int g = 0; g <= j; g++){
            if(m[k][g] >= 0)
                printf("+%d", m[k][g]);
            else 
                printf("%d", m[k][g]);
        }
        printf("\n");
    }

} 

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
    
Par peso(int i, int j){
    //printMatrix(i, j);
    Par ans; ans.peso = 0; ans.items_r = i;
    int choice = m[i][j];
    for(int k = i-1; k >= 0; k--){
        //printf("%d\n", choice);
        if(choice != m[k][j] and ans.peso + p[k] <= 50)
            {j -= p[k]; choice = m[k][j]; ans.peso += p[k]; ans.items_r--;}
        else
            {choice = m[k][j];}
    }
    return ans;
}

void printAns(int i, int j){
    int valor = mochila(i, j);
    Par ans = peso(i, j);
    printf("%d brinquedos\n", valor);
    printf("Peso: %d kg\n", ans.peso);
    printf("sobra(m) %d pacote(s)\n\n", ans.items_r);
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
