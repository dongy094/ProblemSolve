#include <iostream>
#include <algorithm> 
using namespace std;

int dp[310][310]; // dp[i][j]�� ������� j���� ����� {�����ؼ� ���}
				// i��° ��ܱ��� �ö����� ���� ���� �ִ밪, �� i��° �����
				// �ݵ�� ��ƾ� �Ѵ�. 
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
		dp[i][2] = dp[i-1][1] + arr[i]; // i��ܱ��� ����2��������
										// i����, i-1��° ���, ��� ������ ����
										// 2�� �����Ÿ� ���� 3���� X 
	}
	
	cout << max(dp[N][1],dp[N][2]);
	
	return 0;
}
