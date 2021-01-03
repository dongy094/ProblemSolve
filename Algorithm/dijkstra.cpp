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
		for(int j=0;j<6;j++){  //�ּ��� ���� ã��, ���� �湮x�̸鼭 
			if(!visited[j] && dist[j] < minCost){
				minCost = dist[j];
				minVertex = j;
			}
		}
		
		visited[minVertex] = true; //�ּ������� �湮ó���ϰ�, �ּ��� �������� 
								   //�����ִ� ���� ã���鼭 �ּҰ� ���ϱ� 
		for(int j=0;j<6;j++){
			if(dist[j] > dist[minVertex] + graph[minVertex][j]){
				dist[j] = dist[minVertex] + graph[minVertex][j];
				
			}
		}
		
	}
	
	for(int i=0;i<6;i++){
		printf("%d���� �ִܰŸ� : %d \n",i,dist[i]);
	}
	
}


int main(){
	
	dijkstra(0);
	
	return 0;
}
