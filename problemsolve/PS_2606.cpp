#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<int> arr[101];
int check[101]={0,};
int infect_cnt = 0;

void solve(int pos){
	
	check[pos] = 1;
	
	for(int i=0;i<arr[pos].size();++i){
		
		if( check[ arr[pos][i] ] == 0 ){
           
           	infect_cnt++;
			solve(arr[pos][i]);
			
		}
		
	}
	
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	for(int i=0;i<M;++i){
		int a,b;
		cin >> a >> b;
		arr[a].push_back(b);  // a -> b 
		arr[b].push_back(a);  // 양방향 해줘야 1->2->3, 4->3 이런경우도 1,2,3,4 감염된거니까 
	}
	
	solve(1);
	
	cout << infect_cnt;
	
	return 0;
}
