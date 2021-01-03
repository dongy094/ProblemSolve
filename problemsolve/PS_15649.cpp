#include <iostream>
using namespace std;

int N, M;
int arr[10] = { 0, };
int check[10] = { 0, };

void solve(int k) {
	if (k == M) {
		for (int i = 0; i < M ; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!check[i]) {	 // 방문X라면
			arr[k] = i;
			check[i] = 1;
			solve(k + 1);
			check[i] = 0;
		}
	}

}


int main() {

	cin >> N >> M;
	solve(0);

	return 0;
}