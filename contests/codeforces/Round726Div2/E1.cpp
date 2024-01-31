#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 5123456

bool compare(char* s1, char* s2, int n) //quebra quandro s1> s2
{
    for(int i = 0; i < n; i++)
    {
        if(s1[i] > s2[i])
        {
            return true;
        }
        if(s1[i] < s2[i])
        {
            return false;
        }
        else if(s1[i] == s2[i])
        {
            return compare(&s1[i+1], &s2[i+1], n-1-i);
        }
    }
        return false;
}

int main(){
    int n, k, size;
    char s[MAX];
    char r[MAX];
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> s[i];


    for (int j = 0; j < n; j++)
    {
        s[j+n] = s[j];
    }
    n = 2*n;
    size = n;
    for (int i = 1; i < n; i++)
    {
        bool brk;
        brk = compare(&s[i], &s[0], i);
        if (brk)
        {
            size = i;
            break;
        }
    }
    for (int i = 0; i < ceil(k/size)+2; i++)
    {
        for (int j = 0; j < size; j++)
        {
            r[j+size*i] = s[j];
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout << r[i];
    }
    cout << endl;


    return 0;
}