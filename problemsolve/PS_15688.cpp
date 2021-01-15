#include <iostream>
#define MAX 1000000

using namespace std;
int N;
int arr[MAX+MAX+1]={0,};
// 절대값이 1000000 -> -1000000 ~ 1000000 
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	
	int tmp;
	cin >> N;
	for(int i=0;i<N;++i){
		cin >> tmp;
		arr[ tmp + MAX ]++;
	}		
	
	for(int i=0;i<=MAX+MAX;++i){
		
		while(arr[i]){
			cout << i-MAX << "\n";
			arr[i]--;
		}
			
	}
	
	return 0;
}
