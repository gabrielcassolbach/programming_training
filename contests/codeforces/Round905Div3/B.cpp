#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 26


int n, k;
vector<char> s;
int letters[MAX]; 

int isPalindrome(){    
    int counter = 0;
    for(int i = 0; i < MAX; i++)
        if(letters[i] > 0) 
            if(letters[i] % 2 != 0) // se for ímpar.
                counter++;
    if(counter - 1 <= k) return 1;
    else return 0;        
}

void clearLetters(){
    for(int i = 0; i < MAX; i++)
        letters[i] = 0;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++){
            char c; cin >> c; s.push_back(c);
            letters[c-'a']++;    
        }
        if(isPalindrome())
            cout << "yes" << endl;
        else 
            cout << "no" << endl;
        
        s.clear(); clearLetters();
    } 


    return 0;
}