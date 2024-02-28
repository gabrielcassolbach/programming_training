#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define MAX 212345

int main(){
    int v[MAX], t[MAX];
    int n, k, q, a, b;
    cin >> n >> k >> q;

    memset(v, 0, MAX); memset(t, 0, MAX);

    for(int i = 0; i < n; i++){ // n >= 1 && n <= 2.10^5
        cin >> a >> b;
        v[a]++; v[b + 1]--;
    }

    for(int i = 1; i < MAX; i++){
        v[i] += v[i-1];
        if(v[i] >= k)
            t[i]++;
    }

    for(int i = 0; i < MAX; i++)
        {t[i] += t[i-1];}

    while(q--){
        int q1, q2; cin >> q1 >> q2;
        cout << t[q2] - t[q1-1] << endl;
    }

    return 0;
}


/*
    3 2 4
    91 94
    92 97
    97 99

    // 90 91 92 93 94 95 96 97 98 99 100
    // 0  1  1        -1    1  -1     -1
    // 0  1  2  2  2  1  1  2   1  1  -1

    for(int i = 1; i < MAX; i++){
        v[i] += v[i-1];
        if(v[i] >= k) 
            t[i]++;
    }

    for(int i = 1; i < MAX; i++){
        t[i] += t[i-1];
    }
    
    // 90 91 92 93 94 95 96 97 98 99 100
    // 0  0  1  1  1  0  0  1  0  0  0
    // 0  0  1  2  3  3  3  4  4  4  4

    92 94 -> v[94] - v[92 - 1] = 3
    93 97 -> v[97] - v[93 - 1] = 3
    95 96 -> v[96] - v[95 - 1] = 0
    90 100 -> v[100] - v[90 - 1] = 4.
*/