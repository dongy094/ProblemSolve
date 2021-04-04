#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int N,K;
int result[1000]={0};
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> K;
	//init()
	for(int i=1;i<=N;++i){
		q.push(i);
	}
	
	int cur = 0;
	int pos = 1;
	while(!q.empty()){
		
		if(pos == K){
			result[cur] = q.front();
			q.pop();
			cur++;
			pos = 1;
		}else{
			int tmp = q.front();
			q.pop();
			q.push(tmp);
			pos++;
		}
	}	
	cout << "<";
	for(int i=0;i<N;++i){
		if(i==(N-1)){
			cout << result[i];
		}else{
			cout << result[i] <<", ";
		}	
	}	
	cout << ">";
	return 0;
}
