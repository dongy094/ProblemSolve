#include <iostream>
#include <cmath>
using namespace std;

int n;
int map[16];
int ans=0;

bool check(int i){

	for(int j=0 ; j<i ; j++)
	{
	
		if( map[j] == map[i] || abs(map[i]-map[j]) == (i-j) ){
			return false;
		}
		
	}
	return true;
}

bool solve(int i){


	if( i == n ){

		ans +=1;

	}else{

		for(int j=0 ; j<n ; j++){

			map[i] = j; // row+1��, i���� ���� �� �� ����

			if( check( i ) ){ // ������ġ�� ���� �� �ִٸ� 
				solve( i+1 );
			}
		}

	}

}

int main(){

	

	cin >> n;
	solve(0);
	cout << ans;

	return 0;

}
