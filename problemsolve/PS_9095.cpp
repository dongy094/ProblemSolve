#include <iostream>
using namespace std;

int arr[15]={0,};
int dp[15]={0,};



int cnt=0;

void solve(int n){
	
	for(int i=3;i<=n;++i){
		if(dp[i]) continue;
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	}
	
	arr[cnt++] = dp[n];
}


int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	dp[0] = 1; 
	dp[1] = 1; 
	dp[2] = 2;
	
	int N; cin >> N;
	for(int i=0;i<N;++i){
		cin >> arr[i];
		solve(arr[i]);
	}
	
	for(int i=0;i<N;++i){
		cout << arr[i] << "\n";
	}
		
	return 0;
}
