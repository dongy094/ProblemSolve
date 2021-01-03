#include <cstdio>
using namespace std;

int N,K;
int arr[2][7];

int main(){
	
	scanf("%d %d",&N,&K);
	
	int room=0;
	
	for(int i=0;i<N;++i){
		int grade, gender;
		scanf("%d %d",&gender, &grade);
		arr[gender][grade]++; 
	}
	
	for(int i=0;i<2;++i){
		
		for(int j=1;j<=6;++j){
			
			room += ( arr[i][j] / K );
			if(arr[i][j] % K != 0){
				room++;
			}
			
		}
	}
	printf("%d",room);
}
//
//     1  2  3  4  5  6  
//
//[0]  1  2  1  0  1  1
//
//[1]  2  1  3  1  2  1
//


