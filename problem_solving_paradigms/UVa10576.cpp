// Y2K Accounting Bug.
#include <bits/stdc++.h>
using namespace std;

vector <int> v; int answer;

bool best_option(int s, int d, int m){
    int sum = 0;
    for(int i = 0; i < v.size(); i++)
        sum += v[i];
    if(sum >= 0 && sum > answer) 
        answer = sum;
}

bool place(int i, int s, int d, int m){
    int report = 0;
    if(m < 4) return true; 
    for(int i = (m - 4); i < m; i++)
        report += v[i];     
    if(!i) report += s;
    else   report += d; 
    if(report < 0) return true;
    return false;
}

void print_vector(){
    for(int i = 0; i < v.size(); i++)
        printf("%d ", v[i]);
    printf("\n");
}

void backtrack(int s, int d, int m){
    print_vector();
    if(m == 12) {best_option(s, d, m); return;}
    for(int i = 0; i < 2; i++)
        if(place(i, s, d, m)){
            if(!i) v.push_back(s);
            else   v.push_back(d);        
            backtrack(s, d, m + 1);
        }
    //v.pop_back();
}

void set_parameters(){
    answer = -1; v.clear();
}

int main(){
    int s, d;
    while(scanf("%d", &s) != EOF){
        scanf("%d", &d);
        set_parameters(); 
        backtrack(s, d, 0);
        if(answer == -1) printf("Deficit\n");
        else printf("%d\n", answer);
    }
    return 0;
}