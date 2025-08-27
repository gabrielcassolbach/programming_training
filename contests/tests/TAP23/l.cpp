#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int a1, p1, a2, p2; 
    cin >> a1 >> p1;
    cin >> a2 >> p2;
    
    int a = a1 + a2;
    int b = p1 + p2;

    if(a == b)
        cout << "D\n";
    else if(a > b)
        cout << "A\n";
    else 
        cout << "P\n";

    return 0;
}