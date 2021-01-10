#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<int,int>> arr;
int result[55];

void solve(){
	
	for(int pick=0;pick<N;++pick){
		int K=1;
		for(int compare = 0, j=0 ; j<N ; ++j,compare++){
			if(pick==compare) continue;
			
			if(arr[pick].first < arr[compare].first){
				if(arr[pick].second < arr[compare].second){
					K+=1;
				}
			}
		
		}
		result[pick] = K;
	}
	
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i=0;i<N;++i){
		int w,h; cin >> w >> h;
		arr.push_back({w,h});
	}
	
	solve();
	
	for(int i=0;i<N;++i){
		cout << result[i] << " ";
	}
	
	return 0;
}
