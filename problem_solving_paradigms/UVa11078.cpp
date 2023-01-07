#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

int main(){
    int t, n, s[MAX], senior, max_dif;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &s[i]);
        senior = s[0]; max_dif = -MAX;
        for(int i = 1; i < n; i++){
            max_dif = max(max_dif, senior - s[i]);
            senior = max(senior, s[i]);
        }
        printf("%d\n", max_dif);
    }
    return 0;
}