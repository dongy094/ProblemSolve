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
		arr[b].push_back(a);  // ����� ����� 1->2->3, 4->3 �̷���쵵 1,2,3,4 �����ȰŴϱ� 
	}
	
	solve(1);
	
	cout << infect_cnt;
	
	return 0;
}
