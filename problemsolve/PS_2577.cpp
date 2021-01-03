#include <iostream>

using namespace std;

long A,B,C;
int arr[12] = {0,};

void solve(long num){
	
	int number = num;

	while( number != 0 ){
	
		int tmp = 0;
		
		tmp = number%10;
		number = number/10;
		
		arr[tmp]++;
		
	}
	
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> A >> B >> C;
	int num = A*B*C;
	
	solve(num);
	
	//result//
	for(int i=0;i<10;++i){
		cout << arr[i] << "\n";
	}
}
