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
	fill(combi.begin(), combi.begin() + chicken.size() - M, 0); // �ִ� M���� ġŲ�� ����� ���ϱ�	
																// �ٻ���ҋ��� ġŲ�Ÿ� �ּҰ� ����
	
	//�� �� ���ϰ�, ġŲ �� ���� �� �ּҰŸ� ���ϱ�


	int mn = 99999; // ��ü ġŲ�ּҰŸ�

	do {// �ִ� �� ġŲ������ M�� ����  nCm���� ����� �� ��� �ϱ�
		int dist = 0; // ���� ���� ġŲ �ּҰŸ�

		for (auto h : house) { // �� ���� ġŲ �ּҰŸ� ���ϱ� 
							   // ���� ġŲ�� ��ġ ���տ����� ��ü ġŲ�ּҰŸ� ���ϱ�
			int tmp = 99999;
			for (int i = 0; i < chicken.size(); ++i) { //�� ġŲ���� ���� ���� ġŲ�Ÿ� �� �ּ� ���ϱ�
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
