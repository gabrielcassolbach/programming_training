// algoritmo de força bruta.
// Solução baseada no vídeo: https://www.youtube.com/watch?v=IOfsZ-FjqyQ
#include <bits/stdc++.h>
using namespace std;

#define MAX 300

struct color {
	int r;
	int g;
	int b;
};

color v[MAX]; int n;

void read(){
	cin >> n; 
	for(int i = 0; i < n; i++){
		cin >> v[i].r; 
		cin >> v[i].g; 
		cin >> v[i].b;
	}
}

void answer(){
	int a_r, a_g, a_b, ans = 0;
	for(int i = 0; i <= 255; i++){ // r
		for(int j = 0; j <= 255; j++){ // g
			for(int k = 0; k <= 255; k++){ // b
				int d = 1000; // distancia default.	
							
				for(int l = 0; l < n; l++) {
					int cur_d = abs(v[l].r - i) + abs(v[l].g - j) + abs(v[l].b - k);
					if(cur_d < d) d = cur_d;
				}
					
				if(d > ans){ 
					a_r = i; a_g = j; a_b = k;
					ans = d;
				}
			}
		}
	}

	cout << a_r << ' '<< a_g << ' ' << a_b << endl;
}

int main(){
	read();		
	answer();
	return 0;
}


