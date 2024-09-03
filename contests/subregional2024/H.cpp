#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 510

typedef long long ll;

string m, n;
vector<ll> n_msg;
vector<string> m_msg;
int bits[MAX];
ll pot2[MAX];

ll ptc(ll a, ll i, ll mod){
	if(i == 0) return 1;
	if(i % 2) return ptc(a, i-1, mod)*a%mod;
	ll c = ptc(a, i/2, mod)%mod;
	return (c*c)%mod;
}

void getMessagesN() {
	ll pot = 1;
	n_msg.push_back(0);
	for(int i = 0; i < n.size(); i++){
		pot = 1 << i;
		if(n[n.size() - i - 1] == '1'){
			for(int j = 0; j < n_msg.size(); j++)
				n_msg[j] += 1*pot;
		}
		if(n[n.size() - i - 1] == '*'){
			ll qtd = n_msg.size();
			for(int j = 0; j < qtd; j++)
				{n_msg.push_back(n_msg[j]); n_msg[j] += 1*pot;}				
		} 	 
	}
}

void getMessagesM() {
	string a; m_msg.push_back(a);
	for(int i = 0; i < m.size(); i++) {
		if(m[i] == '*'){
			ll qtd = m_msg.size();
			for(int j = 0; j < qtd; j++){
				m_msg.push_back(m_msg[j] + '0');
				m_msg[j] += '1';
			}	
		}else if(m[i] == '0'){
			for(int j = 0; j < m_msg.size(); j++)
				m_msg[j] += '0';
		}else{
			for(int j = 0; j < m_msg.size(); j++)
				m_msg[j] += '1';	
		}
	} 
}

void setBits(string a){
	for(int i = 0; i < a.size(); i++)
		bits[i] = a[i] == '1' ? 1 : 0;
}

string solve() {
	getMessagesM();
	for(int i = 0; i < n_msg.size(); i++) {
		for(int j = 0; j < m_msg.size(); j++){
			ll sum = 0; setBits(m_msg[j]);
			for(int k = m_msg[j].size() - 1; k >= 0; k--) {
				sum *= 2;
				sum %= n_msg[i];
				if(bits[m_msg[j].size() - k - 1]) sum++;
				sum %= n_msg[i];
			}
			if(!(sum)) return m_msg[j];
		}
	}
	return "-1";
}

int main() { _
	cin >> m >> n;
	for(int i = 0; i < MAX; i++) pot2[i] = -1;
	getMessagesN();
	cout << solve() << '\n';
	return 0;
}
