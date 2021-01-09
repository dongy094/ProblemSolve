#include <cstdio>
#include <vector>
using namespace std;

int main(){
	
	int TestCase;
	int num=0,pos;
	scanf("%d",&TestCase);
	
	for(int i=0;i<TestCase;i++){
		
		scanf("%d",&num); 
		vector<int> arr(101,0); //점수 넣을 배열 100점까지 1~100점	
		for(int j=0;j<1000;j++){ //학생의 점수를 배열에 넣기 
			int temp=0;
			scanf("%d",&temp); //점수입력
			arr[temp]++;  //점수 빈도+1 
		}
		
		int maxN=-9999;
		
		pos = 0; //최빈값 위치 알려줄 변수 
		for(int t=1;t<101;t++){ //학생수, 최빈값 구하기 1점~100점 까지 돌면서 최빈값 찾기 
			if( arr[t] >= maxN ){
				maxN = arr[t];
				pos = t; 
			}
		}
	
		printf("#%d %d\n",num,pos);
		num++;
	}
	return 0;
}
