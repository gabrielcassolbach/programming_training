#include <bits/stdc++.h>
using namespace std;

#define MAX 31234

int a[MAX];

void ans(int n, int t){
    int flag = 0; int pos = 1; int count = 1;
    while(count != n && flag != 1 && pos != n){
        pos = pos + a[pos];
        if(pos == t)
            flag = 1;
        count++;
    }
    if(flag) 
        printf("YES\n");
    else
        printf("NO\n"); 
}

int main(){
    int n, t; scanf("%d %d", &n, &t);
    for(int i = 1; i <= n-1; i++)
        scanf("%d", &a[i]);
    ans(n, t);
    return 0;
}
