#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

/*


 o    k
.-.- .-

k     o
.-  .-.-

 */

string translate(char c) {
	if(c == '\n') return "\n"; 
	if(c == 'O') 
		return ".-.-";
	return ".-"; 		
}

int main() {
	fastio; 
	string s, ans; cin >> s;
	ans = "";   
	for(int i = 0; i < s.size(); i++)
		ans += translate(s[i]); 	
	cout << ans; 
	return 0; 
}
