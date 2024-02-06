/*
Brute force approach -> solution was made using the code in the 
link: https://github.com/JayantGoel001/CodeForces/blob/master/Erase%20and%20Extend%20(Easy%20Version).cpp
as example.
*/
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

string generateString(string str, int k){
    string s;
    for(int i = 0; i < k; i++)
        s += str[i%str.size()];
    return s;
}

void print(string out){
    for(int i = 0; i < out.size(); i++)
        cout << out[i];
    cout << endl;
}

string compare(string s1, string s2){
    for(int i = 0; i < s1.size(); i++){
        if(s1[i] < s2[i])
            return s1;
        if(s2[i] < s1[i]) 
            return s2;
    }
    return s1;
}

int main(){
    int n, k; string s;
    cin >> n >> k; cin >> s;
    string out = generateString(s, k);
    for(int i = 0; i < n; i++){
        out = compare(out, generateString(s.substr(0, i+1), k));
    }
    print(out);
    return 0;
}