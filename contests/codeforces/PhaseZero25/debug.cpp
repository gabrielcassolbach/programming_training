#include <bits/stdc++.h>

using namespace std;

using ll = long long;
template<typename T> using arr = vector<T>;
template<typename T> using fun = function<T>;

arr<int> p;

void sieve(int n) {
    for(int i = 2; i < n; ++i) {
        bool is_prime = true;
        for(int j = 0; j < (int)p.size() && is_prime && (ll)p[j]*p[j] <= i; ++j)
            is_prime &= i%p[j] != 0;
        if(is_prime) p.push_back(i);
    }
}

arr<int> fact(int n) {
    arr<int> res;
    for(int j = 0; j < (int)p.size() && n > 1 && (ll)p[j]*p[j] <= n; ++j)
        while(n%p[j] == 0) res.push_back(p[j]), n /= p[j];
    if(n != 1) res.push_back(n);
    return res;
}

int main() {
    sieve(1e5);
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int y, k;
    cin >> y >> k;
    arr<int> f = fact(y);

    for(int i = 0; i < (int) f.size(); i++){
          cout << "f: " << f[i] << "\n";
    }

    arr<int> d(f.size()+1);
    d[0] = 1;
    for(int i = 0; i < (int)f.size(); ++i) {
        d[i+1] = d[i]*f[i];
        cout << "d: " << d[i+1] << " ";
    }

    cout << "\n";
    fun<ll (int, int)> rec = [&](int i, int k) {
        if(i == (int)f.size() || k < f[i]-1) return (ll)(k+1)*d[i];
        return rec(i+1, k-(f[i]-1));
    };
    cout << rec(0, k) << '\n';
    return 0;
}
