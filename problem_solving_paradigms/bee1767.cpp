#include <bits/stdc++.h>
using namespace std;

// o peso máximo da mochila é igual a 50kg.

#define MAX 101
#define WEIGHT 51

typedef struct {
    int v; 
    int p;
} Pair;

Pair itens[MAX];
int tc, pac; 
int m[MAX][WEIGHT];

void printmatrix(){
    printf("\n");
    printf("pac is %d\n", pac);
    for(int i = 0; i < pac + 1; i++){
        for(int j = 0; j <= 50; j++)
            printf("%d ",m[i][j]);
        printf("\n");
    }
    printf("\n");    
}

void printAns(int value){
    

}

void answer(){
    int qtd = 0, w = 0;
    for(int i = 0; i <= (pac); i++)
        m[i][0] = 0;
    for(int j = 0; j <= 50; j++)
        m[0][j] = 0;
    for(int i = 1; i <= pac; i++){
        for(int j = 1; j <= 50; j++){
            if((j < itens[i-1].p) || (m[i-1][j] >= m[i-1][j-itens[i-1].p] + itens[i-1].v))
                m[i][j] = m[i-1][j];
            else   
                m[i][j] = m[i-1][j-itens[i-1].p] + itens[i-1].v;
        }
    }
    printAns(m[pac][50]);
}

int main(){
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &pac);
        for(int i = 0; i < pac; i++)
            scanf("%d %d", &itens[i].v, &itens[i].p);
        answer();
    }
    return 0;
}