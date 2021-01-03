#include <iostream>
#include <queue>

using namespace std;

int r, c, k;
int arr[50][50] = { 0, };
int check[50][50] = { 0, };

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

queue<pair<int, int>> q;

void init() {
	for(int i = 0; i < 50; ++i) {
		for (int j = 0; j < 50; ++j) {
			arr[i][j] = 0;
			check[i][j] = 0;
		}
	}

	while (!q.empty()) {
		q.pop();
	}

}

void solve(int x,int y) {

	q.push({ x,y });

	while (!q.empty()) {

		pair<int, int> cur = q.front(); q.pop();
		
		for (int i = 0; i < 4; ++i) {
			
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (arr[nx][ny] == 1 && check[nx][ny] == 0) {
				check[nx][ny] = 1;
				q.push({ nx,ny });
			}
				
		}

	}


}


int main() {

	int TestCase = 0;
	cin >> TestCase;

	while (TestCase--) {

		init();
		int cnt = 0;

		cin >> c >> r >> k;
		int tx = 0, ty = 0;
		for (int i = 0; i < k; ++i) {
			cin >> ty >> tx;
			arr[tx][ty] = 1; // insert bugs
		}

		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				if (!check[i][j] && arr[i][j]==1) {
					solve(i,j);
					cnt++;
				}
					
			}
		}

		cout << cnt << "\n";
		
	}



	return 0;
}