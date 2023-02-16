// The Monkey and the Oiled Bamboo
#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

void min_k(int tc, int n, int* rungs){
    int a = 0; int b = n - 1; int m = (a + b) / 2;
    while(fabs(a - b) != 1){
        if((rungs[m] - rungs[a]) > (rungs[b] - rungs[m]))
            {b = m; m = (a + b) / 2;}
        else
            {a = m; m = (a + b) / 2;}        
    }
    int k = rungs[b] - rungs[a];
    printf("%d\n", k);
}   

int main(){
    int tc, n, rungs[MAX];
    int cont = 0;
    scanf("%d", &tc);
    while(tc--){
        cont++;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) 
            scanf("%d", &rungs[i]);
        printf("Case %d: ", cont);
        min_k(tc, n, rungs);
    }
    return 0;
} 
   
