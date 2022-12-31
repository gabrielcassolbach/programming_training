#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x; 
    int smaller = (INT_MAX); int pos = -1;
    vector<int> v;
    scanf("%d", &n);
    int i = -1;   
    while(n--){
        i++; 
        scanf("%d", &x);
        v.push_back(x);
        if(v[i] <= smaller) {smaller = v[i]; pos = i;} 
    }
    printf("Menor valor: %d\n", smaller);
    printf("Posicao: %d\n", pos);
    return 0;
}