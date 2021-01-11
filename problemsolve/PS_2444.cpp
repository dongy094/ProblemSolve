#include <iostream>
using namespace std;
int main(){
	
	int N;
	cin >> N;
	
	int start=N,end=N;
	int spare;
	for(int i=1;i<=N*2-1;++i){
	
		if(i<=N){
			spare = N-i; // 4 3 2 1 0
			while(spare--){
				cout << " ";
			}
			for(int j=start;j<=end;++j){
				cout << "*";
			}cout <<"\n";
			start--;
			end++;
		}else{
						 // i = 6 7 8 9
			int tmp = 0; // 	1 2 3 4
			tmp = i-N;
			while(tmp--){
				cout << " ";
			}
			for(int j=start;j<=end;++j){
				cout << "*";
			}cout << "\n";
			start++;
			end--;
		}
		
		if(i==N){
			start+=2;
			end-=2;
		}
	}
	
	
	
	
	
	
	return 0;
}
