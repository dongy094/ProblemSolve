#include <iostream>
#include <cstring>
using namespace std;

int arr[105]; // 0->close, 1->open  1번방 부터 시작 
int n;
 
void init(){
	memset(arr,0,sizeof(arr));
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	
	while(tc--){
		cin >> n;
		init(); 
		
		int cnt = 0;
		for(int round = 1 ; round <= n; ++round){
			for(int num = 1 ; num*round <= n ; num++){
				if(arr[num*round] == 1){
					arr[num*round] = 0;
					cnt--;
				}else{
					arr[num*round] = 1;
					cnt++;
				}
			}
		}

		cout << cnt << "\n";
					
	}	
	

	return 0;
}

