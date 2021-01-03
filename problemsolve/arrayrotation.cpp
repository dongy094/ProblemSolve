#include <iostream>
#include <utility>
using namespace std;

	int arr[10][10]={
		{1,2,3,4},{5,6,7,8},{9,10,11,12}
	};
	
	int arr1[10][10]={
		{1,2,3},{4,5,6},{7,8,9},{10,11,12}
	};
	
	
int r=3;
int c=4;

int r1=4;
int c1=3;

void rotate(){//시계방향90도 
	
	int tmp1[10][10]={0,};
	for(int i=0;i<r;++i){
		for(int j=0;j<c;++j){
			tmp1[i][j] = arr[i][j];
		}
	}
	
//	  * * * *         * * *
//    * * * *   ==>   * * *
//    * * * *         * * *
//                    * * *
	
	for(int i=0;i<c;++i){
		for(int j=0;j<r;++j){
			arr[i][j] = tmp1[r-1-j][i];
		}
	}
	
	swap(r,c);
	
}

void rerotate(){ //반시계방향90도 
	
	int tmp2[10][10]={0,};
	for(int i=0;i<r1;++i){
		for(int j=0;j<c1;++j){
			tmp2[i][j] = arr1[i][j];
		}
	}
	
//	  * * *          * * * *
//    * * *    ==>   * * * *
//    * * *          * * * *
//    * * *                
	
	for(int i=0;i<c1;++i){
		for(int j=0;j<r1;++j){
			arr1[i][j]=tmp2[j][r-1-i];
		}
	}
	
	
	swap(r1,c1);
	
}


int main(){
	

	
	for(int r=0;r<4;++r){
		for(int c=0;c<3;++c){
			cout << arr1[r][c] <<"  ";
		}
		cout << "\n";
	}
	//rotate(); 
	rerotate(); cout << "\n";
	
	for(int i=0;i<r1;++i){
		for(int j=0;j<c1;++j){
			cout << arr1[i][j] <<"  ";
		}
		cout << "\n";
	}

	
	return 0;
}
