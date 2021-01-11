#include <iostream>
#include <vector>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<string> arr;
	string star = "*";
	for(int i=0;i<N;++i){
		arr.push_back(star);
		star+="*";
	}
	for(string a : arr){
		cout << a << "\n";
	}
	return 0;
}
