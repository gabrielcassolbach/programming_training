#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, k; 
vector<int> v; 

/*
{n -> 10⁵}
n e k.
f(i, j) = (i*j) - k*(ai | aj). = 12. 

4

3 3
1 1 3 
1 2 3

2 2
1 2

4 3
1
0 1 2 3 
1 2 3 4
i j

2
0 1 2 3 
1 2 3 4
i   j

3
0 1 2 3 
1 2 3 4
  i j

3
0 1 2 3 
1 2 3 4
i     j

-> iterar sobre esse vetor.

6 6

3 2 0 0 5 6
1 2 3 4 5 6 

0 0 2 3 5 6
4 3 2 1 5 6
  i     j



*/

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        v.clear(); v.resize(n + 1);
        for(int i = 1; i <= n; i++)
            cin >> v[i];
        
        int a, b, value; 
        a = n-1; b = n; 
        value = (a*b) - (k*(v[a] | v[b])); 
        
        for(int i = n; i > 0; i--){


        }

        /*
        4 3
        0 1 2 3 
            i j

        // vector<pair<int, int>> v; 
        //  

        */
        /*
        for(int i = n; i > 0; i--){
        }       
        */


    
    }
    return 0;
}