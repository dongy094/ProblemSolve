#include <iostream>
using namespace std;

int N;
int arr[200];
int dp[200];

int solve(){
	
	int max = 0;	
	
	// dp[i] 나를 포함하여 가장 긴 LIS의 길이
	// 순서대로 줄 세우니까 최대 길이를 세워 놓으면
	// 최대 길이에 해당 하지 않는 숫자를 최소로 옮길 수 있다. 
	dp[0] = 1;
	for(int i=1;i<N;++i){
		dp[i] = 1;
		for(int j=0;j<i;++j){
			if(arr[i]>arr[j] && dp[i]<dp[j]+1){
				dp[i] = dp[j] + 1;
			}
		}
	}
	
	for(int i=0;i<N;++i){
		if(dp[i] > max){
			max = dp[i];
		}
	}
	
	return max;
}

int main(){
	
	cin >> N;
	for(int i=0;i<N;++i){
		cin >> arr[i];
	}
	
	cout << N-solve();
	
	
	return 0;
}
