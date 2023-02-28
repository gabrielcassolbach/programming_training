// Fill the containers -> UVa11413.
// --------------------------------
// Solution using the content of the page:
// https://www.redgreencode.com/binary-search-answer-uva-11413-uva-12032/

#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int v[MAX];

int sum_v(int n){
    int sum = 0;
    for(int i = 0; i < n; i++)  
        sum += v[i];
    return sum;
}

bool tryCapacity(int n, int m, int maxCapacity){
    int current_container_size, number_of_containers;
    current_container_size = 0; 
    number_of_containers = 0;
    for(int i = 0; i < n; i++){
        if(v[i] > maxCapacity) 
            return false;
        if((current_container_size + v[i]) > maxCapacity)
            current_container_size = 0;
        if(!current_container_size)
            number_of_containers++;
        if(number_of_containers > m)
            return false;
        current_container_size += v[i];
    }
    return true;
}

void binary_search(int n, int m){
    int lo, hi, best, mid;
    lo = 1;
    hi = sum_v(n);
    best = hi + 1;
    while (lo <= hi){
        mid = lo + (hi - lo) / 2;
        //printf("lo: %d & hi: %d & mid: %d\n", lo, hi, mid);
        if(tryCapacity(n, m, mid))
            {best = mid; hi = --mid;}
        else 
            {lo = ++mid;}
    }
    printf("%d\n", best);
}

void set_parameters(){memset(v, 0, sizeof v);}

int main(){
    int n, m;
    while(scanf("%d", &n) != EOF){
        scanf("%d", &m);
        set_parameters();
        for(int i = 0; i < n; i++) 
            scanf("%d", &v[i]);
        binary_search(n, m);
    }
    return 0;
}
