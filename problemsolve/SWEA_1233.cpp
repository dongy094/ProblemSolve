#include <cstdio>
#include<iostream>
#include <cstring>
using namespace std;


char arr[201];

int main(){
	
	int TestCase = 10;
	
	for(int tc  = 1 ; tc <= TestCase ; tc++){
		
		memset(arr,0,sizeof(arr));
		
		int size=0;
		scanf("%d",&size);
		
		for(int i=1;i<=size;i++){
			
			int num=0;
			char ch=0;
			
//			scanf("%d",&num);
//			scanf("%c",&ch);
//			getchar();
			cin >> num >> ch;
			arr[num]=ch;
			
			char t1,t2;
			if( i*2 <= size  ){  
				scanf("%d",&t1);
			}else{}
			
			if(i*2+1 <= size){
				scanf("%d",&t2);
			}else{}
			
		}
		

		
		
		for(int j=1;j<=size;j++){
			
			if( j > size/2 ){ // is leaf node	
				if(arr[j]=='+' || arr[j]=='-' || arr[j]=='*' || arr[j]=='/' ){
					printf("#%d 0\n",tc);
					break;
				}else{ // everyting is num
					if(j == size){
						printf("#%d 1\n",tc);
					}
				}	
				
			}else if( j <= size/2 ){ // is not leaf node, to be sign
				if( arr[j]=='+' || arr[j]=='-' || arr[j]=='*' || arr[j]=='/' ){	}
				else{
					printf("#%d 0\n",tc);
					break;
				}
			}
	
		}

	}
	
	return 0;
}
