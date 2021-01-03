#include <iostream>
#include <algorithm>

using namespace std;

int R, C, A;
int arr[310][310] = { 0 };
int tmp[310][310];

int dx[4] = {1,0,-1,0};  
int dy[4] = {0,1,0,-1};
		// 아래, 오른, 위, 왼

int dir;

void copy() {
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			tmp[i][j] = arr[i][j];
		}
	}
}

void solve(int cnt) {

	for (int i = 1; i <= cnt; ++i) { //그 안에서 바꿔주는 그 회전하는는 횟수
									// 맨처음은 1,1 부터 시작 그다음 2,2 ...
		dir = 0;
		int sx = i; //현 위치
		int sy = i;
		while (dir < 4) {

			int nx = sx + dx[dir];
			int ny = sy + dy[dir];
			if (nx >= i && ny >= i && nx <= R-i+1 && ny <= C-i+1) {
				arr[nx][ny] = tmp[sx][sy];
				sx = nx, sy = ny;
			}
			else {
				dir++; // 방향 바꾸기
			}

		}
	}

}



int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C >> A;

	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			cin >> arr[i][j];
			tmp[i][j] = arr[i][j];
		}
	}

	int cnt = min(R, C) / 2; 

	for (int a = 0; a < A; ++a) { // 회전 횟수
		solve(cnt);
		copy();
	}

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}



	return 0;
}