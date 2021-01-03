#include <iostream>
#include <algorithm>

using namespace std;
int N,M;
int arr[10];
int result[10];
int check[10];

void solve(int k,int pre_v){
	
	//base condition
	if( k==M ){
		for(int i=0;i<M;++i){
			cout << result[i] <<" ";
		}
		cout << "\n";
		return;
	}
	
	for(int i=0;i<N;++i){
		
		if(check[i]) continue;
		
		if(pre_v > arr[i]) continue; // 이전에 넣은 수보다 작은 수는 거절한다.
									 // ex)  1이면 7 8 9만
									 // 7이면 8 9만  
		
		check[i] = 1;
		result[k] = arr[i];
		solve(k+1,arr[i]);
		check[i] = 0;
		
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
