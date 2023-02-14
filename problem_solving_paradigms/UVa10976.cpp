// 10976 - Fractions Again.
#include <bits/stdc++.h>
using namespace std;

#define MAX 10000

typedef struct{
    int a;
    int b;
} Pair;

Pair p;

bool formula(int k, int x){
    int y, d;
    d = k*x; 
    y = (fabs(d/k - d/x));
    
    

}

void print_solutions(int k){
    for(int x = 2; x <= MAX; x++)
        if(formula(k, x))   
            printf("1/%d = 1/%d + 1/%d\n", k, p.a, p.b);
}

int main(){
    int k;
    while(scanf("%d", &k) != EOF) 
        print_solutions(k);
    return 0;
}