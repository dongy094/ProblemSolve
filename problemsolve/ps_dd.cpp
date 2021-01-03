#include <iostream>
#include <string>

using namespace std;


int main(){
	
	string s;
	int total;
	while ( getline(cin,s,',') ){
		total += stoi(s);
	}
	cout << total <<"\n";
	
	
	return 0;
}
