#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[26];
	for(int i=0;i<26;++i){
		arr[i] = 0;
	}
	
	string s; cin >> s;
	int s_size = s.size();
	
	for(int i=0;i<s_size;++i){
		arr[ s[i]-97 ]++;
	}
	
	

	for(int i=0;i<26;++i){
		cout << arr[i] << " ";
	}
	
	
	
	return 0;
}
