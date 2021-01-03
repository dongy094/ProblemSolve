#include <cstdio>
#include <cstdlib>
using namespace std;

// 10 
// 1 4  1 6  6 10  5 7  3 8  5 9  3 5  8 11  2 13  12 14

struct meeting{
	int start,end;
};
int N;
meeting *Meets = (meeting*)malloc( sizeof(meeting)*10 );


int solve(){
	for(int i=0;i<N-1;++i){ //sorting
		for(int j=i+1;j<N;++j){
			if(Meets[j].end < Meets[i].end ){
				meeting temp = Meets[j];
				Meets[j] = Meets[i];
				Meets[i] = temp;
			}
		}
	}

	int cnt=0,lastEnd=0;
	for(int k=0;k<N;++k){
		if(Meets[k].start < lastEnd ) continue;
		
		printf("<%d %d>\n",Meets[k].start,Meets[k].end);
		lastEnd = Meets[k].end;
		cnt++;
	}

	return cnt;
}

int main(){
	
	freopen("meeting_input.txt","r",stdin);
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		scanf("%d %d",&Meets[i].start,&Meets[i].end);
	}	
	printf("%d\n",solve());
	free(Meets);
	return 0;
}
