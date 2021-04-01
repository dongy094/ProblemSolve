#include <iostream>
#define INF 10000000
using namespace std;
int result[4][4] = {
	{0, 5, INF, 8},
	{7, 0, 9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0}
};

int main(void) {
// 그래프에서 모든 꼭짓점 사이의 최단 경로의 거리를 구하는 알고리즘
// 그래프를 갱신해 가면서 계산한다 
// 정점에서 거치고 거쳐서 가는게 계산됨
// 1->2->3 계산하고나서 이후에, 1->3->4 이거면 결국 1,2,3,4거쳐 가는 최단경로 

	for(int k = 0; k < 4; k++) { // k = 거쳐가는 노드
	
		for(int start = 0; start < 4; start++) {// start = 출발 노드
			 
			for(int dest = 0; dest < 4; dest++) {// dest = 도착 노드
				if(result[start][k] + result[k][dest] < result[start][dest]) {
					result[start][dest] = result[start][k] + result[k][dest];
				}
			}
		} 
	} 
	
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	} 
	
}
