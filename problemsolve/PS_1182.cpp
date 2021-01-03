#include <iostream> //부분집합의 합이 S인경우, 공집합은 뺴고 
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
	
	solve(pos+1,sum); 	// 더하지 않거나 
	solve(pos+1,sum+arr[pos]);  // 더하거나 
	
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
