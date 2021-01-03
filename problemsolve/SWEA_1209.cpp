#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	
	for(int t=0; t<10 ;t++){
		
		int number=0;
		scanf("%d",&number);
		int arr[100][100]={0,};
		
		int max_sum=-99;
		int acros_sum=0;
		int bcros_sum=0;
		
		for(int i=0; i<100; i++) {
				for(int j=0; j<100; j++) {
					scanf("%d",&arr[i][j]);
				}
		}

		for(int i=0;i<100;i++){               
			int row_sum=0;
			int col_sum=0;
			for(int j=0;j<100;j++){
				
				row_sum+=arr[i][j];
				col_sum+=arr[j][i];
				
			}
			if(row_sum>max_sum) max_sum=row_sum;
			if(col_sum>max_sum) max_sum=col_sum;
		}
		
		for(int q=0;q<100;q++ ){
			
			acros_sum += arr[q][q];
			bcros_sum += arr[q][100-q-1];
		}
		max_sum = max( max_sum, max(acros_sum,bcros_sum) );
	
		printf("#%d %d\n",number,max_sum);
	}
	
	return 0;
}


