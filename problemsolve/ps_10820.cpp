#include <iostream>
#include <string>

using namespace std;

int main(){
	
	string s;
	int low = 0;
	int num = 0;
	int cap = 0;
	int spa = 0;
	
	getline(cin,s);
	for(  char x : s)
	{
		if( x>='a' && x<='z')
			low += 1;
		else if( x>='A' && x<='Z' )
			cap += 1;
		else if( x>=0 && x<=9 )
			num += 1;
		else if( x ==' ')
			spa +=1;
	}

	cout << "low :" <<low<<"cap :"<< cap <<"\n";
	cout << "num :" <<num<<"spa :"<< spa <<"\n";
	
	return 0;

}
