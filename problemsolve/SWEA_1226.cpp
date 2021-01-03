#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;
bool visit[16][16];
int arr[16][16];

		// 좌 우 상 하 
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
queue<pair<int,int>> q;

int bfs(){
	while(!q.empty()){
			q.pop();
	}
	q.push(make_pair(1,1));
	
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		visit[x][y]=true;
		q.pop();
		for(int k=0;k<4;k++){
			int nx= x+dx[k];
			int ny= y+dy[k];
			if(nx<0 || ny<0 || nx>=16 || ny>=16){
				continue;
			}
			
			if( arr[nx][ny] == 0 && visit[nx][ny]==false ){ // != 1로 하면 3도 해당해서 아래 else로 못들감 
				q.push(make_pair(nx,ny));
			}else if(arr[nx][ny] == 3){
					return 1;
			}	
			
		}
	}
	
	return 0;				
}


int main(){
	
	
	int TestCase = 10;
	int num;
	
	while(TestCase--){
		
		int check; 			//탈출 가능여부 default는 탈출불가(0) 
		scanf("%d",&num);
		
		memset(visit,0,sizeof(visit));
		memset(arr,0,sizeof(arr));
		
		for(int i=0;i<16;i++){
			for(int j=0;j<16;j++){
				scanf("%1d",&arr[i][j]);
			}
		}
				
		check = bfs();
		printf("#%d %d\n",num,check);

	}

	return 0;
}
