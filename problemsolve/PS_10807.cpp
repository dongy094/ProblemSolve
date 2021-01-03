#include <iostream>
using namespace std;

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[1000];
	for(int i=0;i<1000;++i){
		arr[i] = 0;
	}
	int num;
	cin >> num;
	for(int i=0;i<num;++i){
		int tmp; cin >>tmp;
		arr[tmp+100]++;
	}
	int result; cin >> result;
	cout << arr[result+100];
	
	return 0;
}
