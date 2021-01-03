#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

char map[1001][1001];
int time[1001][1001];
int es[1001][1001];
queue<pair<int, int>> fire;
queue<pair<int, int>> ji;



int main() {


	int step = 0;
	int n, m; cin >> n >> m;

	for (int i = 0; i < n; ++i) { // ���� �̹湮 ó��
		memset(time[i], -1, sizeof(int) * 1001);
		memset(es[i], -1, sizeof(int) * 1001);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'F') {
				fire.push({ i,j });
				time[i][j] = 0;
			}
			if (map[i][j] == 'J') {
				ji.push({ i,j });
				es[i][j] = 0;
			}
		}
	}

	/*�� ������ �ð� ǥ���ϱ�*/
	while (!fire.empty()) {
		pair<int, int> cur = fire.front(); fire.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (time[nx][ny] >= 0 || map[nx][ny] == '#') continue;

			time[nx][ny] = time[cur.first][cur.second] + 1;
			fire.push({nx,ny});

		}
	}
	/*����*/
	while (!ji.empty()) {
		pair<int, int> pos = ji.front(); ji.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = pos.first + dx[i];
			int ny = pos.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) { //Ż������
				step = es[pos.first][pos.second] + 1;
				cout << step;
				return 0;
			}
			if (es[nx][ny] >= 0 || map[nx][ny] == '#') continue; //�̹̹湮 or ��
			if (es[pos.first][pos.second] + 1 >= time[nx][ny] && time[nx][ny]!=-1) continue; //�����µ�  ���� �̹� ������, 
			ji.push({ nx,ny });
			es[nx][ny] = es[pos.first][pos.second] + 1;
		}
	}

	cout << "IMPOSSIBLE";

}