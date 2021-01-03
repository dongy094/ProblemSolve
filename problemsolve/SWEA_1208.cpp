#include <cstdio>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){

	for(int i=0;i<10;i++){
		
		int moveCnt=0; //움직임 횟수
		
		int arr[100]={0,};
		
		scanf("%d",&moveCnt);  //덤프 값 
		
		for(int j=0;j<100;j++){  // 높이 초기화, 가로 
			int temp=0;
			scanf("%d",&temp);
			arr[j] = temp;
		
		}

		for(int k=0;k<moveCnt;k++){
			
			sort(arr,arr+100); // nlog(n)	
			
			if(arr[99]==arr[0]) break;
			
			arr[99] = arr[99]-1;
			arr[0] = arr[0]+1;

		}
		
			sort(arr,arr+100);
		


		printf("#%d %d\n",i+1,arr[99]-arr[0]);
	}
	
	return 0;
}
