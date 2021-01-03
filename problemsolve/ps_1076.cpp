#include <iostream>
#include <string> 
#include <map>
using namespace std;
int main(){
	map<string,int> d = {
		{"black",0},   {"brown",1},
		{"red",2},  	{"oreange",3},	
		{"yellow",4},   {"green",5},
		{"blue",6},	   {"violet",7},
		{"grey",8},	   {"white",9}	
	};
	
	string a,b,c;
	cin>>a>>b>>c;
	
	long long ans = (long long)( d[a]*10+d[b] );
	for(int i=0;i<d[c];i++)
		{
			ans *= 10;
		}
		
	cout << ans << '\n';
	return 0;
}

