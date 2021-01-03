#include <cstdio>

using namespace std;
			
int solve(int x,int y){
	
	int ans=1;
	while(y>0){
		ans = ans * x;
		y--;
	}

	return ans;
}

int TestCase=10;

int main(){
	
	while(TestCase--){
		
		int number=0;
		scanf("%d",&number);
		
		int x=0; int y=0;
		scanf("%d %d",&x,&y);
		
		int result=0;
		result = solve(x,y);
		
		printf("#%d %d\n",number,result);
		
	}
	
	
	return 0;
}
