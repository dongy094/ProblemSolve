#include <iostream>
#include <vector>
//#include <algorithm>

using namespace std;
int N;
vector<int> arr;

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	arr.push_back(-99);
	int cnt=0;
	cin >> N;
	int x;
	for(int i=0;i<N;++i){
		cin >> x;
		
		if( arr.back() < x ){ // ������ ������ ũ�ٸ� �� �ڿ� ���� 
			arr.push_back(x);
			cnt++;
		}else{ // �� �� ������ �۴ٸ� �� �տ��� �����ؾ� �ϴµ�
				// �ο� �ٿ��� x�� �̻� �� ��ġ�� ���� ���� �� ã�Ƽ�
				//  10 20 25 �ε� 20�� ���� ������ �̻��̴ϱ� 20��ġ�� ��
				//  
			
			vector<int>::iterator iter;
			iter = lower_bound(arr.begin(),arr.end(),x);
			*iter = x;
			
		}
		
	}
	
	cout << cnt;
	return 0;
}
