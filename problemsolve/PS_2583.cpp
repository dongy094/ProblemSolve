#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int M, N, K; //세로(y,m) 가로(x,N)
int l1, l2, r1, r2;
int map[102][102] = {0, }; // 0은 기본 , 1은 색칠
int check[102][102] = { 0, };

/*
   (y)
	^
	l
	l
	l
	l
	 ㅡㅡㅡㅡㅡㅡ> (x)

*/



int dx[4] = {0,0,-1,1}; // 상(위), 하(아래), 좌, 우
int dy[4] = {1,-1,0,0};

void painting() {

	for (int py = l2; py < r2;++py) {
		for (int px = l1; px < r1;++px) {
			map[px][py] = 1;
		}
	}

}


int counting(int x,int y) {

	int cnt = 0;

	queue<pair<int, int>> q;
	q.push({ x,y });
	cnt++;
	check[x][y] = 1;

	while (!q.empty()) {

		pair<int, int> cur = q.front(); 
		q.pop();
		
		for (int p = 0; p < 4; ++p) {
			
			int nx = cur.first + dx[p];
			int ny = cur.second + dy[p];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || check[nx][ny] == 1 || map[nx][ny]==1) continue;
			
			//map = 0, check = 0;
			cnt++;
			check[nx][ny] = 1; //방문처리
			q.push({nx,ny});
		}

	}
	return cnt;
}


int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N >> K;
	while (K--) {

		cin >> l1>> l2>> r1>> r2;
		painting();

	}
	/*
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; ++j) {
			cout << map[j][i] << " ";
		}
		cout << "\n";
	}
	*/



	int pos = 0;
	int arr[10001];
	for (int i = 0; i < M ; ++i) { // M=5
		for (int j = 0; j < N ; ++j) { // N=7
			if (check[j][i] == 0 && map[j][i] == 0) {
				int result = counting(j,i);
				if (result > 0) {
					arr[pos] = result;
					pos++;
				}
				
			}

		}
	}

	sort(arr, arr + pos);
	cout << pos << "\n";
	for (int i = 0; i < pos; ++i) {
		cout << arr[i] << " ";
	}
	



	return 0;
}