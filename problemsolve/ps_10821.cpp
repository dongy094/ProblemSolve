#include <iostream>
#include <string>

using namespace std;

int main(){
	
	int cnt = 0;
	string s;
	
	while ( getline(cin,s,',') )  // 3������ ������ �Է��� ���� ���̰� �� , ������ �Է¹ްڴ�. 
	{
		cnt += 1;
	}
	
	cout << cnt <<'\n';
	
	return 0;
}
