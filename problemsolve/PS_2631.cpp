#include <iostream>
using namespace std;

int N;
int arr[200];
int dp[200];

int solve(){
	
	int max = 0;	
	
	// dp[i] ���� �����Ͽ� ���� �� LIS�� ����
	// ������� �� ����ϱ� �ִ� ���̸� ���� ������
	// �ִ� ���̿� �ش� ���� �ʴ� ���ڸ� �ּҷ� �ű� �� �ִ�. 
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
