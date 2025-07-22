#include <bits/stdc++.h>
using namespace std;


int main(){
    int n1, n2; 
    cin >> n1 >> n2;
    int a = max(n1, n2);
    int b = min(n1, n2);

    if(b >= (a/2 + 7)) 
        {cout << 0 << '\n'; return 0;}

    int anos = 0;
    while(b < (a/2 + 7)){
        b++; a++;
        anos++;
    }

    cout << anos << '\n';
    return 0; 
}