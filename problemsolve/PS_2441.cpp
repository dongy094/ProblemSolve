#include <iostream>
#include <vector>
using namespace std;

int main(){
	int N;
	cin >> N;

	for(int i=N;i>0;--i){
		int spare = N-i;  // 0 1 2 3 4
		for(int j=0;j<N;++j){
			if(j<spare){
				cout << " ";
			}else{
				cout << "*";
			}
		}
		cout << "\n";
	}

	return 0;
}



