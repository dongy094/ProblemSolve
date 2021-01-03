#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct node{
	
	char alpa;
	int left;
	int right;
	
} ;

node *nodes;


void inOder(int pos){

	if(nodes[pos].left != -1 ){
		inOder(nodes[pos].left);
	}
	
	cout << nodes[pos].alpa;
	
	if(nodes[pos].right != -1 ){
		inOder(nodes[pos].right);
	}

}

int main(){
	
	
	for(int a=1;a<=10;a++){
		
		int size=0;
		scanf("%d",&size);
		
		nodes = (node*)malloc( sizeof(node)*(size+1) );
		
		for(int i=0;i<size;i++){
		
			int num,l,r;
			char str;
				
			scanf("%d",&num);
			scanf("%s",&str);
			nodes[num].alpa = str;
				
			if( num*2 <= size ){
				scanf("%d",&l);
				//cin >> l;
				nodes[num].left = l;
			}else{
				nodes[num].left = -1;
			}
			
			if( (num*2) + 1 <= size ){
				scanf("%d",&r);
				//cin >> r;
				nodes[num].right = r;
			}else{
				nodes[num].right = -1;
			}	
					
		}
		
	printf("#%d ",a);
	inOder(1);	
	printf("\n");
	
	free(nodes);
	//cout << arr.size();
	
	}
	
	return 0;
}
