#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> v1, v2;

ll getSequenceSum(int n){
    return ((1 + n)*n) / 2;
}

void answer(int n){
    ll value = getSequenceSum(n); 
    if(value % 2 != 0) printf("NO\n");   
    else{
        int counter = 1;
        for(int i = 7; i > 0; i--){
            
        }
    }
}

int main(){
    int n; scanf("%d", &n); 
    answer(n);
    return 0;
}