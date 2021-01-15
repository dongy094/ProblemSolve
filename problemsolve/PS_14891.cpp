#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
vector<int> arr[10];
vector<int> tp[10]; // ���纻, ������ ��� ����
bool check[5] = { false, };

int K; // ȸ�� Ƚ��
int pick; // ȸ���� ���
int dir;  // 1�̸� �ð���� ȸ��, -1 �ݽð� ȸ��


// �ð���� -> 1ĭ�̵�
void clock_dir(int pick) {
	check[pick] = true;
	int tmp = arr[pick][7];
	for (int i = 7; i >= 1; --i) {
		arr[pick][i] = arr[pick][i - 1];
	}
	arr[pick][0] = tmp;

}

// �ݽð� <- 1ĭ�̵�
void counter_dir(int pick) {
	check[pick] = true;
	int tmp = arr[pick][0];
	for (int i = 0; i <= 6; ++i) {
		arr[pick][i] = arr[pick][i + 1];
	}
	arr[pick][7] = tmp;

}

void solve(int pick,int dir) {  // ������ �� ���¸� ���� �ֺ� ���� ������ ���� ����
								// ������ �� ���� ���¿� �ֺ� ���� ���ϴ°� �ƴ϶�

	if (pick <= 0 || pick >= 5) return;
	if (check[pick]) return;

	if (dir == 1) {// clockwise
		clock_dir(pick); // ó�� ������ �Ŵ� ������ ��������
		
		if (pick == 2 || pick == 3) {
			if (tp[pick][2] != tp[pick+1][6]) { // ���� �κ� �� �ٸ��� �ݴ�� ���� ��¦��
				solve(pick + 1, -1);
			}
			if (tp[pick][6] != tp[pick - 1][2]) { // ����
				solve(pick - 1, -1); // �ƴ� ���� ������ �� �غ��� �ϴµ�
			}			// ��¦���� else if������� ���� ������ ���ٰ� 
		}				// ����� ����� ���ڳ� �ٺ���
		else { // pick == 1 || 4
			if (pick == 1) {
				if (tp[pick][2] != tp[pick + 1][6]) { //������
					solve(pick + 1, -1);
				}
			}
			if (pick == 4) {
				if (tp[pick][6] != tp[pick - 1][2]) { // ����
					solve(pick - 1, -1);
				}
			}
		}
	
	}else if (dir == -1) { //counter c_wise
		counter_dir(pick); // ó�� ������ �Ŵ� ������ ��������
		
		if (pick == 2 || pick == 3) {
			if (tp[pick][2] != tp[pick + 1][6]) {  //������
				solve(pick + 1, 1);
			}
			if (tp[pick][6] != tp[pick - 1][2]) { // ����
				solve(pick - 1, 1);
			}
		}
		else { // pick == 1 || 4
			if (pick == 1) {
				if (tp[pick][2] != tp[pick + 1][6]) {  //������
					solve(pick + 1, 1);
				}
			}
			if (pick == 4) {
				if (tp[pick][6] != tp[pick - 1][2]) { // ����
					solve(pick - 1, 1);
				}
			}
		}

	}

}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �ʱⰪ �Է� �ޱ�
	for (int i = 1; i <= 4; ++i) {
		for (int j = 0; j < 8; ++j) {
			int tmp;
			scanf("%1d", &tmp);
			arr[i].push_back(tmp);
			tp[i].push_back(tmp);
		}
	}
	/*
	clock_dir(1);
	for (int i = 0; i < 8; ++i) {
		printf("%d ", arr[1][i]);
	}
	*/
	
	scanf("%d", &K);

	for (int cnt = 0; cnt < K; ++cnt) {
		
		scanf("%d %d", &pick, &dir);

		solve(pick,dir);

		for (int j = 1; j <= 4; ++j) {
			check[j] = false;
		}
	
		for (int i = 1; i <= 4; ++i) { // ������ �� ���� ���� �ٽ� ����
			for (int j = 0; j < 8; ++j) {
				tp[i][j] = arr[i][j];
			}
		}


	}
	

	//������
	int result = 0;
	int point = 1;
	for (int i = 1; i <= 4; ++i) {

		if (arr[i][0] == 1) {
			result += point;
		}
		point *= 2;

	}
	printf("%d\n", result);


	
	for (int i = 1; i <= 4; ++i) {
		for (int j = 0; j < 8; ++j) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}


	return 0;
}
