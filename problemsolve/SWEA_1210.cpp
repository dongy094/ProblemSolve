#include <cstdio>

using namespace std;

int main(){
	
	int TestCase = 10;
	
	while(TestCase--){
		
		int testNum=0;
		int enterNum=0; // enter position
		int exitNum=0;
		
		int arr[100][100]={0,};
		bool check[100][100]={false,};  //ture가 방문한것 
		
		scanf("%d",&testNum);
	
		for(int i=0 ; i<100 ; i++){
			for(int j=0 ; j<100 ; j++){
				scanf("%d",&arr[i][j]);
			}
		}

		for(int i=0;i<100;i++){
			if( arr[99][i] == 2 ) exitNum = i;
		}

		int row=99; 
		int col=exitNum;
		
		while(true){

			if( ((col-1)<100 && (col-1)>=0) && arr[row][col-1]==1 && check[row][col-1]==false ){ //좌로 이동가능 
				check[row][col] = true; //해당칸 방문처리하고 이동 
				col--;
			}else if( ((col+1)<100 && (col+1)>=0) && arr[row][col+1]==1 && check[row][col+1]==false ){ //우로 이동가능 
				check[row][col] = true;
				col++;
			}else{ //좌우로 이동 못할시 그냥 위로 한칸 이동 
				check[row][col] = true;
				row--;
				if(row==0){
					enterNum=col;
					break;
				}
			}	
		}
	
		printf("#%d %d\n",testNum,enterNum);

	}

	return 0;
}
