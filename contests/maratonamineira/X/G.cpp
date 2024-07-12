// Código feito por João Reis.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*🦛🦛🦛🦛🦛🦛🦛*/

int bolas[5];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, a, b;
    cin >> n;

    bolas[2] = 1;

    while(n--)
    {
        cin >> a >> b;
        swap(bolas[a], bolas[b]);

    }


    for(int i = 0 ; i  <= 3; i++)
        if(bolas[i])
            cout << i << endl;



    return 0;
}
