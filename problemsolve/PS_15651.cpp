#include <iostream>

using namespace std;

int check[1000] = { 0, };
int arr[1000] = { 0, };
int N, M;
void solve(int n) {

	if (n == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		arr[n] = i;
		solve(n + 1);

	}


}


int main() {

	cin >> N >> M;
	
	solve(0);



	return 0;
}
