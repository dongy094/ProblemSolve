#include <iostream>
using namespace std;

int arr[100010]={0,};
int result[100010]={0,}; //´©Àû ÇÕ 

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N,M;
	cin >> N >> M;

	result[0] = 0;
	for(int i=1;i<=N;++i){
		cin >> arr[i];
		result[i] = arr[i] + result[i-1];
	}
	
	while(M--){
		int a,b;
		cin >> a >> b;
		cout << result[b] - result[a-1] << "\n";	
	}

}
