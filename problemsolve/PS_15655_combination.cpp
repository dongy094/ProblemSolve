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
	// 1100 �̸� �̰� 1 2�� 0 2�� ������ ���̴ϱ� 
	// ���� ����� 1���� ������ �ǰ�?
	// 0011 �ϸ� ��� ������ ����� �����µ� 
			
	do{
		for(int i=0;i<N;++i){
		
			if(result[i]==0){
				cout << arr[i] << " ";
			}

		}
		cout <<"\n";	
		
	}while( next_permutation( result,(result+N) )); // ���� �� ��ŭ ���� 
	
	return 0;
}
