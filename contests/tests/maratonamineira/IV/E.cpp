#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    int p = 0;
    bool ccw = false;
    char ch;
    while(cin >> ch, ch != '#') {
        switch(ch) {
            case '?':
                cout << p+1 << ' ';
                break;
            case 'A':
            case '7':
                p = ccw ? (p+n-2)%n : (p+2)%n;
                break;
            case 'Q':
                ccw = !ccw;
            default:
                p = ccw ? (p+n-1)%n : (p+1)%n;
                break;
        }
    }
    cout << '\n';
    return 0;
}
