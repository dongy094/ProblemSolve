#include <cstdio>
using namespace std;

int arr[5][5]={0,};
int n = 5; // 배열 크기 가로, 세로 
int k = 0; // 배열에 넣을 숫자 
int row = 0, col = -1; 
int change = 1; // 열 증가, 행 증가, 열 감소, 행 감소, 열 증가, 행 증가, ... 표현 해주기 위한 변수 

// 1   2   3   4   5
// 16  17  18  19  6
// 15  24  25  20  7
// 14  23  22  21  8
// 13  12  11  10  9

int main(){
	
	while(1){
		
		for(int i=1;i<=n;++i){
			
			++k;
			col += change; // col -> 증 감 증 감 ... 
			arr[row][col] = k;
			
		}	
		
		n -= 1;
		if(n<=0) break;
		
		for(int j=1;j<=n;++j){
			
			++k;
			row += change; // row -> 증 감 증 감 ...
			arr[row][col] = k;
			
		}
		change *= -1;
	}
	
	n = 5;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			printf("%3d",arr[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
