#include <cstdio>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){

	for(int i=0;i<10;i++){
		
		int moveCnt=0; //������ Ƚ��
		
		int arr[100]={0,};
		
		scanf("%d",&moveCnt);  //���� �� 
		
		for(int j=0;j<100;j++){  // ���� �ʱ�ȭ, ���� 
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
