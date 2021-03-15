#include <cstdio>
#include <queue>
using namespace std;

int row,col;
int map[100][100];
int check[100][100]={0,}; // 1 == visit
int result[100][100];

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

queue<pair<int,int>> q;

void solve(int sx,int sy){
	
	q.push({sx,sy});
	check[sy][sx] = 1;
	
	while(!q.empty()){
		
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0;i<4;++i){
			
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx<0 || ny<0 || nx>=col || ny>=row) continue;
			
			if(check[ny][nx]==0 && map[ny][nx]==1){
				
				q.push({nx,ny});
				check[ny][nx] = 1;
				result[ny][nx] = result[y][x] + 1; 
				
			}
		}
		
	}
	
}

int main(){
	
//	cin >> row >> col;
	scanf("%d %d",&row,&col);
	for(int i=0 ; i<row ; ++i){
		for(int j=0 ; j<col ; ++j){
			scanf("%1d",&map[i][j]);
		}
	}

	result[0][0] = 1;
	solve(0,0); // 0,0 start
//	cout << result[row-1][col-1];
	printf("%d", result[row-1][col-1]);
	return 0;
}
