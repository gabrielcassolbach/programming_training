#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

const ll mod = 998244353;

ll prodDivPrimos(ll b){
    int primos[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
221, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293,
307, 311, 313, 317};

    ll prod = 1;
    int div = 2;
    int p_div = 0;
    while (div < 316) {
        if (b % div == 0) {
            while (b % div == 0) {
                b = b / div;
            }
            prod *= div;
        }
        div = primos[p_div];
        p_div++;
    }
    if(b != 1) {
        prod *= b;
    }
    
    return prod;
}

int main(){
    int n;
    cin >> n;
    ll basefinal = 1;
    for (int i = 0; i < n; i++)
    {
        int base;
        int a, b;
        cin >> a >> b;
        a = a % b;
        if (a == 0) {
            base = 2;
        } else {
            base = prodDivPrimos(b);
        }
        basefinal = lcm(basefinal, base) % mod;
    }
    cout << basefinal << endl;
	return 0;
}
