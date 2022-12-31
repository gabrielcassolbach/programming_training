#include <bits/stdc++.h>
using namespace std;

// Falha na lógica interna. Debbugar.

int main(){
    int x, n; char l; 
    int right_pair[31], left_pair[31];
    int pairs;
    while(scanf("%d", &x) != EOF){
        pairs = 0;
        for(int i = 0; i < 31; i++) {right_pair[i] = 0; left_pair[i] = 0;}
        for(int i = 0; i < x; i++){
            scanf("%d %c", &n, &l);
            if(l == 'D')
                right_pair[n - 30]++;
            else
                left_pair[n - 30]++;
        }
        for(int i = 0; i < 31; i++){
            while(right_pair[i] && left_pair[i])
                {pairs++; right_pair[i]--; left_pair[i]--;}
        }

        printf("%d\n", pairs);
    }
    return 0;
}