#include <cstdio>
#include <cstring>
using namespace std;
// 5
// 1 2 4 7 8 3
// 1 1 2 2 4 6
// 6 6 7 7 6 7
// 0 5 4 0 6 0
// 1 0 1 1 2 3
int nums[10];

int solve(int arr[],int pos,int used){
	
	if(pos == 6){
		int run=0,tri=0;
		for(int i=0;i<2;++i){
			if( arr[i*3+1] == arr[i*3]+1 && arr[i*3+2] == arr[i*3+1]+1 ){
				++run;
			}else if(arr[i*3] == arr[i*3+1] && arr[i*3+1] == arr[i*3+2]){
				++tri;
			}
		}	
		
		if( (tri+run) == 2 ){
			return 1;
		}else{
			return 0;
		}
		
	}
	
	for(int p=0;p<6;++p){
		if( used & (1<<p) ){
			continue;
		}
		arr[pos] = nums[p]; 
		if(solve(arr, pos+1, used|(1<<p))){
			return 1;
		}
		
	}
	
	return 0;
}

int main(){
	
	
	freopen("baby_gin.txt","r",stdin);
	
	int tc;
	scanf("%d",&tc);
	for(int i=0;i<tc;++i){
		for(int j=0;j<6;++j){
			scanf("%d",&nums[j]);
		}
		int arr[6]; // 값을 저장할 임시 배열
		
		printf("#%d %d\n",i+1,solve(arr,0,0));
		memset(nums,0,sizeof(nums));
		memset(arr,0,sizeof(arr));
	}
	
	
	
	return 0;
}
