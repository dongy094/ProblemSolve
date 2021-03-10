#include <iostream>
using namespace std;
int arr[10010];
int N, M;
	
int cnt = 0;	
int sum = 0;	
int s=0,e=0; 

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for(int i=0;i<N;++i){
		cin >> arr[i];
	}
	

	
	while(1){
		
		if(sum==M){
			cnt++;
			sum += arr[e++];
		}else if(sum>M){	
			sum -= arr[s++];
		}else{ 	
			sum += arr[e++];
		}
		
		if(e>N) break;
		
	}
	
	cout << cnt;
	
	return 0;
}

