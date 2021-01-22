#include <iostream>
using namespace std;

int N;
int result;

void solve(int num){
	
	int cnt = 0;
	
	for(int j=1;j<=num;++j){
		if(num%j==0){
			cnt++;
		}
	}
	
	if(cnt==2){
		result++;
	}	
}

int main(){
	
	cin >> N;
	for(int i=0;i<N;++i){
		int tmp;
		cin >> tmp;
		solve(tmp);
	}	
	
	cout << result;
	
}
