#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
int arr[10];
int result[10];
int check[10];

void solve(int k){
	
	//base condition
	if(k==M){
		for(int i=0;i<M;++i){
			cout << result[i] << " ";
		}
		cout <<"\n";
		return; // Å»Ãâ!!!!!!!!! 
	}
	
	for(int i=0;i<N;++i){
		
		
		result[k] = arr[i];
		solve(k+1);
		
	}
	
	
	
}


int main(){
	
	cin >> N>> M;
	for(int i=0;i<N;++i){
		cin >> arr[i];
	}
	
	sort(arr,arr+N);
	solve(0);
	
	return 0;
}
