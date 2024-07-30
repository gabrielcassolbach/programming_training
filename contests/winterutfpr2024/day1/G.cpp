#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void print_hanoi(int n, int o, int d, int i) {
    if(n > 1) {
        print_hanoi(n-1, o, i, d);
    }
    cout << o << " " << d << endl;
    if(n > 1) {
        print_hanoi(n-1, i, d, o);
    }
}

int main(){
    int n; cin >> n;
    cout << pow(2, n) - 1 << endl;
    print_hanoi(n, 1, 3, 2);
    return 0;
}