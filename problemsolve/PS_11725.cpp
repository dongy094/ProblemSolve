#include <iostream>
#include <vector>
#define MAX 100010
using namespace std;

int N;
vector<int> arr[MAX];
bool check[MAX]={false,};
int parent[MAX]={0,};

void solve(int pos){
		
    check[pos] = true;
	//
	//if(check[pos]) return;	
    
    
	int size = arr[pos].size();
	for(int i=0;i<size;++i){
		int next_pos = arr[pos][i];
		
		if(check[next_pos]) continue;
		//check[next_pos] = true;
		parent[next_pos] = pos;
		solve(next_pos);
	}
	
	
}


int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	
	for(int i=0;i<N-1;++i){
		int t1,t2;
		cin >> t1 >> t2;
		arr[t1].push_back(t2);
		arr[t2].push_back(t1);
	}
	
	solve(1);
	
	for(int i=2;i<=N;++i){
		cout << parent[i] << "\n";
	}
	
	return 0;
}
