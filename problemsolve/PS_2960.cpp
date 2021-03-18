#include <iostream>

using namespace std;
int arr[1010];
int check[1010]={0,}; // check = 1 

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N,K;
	cin >> N >> K;
	int cnt = 0;
	
	for(int i=2;i<=N;++i){
		for(int j=i;j<=N;j+=i){
			if(check[j]==0){
				check[j] = 1;
				cnt++;
				if(cnt == K){
					cout << j;
					return 0;
				}
			}
		}
	}
	
	
	
	
	return 0;
}
