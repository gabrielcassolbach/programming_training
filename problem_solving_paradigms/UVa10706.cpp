#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

typedef long long int ll;

ll values[MAX], digits[MAX], numbers[MAX], p_range[MAX];

int get_digits(int value){
    int digits = 0;
    while(value) {++digits; value /= 10;}
    return digits;
}

void set_array(){
    for(int n = 0; n < MAX; n++) 
        {numbers[n] = n + 1;}
    values[0] = 1;
    for(int n = 1; n < MAX; n++) 
        {values[n] = values[n - 1] + (get_digits(n + 1));}
    digits[0] = 1;
    for(int n = 1; n < MAX; n++)
        {digits[n] = (values[n] + digits[n - 1]);}
}     

int search (int a, int b, int pos){
    ll cont = 0;
    for(int i = 1; i <= numbers[a]; i++){
        int value = i; 
        while(value) {p_range[cont++] = value % 10; value /= 10;}
    }
    for(int i = 1; i <= numbers[b]; i++){
        int value = i; 
        while(value) {p_range[cont++] = value % 10; value /= 10;}
    }
    for(int i = 0; i < cont; i++) printf("%lld ", p_range[i]);
    printf("\n");
    return -1;
}

ll location(int pos){
    int a = 0; int b = MAX - 1; int m = (a + b) / 2;
    while(abs(a - b) != 1){
        if(digits[m] <= pos) 
            {a = m; m = (a + b) / 2;}
        else 
            {b = m; m = (a + b) / 2;}
    }
    printf("(%d , %d)\n", a, b);
    return search(a, b, pos);
}

int main(){
    int t; ll pos;
    scanf("%d", &t); set_array();
    while(t--) {scanf("%lld", &pos); printf("%lld\n", location(pos));}
    return 0;
}
