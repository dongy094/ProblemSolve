#include <cstdio>
using namespace std;

int parent[10];

void make_set(int v){ //초기화(자기자신 가리키기) 
	parent[v] = v;
}

int find_set(int v){ //정점의 부모노드? 찾기 
	if(v == parent[v]) return v; //자기자신을 가리키니까 자기가 최고노드
	return find_set(parent[v]);	
}
		   // y가 x의 부모노드가 되는것 
void union(int x,int y) { //합치기 
	parent[find_set(x)] = find_set(y);
}


int main(){
	
	return 0;
}
