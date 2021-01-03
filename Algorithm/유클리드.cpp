#include <iostream>
#include <algorithm>
using namespace std;


int gcd(int a,int b){
	
	if(b==0){
		return a;
	}
	else{
		if(a>=b){
			return gcd(b,a%b);
		}
		else{
			swap(a,b);
			gcd(a,b);
		}
		
	}
	
}

int main(){
	
	int a,b;
	cin >> a >> b;
	cout << gcd(a,b);

	return 0;
}
