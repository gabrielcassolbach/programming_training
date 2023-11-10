#include <bits/stdc++.h>
using namespace std;

/*
Entrada: duas strings (A e B).
Saída: máxima subsequência comum entre A e B.
*/

#define MAX 1123

int m, n, table[MAX][MAX], values[MAX][MAX];
char a[MAX], b[MAX];

void print(){
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++)
            printf("%d ", table[i][j]);
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++)
            printf("%d ", values[i][j]);
        printf("\n");
    }
}

void lerValores(){
    scanf("%d %d", &m, &n);
    printf("m: %d & n: %d\n", m, n);
    for(int i = 1; i <= m; i++)
        {scanf(" %c", &a[i]); printf("%c", a[i]);}
    printf("\n");
    for(int j = 1; j <= n; j++)
        {scanf(" %c", &b[j]); printf("%c", b[j]);}
    printf("\n\n");
}

void lcs(){
    for(int i = 0; i <= m; i++)
        table[i][0] = 0;
    for(int i = 0; i <= n; i++)
        table[0][i] = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(a[i] == b[j])
                {table[i][j] = table[i-1][j-1] + 1; values[i][j] = 3;}
            else if(table[i-1][j] >= table[i][j-1])
                {table[i][j] = table[i-1][j]; values[i][j] = 2;}
            else 
                {table[i][j] = table[i][j-1]; values[i][j] = 1;}
        }
    }
}

void printSeq(int m, int n){
    if(m == 0 || n == 0) return;
    printf("(%d %d)\n", m, n);
    if(values[m][n] == 3) 
        {printf("%c\n", a[m]); printSeq(m-1, n-1);}
    else if(values[m][n] == 2) 
        {printSeq(m-1, n);}
    else 
        {printSeq(m, n-1);}
}

int main(){
    lerValores();
    lcs();
    print();
    printSeq(m, n);
    return 0;
}





