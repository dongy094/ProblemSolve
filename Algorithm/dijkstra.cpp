#include <stdio.h>
#define INF 999999
using namespace std;
int dist[6];
bool visited[6]={false};

int graph[6][6]={
	{0,	   3,   6,    INF,  INF,  INF},
	{INF,  0,   2,    4,    INF,  INF},
	{INF,  1,   0,    3,    6,    INF},
	{INF,  INF, INF,  0,    2,    3},
	{3,    INF, INF,  INF,  0,    6},
	{INF,  INF, INF,  INF,  INF,  0}
};

void dijkstra(int start){
	
	for(int i=0;i<6;++i){
		dist[i] = INF;
	}
	dist[start] = 0;
	
	for(int i=0;i<6;++i){
		
		int minCost=INF, minVertex;
		for(int j=0;j<6;j++){  //최소인 정점 찾기, 아직 방문x이면서 
			if(!visited[j] && dist[j] < minCost){
				minCost = dist[j];
				minVertex = j;
			}
		}
		
		visited[minVertex] = true; //최소인정점 방문처리하고, 최소인 정점에서 
								   //갈수있는 정점 찾으면서 최소값 구하기 
		for(int j=0;j<6;j++){
			if(dist[j] > dist[minVertex] + graph[minVertex][j]){
				dist[j] = dist[minVertex] + graph[minVertex][j];
				
			}
		}
		
	}
	
	for(int i=0;i<6;i++){
		printf("%d정점 최단거리 : %d \n",i,dist[i]);
	}
	
}


int main(){
	
	dijkstra(0);
	
	return 0;
}
