#include <iostream>
using namespace std;

int quicksort( int arr[],int left,int right ){
	
	if(left<right){  // 배열1개라면 교환할 필요가 없다. 
					 // left<right 면 교환할 여지가 남아있다. 
		int p = left, i=left+1, j=right; 
		while( i <= j ){
			while( arr[i] <= arr[p] ) i++;
			while( arr[j] > arr[p] ) j--;
			
			if( i < j ){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		int temp = arr[p];
		arr[p] =  arr[j];
		arr[j] = temp;
		
		quicksort(arr,left,j-1);
		quicksort(arr,j+1,right);
	}
}

int main(){
	
	int arr[10] = {91,51,4,11,8,72,46,88,3,67};
	quicksort(arr,0,9);
	for(int i=0;i<10;++i){
		cout << arr[i] << " ";
	}
	cout << endl;
	
	return 0;
}
