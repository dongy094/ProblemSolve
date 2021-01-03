#include <cstdio>
#include <vector>
using namespace std;


//vector<int> arr[100];

vector< vector<int> > arr;		//
int result;


void solve(int x){
		
		
		if(x == 99){
			result = 1;
			return;
		}
	
		for(int i=0;i<arr[x].size();i++){
			
			int nx = arr[x][i];
			solve(nx);
		}
	
	
}

int TestCase=10;
int main(){
int size;

	
	while(TestCase--){
		

		int case_num=1;
		size=0;	result=0;
		
		scanf("%d %d",&case_num,&size);
		arr.resize(size); //
		
		for(int i=0;i<size;i++){
			
				int s=0;
				int e=0;
			
				scanf("%d %d",&s,&e);
				arr[s].push_back(e);		

		}

		solve(0); // 시작위치에서 출발해서 99찾기 
		printf("#%d %d\n",case_num,result);
		arr.clear();
		

	}
	
	return 0;
}
