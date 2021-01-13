#include <iostream>

using namespace std;
int N;

struct node{
	char left,right;
	char alpha;
};

node *nodes;

void preOrder(char pos){
	
	cout << nodes[pos].alpha;
	
	if(nodes[pos].left != -1){
		preOrder(nodes[pos].left);
	}
	
	if(nodes[pos].right != -1){
		preOrder(nodes[pos].right);
	}
	
}

void inOrder(char pos){
	
	
	if(nodes[pos].left != -1){
		inOrder(nodes[pos].left);
	}
	
	cout << nodes[pos].alpha;

	if(nodes[pos].right != -1){
		inOrder(nodes[pos].right);
	}
	
}

void postOrder(char pos){
	
	if(nodes[pos].left != -1){
		postOrder(nodes[pos].left);
	}
	
	if(nodes[pos].right != -1){
		postOrder(nodes[pos].right);
	}
	
	cout << nodes[pos].alpha;
	
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;	
	nodes = (node*)malloc(sizeof(node)*(N+1));
	for(int i=1;i<=N;++i){
		
		char val,le,ri;
		cin >> val >> le >> ri;
		
		nodes[val].alpha = val;
		
		if(le!='.'){
			nodes[val].left = le;
		}else{
			nodes[val].left = -1;
		}
		
		if(ri!='.'){
			nodes[val].right = ri;
		}else{
			nodes[val].right = -1;
		}
			
	}
	
	preOrder('A'); cout << "\n";
	inOrder('A'); cout << "\n";
	postOrder('A'); cout << "\n";
	
	free(nodes);
	
	return 0;
}
