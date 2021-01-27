#include <cstdio>
using namespace std;

int arr[6][6];

// 13   14  15  16  17
// 12   3   4   5   18
// 11   2   1   6   19
// 10   9   8   7   20
// 25   24  23  22  21
// 감 감 증 증 감 감 감 증 증 증
 
int n = 1;
int row=3,col=3;
int k=1;
int change=-1;
int main(){
	
	while(1){
		
		for(int i=0;i<n;++i){
			arr[row][col] = k++;
			col += change;
		}
		
		if(n>=5){
			break;
		}
		
		for(int i=0;i<n;++i){
			arr[row][col] = k++;
			row += change;
		}
		
		n += 1;
		change *= -1;
		
	}
	
	for(int i=1;i<=5;++i){
		for(int j=1;j<=5;++j){
			printf("%3d",arr[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
}
