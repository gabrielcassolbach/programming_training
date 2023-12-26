#include "bits/stdc++.h"
using namespace std;

#define MAX 112345

// 987 - Popes.     
// ------------
int y; int n; int popes[MAX]; int max_interval; 
int pope1, pope2; 

void best_interval(){
    max_interval = 0;
    int interval; int point_b;
    for(int i = 0; i < n; i++){ 
        point_b = lower_bound(popes, popes + n, popes[i] + y) - popes;
        interval = (point_b - i);
        if(interval > max_interval) 
            {max_interval = interval; pope1 = popes[i]; pope2 = popes[point_b - 1];}
    }
}

int main(){
    while(scanf("%d", &y) != EOF){ 
        scanf("%d", &n);
        for(int i = 0; i < n; i++) 
            scanf("%d", &popes[i]);   
        best_interval();
        printf("%d %d %d\n", max_interval, pope1, pope2);
    }
    return 0;
}