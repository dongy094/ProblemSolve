#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//상,하,좌,우 cctv 90도 회전하기 위한 방향설정
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 남쪽, 동쪽, 북쪽, 서쪽 순서
int N, M;

vector<pair<int, int>> cctv;

int map1[10][10]; // cctv발견 최초 좌표 표시용(백업)
int map2[10][10]; // 사각 지대의 개수를 세기 위해 사용할 변수

bool OOB(int a,int b) {
	return (a < 0 || b < 0 || a >= N || b >= M);
}

void check(int x,int y,int dir) {
	// 최초 함수로 들어온 좌표는 cctv현 좌표
			// check호출할때 nun+3이런경우 -> 5이면 ??dx범위 아니네
				// 다시한번 %= 4 해줘서 범위로 좁히기 
	dir %= 4;
	while (1) {
		x += dx[dir];
		y += dy[dir];
		// 범위밖 or 벽(6) 이면  종료 cctv더이상 갈곳 없다
		if (OOB(x, y) || map2[x][y] == 6) return;
		// cctv면 넘어갈 수 있으니까 다음 좌표로 or 이미방문했으면 다음으로
		if (map2[x][y] != 0) continue;
		map2[x][y] = 7; // cctv가 갈 수 있는곳 마킹(7로)

	}

}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	int init_size = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			
			cin >> map1[i][j];
			if (map1[i][j] != 0 && map1[i][j] != 6) {
				cctv.push_back({ i,j });
			}
			if(map1[i][j] == 0) init_size++;

		}
	}


	//cctv갯수의 4방향 모든 조합
	for (int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++) {

		// 초기map을 map2에 복사
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map2[i][j] = map1[i][j];
			}
		}

		int brute = tmp;
		for (int j = 0; j < cctv.size(); j++) {

			int num = brute % 4; // num은 cctv 상,하,좌,우 중 한 방향(90도 회전)
			brute /= 4; // 하니까

			int x = cctv[j].first;
			int y = cctv[j].second;

			if (map1[x][y] == 1) {
				check(x, y, num);
			}
			else if (map1[x][y] == 2) {
				check(x, y, num);
				check(x, y, num+2);
			}
			else if (map1[x][y] == 3) {
				check(x, y, num);
				check(x, y, num + 1);
			}
			else if (map1[x][y] == 4) {
				check(x, y, num);
				check(x, y, num + 1);
				check(x, y, num + 2);
			}
			else {
				check(x, y, num);
				check(x, y, num + 1);
				check(x, y, num + 2);
				check(x, y, num + 3);
			}	
		}

		int result = 0;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				if (map2[i][j] == 0) {
					result++;
				}
			}
		}
		if (init_size > result) {
			init_size = result;
		}
	}

	cout << init_size;

}