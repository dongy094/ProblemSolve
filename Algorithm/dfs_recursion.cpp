#include <cstdio>
#include <iostream>
using namespace std;

bool visited[100]={false};
int map[100][100]={0};
int E,N;

void dfs(int n){
	
	visited[n]=true;
	cout << n << ' ';
	
	for(int next=0;next<N;next++){
		if( !visited[next] && map[n][next] ){
			dfs(next);
		}
	}
}

int main(){
	
	freopen("graph_search_input.txt","r",stdin);
	cin >> N >> E;
	for(int i=0;i<E;i++){
		int a,b;
		cin >> a >> b;
		map[a][b]=map[b][a]=1;
	}
	dfs(0);
	return 0;
}
