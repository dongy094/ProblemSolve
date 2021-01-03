#include <cstdio>
#include <cstring>

using namespace std;
int parent[10001], Depth[10001], Size[10001];
//  i�Ǻ�=p[i]�� 
int tree[10001][2];

void init(){
	
	for(int i=0;i<10001;++i){
		memset(tree[i],0,sizeof(int)*2);
	}
	
}


int search_child(int node,int depth){
	int cnt = 0;
	if(node != 0){
		cnt++;
		cnt += search_child( tree[node][0], depth+1 );
		cnt += search_child( tree[node][1], depth+1 );
	}
	
	Depth[node] = depth;
	Size[node] = cnt;
	return cnt;
}

int search_ans(int n1,int n2){
	
	int u = Depth[n1] > Depth[n2] ? n1 : n2; // u�� ���� �� ���� �ִ�. 
	int v = Depth[n1] > Depth[n2] ? n2 : n1;
	
	int hdiff =  Depth[u] - Depth[v]; // �� ����� �������� 
	for(int h=0;h<hdiff;++h){ // �� ����� ���� ���߱� 
		u = parent[u];
	}
	
	while( u != v ){ //��������ã�� 
		u = parent[u];
		v = parent[v];
	}
	
	return u;
}


int main(){
	
	int tc=0;
	scanf("%d",&tc);
	int V=0,E=0;
	int n1=0,n2=0;
	for(int i=1;i<=tc;++i){

		scanf("%d %d",&V,&E);
//		for(int i=1;i<=V;++i){
//			tree[i][0] = tree[i][1] = 0;
//		}
		init();	
		scanf("%d %d",&n1,&n2);
		for(int j=0;j<E;++j){
			int p,c;
			scanf("%d %d",&p,&c);
			if(tree[p][0] == 0) {
				tree[p][0]=c;	
			}else{
				tree[p][1]=c;
			} 
			parent[c]=p;
		}
		search_child(1,0); 
		int com_ans = search_ans(n1,n2);
		printf("#%d %d %d\n",i, com_ans, Size[com_ans]);
	}
	
	
	return 0;
}
