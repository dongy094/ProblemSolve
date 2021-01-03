#include <iostream>
#include <algorithm>
using namespace std;

int note[50][50];  //노트의 크기
int paper[12][12]; // 현재 확인할 스티커 정보


int r, c;
int n, m, k;
void rotate() { //스티커를 회전 시켜서 다시 스티커에 담아야 한다.

	int tmp[12][12] = { 0, };
	for (int i = 0; i < r; ++i) { // tmp에 담고
		for (int j = 0; j < c; ++j) {
			tmp[i][j] = paper[i][j];
		}
	}
	
	for (int i = 0; i < c; i++) { //회전 시키고 r,c 서로 바꾸기 행과열 서로 바꾸기
		for (int j = 0; j < r; j++) {
			paper[i][j] = tmp[r-1-j][i];
		}
	}
	swap(r, c);
}

bool possible(int x, int y) {

	for (int i = 0; i < r; ++i) { // 스티커를 붙일 수 있는지 검사
		for (int j = 0; j < c; ++j) {
			if (paper[i][j] == 1 && note[x + i][y + j] == 1) {
				return false;
			}
		}
	}
	// 붙일 수 있다면 note에 표시
	for (int i = 0; i < r; ++i) { 
		for (int j = 0; j < c; ++j) {
			if (paper[i][j] == 1) {
				note[x + i][y + j] = 1;
			}
		}
	}
	return true;

}


int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	while (k--) { // 스티커 갯수 만큼 돌면서 확인

		cin >> r >> c;

		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				cin >> paper[i][j];
			}
		}
		
		for (int k = 0; k < 4; ++k) { // 회전하면서 스티커 붙일 수 있나 확인
			bool check = false;
			for (int x = 0; x <= n - r; ++x) { //좌측 상단부터 붙여가며 붙일 수 있는지 확인
				if (check) break;
				for (int y = 0; y <= m - c; ++y) {
					if ( possible(x, y) ) {
						check = true;
						break;
					}
				}
			}
			if (check) break;// 현재 스티커 붙일 수 있으면 다음 스티커로 넘어가기

			rotate();// 현재 스티커를 현재 상태로 붙일 수 없으면 rotate
		}
		
	}//while
	
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (note[i][j] == 1) {
				cnt++;
			}
		}
	}
	cout << cnt;

	return 0;
}
