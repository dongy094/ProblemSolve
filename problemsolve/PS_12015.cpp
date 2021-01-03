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
		
		if( arr.back() < x ){ // 마지막 값보다 크다면 맨 뒤에 삽입 
			arr.push_back(x);
			cnt++;
		}else{ // 맨 뒤 값보다 작다면 그 앞에다 삽입해야 하는데
				// 로우 바운드로 x값 이상 인 위치중 제일 작은 값 찾아서
				//  10 20 25 인데 20값 넣을 순서면 이상이니까 20위치에 들어감
				//  
			
			vector<int>::iterator iter;
			iter = lower_bound(arr.begin(),arr.end(),x);
			*iter = x;
			
		}
		
	}
	
	cout << cnt;
	return 0;
}
