#include <iostream>
using namespace std;
int main(){
	
	int N;
	cin >> N;
	int start=1,end=2*N;
	// 2,9 3,8 4,7 5,6
	
	// 5,6  
	// 4,7
	
	for(int i=1;i<=N*2-1;++i){
		
		if(i<=N){
			for(int j=1;j<=N*2;++j){
				if(j<=start || j>=end){
					cout << "*";
				}else{
					cout << " ";
				}
			}cout << "\n";	
			start++;
			end--;
		}else{ // s=5,e=6 에서 처음 시작 
			for(int j=1;j<=N*2;++j){ // 	4,7   3,8   2,9   1,10
				
				if(j<start || j>end){
					cout << "*";
				}else{
					cout << " ";
				}
			}cout << "\n";
			start--;
			end++; 
		}
		
		if(i==N){
			start--;
			end++;	
		}
		
	}
	
	
	
	
	
	
	return 0;
}
