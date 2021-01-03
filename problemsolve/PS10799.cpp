#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
	
	stack<int> s;
	string a;
	cin >> a;
	int sum = 0;
	int n = a.size();
	
	for(int i=0 ; i<n ; i++)
	{
		if(a[i]=='(') 
		{
			s.push(i);
		}
		else if(a[i]==')')
		{
			if( s.top() + 1 == i )
			{
				s.pop();
				sum += s.size();
			}
			else 
			{
				s.pop();
				sum += 1;
			}
		}	
	}
	cout << sum << "\n";
	return 0;
}



