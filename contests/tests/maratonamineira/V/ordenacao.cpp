    #include <bits/stdc++.h>
    using namespace std;

    int main(){
        int val, val2; cin >> val;
        for(int i = 1; i < 5; i++){
            cin >> val2;
            if(val > val2){
                cout << "NAO\n";
                return 0;
            }
            val = val2;
        }
        cout << "SIM\n"; 
        return 0; 
    }