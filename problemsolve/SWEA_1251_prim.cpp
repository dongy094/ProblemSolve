#include <cstdio>
#include <iostream>
#include <cstring> 
#define INF 9223372036854775807
using namespace std;
int N;
double E;
int arrX[1000],arrY[1000];
long long graph[1000][1000];
long long check[1000];

//void init(){
//	memset(arrX,0,1000);	
//	memset(arrY,0,1000);
//	for(int i=0;i<1000;++i){
//		memset(graph[i],INF,1000);
//	}
//}


void make_graph(){
	
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			if(i!=j){
				long long X = (arrX[i] - arrX[j]);
				long long Y = (arrY[i] - arrY[j]);
				long long cost = (X*X) + (Y*Y);
				graph[i][j] = cost;
			}
		}
	}
}

long long prim(){
	
	for(int i=0;i<N;++i){ check[i] = -1; }
	check[0] = 0; // prim�� ��� �����ϵ� ��� ���� 
	for(int k=1;k<N;++k){ // n-1�� ������ ��� ���� ���ᰡ�� 
		long long minValue = INF;
		int minV;
		for(int i=0;i<N;++i){
			if(check[i] < 0 ) { continue; }
			for(int j=0;j<N;++j){
				if(check[j] >= 0 ){ continue; } 
				if(graph[i][j] < minValue){
					minV = j;
					minValue = graph[i][j];
				}
			}
		}
		check[minV] = minValue; 
	} 
	
	long long sum = 0;
	for(int i=0;i<N;++i){
		sum += check[i];
	}
	return (long long)(sum*E + 0.5); //0.5�� �ݿø��ϱ����� 
}


int main(){
	
	int TestCase=0;
	scanf("%d",&TestCase); 
	for(int tc=1;tc<=TestCase;++tc){
		//init();
		cin >> N;
		for(int i=0;i<N;++i) { //x��ǥ
			cin >> arrX[i];
		}  
		for(int i=0;i<N;++i) { //y��ǥ
			cin >> arrY[i];
		}  
		cin >> E;
		make_graph(); //x,y��ǥ ������ �� ������ ������ִ� ��� �Ÿ���? ���ϱ� 
		
		//cout << "#"<< tc << " "<< prim() << endl;
		printf("#%d %lld",tc,prim());
	}
	
	return 0;
}
