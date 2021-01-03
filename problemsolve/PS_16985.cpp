#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

// int map[dir][k][r][c]; dir�� ȸ��, k��, r,c��
int map[4][5][5][5];
int maze[5][5][5]; // �������� �迭
int dist[5][5][5]; // �ִ� �Ÿ� �����

//x,y,z����
int dx[6] = {1,0,0,-1,0,0};
int dy[6] = {0,1,0,0,-1,0};
int dz[6] = {0,0,1,0,0,-1};

struct point {
	int x, y, z;
};



int solve() {

	if (maze[0][0][0] == 0 || maze[4][4][4] == 0) return 99999;

	for (int a = 0; a < 5; ++a) {
		for (int b = 0; b < 5; ++b) {
			for (int c = 0; c < 5; ++c) {
				dist[a][b][c] = -1;
			}
		}
	}

	queue<point> q;
	

	q.push({0,0,0});
	dist[0][0][0] = 0; //�湮ǥ�� �� �Ÿ�������


	while (!q.empty()) {

		point cur = q.front();
		q.pop();

		for (int dir = 0; dir < 6; ++dir) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			int nz = cur.z + dz[dir];
			
			if (nx < 0 || ny < 0 || nz < 0 || nx >= 5 || ny >= 5 || nz >= 5) continue;
			if (maze[nx][ny][nz] == 0 || dist[nx][ny][nz] != -1) continue;
			// 0(�������±�) �̰ų� dist�� -1�� �ƴ� �ٸ����� �̹� �湮 �߱⿡ 

			if (nx == 4 && ny == 4 && nz == 4) 
				return dist[cur.x][cur.y][cur.z]+1;

			dist[nx][ny][nz] = dist[cur.x][cur.y][cur.z] + 1;
			q.push({ nx,ny,nz });
			
		}

	}

	return 99999; // �ⱸ 4,4,4 ã�� ���ߴٸ� 99999 �������༭ ans���� ���� ���߱�
}


void init_reshape() {
	for (int k = 0; k < 5; ++k) {

		for (int r = 0; r < 5; ++r) {
			for (int c = 0; c < 5; ++c) {
				cin >> map[0][k][r][c];
			}
		}
	
	
		for (int r = 0; r < 5; ++r) {
			for (int c = 0; c < 5; ++c) {
				map[1][k][r][c] = map[0][k][5 - 1 - c][r];
			}
		}
	
	
		for (int r = 0; r < 5; ++r) {
			for (int c = 0; c < 5; ++c) {
				map[2][k][r][c] = map[1][k][5 - 1 - c][r];
			}
		}
	
	
		for (int r = 0; r < 5; ++r) {
			for (int c = 0; c < 5; ++c) {
				map[3][k][r][c] = map[2][k][5 - 1 - c][r];
			}
		}

	}

}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	init_reshape();

	int order[5] = { 0,1,2,3,4 }; //�� ���� �ϱ� ���� �迭
	
	int ans = 99999;
	do { // �ϳ��� �� �������� ���� ������ ����(ȸ��) �ؼ� ���� ������ ã��

		for (int tmp = 0; tmp < 1024; ++tmp) { // 4���� ����^5�� ����1024
				
			int brute = tmp;
			for (int i = 0; i < 5; ++i) { 
				int dir = brute % 4; //dir�� ���� �� map��dir
				brute /= 4;

				for (int r = 0; r < 5; ++r) { //�� ���� ������ �״´� maze��
					for (int c = 0; c < 5; ++c) {
						maze[i][r][c] = map[dir][order[i]][r][c];
					}
				}
			}

			ans = min(ans, solve());
		}

	} while (next_permutation(order, order + 5));

	if (ans == 99999) {
		ans = -1;
	}

	cout << ans;

	return 0;
}