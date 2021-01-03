#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int map[52][52];
int N, M;

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 1) { // house
				house.push_back({ i,j });
			}
			if (map[i][j] == 2) {
				chicken.push_back({ i,j });
			}
		}
	}

	vector<int> combi(chicken.size(), 1);
	fill(combi.begin(), combi.begin() + chicken.size() - M, 0); // 최대 M개의 치킨집 골랐을 때니까	
																// 다사용할떄가 치킨거리 최소값 나옴
	
	//한 집 택하고, 치킨 집 조합 중 최소거리 구하기


	int mn = 99999; // 전체 치킨최소거리

	do {// 최대 총 치킨집에서 M개 선택  nCm조합 경우의 수 모두 하기
		int dist = 0; // 현재 집의 치킨 최소거리

		for (auto h : house) { // 각 집의 치킨 최소거리 구하기 
							   // 현재 치킨집 위치 조합에서의 전체 치킨최소거리 구하기
			int tmp = 99999;
			for (int i = 0; i < chicken.size(); ++i) { //각 치킨집별 지금 집의 치킨거리 중 최소 구하기
				if (combi[i] == 0) continue;
				tmp = min(tmp, abs(chicken[i].first - h.first) + abs(chicken[i].second - h.second) );

			}
			dist += tmp;
		}
		
		mn = min(mn, dist);
	} while (next_permutation( combi.begin(), combi.end() ) );
	
	cout << mn;

	return 0;
}
