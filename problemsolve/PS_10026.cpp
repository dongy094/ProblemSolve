#include <iostream>
#include <queue>
using namespace std;
int num;

int visit1[101][101] = { 0, }; //정상
int visit2[101][101] = { 0, }; //적록색약

int check1[101][101] = { 0, };
int check2[101][101] = { 0, };

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int cnt1, cnt2;

// R = 1, G = 2, B = 3

void solve1(int x, int y) {

	check1[x][y] = 1;
	
	for (int i = 0; i < 4; i++) {
		
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx < 0 || ny < 0 || nx >= num || ny >= num) continue;
		if (check1[nx][ny] == 1) continue;
		if (visit1[nx][ny] != visit1[x][y]) continue;
		solve1(nx, ny);

	}

}
void solve2(int x, int y) {

	check2[x][y] = 1;

	for (int i = 0; i < 4; i++) {

		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx < 0 || ny < 0 || nx >= num || ny >= num) continue;
		if (check2[nx][ny] == 1) continue;
		if (visit2[nx][ny] != visit2[x][y]) continue;
		solve2(nx, ny);

	}

}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	 cin >> num;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			char tmp;
			cin >> tmp; 
			if (tmp == 'R') {
				visit1[i][j] = 1;
				visit2[i][j] = 1;
			}
			else if (tmp == 'G') {
				visit1[i][j] = 2;
				visit2[i][j] = 1;
			}
			else if (tmp == 'B') {
				visit1[i][j] = 3;
				visit2[i][j] = 3;
			}
		}
	}


	for (int i = 0;i<num; i++) {
		for (int j = 0; j < num; j++) {
			if (check1[i][j] != 1) {
				solve1(i, j);
				cnt1++;
			}
		}
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (check2[i][j] != 1) {
				solve2(i, j);
				cnt2++;
			}
		}
	}

	cout << cnt1 << " " << cnt2;

	return 0;
}