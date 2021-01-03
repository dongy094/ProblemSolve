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
	
	weight[0]=0;								//������ġ 
	for(int k=1;k<N;k++){ 						// N���� N-1���� ����Ǹ� �� 
		
		int minW = INF;
		int minV,minP;
	
		for(int i=0;i<N;i++){ 					// i���� �����ؼ� ���� �� ã��
		
			if(weight[i] < 0 ) 		// i���� �����Ұǵ� �湮���� ������x 
			{
				continue;
			}
		
			for(int j=0;j<N;j++){ 				// �ּ��� ���� �� ã�� 
			
				if(weight[j] >= 0 ) 	//�̹� ���������� ����Ŭ �߻��Ѵ�. 
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
