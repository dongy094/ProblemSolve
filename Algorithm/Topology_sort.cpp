#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int indegree[100]={0,};
queue<int> q;
vector<int> arr[100];

int n =7;


void topology(){
	
	for(int i=1;i<=n;++i){
		if(indegree[i] == 0){
			q.push(i);
		}
	} 
	
	while(!q.empty()){
		
		int x = q.front(); q.pop();
		cout << x << " ";
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

	//	  --->(2) --->(3) --->(4)
	//    |                    |	  
	//	 (1)           天天天天天 ( 4 --> 6 )
	//	  |            |
	//	  --->(5) --->(6) --->(7)

	arr[1].push_back(2);	
	indegree[2]++;
	arr[1].push_back(5);	
	indegree[5]++;
	arr[2].push_back(3);	
	indegree[3]++;
	arr[3].push_back(4);	
	indegree[4]++;
	arr[4].push_back(6);	
	indegree[6]++;
	arr[5].push_back(6);	
	indegree[6]++;
	arr[6].push_back(7);	
	indegree[7]++;
	
	

	
	topology();
	
	return 0;
}
