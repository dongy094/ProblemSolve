#include <iostream>
using namespace std;
			// xÀÇ n½Â 
int dcPower(int x,int n){
	if(n==1) return x;
	if(n==0) return 1;
	
	if( n%2 == 0 ){
		int ret = dcPower(x,n/2);
		return ret*ret;
	}else{
		int ret = dcPower(x,(n-1)/2);
		return ret*ret*x;
	}
	
}

int main(){
	
	int result = dcPower(2,10);
	cout << result;
	
	return 0;
}
