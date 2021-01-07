#include <cstdio>
#include <algorithm>
using namespace std;

int value,num,arr[100001];

bool solve(int mid){
	
	int ret=0;
	for(int i=0;i<num;++i){
		// 총 액수보다 적으면 상한액을 올려가면서 검사하는거 
		ret += min(mid,arr[i]);
	}
	
	return ( ret <= value );
	
}

int main(){
	
	int left=0,right=0;	
	scanf("%d",&num);
	for(int i=0;i<num;++i){
		scanf("%d",&arr[i]);
		right = max(right,arr[i]);
	}
	scanf("%d",&value);	
	while( left != right ){
		// mid는 상한액  
		int mid = (left + right + 1) / 2;
		if(solve(mid)){ // 상한액 여유있다면 올려도 된다면 
			left = mid; 
		}else{
			right = mid-1; // mid값해서 않됬으니까 -1해주기  
		}
	}
	
	printf("%d\n",left);
	
	return 0;
}
