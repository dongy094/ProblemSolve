#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int arr[10] = { 0, };
int check[10] = { 0, };
int asc[100] = { 0, };


void solve(int k,int tp) {
	
	if (k == M) {
		for (int i = 0; i < M ; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for(int t=1;t<=N;t++){
		
		if(t<tp) continue;
		
		if(!check[t]){
			arr[k] = t;
			check[t] = 1;
			solve(k+1,t);
			check[t] = 0;
		}
	}
	
	
}

int main() {

	cin >> N >> M;
	solve(0,0);

	return 0;
}
