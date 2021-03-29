#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10010

using namespace std;

int N;

vector<pair<int,int>> arr[MAX];
bool check[MAX] = {0,};

int far_node = 0;
int diameter = 0;

void solve(int pos,int sum){
	
	check[pos] = true; // 트리 방문할때 처음 시작하는 노드도 방문처리 꼭!! 
	
	if(sum>diameter){
		diameter = sum;
		far_node = pos;
	}
	
	int size = arr[pos].size();
	for(int i=0;i<size;++i){
		
		int next_pos = arr[pos][i].first;
		if(!check[next_pos]){
			
		//	check[next_pos] = true;
		//	sum += arr[pos][i].second;
			solve(next_pos,sum+arr[pos][i].second);
		}
		
	}
	
	
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	for(int i=0;i<N-1;++i){
		int p,c,v;
		cin >> p >> c >> v;
		arr[p].push_back({c,v});
		arr[c].push_back({p,v});
	} 
	
	solve(1,0);
	//cout << far_node << " " << diameter << "\n";
	for(int i=0;i<MAX;++i){
		check[i] = false;
	}
	diameter = 0;
	solve(far_node,0);
	
	cout << diameter;
	
	return 0;
}
