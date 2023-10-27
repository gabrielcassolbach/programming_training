#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

char s[MAX];
int usedi[MAX];
int k, total;

int isChar(char c){
    return (c >= 'a' && c <= 'z');
}

void readValues(){
    int i = 0; 
    scanf("%c", &s[i]);
    while(isChar(s[i]))
        scanf("%c", &s[++i]);
    scanf("%d", &k);
    total = i;
}

void getMinString(){
    int j = 0, ctrler = 0;
    vector<char> auxs; 
    for(int i = 0; i < MAX; i++) usedi[i] = -1;
    while(j <  total){
        for(int i = ctrler; i < total; i += k){
            if (usedi[i] == -1)
                {usedi[i] = 0; auxs.push_back(s[i]); j++;}
        }
        sort(auxs.begin(), auxs.end());
        int index = 0;
        for(int i = ctrler; i < total; i += k)
            {s[i] = auxs[index++];}
        auxs.clear();
        ctrler++;
    }
}

void printString(){
    for(int i = 0; i < total; i++)
        printf("%c", s[i]);
    printf("\n");
}

int main(){
    readValues();
    getMinString();
    printString();
    return 0;
}
