#include <iostream>
#include <vector>
using namespace std;

int main(){
	int N;
	cin >> N;
	for(int i=1;i<=N;++i){
		int spare = N-i; // 4 3 2 1 0
		for(int j=1;j<=N;++j){
			if(j<=spare){
				cout << " ";
			}else{
				cout << "*";
			}
		}
		cout << "\n";
	}


	return 0;
}
