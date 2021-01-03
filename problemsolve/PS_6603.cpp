#include <iostream>

using namespace std;


int n;
int check[15];
int arr[15];
int result[15];

void init(){
	for(int i=0;i<15;++i){
		check[i] = 0;
		arr[i] = 0;
		result[i] = 0;
	}
}

void solve(int k,int pre){
	
	// base condition
	if(k==6){
		for(int i=0;i<6;++i){
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for(int i=0;i<n;++i){
		
		
		if(check[i] == 1) continue;
		if(arr[i] < pre) continue;
		
		check[i] = 1;
		result[k] = arr[i];
		solve(k+1,arr[i]);
		check[i] = 0;
			
	}
		
}


int main(){
	
	while(true){
		
		cin >> n;
		if(n==0){
			break;
		}
			
		init();
		
		for(int i=0;i<n;++i){
			cin >> arr[i];
		}
		
		solve(0,-1);
		cout << "\n";
		
	}
	
	
	
	return 0;
}
