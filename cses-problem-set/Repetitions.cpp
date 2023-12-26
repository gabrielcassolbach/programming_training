#include <bits/stdc++.h>
using namespace std;

int main(){
    int counter = 1, max_counter = -1;
    char c, c1;
    scanf("%c", &c1);
    while(scanf("%c", &c) != EOF){
        if(c1 == c)
            counter++;
        else
            counter = 1;
        c1 = c;
        if(max_counter < counter)
            max_counter = counter;
    }
    printf("%d\n", max_counter);
    return 0;
}