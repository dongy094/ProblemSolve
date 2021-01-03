#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	int total=0;
	while ( getline(cin,s,',') ){
		total += stoi(s);  // 문자열을 인트로(i)  ,    인트말고도 있음 double -> stod 등등 
	}
	cout << total <<'\n';
	return 0;
}
