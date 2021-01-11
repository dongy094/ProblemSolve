#include <iostream>
using namespace std;
int main(){
	// 아니 당연히 대칭인줄 알았지  
	int N;
	cin >> N;
	
	int start=1, end=2*N;
	int spare_s, spare_e;
	for(int i=1;i<=2*N-1;++i){  // 0 1 2 3 4 5 6 7 8 <- 9개 
		
		if(i<=N){ 	// 0,0  1,9  2,7
			spare_s = i, spare_e = 2*N-i;
		//	1 9  2 8  3 7  4 6  5 5
			for(int j=1;j<=2*N-1;++j){ 
				//     1             9
				if(j<spare_s ){
					cout << " ";
				}else if( j>spare_e){
					continue;
				}
				else{
					cout << "*";
				}
				
			}cout << "\n";
		}else{ 
			spare_s = 2*N-i, spare_e = i;
			for(int j=1;j<=2*N-1;++j){
				if(j<spare_s){
					cout << " ";
				}else if( j>spare_e){
					continue;
				}else{
					cout << "*";
				}
			}cout << "\n";	
		}		
	}

	return 0;
}
