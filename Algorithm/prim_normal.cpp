#include <iostream>
using namespace std;
#define INF 99999
#define MAX_N 1000
int N = 7, parent[7]={0}, weight[7]={0};

int graph[7][7]={
	{0,  32, 31, 0,  0,  60, 51 },
	{32, 0,  21, 0,  0,  0,  0, },
	{31, 21, 0,  0,  46, 0,  25 },
	{0,  0,  0,  0,  34, 18, 0  },
	{0,  0,  46, 34, 0,  40, 51 },
	{60, 0,  0,  18, 40, 0,  0  },
	{51, 0,  25, 0,  51, 0,  0  }
};


	
void prim(){
	
	for(int i=0;i<N;i++){
		weight[i] = -1;
	}
	
	weight[0]=0;								//시작위치 
	for(int k=1;k<N;k++){ 						// N개중 N-1개만 연결되면 됨 
		
		int minW = INF;
		int minV,minP;
	
		for(int i=0;i<N;i++){ 					// i에서 시작해서 다음 점 찾기
		
			if(weight[i] < 0 ) 		// i에서 시작할건데 방문한적 없으면x 
			{
				continue;
			}
		
			for(int j=0;j<N;j++){ 				// 최소인 다음 점 찾기 
			
				if(weight[j] >= 0 ) 	//이미 선택했으면 사이클 발생한다. 
				{
					continue;
				}
				if(graph[i][j] < minW){
					minV = j; minP = i;
					minW = graph[i][j];
				}
			}	
		} 
		parent[minV] = minP;
		weight[minV] = minW;
	}

	int sum=0;
	for(int i=0;i<N;i++){
		sum += weight[i];
	}
	cout << sum << endl;
}


int main(void){
	
	prim();
	return 0;
	
}
