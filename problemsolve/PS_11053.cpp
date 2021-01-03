#include <iostream>

using namespace std;

int N;
int arr[1010] = { 0, };
int dp[1010] = { 0, };

void solve() {

	for (int i = 1; i < N; ++i) {
		dp[i] = 1;
		for (int j = 0; j < i; ++j) {
			
			if ( arr[i] > arr[j] && dp[i] <dp[j] + 1  ) {
				dp[i] = dp[j] + 1;
			}

		}

	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	
	dp[0] = 1;
	solve();

	int result = 0;
	
	for (int i = 0; i < N; ++i) {
		if(dp[i] >result ){
			result = dp[i];
		}
	}

	cout << result;

}