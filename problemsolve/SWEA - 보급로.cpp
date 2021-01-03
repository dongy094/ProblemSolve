#include <iostream> //보급로 문제 
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

bool check[101][101]={false,};
int map[101][101];
int dist[101][101];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int size;



queue< pair<int,int> > q;

void bfs(){

	q.push(make_pair(0,0));
	check[0][0]=true;

	while(!q.empty()){
		
		int x = q.front().first;
		int y = q.front().second;
		q.pop();	
		
		for(int k=0;k<4;k++){ //상하좌우 
			int nx = x + dx[k];
			int ny = y + dy[k];
			
			if( (nx>=0 && nx<size) && (ny>=0 && ny<size) ){
			
				if( map[nx][ny]+dist[x][y] < dist[nx][ny] ){   //그리고 왜 9999하면 방문처리는 왜 필요없지? 
						dist[nx][ny] = map[nx][ny]+dist[x][y];
						q.push(make_pair(nx,ny));
					}
			}
		}
	}
}


void init(){
	memset( dist,9999,sizeof(dist) );
	dist[0][0] = 0;
} 


int main(){
	
	int TestCase=0;
	cin >> TestCase;
	int c=0;
	
	while(TestCase--){
		
		scanf("%d",&size);
		
		init();
		
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				scanf("%1d",&map[i][j]);
			}
		}	
		dist[0][0]=0;    
		bfs();
		c++;	
		printf("#%d %d",c,dist[size-1][size-1]);
	
	}
	
	return 0;
}
