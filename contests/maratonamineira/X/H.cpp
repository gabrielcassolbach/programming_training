#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 21

/*
pega a visão.
 f f g g h 	
{qtd_impares, qtd_pares}

memo -> [{1, 0}, {0, 1}, {}, {}, {}]

for(int i = 2; i <= n; i++){
	ans++; // garantindo que há pelo menos mais um palíndromo.
	quantos palíndromos são gerados após a adição 

}

f f g g h

N    1    2    3    4    5
PP   0    1    0    2    0
PI   1    1    2    2    3

Ul-> é o que?


PI(n) = 1 + (PI(Ul(n) - 1)) + PP(n - 1)    , se a letra ja apareceu
      = 1 + PP(n - 1)                      , se a letra ainda nao apareceu
PP(n) = PP(Ul(n) - 1) + 1                  , se a letra ja apareceu
	  = 0                                  , se a letra ainda nao apareceu


*/

typedef long long ll;

ll n;
vector<char> v; vector<pair<int, int>> memo;
int alfabet[MAX];

void read(){
	cin >> n;
	v.resize(n + 3); 
	for(int i = 1; i <= n; i++) cin >> v[i];
}

void init(){
	for(int i = 0; i < MAX; i++) alfabet[i] = 0;
	memo.resize(n + 3);
}

int main(){
	read();
	init();

	return 0;
}
