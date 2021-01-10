#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<string> arr;
int result = 10;
string str;

void solve(){
	
	int size = str.size();
	for(int i=1;i<size;++i){
		if(str[i-1] == str[i]){
			result += 5;
		}else{
			result += 10;
		}
	}
		

}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> str;
	solve();
	cout << result;
	
	return 0;
}


