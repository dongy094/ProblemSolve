#include <iostream>
#include <cstring>
#define MAX 9999999999
#define ll long long
using namespace std;

int k;
int arr[11]; // 부등호 넣기  < == 0, > == 1 
int result[11];
bool check[11];
 				// 부등호  
ll vmax = -MAX;
ll vmin = MAX;
string large,mini;
void solve(int n,int c){
	
	if(n==k+1){
		
		string sval = "";
		ll val = 0;
		ll tmp = 1; 
		
		for(int i=0;i<=k;++i){
			sval += result[i] + '0';
			
			val += result[k-i]*tmp;
			tmp *= 10;
		}

		if(val>vmax){
			vmax = val;	
			large = sval;
		}
		if(val<vmin){
			vmin = val;
			mini = sval;
		}
		
		return;
	}
	
	for(int i=0;i<10;++i){
		
		if(check[i]==false){

			if(n==0){ // 맨처음이면 부동호 비교 필요없으니까 
				check[i] = true;
				result[n] = i;
				solve(n+1,c);
				check[i] = false;
			}else{
				
				if(arr[c] == 0){ 	// <
					
					if(result[n-1] < i){
						result[n] = i;
						check[i] = true; 
						solve(n+1,c+1);
						check[i] = false;

					}
					
				}else{  			// >
					
					if(result[n-1] > i){
						result[n] = i;
						check[i] = true; 
						solve(n+1,c+1);
						check[i] = false;
					}
					
				}
			}
			
			
		}
	}
	
	
} 


int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> k;
	for(int i=0;i<k;++i){
		string tmp;
		cin >> tmp;
		if(tmp == "<"){
			arr[i] = 0; 
		}else{ // '>'
			arr[i] = 1;
		}
		
	}
	
	solve(0,0);
	cout << large << "\n" << mini;
	
	
	return 0;
}
