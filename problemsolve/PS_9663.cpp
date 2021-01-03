#include <iostream>
#define ABS(x) ( x<0 ? -(x):x )

using namespace std;
int N;
int arr[20]={0,}; // i는행, arr[i]는 열 <- 퀸 위치 
int cnt=0;
bool check(int cur){
	
	for(int i=1;i<cur;i++){
		if( arr[i] == arr[cur] || ABS(cur-i) == ABS(arr[i]-arr[cur]) ){	
			return false;
		}
	}
	return true;
}

void solve(int x){ // x행 
	
	if( !check(x) ) return;
	
	if(x==N){
		cnt++;
		return;
	}

	for(int i=1;i<=N;i++){
		arr[x+1] = i;
		solve(x+1);
	}

}



int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	solve(0);
	cout << cnt;
	
	return 0;
}
