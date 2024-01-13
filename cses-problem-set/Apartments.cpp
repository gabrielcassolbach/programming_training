#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 212345

typedef long long ll;

ll n, m, k;
ll ap[MAX], ap_size[MAX];

int answer(){
    int i, j, ans;      
    sort(ap, ap + n);  sort(ap_size, ap_size + m);
    ans = 0; i = j = 0;
    while((i < n) && (j < m)){
        if(abs(ap[i] - ap_size[j]) <= k)
            {i++; j++; ans++;}
        else if(ap[i] > ap_size[j]) 
            {j++;}
        else if(ap[i] < ap_size[j])
            {i++;}
    }
    return ans;
}

void read(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> ap[i];
    for(int i = 0; i < m; i++)
        cin >> ap_size[i]; 
}

int main(){
    read();
    cout << answer() << endl;
    return 0;
}
