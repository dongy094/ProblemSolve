#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	int total=0;
	while ( getline(cin,s,',') ){
		total += stoi(s);  // ���ڿ��� ��Ʈ��(i)  ,    ��Ʈ���� ���� double -> stod ��� 
	}
	cout << total <<'\n';
	return 0;
}
