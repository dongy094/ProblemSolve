#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
int arr[10];
int check[10];
int result[10];

void solve(int k,int pre){
	
	//base condition
	if(k==M){
		for(int i=0;i<M;++i){
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for(int i=0;i<N;++i){
		
		if( arr[i] >= pre ){
			result[k] = arr[i];
			solve(k+1,arr[i]);
		}
		
	}
	
	
	
}


int main(){
	
	cin >> N >> M;
	for(int i=0;i<N;++i){
		cin >> arr[i];
	}
	
	sort(arr,arr+N);
	solve(0,-1);
	
	
	return 0;
}
