#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

/*
Alice moves first.

-> se n == 1 -> Bob.
-> se n é primo -> Bob.

y1 =>>>> primo. (descobre quem perdeu e, consequentemente, quem venceu).


12 - (12/3)*(3-1):   div n, n-1 oper 
3 2
2 1
2 1
  4

3 2  
4 3
  5

x -> y 

8    2 
12 4

227.

// tabela com os primos = 2, 3, 4, 5, 7  ate floor(sqrt(n))



Escolha ótima:
    Bob -> um divisor que torne o número primo ou -> um divisor cujo próximo divisor não seja primo.

-> teria o primeiro primo e o segundo primo.

*/


void answer(ll n){
    if(n == 1)
        {cout << "Bob" << endl; return;}

    int div = 0; 

    /*
    while(not primo){
        div++;
        escolha o divisor ótimo
        n /= d;
    }
    if(div % 2) 
        cout << "Alice" << endl;
    else 
        cout << "Bob" << endl;
    */
    
}

int main(){
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        cout << answer(n) << endl;
    }   
    return 0;
}