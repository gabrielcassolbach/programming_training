#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
Given two arrays of integers, find their longest common subsequence.

A subsequence is a sequence of array elements from left to right that can 
contain gaps. A common subsequence is a subsequence that appears in both arrays.

Output:

First, print the length of the longest common subsequence. 


After that, print an example of such a sequence. 

8 6
3 1 3 2 7 4 8 2 
6 5 1 2 3 4

I can add a number or not, at each iteration.





*/


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m; 
    vector<ll> a, b; a.resize(n); b.resize(n);
    
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];





    return 0;
}