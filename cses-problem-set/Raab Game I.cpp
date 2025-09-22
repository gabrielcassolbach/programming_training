#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t; 
    while(t--){
        int n, a, b; cin >> n >> a >> b; 
        if(a + b > n)
            {cout << "NO\n"; continue;}

        int d = (n - (a + b)); 
        n -= (n - (a + b)); 
    
        if((a == 0 && b != 0) || (a != 0 && b == 0))
            {cout << "NO\n"; continue;}

        cout << "YES\n";
        for(int i = 1; i <= n; i++)
            cout << i <<  " ";
        
        for(int i = n + 1; i <= (n + d); i++)
            cout << i <<  " ";
        cout << "\n";

        int shift = 1 + a; 
        for(int i = 1; i <= n; i++){
            cout << shift << " ";
            shift++; 
            if(shift > n)
                shift = 1;
        }

        for(int i = n + 1; i <= (n + d); i++)
            cout << i <<  " ";
        cout << "\n";
    }


    return 0; 
}