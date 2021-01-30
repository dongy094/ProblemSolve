#include <iostream>
#include <algorithm>
#define MAX 987654321
using namespace std;

int arr[10];
bool check = false;
int tmp_sum;
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int sum_height = 100;
	
	
	for(int i=1;i<=9;++i){
		cin >> arr[i];
		tmp_sum += arr[i];
	}
	
	for(int i=1;i<=9-1;++i){
		
		for(int j=i+1;j<=9;++j){

			if( ( tmp_sum - arr[i] - arr[j] ) == 100){
				check = true;
				arr[i] = MAX;
				arr[j] = MAX;
				break;
			}
			
		}
		if(check) break;
	}
	
	sort(arr,arr+10);
	
	for(int i=1;i<=7;++i){
		if(arr[i] != MAX)
			cout << arr[i] << "\n";
	}
	
	return 0;
}
