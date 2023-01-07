#include <bits/stdc++.h>
using namespace std;

#define MAX 1123

int closest_sum(int* v, int size, int value){
    int dif = INT_MAX, sum = 0;
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(abs(value - (v[i] + v[j])) < dif){
                dif = abs(value - (v[i] + v[j]));
                sum = v[i] + v[j];   
            }
        }
    }
    return sum;
}

int main(){
    int n, m, v[MAX], values[25], cases = 0;
    scanf("%d", &n);
    while(n){
        cases++; printf("Case %d:\n", cases);
        for(int i = 0; i < n; i++) scanf("%d", &v[i]);
        sort(v, v + n); scanf("%d", &m);
        for(int i = 0; i < m; i++) scanf("%d", &values[i]);
        for(int i = 0; i < m; i++) 
            printf("Closest sum to %d is %d.\n", values[i], closest_sum(v, n, values[i])); 
        scanf("%d", &n);
    }  
    return 0;
}