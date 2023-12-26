#include <bits/stdc++.h>
using namespace std;
#define MAX 12

int main(){
    int k, s[MAX];
    scanf("%d", &k);
    while(k != 0){
        for(int i = 0; i < k; i++)
            scanf("%d", &s[i]);
        for(int a = 0;     a < k - 5; a++) 
         for(int b = a + 1; b < k - 4; b++)
          for(int c = b + 1; c < k - 3; c++)
           for(int d = c + 1; d < k - 2; d++)
            for(int e = d + 1; e < k - 1; e++)
             for(int f = e + 1; f < k;     f++)
                printf("%d %d %d %d %d %d\n", 
                    s[a],s[b],s[c],s[d],s[e],s[f]);
        scanf("%d", &k); if(k) printf("\n");
    }
    return 0;
}