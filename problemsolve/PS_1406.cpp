#include <iostream>
#include <list>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	list<char> p;
	string s; cin >> s;
	int s_size = s.size();
	for(int i=0;i<s_size;++i){
		p.push_back( s[i] );
	}
	int num; cin >> num;
	list<char>::iterator it = p.end();
	
	for(int i=0;i<num;++i){
		char op; cin >> op;
		if(op == 'P'){
			char insub; cin >> insub;
			p.insert(it,insub);
		}else if(op == 'L'){
			if(it != p.begin()){
				it--;
			}
		}else if(op == 'D'){
			if(it != p.end()){
				it++;
			}
		}else if(op == 'B'){
			if(it != p.begin()){
				it--;
				it = p.erase(it);	
			}
		}
	}
	
	for(auto c : p){
		cout << c;
	}
	
	return 0;
}
