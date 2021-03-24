#include <iostream>
#include <algorithm>
#define ABS(x) ( x<0 ? -(x) : (x) )
using namespace std;

int N;
int arr[10];
int main(){
	
	cin >> N;
	for(int i=0;i<N;++i){
		cin >> arr[i];
	}
	
	int max_v = -100000000;
	
	sort(arr,arr+N);
	
	do{
		int tmp_sum = 0;
		for(int i=0;i<N-1;++i){
			int tmp = ABS(arr[i]-arr[i+1]);
			tmp_sum += tmp;
		}
		
		max_v = max(max_v,tmp_sum);

	}while(next_permutation(arr,arr+N));
	

	cout << max_v;
	
	return 0;
}
