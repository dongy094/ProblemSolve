#include <iostream>
#include <algorithm>
using namespace std;

int note[50][50];  //��Ʈ�� ũ��
int paper[12][12]; // ���� Ȯ���� ��ƼĿ ����


int r, c;
int n, m, k;
void rotate() { //��ƼĿ�� ȸ�� ���Ѽ� �ٽ� ��ƼĿ�� ��ƾ� �Ѵ�.

	int tmp[12][12] = { 0, };
	for (int i = 0; i < r; ++i) { // tmp�� ���
		for (int j = 0; j < c; ++j) {
			tmp[i][j] = paper[i][j];
		}
	}
	
	for (int i = 0; i < c; i++) { //ȸ�� ��Ű�� r,c ���� �ٲٱ� ����� ���� �ٲٱ�
		for (int j = 0; j < r; j++) {
			paper[i][j] = tmp[r-1-j][i];
		}
	}
	swap(r, c);
}

bool possible(int x, int y) {

	for (int i = 0; i < r; ++i) { // ��ƼĿ�� ���� �� �ִ��� �˻�
		for (int j = 0; j < c; ++j) {
			if (paper[i][j] == 1 && note[x + i][y + j] == 1) {
				return false;
			}
		}
	}
	// ���� �� �ִٸ� note�� ǥ��
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

	while (k--) { // ��ƼĿ ���� ��ŭ ���鼭 Ȯ��

		cin >> r >> c;

		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				cin >> paper[i][j];
			}
		}
		
		for (int k = 0; k < 4; ++k) { // ȸ���ϸ鼭 ��ƼĿ ���� �� �ֳ� Ȯ��
			bool check = false;
			for (int x = 0; x <= n - r; ++x) { //���� ��ܺ��� �ٿ����� ���� �� �ִ��� Ȯ��
				if (check) break;
				for (int y = 0; y <= m - c; ++y) {
					if ( possible(x, y) ) {
						check = true;
						break;
					}
				}
			}
			if (check) break;// ���� ��ƼĿ ���� �� ������ ���� ��ƼĿ�� �Ѿ��

			rotate();// ���� ��ƼĿ�� ���� ���·� ���� �� ������ rotate
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
