#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000100
using namespace std;

//int arr[7]={20,40,30,50,10,80,70};
int arr[7]={3,8,1,5,2,7,10};
int N = 7;
vector<int> vec;
int ans = 0;

void solve(){
	
	vec.push_back(-INF);
	for(int i=0;i<N;++i){
		int x = arr[i];
		if( vec.back() < x ){
			vec.push_back(x);
			ans++;
		}else{
			auto iter = lower_bound(vec.begin(),vec.end(),x);
			*iter = x;
		}
	}
	
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	int size = vec.size();
	for(int i=1;i<size;++i){
		cout << vec[i] << " ";
	}
	
	
	return 0;
}
