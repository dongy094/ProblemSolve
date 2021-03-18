#include <iostream>
using namespace std;
int arr[21];
int tmp[20];

void init(){
	
	for(int i=0;i<20;++i){
		tmp[i] = 0; 
	}
	
}

void solve(int s,int e){
	
	int size = ((e-s)+1)/2;
	for(int i=1;i<=size;++i){
		int tmp = 0;
		tmp = arr[s];
		arr[s] = arr[e];
		arr[e] = tmp;
		s++, e--;
	}
	
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	init();
	
	for(int i=1;i<=21;++i){
		arr[i] = i; 
	}
	
	for(int tc = 0;tc<10;++tc){
		int ts,te;
		cin >> ts >> te;
		solve(ts,te);
	}
	
	for(int i=1;i<=20;++i){
		cout << arr[i] << " ";
	}
	
	return 0;
}
