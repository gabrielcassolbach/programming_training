#include <bits/stdc++.h>
using namespace std;
#define MAX 20

// observation: tracks do not repeat!
int s[MAX], cd[MAX], n, tracks, best_track = -1, delta;
bool found;

bool best_option(int sum){
    if(fabs(sum - best_track) < delta)
        {delta = fabs(sum - best_track); return true;}
    return false;
}

bool add_track(int sum, int value){    
    for(int i = 0; i < tracks; i++)
       if(value == s[i]) return false; 
    if(sum + value > n) return false;
    return true;
}

void backtrack(int sum, int count){ 
    if(sum <= n && best_option(sum)){
        best_track = sum;
        printf("Best Track: %d\n", best_track);
    }
    for(int i = 0; i < tracks; i++)
        if(add_track(sum, cd[i]))  
            {s[count] = cd[i]; backtrack(sum + cd[i], count + 1);}
}

int main(){
    while(scanf("%d", &n) != EOF){
        scanf("%d", &tracks);
        for(int i = 0; i < tracks; i++) scanf("%d", &cd[i]);
        memset(s, 0, sizeof s);
        best_track = -1; found = false; delta = 112345;
        backtrack(0, 0);
        printf("\n");
        //print_solution();
        //printf("sum: %d\n", best_track);
    }
    return 0;
}
