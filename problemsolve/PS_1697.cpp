#include <cstdio>
#include <queue>
using namespace std;

queue<int> q;
int N,K;
int min_time = 0;
int tmp = 9999;
bool check[100100] = {false,};
int dist[100100] = {0,};
int dir[3] = {-1,1,2};
int main(){
	
	scanf("%d %d",&N,&K);
	
	q.push(N);
	check[N] = true;
	
	while(!q.empty()){
		
		int cur = q.front(); q.pop();
		for(int i=0;i<3;++i){
			int next = 0;
			if(i<2){
				next = cur + dir[i];
			}else{
				next = cur * dir[i];
			}
			
			if(next>=0 && next<=100000 && check[next]==false){
				//if(dist[next]!=0) continue;
				if(dist[next]<dist[cur]+1){
					dist[next] = dist[cur]+1;
					q.push(next);
					check[next] = true;
				}
				
			}
			
		}
		
	}
	
//	for(int i=0;i<20;++i){
//		printf("%d ",dist[i]);
//	}
	
	printf("%d",dist[K]);
	
	
	
	return 0;
}
