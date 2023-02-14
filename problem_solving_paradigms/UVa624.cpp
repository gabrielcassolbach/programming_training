#include <bits/stdc++.h>
using namespace std;
#define MAX 20

/*----------------------------------------------*/
/*                  (CD - 624)                  */
/*----------------------------------------------*/

int CD[MAX], n, tracks, best_track, delta, id;
vector<int> p; vector<int> bp;

void print_answer(int value){
    for(int i = 0; i < bp.size(); i++) 
        printf("%d ", bp[i]);
    printf("sum:%d\n", value);
}

bool best_option(int sum){
    if(fabs(sum - n) < delta)
        {delta = fabs(sum - n); return true;}
    return false;
}

void save_path(int sum){
    while(!bp.empty()) bp.pop_back();
    for(int i = 0; i < p.size(); i++)
        bp.push_back(p[i]);
    best_track = sum;
}
    
void backtrack(int pos, int sum){ 
    if(sum > n) return;
    if(pos >= 0) p.push_back(CD[pos]);
    for(int i = pos + 1; i < tracks; i++)
        backtrack(i , sum + CD[i]);
    if(best_option(sum)) save_path(sum);
    p.pop_back();
}
                                                                
void set_parameters(){
    best_track = -10; delta = 99999; id = -1;
    p.clear(); bp.clear();
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