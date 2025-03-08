#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;

int main(){
    _
    ll t, maxSum, n, m, sum, maxNum;
    cin >> t;
    for (ll k = 0; k < t; k++)
    {
        cin >> n;
        maxSum = 0;
        maxNum = 0;
        for (ll i = 2; i <= n; i++)
        {
            sum = 0;
            m = i;
            while (m <= n)
            {
                sum +=m;
                m += i;
            }
            if (maxSum < sum) {
                maxSum = sum;
                maxNum = i;
            }
        }
        cout << maxNum << endl;
    }
    

}