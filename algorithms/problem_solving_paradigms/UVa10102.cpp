#include "bits/stdc++.h"
using namespace std;
#define MAX 12345

// The path in the colored field. -> UVa10102.

char field[MAX][MAX]; int c_field[MAX][MAX];

void print_field(int n){
    for(int i = 0; i < n; i++){
        printf("\n");
        for(int j = 0; j < n; j++)
            printf("%d ", c_field[i][j]);
    }
    printf("\n");
}

void create_field (int n){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            c_field[i][j] = (int) (field[i][j] - '0');  
}

int get_distance(int i, int j, int k, int n) 
    {return (fabs(k - i) + fabs(n - j));}

int check(int size, int i, int j){
    int d = 0, min_path = size*size; // d = 0 & min_path = 15*15.
    for(int k = 0; k < size; k++)
        for(int n = 0; n < size; n++)
            if(c_field[k][n] == 3)
                {d = get_distance(i, j, k, n); min_path = min(min_path, d);} 
    return min_path;
}

int best_path(int size, int best_distance){
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            if(c_field[i][j] == 1) 
                best_distance = max(check(size, i, j), best_distance); 
    return best_distance;
}

int main(){
    int size, best_distance;
    while(scanf("%d", &size) != EOF){
        for(int i = 0; i < size; i++)
            for(int j = 0; j < size; j++)
                { if(!j) scanf("\n%c", &field[i][j]);
                  else   scanf("%c", &field[i][j]); }
        create_field(size); //print_field(size);
        best_distance = 0;  printf("%d\n", best_path(size, best_distance));
    }
    return 0;
}

