#include <iostream>
#include <queue>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<int> q;
	
	int cnt; cin>>cnt;
	for(int i=0;i<cnt;++i){
		string ch; cin>>ch;
		if(ch=="push"){
			int num; cin>>num;
			q.push(num);
		}else if(ch=="pop"){
			if(q.empty()){
				cout << -1 <<"\n";
			}else{
				cout << q.front() <<"\n";
				q.pop();
			}
		}else if(ch=="size"){
			cout << q.size() <<"\n";
		}else if(ch=="empty"){
			if(q.empty()){
				cout << 1 <<"\n";
			}else{
				cout << 0 <<"\n";
			}
		}else if(ch=="front"){
			if(q.empty()){
				cout << -1 <<"\n";
			}else{
				cout <<q.front() <<"\n";
			}
		}else if(ch=="back"){
			if(q.empty()){
				cout << -1 <<"\n";
			}else{
				cout << q.back() <<"\n";
			}
		}
	}
	
	return 0;
}
