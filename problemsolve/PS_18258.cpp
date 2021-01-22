#include <iostream>
#include <queue>
using namespace std;

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;
	
	queue<int> q;
	
	for(int i=0;i<N;++i){
		
		string str; 
		int num;
		cin >> str;
		
		if(str=="push"){
			cin >> num;
			q.push(num);
		}else if(str=="front"){
			if(!q.empty()){
				cout << q.front() << "\n";	
			}else{
				cout << -1 << "\n";
			}
		}else if(str=="back"){
			if(!q.empty()){
				cout << q.back() << "\n";
			}else{
				cout << -1 << "\n";
			}
		}else if(str=="size"){
			cout << q.size() << "\n";
		}else if(str=="empty"){
			if(q.empty()){
				cout << 1 << "\n";
			}else{
				cout << 0 << "\n";
			}
		}else if(str=="pop"){
			if(!q.empty()){
				cout << q.front() << "\n";
				q.pop();
			}else{
				cout << -1 << "\n";
			}
		}
		
	}
	
	return 0;
}
