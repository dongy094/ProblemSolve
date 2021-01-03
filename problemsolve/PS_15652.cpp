#include <iostream>
using namespace std;
int N,M;
int arr[1000]={0,};

void solve(int n,int pre_v){
	
	if( n==M ){
		for(int i=0;i<M;i++){
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for(int i=1;i<=N;i++){
		if( i < pre_v ) continue;
		arr[n]=i;
		solve(n+1,i);
	}
	
	
	
}


int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	solve(0,0);
	
	
	
	return 0;
}

