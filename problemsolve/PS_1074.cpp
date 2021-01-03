#include <iostream>

using namespace std;
int N, R, C;


int solve(int n, int r, int c) {

	//base condition
	if (n==0) {
		return 0;
	}

	int length = (1 << n);
	int half = length / 2;
	
	//visit to Z shape

	// 2��и鿡 ��ġ�� �ִٸ� R,C ��ǥ��
	if ( r < half && c < half) {
		return solve(n - 1, r, c);
	}
	// 1��и�
	if (r < half && c >= half) {
		return half * half + solve(n - 1, r, c-half);
	}
	// 3��и�
	if (r >= half && c < half) {
		return 2 * (half*half) + solve(n - 1, r-half, c);
	}
	// 4��и�
	if (r >= half && c >= half) {
		return 3 * (half*half) + solve(n - 1, r-half, c-half);
	}
}


int main() {

	cin >> N >> R >> C;
	int result = solve(N, R, C);
	cout << result;


	return 0;
}