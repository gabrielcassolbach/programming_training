// Solução feita por @joaoreis28.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map <char, int> pos;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i = '1'; i <='9'; i++)
        pos[i] = i - '0';


    pos['0'] = 10;

    ll t;
    cin >> t;

    while(t--)
    {
        string n;
        cin >> n;
        char inicio = '1';
        int ans = 4; // imprimir o numero
        for(auto letra:n)
        {
            ans = ans + (abs(pos[inicio] - pos[letra]));
            inicio = letra;

        }

        cout << ans << endl;
    }
    
        
        
    return 0;
}
