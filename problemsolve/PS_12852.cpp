#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000005];
int route[1000005];
int N;

int main(){
	
	cin >> N;
	arr[1] = 0;
	for(int i=2;i<=N;++i){
		
		arr[i] = arr[i-1] + 1;
		route[i] = i-1;
		
		if(i%2==0){
			if(arr[i]>arr[i/2]+1){
				arr[i] = arr[i/2]+1;
				route[i] = i/2;
			}
		
			
		}
		if(i%3==0){
			if(arr[i]>arr[i/3]+1){
				arr[i] = arr[i/3]+1;
				route[i] = i/3;
			}
		
		
		}
	}
	
	cout << arr[N] << "\n";
	int pre = N;
	while(true){
		cout << pre << " ";
		if(pre==1){
			break;
		}
		pre = route[pre];
	
	}
	
	
	return 0;
}
