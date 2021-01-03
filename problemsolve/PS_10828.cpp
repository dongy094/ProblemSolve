#include <iostream>
#include <stack>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<int> s;

	int tc; cin >> tc;
	for(int i=0;i<tc;i++){
		
		string ch; 
		cin >> ch;
		if(ch == "push"){
			int num; 
			cin >> num;
			s.push(num);
		}else if(ch == "top"){
			if( s.empty() ){
				cout << -1 <<"\n";
			}else{
				cout << s.top()<<"\n";
			}
		}else if(ch == "size"){
			cout << s.size()<<"\n";
		}else if(ch == "empty"){
			if( s.empty() ){
				cout << 1 <<"\n";
			}else{
				cout << 0 <<"\n";
			}
		}else if(ch=="pop"){
			if(s.empty()){
				cout << -1 <<"\n";
			}else{
				cout << s.top() << "\n";
				s.pop();	
			}
		}
	}
	
	return 0;
}
