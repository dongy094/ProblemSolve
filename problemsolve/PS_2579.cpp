#include <iostream>
#include <algorithm> 
using namespace std;

int dp[310][310]; // dp[i][j]는 현재까지 j개의 계단을 {연속해서 밟고}
				// i번째 계단까지 올라섰을때 점수 합의 최대값, 단 i번째 계단은
				// 반드시 밟아야 한다. 
int arr[310];
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N; cin >> N;
	for(int i=1;i<=N;++i) cin >> arr[i];
	
	if(N==1) cout << arr[N];
	
	// 
	dp[1][1] = arr[1];
	dp[1][2] = 0;
	dp[2][1] = arr[2]; 
	dp[2][2] = arr[1] + arr[2];
	
	for(int i=3;i<=N;++i){
		dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + arr[i];
		dp[i][2] = dp[i-1][1] + arr[i]; // i계단까지 연속2개밟으면
										// i번쨰, i-1번째 밟고, 대신 이전이 연속
										// 2번 밟은거면 연속 3개라서 X 
	}
	
	cout << max(dp[N][1],dp[N][2]);
	
	return 0;
}
