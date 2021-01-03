#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
int arr[10];
int result[10];
int check[10];

void solve(int k,int pre){
	
	if(k==M){
		for(int i=0;i<M;++i){
			cout << result[i] <<" ";
		}
		cout <<"\n";
		return;
	}
	

	int tmp=0;
	
	for(int i=0;i<N;++i){
		
		if( check[i] ) continue;
		if( arr[i] < pre ) continue;
		
		// tmp ��ġ�� �߿��ϳ� ��������, 1, 9, 9 �� ��� �����غ���
        // 1 9 ���� �� 1 9 �ٽ� �ö� ����!
		if(arr[i] != tmp){
			tmp = arr[i];	
			check[i] = 1;	
			result[k] = arr[i];
			solve(k+1,arr[i]);
			check[i] = 0;
			
		}
		
	}
	
	
}

int main(){
	
	cin >> N >> M;
	for(int i=0;i<N;++i){
		cin >> arr[i];
	}
	sort(arr,arr+N);
	solve(0,-1);
	
	
	
	return 0;
}
