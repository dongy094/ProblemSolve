#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
int arr[10];
int result[10];
int check[10];

void solve(int k,int pre){
	
	if(k==M){
		for(int i=0;i<M;++i){
			cout << result[i] <<" ";
		}
		cout <<"\n";
		return;
	}
	

	int tmp=0;
	
	for(int i=0;i<N;++i){
		
		if( check[i] ) continue;
		if( arr[i] < pre ) continue;
		
		// tmp 위치가 중요하네 이전꺼도, 1, 9, 9 인 경우 생각해보기
        // 1 9 조합 후 1 9 다시 올때 생각!
		if(arr[i] != tmp){
			tmp = arr[i];	
			check[i] = 1;	
			result[k] = arr[i];
			solve(k+1,arr[i]);
			check[i] = 0;
			
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
