#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
vector<int> arr[10];
vector<int> tp[10]; // 복사본, 돌리전 톱니 상태
bool check[5] = { false, };

int K; // 회전 횟수
int pick; // 회전할 톱니
int dir;  // 1이면 시계방향 회전, -1 반시계 회전


// 시계방향 -> 1칸이동
void clock_dir(int pick) {
	check[pick] = true;
	int tmp = arr[pick][7];
	for (int i = 7; i >= 1; --i) {
		arr[pick][i] = arr[pick][i - 1];
	}
	arr[pick][0] = tmp;

}

// 반시계 <- 1칸이동
void counter_dir(int pick) {
	check[pick] = true;
	int tmp = arr[pick][0];
	for (int i = 0; i <= 6; ++i) {
		arr[pick][i] = arr[pick][i + 1];
	}
	arr[pick][7] = tmp;

}

void solve(int pick,int dir) {  // 돌리기 전 상태를 보고 주변 꺼를 돌릴지 말지 결정
								// 돌리고 난 후의 상태와 주변 꺼를 비교하는게 아니라

	if (pick <= 0 || pick >= 5) return;
	if (check[pick]) return;

	if (dir == 1) {// clockwise
		clock_dir(pick); // 처음 돌리는 거는 무조건 돌려야함
		
		if (pick == 2 || pick == 3) {
			if (tp[pick][2] != tp[pick+1][6]) { // 접촉 부분 극 다르면 반대로 돌려 그짝거
				solve(pick + 1, -1);
			}
			if (tp[pick][6] != tp[pick - 1][2]) { // 왼쪽
				solve(pick - 1, -1); // 아니 왼쪽 오른쪽 다 해봐야 하는데
			}			// 이짝에서 else if써버리면 위에 오른쪽 들어갔다가 
		}				// 여기는 못들어 오자나 바보야
		else { // pick == 1 || 4
			if (pick == 1) {
				if (tp[pick][2] != tp[pick + 1][6]) { //오른쪽
					solve(pick + 1, -1);
				}
			}
			if (pick == 4) {
				if (tp[pick][6] != tp[pick - 1][2]) { // 왼쪽
					solve(pick - 1, -1);
				}
			}
		}
	
	}else if (dir == -1) { //counter c_wise
		counter_dir(pick); // 처음 돌리는 거는 무조건 돌려야함
		
		if (pick == 2 || pick == 3) {
			if (tp[pick][2] != tp[pick + 1][6]) {  //오른쪽
				solve(pick + 1, 1);
			}
			if (tp[pick][6] != tp[pick - 1][2]) { // 왼쪽
				solve(pick - 1, 1);
			}
		}
		else { // pick == 1 || 4
			if (pick == 1) {
				if (tp[pick][2] != tp[pick + 1][6]) {  //오른쪽
					solve(pick + 1, 1);
				}
			}
			if (pick == 4) {
				if (tp[pick][6] != tp[pick - 1][2]) { // 왼쪽
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

	// 초기값 입력 받기
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
	
		for (int i = 1; i <= 4; ++i) { // 돌리고 난 후의 상태 다시 복사
			for (int j = 0; j < 8; ++j) {
				tp[i][j] = arr[i][j];
			}
		}


	}
	

	//결과출력
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
