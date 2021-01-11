#include <iostream>
#include <vector>
using namespace std;

int main(){
	int N;
	cin >> N;
	for(int i=N;i>0;--i){ // 5 4 3 2 1
		for(int j=1;j<=i;++j){
			cout <<"*";
		}
		cout << "\n";
	}
	

	return 0;
}
