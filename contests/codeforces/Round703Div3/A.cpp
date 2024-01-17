// Solução por Felipe Stillner.
//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  ll t, n, r, x, y, z, ind;

  cin >> t;

  for (int i = 0; i < t; i++)
  {
    cin >> n;
    cin >> x >> y >> z;
    if (x == y && y == z)
    {
      r = z;
    }
    else if (x == y)
    {
      r = x;
      ind = 3;
    }
    else if (x == z)
    {
      r = x;
      ind = 2;
    }
    else if (z == y)
    {
      r = z;
      ind = 1;
    }
    for (int j = 0; j < n-3; j++)
    {
      cin >> x;
      if (x != r)
      {
        ind = j+4;
      }
    }
    cout << ind << endl;
  }
  return 0;
}