#include <iostream>
using namespace std;
int main(){
	
	int N;
	cin >> N;
	
	int spare = 0;
	int t=0;
	int start = N, end = N;
	for(int i=1;i<=N;++i){
		
		spare = N-i; // 4 3 2 1 0 
		
		while(spare--){
			cout << " ";
		}
		for(int j=start;j<=end;++j){
			
			cout << "*";
		}
		cout << "\n";
		start--;
		end++;
		
	}
	
	return 0;
}
