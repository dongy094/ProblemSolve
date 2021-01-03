#include <cstdio>
#include <cmath>
using namespace std;
int row[100]={0,}, n;
// row[1]=1 은 1행1열에 퀸이 위치한것 

void printResult(){

	for(int i=1;i<=n;++i){
		printf("<%d,%d> ",i,row[i]);
	}
	printf("\n");
}

bool promising(int q){ //행에 놓을 수 있나? 
	
	for(int i=1;i<q;++i){
		if( row[q]==row[i] || abs(row[q]-row[i]) == (abs(q-i)) ){
			return false;
		} 
	}
	
	return true;
}

void nq(int q){
	if(!promising(q)) return; // 가지치기  
	
	if(q==n){ // 가지치기 통과하고 마지막행에 놓을 수 있으면 찾은거 

		printResult();
		return;
	}
	
	for(int i=1;i<=n;++i){
		row[q+1] = i;
		nq(q+1); 
	}

}

int main(){

	scanf("%d",&n);
	nq(0);
	return 0;
}
