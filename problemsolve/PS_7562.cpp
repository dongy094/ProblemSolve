#include <iostream>
#include <queue>
using namespace std;

int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { -2,-1,1,2,-2,-1,1,2 };
int sx, sy;
int ex, ey;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc; cin >> tc;
	while (tc--) {
		int num; cin >> num;
		cin >> sx >> sy;
		cin >> ex >> ey;

		int visit[302][302] = { 0, };
		int map[302][302] = { 0, };

		queue< pair<int, int> > q;
		q.push({ sx,sy });
		visit[sx][sy] = 1;
		int cnt = 0;
		int min = 99999;
		while (!q.empty()) {

			pair<int, int> pos = q.front();
			q.pop();

			for (int i = 0; i < 8; i++) {
				int nx = pos.first + dx[i];
				int ny = pos.second + dy[i];
				if (nx < 0 || ny < 0 || nx >= num || ny >= num) continue;
				if (visit[nx][ny] == 1) continue;
				//cnt++;   x  -> 호출하고 올라갈떄 cnt값 같이 넘어가야 됨, 이렇게X
			
				q.push({ nx,ny });
				visit[nx][ny] = 1;
				map[nx][ny] = map[pos.first][pos.second] + 1;

			}

		}

		cout << map[ex][ey] << "\n";
		
	}



	return 0;
}