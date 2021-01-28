#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000000]; // arr[i] = i를 1로 만드는데 최소 횟수 

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N; cin >> N;
	arr[1] = 0;
	for(int i=2;i<=N;++i){
		arr[i] = arr[i-1] + 1;
		if(i%2==0){
			arr[i] = min(arr[i/2]+1,arr[i]);
		}
		if(i%3==0){
			arr[i] = min(arr[i/3]+1,arr[i]);
		}
	} 
	
	cout << arr[N];
	
	return 0;
}
