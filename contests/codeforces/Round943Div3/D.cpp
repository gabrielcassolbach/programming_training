#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

ll n, k, pb, ps; 
vector<ll> a, p;


/*
4 2 3 2
k = 2.
n = 4.
posB = 3.
posS = 2.

P: 2 1 4 3
A: 7 2 5 6

B
Posicao  : 3      2                1                             ... n
pontuacao: k*a[3] a[3]+(k-1)(a[2]) a[3] + a[2] + (k-2)*a[1] 
max:       k*a[3] a[3]+(k-1)(a[2]) a[3]+(k-1)(a[2]) 


*/

int main(){
    int t; cin >> t; 
    while(t--){
        cin >> n >> k >> pb >> ps;
        vector<ll> p, a;

        ll x;
        for(int i = 0 ; i < n; i++){
            cin >> x;
            p.push_back(x);
        }    
        for(int i = 0 ; i < n; i++){
            cin >> x;
            a.push_back(x);
        }   
        
        ll scr_b, scr_s;
        ll scr_way_b = 0, scr_way_s = 0;
        ll max_b = 0, max_s = 0;
        for(int i = 0 ; i < n && i <= k ; i++){            
            scr_b = scr_way_b+(k-i)*a[pb-1];       
        
            if (scr_b > max_b)
                max_b = scr_b;
            
            scr_way_b += a[pb-1];       
            pb = p[pb-1];

            //cout<< " i: " << i << ", pb: " << pb << ", max_b: " << max_b << ", scr_b: " << scr_b << ", scr_way_b: " << scr_way_b<<  endl;
        }    
                    
        //cout <<  endl;
        for(int i = 0 ; i < n && i <= k; i++){
            scr_s = scr_way_s+(k-i)*a[ps-1];       
        
            if (scr_s > max_s)
                max_s = scr_s;
            
            scr_way_s += a[ps-1];  
            ps = p[ps-1]; 

            //cout << " i: " << i << ", ps: " << ps << ", max_s: " << max_s << ", scr_s: " << scr_s<< ", scr_way_s: " << scr_way_s <<  endl;    
        }    

        if(max_s > max_b)
            cout << "Sasha" << endl;
        else if(max_s < max_b)
            cout << "Bodya" << endl; 
        else 
            cout << "Draw" << endl;
    }

    return 0;
}