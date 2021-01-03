#include <cstdio>
#include <cmath>
using namespace std;
int row[100]={0,}, n;
// row[1]=1 �� 1��1���� ���� ��ġ�Ѱ� 

void printResult(){

	for(int i=1;i<=n;++i){
		printf("<%d,%d> ",i,row[i]);
	}
	printf("\n");
}

bool promising(int q){ //�࿡ ���� �� �ֳ�? 
	
	for(int i=1;i<q;++i){
		if( row[q]==row[i] || abs(row[q]-row[i]) == (abs(q-i)) ){
			return false;
		} 
	}
	
	return true;
}

void nq(int q){
	if(!promising(q)) return; // ����ġ��  
	
	if(q==n){ // ����ġ�� ����ϰ� �������࿡ ���� �� ������ ã���� 

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
