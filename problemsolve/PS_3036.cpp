#include <iostream>
using namespace std;

int gcd(int a,int b){
	return b ? gcd(b,a%b) : a;
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;++i){
		cin >> arr[i];
		if(i!=0){
			int div = gcd(arr[0],arr[i]);
			cout << (arr[0]/div) << "/" << (arr[i]/div) << "\n";
		}
	}
	
	
	return 0;
	
}
