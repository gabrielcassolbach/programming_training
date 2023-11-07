// problem set: PAAS73-2023/2.
// voltar.
#include <bits/stdc++.h>
using namespace std;

int n, w;
int v[4], p[4];
int m[5][7];

void printMatrix(){
    for(int i = 0; i <= 4; i++){
        for(int j = 0; j <= 6; j++){
            if(m[i][j] >= 0)
                printf("+%d ", m[i][j]);
            else  
                printf("%d ", m[i][j]);   
        }
        printf("\n");
    }
    printf("\n");
}

int mochila(int i, int j){
    
}

void initMatrix(){
    for(int i = 0; i <= 4; i++)
        for(int j = 0; j <= 6; j++)
            m[i][j] = -1;
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
    initMatrix();
    printf("valor da mochila: %d\n", mochila(4, 6)); 
    printMatrix();
    return 0;
}
