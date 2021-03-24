#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[15];

// 0="+" , 1="-" , 2="*" , 3="/"
int oper[4]; // ¿¬»êÀÚ °¹¼ö 

int max_v = -1000000000+1;
int min_v = 1000000000+1;

void solve(int plus, int minus, int multi, int divide, int cnt ,int sum){
	
	if(cnt == N ){
		max_v = max(max_v,sum);
		min_v = min(min_v,sum);
	}

	if(plus>0){
		solve(plus-1,minus,multi,divide,cnt+1,sum+arr[cnt]);
	}
	if(minus>0){
		solve(plus,minus-1,multi,divide,cnt+1,sum-arr[cnt]);
	}
	if(multi>0){
		solve(plus,minus,multi-1,divide,cnt+1,sum*arr[cnt]);
	}
	if(divide>0){
		solve(plus,minus,multi,divide-1,cnt+1,sum/arr[cnt]);
	}
	
}


int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for(int i=0;i<N;++i){
		cin >> arr[i];
	}
	for(int i=0;i<4;++i){
		cin >> oper[i];
	}
	
	solve(oper[0],oper[1],oper[2],oper[3],1,arr[0]);
	cout << max_v << "\n" << min_v;
	
	return 0;
}
