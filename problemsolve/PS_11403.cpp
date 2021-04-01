#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int map[100][100];
int check[100] = { 0 };
int result[100][100] = { 0 };
int n;

void bfs(int start) {
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 0; i < n; i++) {
			if (map[current][i] == 1 && check[i] == 0) {
				q.push(i);
				check[i] = 1;
				result[start][i] = 1;
			}
		}
	}

}

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
			memset(check, 0, sizeof(int)*100);
			bfs(i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
}
