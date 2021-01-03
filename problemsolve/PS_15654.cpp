#include <iostream>
#include <algorithm>

using namespace std;
int N,M;
int arr[10];
int result[10];
int check[10]={0};

void solve(int k,int pre){
	
	//base condition
	if(k==M){
		
		for(int i=0;i<M;++i){
			cout << result[i] << " ";
		}
		cout << "\n";
		
		return;
	}
	
	for(int i=0;i<N;++i){
	
	
		if(!check[i]){
			check[i] = 1;
			result[k] = arr[i];	
			solve(k+1,arr[i]);
			check[i] = 0;
		}
	
		
		
		
	}
	
	
	
}

int main(){
	
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> N >> M;
	
	for(int i=0;i<N;++i){
		cin >> arr[i];
	}

	sort(arr,arr+N);
	solve(0,-1);
	
	
	return 0;
}
