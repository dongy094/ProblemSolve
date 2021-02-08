#include <iostream>

using namespace std;
int TestCase = 0;
int N = 0;
int arr[12][12] = {0,};


// 0 0 0 0 0
// 0 1 0 0 0
// 0 1 1 0 0
// 0 1 2 1 0
// 0 1 3 3 1
// N=4이면 5할당하깅 
 
void init(){ // N = 4+1 -> 5
 	for(int i=0;i<N+1;++i){
 		for(int j=0;j<N+1;++j){
 			arr[i][j] = 0;
		}
	}
	arr[1][1] = 1;
}
 
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> TestCase;
	
	for(int num=1;num<=TestCase;++num){
		
		cin >> N;
		
		init();

		for(int i=1;i<=N;++i){
			for(int j=1;j<=N;++j){
				if(i==1 && j==1) continue;
				arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
			}
		}
		
		cout << "#" << num << "\n";
		for(int i=1;i<=N;++i){
			for(int j=1;j<=N;++j){
				if(arr[i][j] != 0){
					cout << arr[i][j] << " ";
				}
			}
			cout << "\n";
		}
		
		
	}
	
	
	
	return 0;
}
