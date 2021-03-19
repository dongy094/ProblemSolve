#include <iostream>
#include <cstring>
#define MAX 1004000 
using namespace std;
int N;
int arr[MAX]; // sosu == 0

void sosu(){ // mark sosu
	
	memset(arr,0,sizeof(arr));
	arr[1]=1;
	
	for(int i=2;i*i<MAX;++i){
		if(arr[i]) continue;
		for(int j=i+i;j<MAX;j+=i){
			arr[j] = 1;
		}
	} 
	
}

int solve(int st){ //한자리 숫자도 펠린드롬이다! 

		string str = to_string(st);
		int size = str.size();
		int f_cnt = size/2;
		for(int j=0;j<f_cnt;++j){
			if(str[j] != str[size-1-j]){
				return 0;
			}
		}
		return 1;
		
	}
	


int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	
	sosu(); // mark sosu

	for(int i=N;;++i){
		if(arr[i]) continue;  // 1 == 소수아니면 
		if(solve(i)){
			cout << i;
			return 0;
		}
	}

	return 0;
}
