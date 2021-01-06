#include <iostream>
#include <vector>
#include <queue>
#define MAX 35000
using namespace std;
int N,M;

queue<int> q;
vector<int> arr[MAX];
int indegree[MAX]={0,};
vector<int> seq;

void solve(){
	
	for(int i=1;i<=N;++i){
		if(indegree[i]==0){
			q.push(i);
		}
	}
	
	while(!q.empty()){
		int x = q.front(); q.pop();
		seq.push_back(x);
		
		for(int i=0;i<arr[x].size();++i){
			int tmp = arr[x][i];
			indegree[tmp]--;
			
			if(indegree[tmp]==0){
				q.push(tmp);
			}
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
		indegree[b]++; // b 앞에 있어야 하는 숫자 갯수 
		arr[a].push_back(b); //  a다음 순서 
	}
	
	solve(); 
	
	for(int i=0;i<seq.size();++i){
		cout << seq[i] << " ";
	}
	
	return 0;
}
