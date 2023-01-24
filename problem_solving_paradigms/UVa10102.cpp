#include "bits/stdc++.h"
using namespace std;
#define MAX 12345

// The path in the colored field. -> UVa10102.

int field[MAX][MAX], input[MAX];
stack<int> s; stack<int> u;

void decompose(int n){
    printf("Começou a decompor\n");
    for(int i = 0; i < n; i++){        
        while(input[i]){
            s.push(input[i] % 10);
            input[i] /= 10;
        }
        printf("\n");
    }
}

void create_field(int n){
    printf("Entrou no create_field\n");
    decompose(n);
    printf("CREATE FIELD");
    for(int i = n - 1; i >= 0; i--)
        for(int j = 0; j < n; j++)
            {field[i][j] = s.top(); s.pop();}
    printf("Criou.\n");
}

int get_distance(int i, int j, int k, int n) 
    {return fabs((k - i) + (n - j));}

int check(int size, int i, int j){
    int d = 0, min_path = size*size;
    for(int k = 0; k < size; k++)
        for(int n = 0; n < size; n++)
            if(field[k][n] == 3)
                {d = get_distance(i, j, k, n); min_path = min(min_path, d);} 
    return min_path;
}

int best_path(int size, int best_distance){
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            if(field[i][j] == 1) 
                best_distance = max(check(size, i, j), best_distance); 
    return best_distance;
}

int main(){
    int size, best_distance;
    while(scanf("%d", &size) != EOF){
        for(int i = 0; i < size; i++)
                scanf("%d", &input[i]);
        printf("Leu todo o input!\n");
        create_field(size);
        printf("created field\n");
        best_distance = 0;  printf("%d\n", best_path(size, best_distance));
    }
    return 0;
}

