#include <cstdio>
using namespace std;

int parent[10];

void make_set(int v){ //�ʱ�ȭ(�ڱ��ڽ� ����Ű��) 
	parent[v] = v;
}

int find_set(int v){ //������ �θ���? ã�� 
	if(v == parent[v]) return v; //�ڱ��ڽ��� ����Ű�ϱ� �ڱⰡ �ְ���
	return find_set(parent[v]);	
}
		   // y�� x�� �θ��尡 �Ǵ°� 
void union(int x,int y) { //��ġ�� 
	parent[find_set(x)] = find_set(y);
}


int main(){
	
	return 0;
}
