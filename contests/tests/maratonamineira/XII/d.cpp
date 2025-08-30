#include <bits/stdc++.h>

using namespace std;

template<typename T> using arr = vector<T>;

arr<int> convolve(arr<int> const &a, arr<int> const &b) {
    int m = a.size(), n = b.size();
    arr<int> c(m+n-1, 0);
    for(int i = 0; i < (int)c.size(); ++i) {
        for(int j = 0; j < i; ++j)
            if(j < m && i-j < n) c[i] += a[j]*b[i-j];
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int k;
    cin >> k;
    arr<int> a = {0, 1, 1, 1, 1, 1, 1};
    arr<int> a3 = convolve(a, convolve(a, a));
    int sum = accumulate(a3.begin(), a3.end(), 0);
    cout << fixed << setprecision(12) << (double)a3[k]/sum << '\n';
    return 0; 
}
