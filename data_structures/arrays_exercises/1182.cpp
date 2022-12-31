#include <bits/stdc++.h>
using namespace std;
#define SIZE 12

int main(){
    int coluna; 
    char op;
    float sum = 0, m[SIZE][SIZE];

    scanf("%d\n", &coluna); scanf("%c", &op);

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            scanf("%f", &m[i][j]);
            //printf("%f\n", m[i][j]);
        }
    }

    for(int i = 0; i < SIZE; i++) {
        //printf("%d %d\n", i, coluna);
        sum += m[i][coluna];    
    }

    if(op == 'S')
        printf("%.1f\n", sum);
    else
        printf("%.1f\n", (sum/(float)SIZE));    

    return 0;
}