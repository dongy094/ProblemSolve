#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;

int main(){
	

	int cnt=0;


	for(int i=0;i<10;i++){
		
		int arr[1000]={0,};
		int size=0;
		scanf("%d",&size);
		
		for(int i=0;i<size;i++){
			int temp=0;
			scanf("%d",&temp);
			arr[i] = temp;
		}
		
	
	for(int i=0;i<size;i++){
		
		int l_min = 999;
		int r_min = 999;
		if(arr[i] != 0){
			
			l_min = arr[i]-arr[i-1];
			l_min = min(l_min, (arr[i]-arr[i-2]) );
			r_min = arr[i]-arr[i+1];
			r_min = min(r_min, (arr[i]-arr[i+2]) );
			
			if(l_min>0 && r_min>0){
				cnt += min(l_min,r_min);
			}
		}
	}
	
		
		printf("#%d %d\n",(i+1),cnt);
		cnt = 0;
	}

	return 0;
}
