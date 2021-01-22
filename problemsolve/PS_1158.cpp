#include <iostream>
#include <queue>
using namespace std;

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N,K;
	cin >> N >> K;
	
	queue<int> q;
	int result[5010]={0,};
	
	for(int i=1;i<=N;++i){
		q.push(i);
	}
	
	int cnt = 1;
	int pos = 1;
	while(true){
		
		if(q.empty()){
			break;
		}
		
		if(cnt==K){
			result[pos++] = q.front(); q.pop();
			cnt = 1;
		}else{
			int tmp = q.front(); q.pop();
			q.push(tmp);
			cnt++;
		}
		
	}
	
	cout << "<";
	for(int i=1;i<=N;++i){
		if(i==N){
			cout << result[i];
		}else{
			cout << result[i] << ", ";	
		}
		
	}
	cout << ">";
	return 0;
}
