#include <iostream>
#include <queue>
using namespace std;
#define INF 99999
#define MAX_N 1000
int N = 7; bool visited[7]={false};							// 작은수가 탑에 오게 
priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
									// first=weight, second = curr
int graph[7][7]={
	{INF,  32, 31, INF,  INF,  60, 51 },
	{32, INF,  21, INF,  INF,  INF,  INF, },
	{31, 21, INF,  INF,  46, INF,  25 },
	{INF,  INF,  INF,  INF,  34, 18, INF  },
	{INF,  INF,  46, 34, INF,  40, 51 },
	{60, INF,  INF,  18, 40, INF,  INF  },
	{51, INF,  25, INF,  51, INF,  INF  }
};

void prim(){
	
	visited[0] = true;
	for(int i=0;i<N;i++){
		pq.push(make_pair(graph[0][i],i));
	}
	int sum = 0;
	
	while(!pq.empty()){
		int weight = pq.top().first;
		int curr = pq.top().second;
		pq.pop();
		if(visited[curr]) continue;
		visited[curr] = true;
		sum += weight; 
		// 이제 0에서 가장 w가 작은 위치 curr 에서 다음에 갈 수 있는 위치들을 넣기 
		for(int i=0;i<N;i++){
			pq.push(make_pair(graph[curr][i],i));
		}
	}
	cout << sum << ' ';
	
}

int main(void){
	
	prim();
	return 0;
	
}
