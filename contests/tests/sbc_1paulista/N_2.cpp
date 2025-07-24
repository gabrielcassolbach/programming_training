#include <bits/stdc++.h>
using namespace std;

const int MAX = 1.1e6;
 
vector<int> low_prime;
vector<int> light;
vector<int> steps_per_prime;
map<int, int> primes_per_steps;

void sieve() {
    low_prime.resize(MAX);
    iota(low_prime.begin(), low_prime.end(), 0);
    for(int i = 2; i < MAX; ++i) {
        if(low_prime[i] != i) continue;
        for(int j = 2*i; j < MAX; j += i) low_prime[j] = min(low_prime[j], i);
    }
}

vector<int> factor(int a) {
    vector<int> p;
    while(a != 1) {
        if(p.empty() || p.back() != low_prime[a]) p.push_back(low_prime[a]);
        a /= low_prime[a];
    }
    return p;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    sieve();

    int n; cin >> n;
    light.resize(MAX, 0);
    steps_per_prime.resize(MAX, 0);

    while(n--){
        int d; cin >> d;
        light[d] = !light[d];
        vector<int> p = factor(d);
        for(auto prime : p) {
            if(light[d]) { // se acendeu
                steps_per_prime[prime]++;
                primes_per_steps[steps_per_prime[prime]]++;
                if(steps_per_prime[prime] != 1) {
                    primes_per_steps[steps_per_prime[prime]-1]--;
                    if(primes_per_steps[steps_per_prime[prime]-1] == 0)
                        primes_per_steps.erase(steps_per_prime[prime]-1);
                }
            } else { // se apagou
                steps_per_prime[prime]--;
                if(steps_per_prime[prime] != 0)
                    primes_per_steps[steps_per_prime[prime]]++;
                primes_per_steps[steps_per_prime[prime]+1]--;
                if(primes_per_steps[steps_per_prime[prime]+1] == 0)
                    primes_per_steps.erase(steps_per_prime[prime]+1);
            }
        }
        cout << (primes_per_steps.empty() ? 0 : primes_per_steps.rbegin()->first) << '\n';
    }

    return 0;
}