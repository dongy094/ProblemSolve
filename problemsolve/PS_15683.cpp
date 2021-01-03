#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//��,��,��,�� cctv 90�� ȸ���ϱ� ���� ���⼳��
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // ����, ����, ����, ���� ����
int N, M;

vector<pair<int, int>> cctv;

int map1[10][10]; // cctv�߰� ���� ��ǥ ǥ�ÿ�(���)
int map2[10][10]; // �簢 ������ ������ ���� ���� ����� ����

bool OOB(int a,int b) {
	return (a < 0 || b < 0 || a >= N || b >= M);
}

void check(int x,int y,int dir) {
	// ���� �Լ��� ���� ��ǥ�� cctv�� ��ǥ
			// checkȣ���Ҷ� nun+3�̷���� -> 5�̸� ??dx���� �ƴϳ�
				// �ٽ��ѹ� %= 4 ���༭ ������ ������ 
	dir %= 4;
	while (1) {
		x += dx[dir];
		y += dy[dir];
		// ������ or ��(6) �̸�  ���� cctv���̻� ���� ����
		if (OOB(x, y) || map2[x][y] == 6) return;
		// cctv�� �Ѿ �� �����ϱ� ���� ��ǥ�� or �̹̹湮������ ��������
		if (map2[x][y] != 0) continue;
		map2[x][y] = 7; // cctv�� �� �� �ִ°� ��ŷ(7��)

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


	//cctv������ 4���� ��� ����
	for (int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++) {

		// �ʱ�map�� map2�� ����
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map2[i][j] = map1[i][j];
			}
		}

		int brute = tmp;
		for (int j = 0; j < cctv.size(); j++) {

			int num = brute % 4; // num�� cctv ��,��,��,�� �� �� ����(90�� ȸ��)
			brute /= 4; // �ϴϱ�

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