#include <iostream>
#include <queue>
#include <utility>
int arr[1000][1000];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int visit[1000][1000];

using namespace std;
queue< pair<int, int> > q;

int main() {
	
	
	int m, n;
	cin >> m >> n;
	for (int i = 0;i<n; ++i) {
		for (int j = 0; j < m; j++) {
			int tmp = 0;
			cin >> tmp; 
			arr[i][j] = tmp;
			if (tmp == 1) {
				q.push(make_pair(i, j));
			}
			else if (tmp == 0) {
				visit[i][j] = -1;
			}
		}
	}


	while ( !q.empty() ) {

		pair<int, int> cur = q.front(); q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visit[nx][ny] >= 0 ) continue;
			q.push(make_pair(nx, ny));
			visit[nx][ny] = visit[cur.first][cur.second] + 1;
		}
	}

	int result = 0;
	for (int i = 0;i<n; ++i) {
		for (int j = 0;j<m; ++j) {
			if (visit[i][j] == -1) {
				cout << -1;
				return 0;
			}

			if (visit[i][j] > result) {
				result = visit[i][j];
			}
		}
	}

	cout << result;


}