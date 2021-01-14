#include <iostream>
using namespace std;

int main(){
	
	int N, K;
	cin >> N >> K;

	int money[10];
	
	for(int i=1;i<=N;++i){
		cin >> money[i];
	}

	int pick = N; // 10
	int cnt = 0;

	while(K!=0){
		
		int mok = K/money[pick]; 
		if( mok ){ // 몫이 존재하면 
			cnt += mok;
			K = K - mok*money[pick];
		}
		pick--;
	}
	cout << cnt;

	return 0;
}
