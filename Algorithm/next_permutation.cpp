#include <iostream>
#include <algorithm>
using namespace std;

// combination

int main(){
	
	int a[5] = {0,0,0,1,1};
	do{
		for(int i=0;i<5;++i){
			cout << a[i] << " ";
		}
		cout << "\n";
	}while(next_permutation(a,a+5));
	
	return 0;
}
