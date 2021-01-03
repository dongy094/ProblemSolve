#include <cstdio>

using namespace std;

int main(){
	
	int arr[3] = {3,1,8};
	
	
	for( int i=0 ; i<(1<<3) ; i++) {
		for( int j=0 ; j<3 ; j++ ){
			if(i & (1<<j) ){
				printf("%d ",arr[j]);
			}
		}
		printf("\n");
	}
	
	
	
	return 0;
}
