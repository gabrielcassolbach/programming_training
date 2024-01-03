#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;

void findMoves(int n){
    int totalMoves = 0;
}

void answer(){
    printf("%d\n", (int) v.size());
    for(int i = 0; i < v.size(); i++)
        printf("%d %d\n", v[i].first, v[i].second);
}

int main(){
    int n; 
    scanf("%d", &n);
    findMoves(n);
    answer();   
    return 0;
}