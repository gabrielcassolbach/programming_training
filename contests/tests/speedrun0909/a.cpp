#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll vr, vl, vd, vm, n;
    cin >> vr >> vl >> vd >> vm >> n;
    ll total = vr + vl + vd + vm + n;
    vector<string> v;
    
    if(vr + n > (total/2)) 
        v.push_back("Rafael");
    
    if(vl + n > (total/2)) 
        v.push_back("Leonardo");
    
    if(vd + n > (total/2)) 
        v.push_back("Donatello");

    if(vm + n > (total/2)) 
        v.push_back("Michelangelo");

    if(v.size() == 0)
        cout << "sem vencedores\n";
    else{
        sort(v.begin(), v.end());
        for(int i= 0; i < (int) v.size(); i++)
            cout << v[i] << "\n";
    }

    return 0;
}