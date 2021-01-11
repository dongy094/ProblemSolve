#include <iostream>
using namespace std;
int main(){
	
	int N;
	cin >> N;
	int start,end;
	int spare;
	
	start = 1, end = N*2-1;
	
	for(int i=1;i<=N;++i){
		
		int tmp = i;
		while(tmp>1){  // 0 1 2 3 4
			cout << " ";
			tmp--;
		}
		
		for(int j=start;j<=end;++j){
			cout << "*";
		}cout << "\n";
		start++;
		end--;
		
	}
	
	
	return 0;
}
