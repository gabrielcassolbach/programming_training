#include <bits/stdc++.h>
using namespace std;

#define MAX 1123

int main(){
    int t, n, sum, sales[MAX];
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n); sum = 0;
        for(int i = 0; i < n; i++) scanf("%d", &sales[i]);
        for(int i = 1; i < n; i++)
            for(int j = i - 1; j >= 0; j--)
                if(sales[i] >= sales[j]) sum++;
        printf("%d\n", sum);
    }
    return 0;
}