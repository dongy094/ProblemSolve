#include <iostream>
using namespace std;
int arr[10100];

int main(){
	
	int N,K;
	cin >> N >> K;
	int cur = 1;
	for(int i=1;i<=N;++i){
		if(N%i==0){
			arr[cur++] = i;
		}
	}	 
	
	cout << arr[K];
	
}
