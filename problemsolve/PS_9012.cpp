#include <iostream>
#include <stack>
using namespace std;

string vaild(string ch)
{
	
	int cnt = 0;
	for( char x : ch ) //string은 변수 갯수 갤수 있다?  i<s.size()
	{
		if(x=='(')
		{
			cnt++;
		}
		else if(x==')'){
			cnt--;
		}	
		if(cnt<0){
			return "NO\n";
		}
	}
	
	if( cnt == 0  )   
		{
			return "YES\n";
		}
	else//잔여물이 있어도 No 
	{
		return "NO\n";
	}
	
}


int main(){
	
	int t;
	cout << t;
	while(t--){
		string s;
		cin >> s;
		cout << vaild(s) << "\n";
	}
	
}





