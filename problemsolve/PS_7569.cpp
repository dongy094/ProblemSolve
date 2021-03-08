#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

// 상 하 좌 우 위 아래 
int dx[6]={0,0,1,-1,0,0};
int dy[6]={1,-1,0,0,0,0};
int dz[6]={0,0,0,0,1,-1};
int row,col,dep;
int map[105][105][105];

queue< tuple<int,int,int> > q;


void spread(){
	
	while(!q.empty()){
		// y , x , z
		tuple<int,int,int> tmp = q.front(); q.pop();
		int y = get<0>(tmp);
		int x = get<1>(tmp);
		int z = get<2>(tmp);
		
		for(int i=0;i<6;++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
		
			
	
			if(nx>=0 && nx<col && ny>=0 && ny<row && nz>=0 && nz<dep){ //범위 안에 
			
					if(map[ny][nx][nz]){ // 0 빼고 다 
						continue;	
					} 
					
					map[ny][nx][nz] = map[y][x][z]+1;
					q.push(make_tuple(ny,nx,nz));
			}
	
		}
		
	}
	
}


int main(){

	cin >> col >> row >> dep;

	for(int i=0;i<dep;++i){  // input
		for(int r=0;r<row;++r){
			for(int c=0;c<col;++c){
				cin >> map[r][c][i];
				if(map[r][c][i] == 1){
					q.push(make_tuple(r,c,i));
				}
			}
		}	
	}
	
	spread();  
//
//	for(int i=0;i<dep;++i){  // output
//		for(int r=0;r<row;++r){
//			for(int c=0;c<col;++c){
//				cout << map[r][c][i] << " ";
//			}
//			cout << "\n";
//		}		
//	}
//	cout << "\n";

	bool flag = false;
	int time = 0;
	for (int k = 0; k < dep; k++) 
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if(map[i][j][k]==0){
					flag = true;
				}
				if(map[i][j][k]>time){
					time = map[i][j][k];
				}
			}
		}
	}
	
	if(flag){
		cout << -1;
		return 0;
	}
	cout << time-1;

	return 0;
}
