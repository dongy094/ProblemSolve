#include <iostream>
#include <algorithm>

using namespace std;
int arr[12][12];
int N;
int visit[12][12];
int result = 1319999;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool check(int y, int x) {

	if (visit[y][x]) return false;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= N || ny >= N || nx < 0 || ny < 0) return false;
		if (visit[ny][nx]) return false;
	}

	return true;
}

int make_flower(int y, int x) {

	int area_sum = arr[y][x];
	visit[y][x] = 1;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		visit[ny][nx] = 1;
		area_sum += arr[ny][nx];
	}
	return area_sum;
}

void unmake_flower(int y, int x) {

	visit[y][x] = 0;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		visit[ny][nx] = 0;
	
	}
	return;
}

void solve(int sum, int cnt) {

	//base condition
	if (cnt == 3) {
		result = min(result, sum);
		return;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {

			// 해당 자리 꽃 피는게 가능한지, 주변 꽃 없는지랑 범위 초과
			if ( check(i, j) ) {

				int tmp_sum = make_flower(i, j); // 꽃 표시
				solve(sum+tmp_sum, cnt+1);

				unmake_flower(i, j);

			}
		}
	}
	return;
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}

	solve(0,0); // sum, cnt

	cout << result;



	return 0;
}