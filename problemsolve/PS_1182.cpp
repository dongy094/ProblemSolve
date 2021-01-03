#include <iostream> //�κ������� ���� S�ΰ��, �������� ���� 
using namespace std;

int N,S;
int arr[21]={0,};
int cnt=0;

void solve(int pos, int sum){
	
	if(pos == N){
		if(sum == S){
			cnt++;
		
		} 
		return;	
	}
	
	solve(pos+1,sum); 	// ������ �ʰų� 
	solve(pos+1,sum+arr[pos]);  // ���ϰų� 
	
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>S;
	for(int i=0;i<N;i++){
		cin >> arr[i];
	}
	
	solve(0,0);
	if(S==0) cnt--;
	cout << cnt;
	
	return 0;
}
