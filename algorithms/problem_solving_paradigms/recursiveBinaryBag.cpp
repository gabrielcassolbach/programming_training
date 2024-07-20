#include <bits/stdc++.h>
using namespace std;

#define MAX 1123

int v[MAX], p[MAX], m[MAX][MAX];
int n, w;

void printMatrix(){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= w; j++){
            if(m[i][j] >= 0)
                printf("+%d ", m[i][j]);
            else 
                printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void init(){
    scanf("%d", &n);
    scanf("%d", &w);
    for(int i = 1; i <= n; i++) 
        scanf("%d", &v[i]);
    for(int i = 1; i <= n; i++) 
        scanf("%d", &p[i]);
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= w; j++)
            m[i][j] = -1;
}

int mochila(int i, int j){
    if(!i || !j) 
        {m[i][j] = 0; return m[i][j];} // caso base.
    if(m[i][j] != -1) 
        return m[i][j];
    if(j < p[i])
        m[i][j] = mochila(i-1, j);
    else 
        m[i][j] = max(mochila(i-1, j), mochila(i-1, j-p[i]) + v[i]);
    return m[i][j];
}

int main(){
    init();
    printf("%d\n", mochila(4, 6));
    printMatrix();
    return 0;
}

