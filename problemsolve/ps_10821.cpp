#include <iostream>
#include <string>

using namespace std;

int main(){
	
	int cnt = 0;
	string s;
	
	while ( getline(cin,s,',') )  // 3번쨰는 어디까지 입력을 받을 것이가 즉 , 전까지 입력받겠다. 
	{
		cnt += 1;
	}
	
	cout << cnt <<'\n';
	
	return 0;
}
