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
		indegree[b]++; // b �տ� �־�� �ϴ� ���� ���� 
		arr[a].push_back(b); //  a���� ���� 
	}
	
	solve(); 
	
	for(int i=0;i<seq.size();++i){
		cout << seq[i] << " ";
	}
	
	return 0;
}
