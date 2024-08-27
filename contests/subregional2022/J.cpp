#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 14

int freq[MAX];
int j_1, j_2, m1, m2;
int sum = 0; int n;

void init(){ 
    for(int i = 0; i < MAX; i++){
        freq[i] = 0;
    }
    cin >> n; 
    cin >> j_1 >> j_2; freq[j_1]++; freq[j_2]++;
    cin >> m1 >> m2; freq[m1]++; freq[m2]++;
    
    if(j_1 > 10) j_1 = 10;
    if(j_2 > 10) j_2 = 10;
    if(m1 > 10) m1 = 10;
    if(m2 > 10) m2 = 10;

    for(int i = 0; i < n; i++){
        int val; cin >> val;
        freq[val]++;

        if(val <= 10)
            sum += val;
        else 
            sum += 10;
    }
}

void solve(){
    int sum_j = sum + j_1 + j_2; int sum_m = sum + m1 + m2;
    int ans = INT_MAX;

    int p1 = 23 - sum_m; 
    if(freq[p1] < 4 && p1 <= 10) ans = p1;

    int p2 =  24 - sum_j;
    if(p2 <= 10){ 
        for(int j = p2; j <= 13; j++){
            if(freq[j] < 4) {
                ans = min(ans, j);
            }
        }
    }

    if(ans == INT_MAX)
        {cout << -1 << endl; return;}

    if(ans + sum_m > 23) cout << -1 << endl;
    else cout << ans << endl;

}

int main() { 
    init();
    solve();
    return 0;
}