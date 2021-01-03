#include <iostream>
using namespace std;

void solve(int a, int b, int num){
	if(num == 1){
		cout << a << " " << b << "\n";
		return;
	}
	solve(a,6-a-b,num-1);  // n-1개를 a-> a도b도아닌 (6-a-b)로 옮긴다 
	cout << a << " "<< b << "\n"; // n개를 a->b 로 옯긴다.  
	solve(6-a-b,b,num-1);   // n-1개를 6-a-b 에서 b로 옯긴다. 

}


int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int num; cin>>num;
	cout << (1<<num)-1 << "\n";
	solve(1,3,num);
	
	return 0;
}
