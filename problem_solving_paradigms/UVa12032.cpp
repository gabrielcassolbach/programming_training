// The Monkey and the Oiled Bamboo -> {UVa12032}
#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

/*
- Input starts with a integer t (t <= 500), denoting the number of test cases.
Each case starts with a line containing an integer n denoting the number of 
rungs in the ladder. The next line contains n space separated integers r1, r2, .. rn. 
denoting the heights of the rungs from the ground.

- observations: 
 - we can have 10⁵ rungs in the worst case.
 - each rung can have a value of 10⁷.

- Output:
- For each test case, print the minimum k value necessary to the person climb up the ladder.
-> The objective of this problem is to find an algorithm that finds that.
*/

void min_k (int t, int n, int* v){
    

}

int main(){
    int t, n;
    int v[MAX];
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++) 
            scanf("%d", &v[i]);
        min_k(t, n, v);
    }
    return 0;
} 
   
