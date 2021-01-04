#include <iostream>

#define ll long long
using namespace std;

int gcd(int a,int b){
	return b ? gcd(b,a%b) : a;
}

int tc;
int k;
int arr[100];
ll result[100];


int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >>  tc;
	
	for(int cnt = 1;cnt<=tc;++cnt){
		
		cin >> k;
		for(int i=0;i<k;++i){
			cin >> arr[i];
		}
		
		
		ll tmp_sum = 0;
		for(int i=0;i<k-1;++i){
			for(int j=i+1;j<k;++j){
				tmp_sum += gcd(arr[i],arr[j]);
			}
		}
		
		result[cnt-1] = tmp_sum;

	}
	
	for(int i=0;i<tc;++i){
		cout <<result[i] << "\n";
	}
	
	
	return 0;
}


	
	
