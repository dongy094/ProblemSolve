#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];
int result[10];
int N,M;

void solve(int k,int pre){
	// base condition
	if(k==M){
		for(int i=0;i<M;++i){
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	int tmp=0;
	for(int i=0;i<N;++i){
		
		if(arr[i] >= pre && tmp != arr[i]){
			tmp = arr[i];
			result[k] = arr[i];
			solve(k+1,arr[i]);	
		}
		
		
		
	}
	
	
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	for(int i=0;i<N;++i){
		cin >> arr[i];
	}
	
	sort(arr,arr+N);
	solve(0,-1);
	
	
	return 0;
}
