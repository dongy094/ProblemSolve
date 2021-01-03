#include <iostream>
using namespace std;

void solve(int a, int b, int num){
	if(num == 1){
		cout << a << " " << b << "\n";
		return;
	}
	solve(a,6-a-b,num-1);  // n-1���� a-> a��b���ƴ� (6-a-b)�� �ű�� 
	cout << a << " "<< b << "\n"; // n���� a->b �� �����.  
	solve(6-a-b,b,num-1);   // n-1���� 6-a-b ���� b�� �����. 

}


int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int num; cin>>num;
	cout << (1<<num)-1 << "\n";
	solve(1,3,num);
	
	return 0;
}
