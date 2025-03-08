#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define MAX 112
#define MAX2 11234

int flag[MAX];
int v[MAX];
int n, d;
int ans = 0;

void read(){
	cin >> n >> d;
	for(int i = 1; i <= n; i++)
		 cin >> v[i];
}

// 0 down and 1 up.
void setFlags(){
	for(int i = 1; i <= n; i++)
		flag[i] = 0;
}

void debug(){
	for(int i = 1; i <= n; i++)
		cout << v[i] << " ";
	cout << endl;
}

int get_opt(int j){
	if(v[j] == d && flag[j]){
		ans++; v[j] = -1;
		return 1;
	}
	return 0;
}

int pos_sol(int j, int index){
	if(index != -1) return index;
	if(v[j] == d) return j;
	return -1;
}

void update_v(int j){
	if(v[j] == -1) return;
	if(!flag[j] && v[j] == 0)
		{flag[j] = 1;}
	
	if(flag[j]) 
		{v[j]++;}
	else 
		{v[j]--;}
}

int answer(){
	for(int i = 1; i <= MAX2; i++){
		int index = -1; int has_opt = 0;
		for(int j = 1; j <= n; j++){
			if(!has_opt)
				{has_opt = get_opt(j);} 			
			if(!has_opt)
				{index = pos_sol(j, index);}
			update_v(j);
		}
		if(!has_opt && index != -1)
			{v[index] = -1; ans++;}
		//cout << "debug: " << has_opt << " " << index << endl;
		//debug();
	}
	return ans;	
}

int main(){
	read();	
	setFlags();
	cout << answer() << endl;
	return 0;
}


