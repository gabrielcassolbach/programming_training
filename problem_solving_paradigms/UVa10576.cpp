// Y2K Accounting Bug.
// Hints: Generate all, prune, take max.
// Primeira tentativa: começando a entender o problema.

#include <bits/stdc++.h>
using namespace std;

#define MAX 12

int month[MAX];

void backtrack(int s, int d, int m){}

int surplus(int s, int d){
    backtrack(s, d, 0);
    // use the array to return -1 if you have in the best_path a deficit.
    // or the surplus of the year.
}

void set_parameters() {memset(month, 0, sizeof month);}

int main(){
    int s, d; int total;
    while(scanf("%d", &s) != EOF){
        scanf("%d", &d);
        set_parameters();
        total = surplus(s, d);
        if(total >= 0) printf("%d\n", total);
        else printf("Deficit\n");
    }
    return 0;
}