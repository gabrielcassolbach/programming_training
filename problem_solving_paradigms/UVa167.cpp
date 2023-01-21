#include <bits/stdc++.h>
using namespace std;
#define N 8
// The Sultan Sucessor.

/*
Input: 
-> k boards (maximum number of boards is 20);
-> k sets of 64 numbers {matrix 8x8}, all positive integers less than 100;
Output:
-> k numbers, consisting k scores. 
(each score on a line by itself and right justified in a field 5 characters wide).
*/

int board[N][N]; int row[N];
int best_score;

int total(){
    int total = 0;
    for(int i = 0; i < N; i++)  
        total += board[row[i]][i];
    return total;
}

bool place(int r, int c){
    for(int prev = 0; prev < c; prev++)
        if(row[prev] == r || (abs(row[prev] - r)) == abs(prev - c))
            return false;
    return true;
}

// c represents the columns.
void backtrack(int c){
    if(c == N){
        int value = total();
        if(value > best_score) best_score = value;
    }
    for(int r = 0; r < N; r++)
        if(place(r, c))
            {row[c] = r; backtrack(c + 1);}
}

int justify(){
    int value = best_score;
    int cont = 0;
    while(value > 0){
        cont++;
        value = value/10;
    }    
    return cont;
}

int main(){
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        memset(row, 0, sizeof row); best_score = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                scanf(" %d", &board[i][j]);
        backtrack(0); 
        for(int i = 0; i < (5 - justify()); i++) printf(" ");
        printf("%d\n", best_score);
    }
    return 0;
}
