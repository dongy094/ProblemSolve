#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int visit[502][502] = {0,};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
queue< pair<int,int> > q;
int row, col;
int arr[502][502];
int n,m;

int main(){
	
	int size = 0;
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int max_size=0;
	int cnt=0; 
	

	cin >> n >> m;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin >> arr[i][j];
		}
	}
	
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(arr[i][j] == 0 || visit[i][j] ) continue;
				size=0;
				cnt++;
				visit[i][j] = 1;
				q.push(make_pair(i,j));

				while( !q.empty() ){
					size++;
					pair<int,int> cur = q.front();
					q.pop();
					for(int i=0;i<4;++i){
						int nx = dx[i] + cur.first;
						int ny = dy[i] + cur.second;
						
						if(nx < 0 || ny < 0 || nx >= n || ny >= m ) continue;
						if( visit[nx][ny] || arr[nx][ny] != 1 ) continue;
						visit[nx][ny] = 1;
						q.push(make_pair(nx,ny));
	
					}
				}
				
				if( size > max_size ){
					max_size = size;
				}
			
		}
	}	
	cout << cnt << "\n" << max_size;

	return 0;
}
