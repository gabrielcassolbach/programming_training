#include <bits/stdc++.h>
using namespace std;

#define h 5
#define l 7

// entrada: dois vetores -> peso e valor. ( ou um único vetor que armazena uma struct com dois campos).
int n, w;
int v[4], p[4];
int m[h][l];

void printmatrix(){
    printf("\n matrix: \n");
    for(int i = 0; i < h; i++){
        for(int j = 0; j < l; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
    printf("\n");
}

void mochila(){
    for(int i = 0; i < h; i++) 
        m[i][0] = 0;
    for(int j = 0; j < h; j++)
        m[0][j] = 0;
    printmatrix();
    for(int i = 1; i < h; i++){
        for(int j = 1; j < l; j++){
            if((j < p[i-1]) || (m[i-1][j] >= m[i-1][j-p[i-1]] + v[i-1]))
                {m[i][j] = m[i-1][j]; printf("you didn't pick item a%d\n", i-1);}
            else 
                {m[i][j] = m[i-1][j-p[i-1]] + v[i-1];  printf("you pick item a%d\n", i-1);}
        }
        printmatrix();
    }
    printmatrix();
}

void lerValores(){
    scanf("%d", &n);
    scanf("%d", &w);
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &p[i]);
}

int main(){
    lerValores();
    mochila();
    return 0;
}
