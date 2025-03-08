#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define MAX 51

int main() { _
    int n; cin >> n;
    int matrix[MAX][MAX];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];
    int choice = max(max(matrix[0][0], matrix[0][n-1]), max(matrix[n-1][n-1], matrix[n-1][0]));
    if(choice == matrix[0][0]) cout << 2 << '\n';
    if(choice == matrix[0][n-1]) cout << 3 << '\n';
    if(choice == matrix[n-1][0]) cout << 1 << '\n';
    if(choice == matrix[n-1][n-1]) cout << 0 << '\n';
    return 0;
}