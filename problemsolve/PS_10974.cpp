#include <iostream>

using namespace std;
int N;
int arr[8]={0};
bool check[8]={false};
int result[8]={0};

void solve(int k){
	
	if(k==N){
		for(int i=0;i<N;++i){
			cout << result[i] << " ";
		}
		cout << "\n";
	}
	
	for(int i=0;i<N;++i){
		if(!check[i]){
			check[i] = true;
			result[k] = arr[i];
			solve(k+1);
			check[i] = false;
		}
	}
	
	
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	int num = 1;
	for(int i=0;i<N;++i){
		arr[i] = num++;
	}
	
	solve(0);
	
	return 0;
}
