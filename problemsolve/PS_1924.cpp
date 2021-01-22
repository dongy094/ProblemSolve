#include <iostream>
#include <cstring>
using namespace std;

int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
string week[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int m,d;
	cin >> m >> d;
	
	int total=0;
	total += (d-1);
	for(int i=1;i<m;++i){
		total += month[i];
	}
	
	int mo = total % 7;
	cout << week[mo];
	
	return 0;
}
