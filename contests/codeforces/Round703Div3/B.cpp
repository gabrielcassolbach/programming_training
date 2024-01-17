// Solução feita por @JoãoReis28
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t, n;
    cin >> t;

    while(t--){

      cin >> n;  
    vector <string> s(n);

    vector <pair<int, int>> v;
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
        for(int j = 0; j < n; j++)
            if(s[i][j] == '*')
                v.push_back({i, j});
    }



        v.push_back(v[0]);
        v.push_back(v[1]);
        if (v[0].first == v[1].first) // mesma linha
        {
            v[2].first = (v[2].first + 1) % n;
            v[3].first = (v[3].first + 1) % n;
        }
        else if (v[0].second == v[1].second) // mesma coluna
        {
            v[2].second = (v[2].second + 1) % n;
            v[3].second = (v[3].second + 1) % n;
        }
        else // caso restante
            swap(v[2].first, v[3].first);

        s[v[2].first][v[2].second] = '*';
        s[v[3].first][v[3].second] = '*';


        for(int i = 0; i < n; i++)
            cout << s[i] << endl;

    }


    return 0;

}