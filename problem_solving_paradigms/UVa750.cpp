#include <bits/stdc++.h>
using namespace std;

// Backtracking Example - HALIM | HALIM.
 
int row[8], TC, a, b, lineCounter;

bool place(int r, int c){
    for(int prev = 0; prev < c; prev++) // check previously placed queens.
        if(row[prev] == r || (abs(row[prev] - r)) == abs(prev - c)) // 1 == 1
            return false; // share same row or same diagonal.
    return true;
} 

void backtrack(int c){
    if(c == 8 && row[b] == a){ // candidate sol, (a, b) has 1 queen.     
        printf("%2d        %d", ++lineCounter, row[0] + 1);
        for(int j = 1; j < 8; j++) printf(" %d", row[j] + 1);
        printf("\n");
    }
    for(int r = 0; r < 8; r++) // try all possible row.
        if(place(r, c)) // if can place a queen at this col and row.
            {row[c] = r; backtrack(c + 1);} // put this queen here and recurse.
}       

int main(){
    scanf("%d", &TC);
    while(TC--){
        scanf("%d %d", &a, &b); a--; b--; // row starts at 0.
        memset(row, 0, sizeof row); lineCounter = 0; // set all row values to 0.
        printf("SOLN        COLUMN\n");
        printf(" #        1 2 3 4 5 6 7 8\n\n");
        backtrack(0); // Generate all possible 8! candidate solutions.
        if(TC) printf("\n");
    }
    return 0;
}