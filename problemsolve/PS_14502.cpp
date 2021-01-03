#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N, M;
const int wall = 3;
int map[8][8]; // 오리지날
int map_copy[8][8]; // 벽세우기용
int map_v[8][8]; //바이러스 증식용

int dx[4] = {-1,1,0,0}; // T B L R
int dy[4] = {0,0,-1,1};

queue<pair<int, int>> q;
vector<pair<int, int>> virus;
int safe_area = -1;

void copy_area() {

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			map_v[i][j] = map_copy[i][j];
		}
	}

}

int area() { // safe_area_count

	int tmp_value = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (map_v[i][j] == 0) {
				tmp_value++;
			}
		}
	}
	
	return tmp_value;
}

void virus_check() { // 바이러스 증식하기

	int size = virus.size();

	for (int cnt = 0; cnt < size; ++cnt) { // 바이러스 갯수

		pair<int, int> vec_cur = virus[cnt];

		while (!q.empty()) {
			q.pop();
		}

		q.push({ vec_cur });

		while (!q.empty()) {

			pair<int, int> cur = q.front(); q.pop();

			for (int i = 0; i < 4; ++i) {

				int nx = dx[i] + cur.first;
				int ny = dy[i] + cur.second;
				if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
					if (map_v[nx][ny] != 1 && map_v[nx][ny] != 2) {
						map_v[nx][ny] = 2;
						q.push({ nx,ny });
					}

				}

			}
		}

		

	}


}

void solve(int k) {

	if ( k == 3  ) { // 벽 다 세웠으면 

		virus_check(); // 바이러스 증식하기

		int result = area();
		if (result > safe_area) {
			safe_area = result;
		}
		return;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (map_copy[i][j] == 0) { // 일반 땅이면 

				map_copy[i][j] = 1;
				map_v[i][j] = 1;

				solve(k + 1);

				map_copy[i][j] = 0;
				copy_area();
			}
		}
	}

}



int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
			map_copy[i][j] = map[i][j];
			map_v[i][j] = map[i][j];
			if (map[i][j] == 2) { // virus
				virus.push_back({ i,j });
			}
		}
	}

	solve(0);


	cout << safe_area << "\n";


	return 0;
}

// M*N*3