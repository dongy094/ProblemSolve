#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXV 1000
using namespace std;
int arrX[MAXV], arrY[MAXV], N, parent[MAXV];
int edgecCnt;
double e;

struct edge{
	int u,v;
	long long cost;
};

edge arrE[ MAXV*(MAXV-1) / 2 ]; //정점들중 2개 선택해서 만드는 거니까 nC2; 

bool cmp(const edge &n,const edge &m){
	if(n.cost < m.cost){
		return true;
	}else{
		return false;
	}

}

void make_edge(){ // 모든 연결가능한 정점들 끼리 연결하기 
	edgecCnt=0;
	for(int i=0;i<N-1;++i){
		for(int j=i+1;j<N;j++){
			long long a = (arrX[i] - arrX[j]);
			long long b = (arrY[i] - arrY[j]);
			long long cost = (a*a) + (b*b);
			
			arrE[edgecCnt] = {i,j,cost}; 
			edgecCnt++;
		}
	}
}

int findset(int p){
	if(p == parent[p]) return p;
	return findset(parent[p]);
}

long long kruskal(){
	
	sort(arrE,arrE+edgecCnt,cmp);
	for(int i=0;i<N;++i){
		parent[i] = i;
	}
	
	long long result=0; 
	long long cnt=0;	
	for(int i=0;i<edgecCnt;++i){
		int p1,p2;
		p1 = arrE[i].u, p2 = arrE[i].v;
		if( findset(p1) == findset(p2) ) {
			continue;
		}
		
		parent[findset(p1)] = findset(p2); // 같은 소속아니면 같은 집합으로 만들기
		
	
		result += arrE[i].cost;
		if(++cnt >= N-1) {
			break;
		}
	}
	
	return (long long)(result*e);
}

int main(){
	cout.precision(0);
	cout << fixed;
	
	int TestCase;
	scanf("%d",&TestCase);
	for(int tc=1;tc<=TestCase;++tc){
		scanf("%d",&N); //섬 갯수 
		for(int i=0;i<N;++i) cin >> arrX[i];
		for(int j=0;j<N;++j) cin >> arrY[j];
		scanf("%lf",&e);
		make_edge();
		
		cout <<"#"<<tc<<" "<<kruskal()<<endl;
	}
	
	return 0;
}
