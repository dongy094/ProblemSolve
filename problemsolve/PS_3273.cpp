#include <iostream>
#include <algorithm>
using namespace std;

int arr[100010]={0,};
int n,x;
int result = 0;

int main(){
	
	cin >> n;
	for(int i=0;i<n;++i){
		cin >> arr[i];
	}	
	cin >> x;
	
	sort(arr,arr+n); 
	
	int front,rear; // two pointer
	front = 0, rear = n-1;
	
	while(1){
		
		if(front>=rear) break;
		int sum = arr[front] + arr[rear];
		if(sum == x){
			result++;
			front++, rear--;
		}else if(sum>x){
			rear--;
		}else if(sum<x){
			front++;
		}		
			
	}
	
	cout << result;
	return 0;
}
