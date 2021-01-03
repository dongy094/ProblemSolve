#include <iostream>
#include <stack>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<int> s;

	int tc; cin >> tc;
	int sum=0;
	while(tc--){
		int num; cin >> num;
		if( num ){ // if num is zero(false)
			s.push(num);
			sum += num;
		}else{ // num is zero
			if(!s.empty()){
				sum -= s.top();
				s.pop();
			}
		}
	}

		 	
	cout << sum;


	return 0;
}
