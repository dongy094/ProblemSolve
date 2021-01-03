#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

string str;
int cnt=0;
int ans=0;
int arr[1000000][15]={0,};

void solve(int pos, int num){
	
	if( num == cnt ){
		ans = max(ans,stoi(str));
		return;
	}
	
	//중복 체크하기 - 시간줄이기
	if(arr[stoi(str)][num]){
		return;
	}
	arr[stoi(str)][num]=1;
	
	
	for(int i=pos ; i<str.size() ; i++){
		for(int j=i+1 ; j<str.size() ; j++){
			
				swap(str[i],str[j]);
				solve(i,num+1);
				swap(str[i],str[j]); 

		}
	}
	

}

int main(){
	
	int tc;
	cin >> tc;
	for(int i=1;i<=tc;i++){
				
		cin >> str >> cnt;
		solve(0,0);
		printf("#%d %d\n",i,ans);
		memset(arr,0,sizeof(arr));
		ans=0;
		cnt=0;	
		
	}
	
	return 0;
}
