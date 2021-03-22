#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <set>
using namespace std;

string Start, End;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int move_cnt = 0;
set<string> s; // 해당 조합을 한적이 있는지 검사

int solve() {
		//        조합 ,  move_cnt 
	queue < pair<string, int> > q;
	q.push({ Start, 0 });
	s.insert(Start);

	while (!q.empty()) {

		string ch = q.front().first;
		int move_cnt = q.front().second;
		q.pop();

		if (ch == End) {
			return move_cnt;
		}

		int index = ch.find('0');
		int x = index % 3; //0위치 (배열상) index이용하여  x,y구하기
		int y = index / 3;

		for (int i = 0; i < 4; ++i) {

			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 3 || ny >= 3 || nx < 0 || ny < 0) continue;

			string next = ch;
			// 현 0위치 x,y 랑  바꿀 수 있는 다음 위치 nx,ny를 바꾸기 조합 찾아보기
			swap(next[y * 3 + x], next[ny * 3 + nx]);

			if (s.find(next) == s.end()) {
				s.insert(next);
				q.push({ next, move_cnt+1 });
			}

		}


	}


	return -1;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	End = "123456780";
	int a;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> a; 
			char tmp = a + '0';	// 문자로 만들기
			Start += tmp;
		}
	}

	cout << solve();

	return 0;
}