#include <iostream>
#include <algorithm>
using namespace std;


int gcd(int a,int b){
	
	if(b==0){
		return a;
	}
	else{
		return gcd(b,a%b);
	}
	
}

int main(){
	
	
	int t;
	int cnt=0;
	int a,b;
	cin >> t;
	int tt=t;
	int arr[t];
	
	while(t--){
		
		cin >> a >>b;
		
		int g =gcd(a,b);
		arr[cnt] = (a*b)/g;
		cnt++;
	}
	
	for(int i=0 ; i<tt ; i++){
		cout << arr[i] <<'\n';
	}

	return 0;
}
