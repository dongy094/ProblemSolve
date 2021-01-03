#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
int arr[10]={0};
int result[10]={0};

int main(){
	
	cin >> N >> M;

	for(int i=0;i<N;++i){
		cin >> arr[i];
	}
	sort(arr,arr+N);
	
	for(int i=0;i<N;++i){
		if( i < M ){
			result[i] = 0;	
		}else{
			result[i] = 1;
		}
	}
	// 1100 이면 이게 1 2개 0 2개 조합의 끝이니까 
	// 조합 결과가 1개만 나오는 건가?
	// 0011 하면 모든 조합의 결과가 나오는데 
			
	do{
		for(int i=0;i<N;++i){
		
			if(result[i]==0){
				cout << arr[i] << " ";
			}

		}
		cout <<"\n";	
		
	}while( next_permutation( result,(result+N) )); // 조합 수 만큼 돈다 
	
	return 0;
}
