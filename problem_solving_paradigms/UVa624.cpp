#include <bits/stdc++.h>
using namespace std;

#define MAX 20

//      (CD - 624)
// ---------------------------------------------------
int CD[MAX];
int n, tracks, best_track, delta, id;

void print_answer(int value){
    printf("sum: %d\n", value);
}

bool best_option(int sum){
    if(fabs(sum - n) <= delta)
        {delta = fabs(sum - n); return true;}   
    return false; 
}

void save_path(int sum){
    best_track = sum;
}
    
void backtrack(int pos, int sum){ 
    if(sum > n) return; 
    for(int i = pos + 1; i < tracks; i++)
            backtrack(i , sum + CD[i]);
    if(best_option(sum)) save_path(sum); 
}

void set_parameters(){
    best_track = -10; delta = 99999; id = -1;
}

int main(){
    while(scanf("%d", &n) != EOF){ 
        scanf("%d", &tracks); 
        for(int i = 0; i < tracks; i++)
            scanf("%d", &CD[i]);
        set_parameters();
        backtrack(-1, 0);
        print_answer(best_track);
    }
    return 0;
}
