#include <cstdio>
#include <cstring>
#define ABS(x) ( x >= 0 ? (x) : -(x) )
#define INF 9999999
using namespace std;

int visit[100];
int ax[10], ay[10];
int cx, cy;
int hx, hy;
int N; //고객수
int answer=999999;

void solve(int x,int y, int cnt,int dist) {

	if(dist>answer){
		return;	
	} 

	if(cnt == N) { // 집까지 거리 더하기
		int homedist = ABS(hx-x) + ABS(hy-y);
		if(dist+homedist<answer) {
			answer = dist+homedist;
		}
		return;
	}

	for(int i=0; i<N; i++) {

		if(visit[i]){
			continue;
		}
		visit[i] = 1;

		int nx = ax[i], ny = ay[i];

		int nd = ABS(x-nx) + ABS(y-ny);
		solve(nx, ny, cnt+1, dist+nd);
		visit[i] = 0;

	}

}

int main() {

	int TestCase;
	scanf("%d",&TestCase); //TestCase
	for(int tc=0 ; tc<TestCase ; tc++) {

		scanf("%d",&N);
		scanf("%d %d",&cx,&cy);
		scanf("%d %d",&hx,&hy);

		for(int i=0; i<N; i++) {
			scanf("%d %d",&ax[i],&ay[i]);
		}

		solve(cx,cy,0,0);

		printf("#%d %d\n",tc+1,answer);
		answer = INF;
		memset(visit,false,sizeof(visit));
		memset(ax,0,sizeof(ax));
		memset(ay,0,sizeof(ay));
	}


	return 0;
}
