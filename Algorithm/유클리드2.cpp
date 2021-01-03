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
	
	int a,b,c;
	cin >> a >> b >>c;
	cout << gcd( gcd(a,b),c );  //세개면 두개의 최대공약수 구하고 그거랑 나머지랑 해서 최대공약수 구하기 

	return 0;
}
