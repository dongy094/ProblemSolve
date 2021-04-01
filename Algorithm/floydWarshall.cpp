#include <iostream>
#define INF 10000000
using namespace std;
int result[4][4] = {
	{0, 5, INF, 8},
	{7, 0, 9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0}
};

int main(void) {
// �׷������� ��� ������ ������ �ִ� ����� �Ÿ��� ���ϴ� �˰���
// �׷����� ������ ���鼭 ����Ѵ� 
// �������� ��ġ�� ���ļ� ���°� ����
// 1->2->3 ����ϰ��� ���Ŀ�, 1->3->4 �̰Ÿ� �ᱹ 1,2,3,4���� ���� �ִܰ�� 

	for(int k = 0; k < 4; k++) { // k = ���İ��� ���
	
		for(int start = 0; start < 4; start++) {// start = ��� ���
			 
			for(int dest = 0; dest < 4; dest++) {// dest = ���� ���
				if(result[start][k] + result[k][dest] < result[start][dest]) {
					result[start][dest] = result[start][k] + result[k][dest];
				}
			}
		} 
	} 
	
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	} 
	
}
