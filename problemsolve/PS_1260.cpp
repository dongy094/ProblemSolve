#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>


using namespace std;

vector<int> a[1001];
queue<int> q;
bool check[1001]={false,};

void dfs(int s){
	
	check[s]=true;
	printf("%d ",s);
	
	for(int i=0 ; i<a[s].size() ; i++){
		int y=a[s][i];
		if(check[y]==false){
			check[y]=true;
			dfs(y);
		}
	}
}

void bfs(int s){
	
	memset(check,false,sizeof(check)); 	// dfs���� ����ߴ� check�迭�� false�� �ʱ�ȭ �ϱ� 
	check[s]=true;
	q.push(s);

	while( !q.empty() ){ 			//ť�� ��Ұ� �����Ƿ� 0�ε� !�ؼ� 1�� 
		
		int x = q.front();
		q.pop();
		printf("%d ",x);
		for(int i=0;i<a[x].size();i++){
			int y = a[x][i];
			if(check[y]==false){
				check[y]= true;
				q.push(y);
			}
		}	
	} 
}


int main(){
	
	int i,j;
	int n,m,start;
	scanf("%d %d %d",&n,&m,&start);
	while(m--){
		scanf("%d %d",&i,&j);
		a[i].push_back(j);
		a[j].push_back(i);
	}
	
	for(int t=1 ; t<=n ; t++){
		sort(a[t].begin(),a[t].end());
	}
	
	
	dfs(start);
	printf("\n");
	bfs(start);
	
	return 0;
}
