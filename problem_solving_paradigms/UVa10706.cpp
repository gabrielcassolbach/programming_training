#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000

/*
25875
15282
141
*/

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

int get_digit(int pos, int value){
    int i = get_digits(value) - 1; int s[7]; 
    while(value) {s[i--] = value % 10; value /= 10;} 
    return s[pos - 1];  
}

ll create_prange(int a, int b){
    ll cont = 0;
    for(int i = 1; i <= numbers[a]; i++){
        int value = i; 
        for(int j = 1; j <= get_digits(value); j++){ // 1 -> 2.
            p_range[cont++] = get_digit(j, value);
        }
    }
    for(int i = 1; i <= numbers[b]; i++){
        int value = i; 
        for(int j = 1; j <= get_digits(value); j++){ // 1 -> 2.
            p_range[cont++] = get_digit(j, value);
        }
    }
    return cont;
}

int search (int a, int b, int pos){
    ll range_size = create_prange(a, b); ll cont = 0;
    if(pos == digits[a]) {return p_range[range_size - 1 - (values[a] - values[a - 1])];}
    for(int n = digits[a] + 1; n <= digits[b]; n++){ 
        if(n == pos) return p_range[cont];
        cont++; 
    }
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
    return search(a, b, pos);
}

int main(){
    int t; ll pos;
    scanf("%d", &t); 
    set_array(); 
    while(t--) {scanf("%lld", &pos); printf("%lld\n", location(pos));}
    return 0;
}
