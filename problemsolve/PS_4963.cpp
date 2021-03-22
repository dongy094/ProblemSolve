#include <iostream>
#include <queue>
using namespace std;

int col,row;
int arr[50][50]={0,};
bool check[50][50];
int dx[8] = { 1, 0, -1, 0 , 1 , 1,-1,-1 };
int dy[8] = { 0, 1, 0 , -1, -1, 1,-1, 1 };
int cnt;

void init(){
	cnt = 0;
	for(int i=0;i<50;++i){
		for(int j=0;j<50;++j){
			arr[j][i] = 0;
			check[j][i] = false;
		}
	}
}

queue<pair<int,int>> q;
void solve(int x,int y){
	
	q.push({x,y});
	check[y][x] = true;
				
	while(!q.empty()){
					
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();
					
			for(int n=0;n<8;++n){
				int nx = tx + dx[n];
				int ny = ty + dy[n];
						
				if(nx<col && ny<row && nx>=0 && ny>=0){
					
					if(!check[ny][nx] && arr[ny][nx]){
					q.push({nx,ny});
					check[ny][nx] = true;
					}
					
				}
						
				
			}
					
	}

}


int main(){
	
	while(1){
		init();
		cin >> col >> row;
		
		if(col==0 && row==0){
			break;
		}

		for(int y=0;y<row;++y){  //  
			for(int x=0;x<col;++x){
				cin >> arr[y][x];
			}
		}

				
		for(int y=0;y<row;++y){
			for(int x=0;x<col;++x){
				if( check[y][x]==0 && arr[y][x]==1 ){
					solve(x,y);	
					cnt++;	
					
				}
			}
		}	
		cout << cnt << "\n";
		
	}
	

	return 0;
}

