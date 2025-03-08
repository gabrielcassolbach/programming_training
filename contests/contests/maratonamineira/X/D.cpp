// Código feito por João Reis.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*🦛🦛🦛🦛🦛🦛🦛*/

int n, soma = 0,a ;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;

    for(int i = 0; i < n - 1; i++)
    {
        cin >> a;
        soma += a;
    }

    vector<int> criancas(n, -1);
    for(int i = 20; i >= 0; i--)
    {
        criancas[(soma + i) % n] = i;
    }

    for(auto resp : criancas)
        cout << resp << endl;
    return 0;
}
