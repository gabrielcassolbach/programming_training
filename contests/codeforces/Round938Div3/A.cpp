#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main(){
    int t; cin >> t;
    while(t--){
        int a, b, n;
        cin >> n >> a >> b;
        if(!(n % 2)){
            int op1 = (n/2)*b;
            int op2 = (n)*a;
            if(op1 < op2) 
                cout << op1 << endl;
            else 
                cout << op2 << endl;    
        }else{
            int op1 = ((n-1)/2)*b + a;
            int op2 = (n)*a;
            if(op1 < op2) 
                cout << op1 << endl;
            else 
                cout << op2 << endl;    
        }
    }
    return 0;
}