#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int L,C;
string arr[15];
int voewl[15];

string result[15];

void solve(int voe, int con,int k,int pre){
	
	if(con>=2 && voe>=1 && k==L){
		for(int i=0;i<L;++i){
			cout << result[i];
		}
		cout << "\n";
		return;
	}
	
	// a c i s t w
	// 97 99 
	// ���ڸ� > ���ϱ� �� �׷�
	// ���� �ε��� ��ġ ����ؼ� ���� �ε��� ���� �տ� �ִ°Ŵ� �Ÿ��� 
	for(int i=pre+1;i<C;++i){
		
			result[k] = arr[i];
			if(voewl[i]==1){ // ���� 
				solve(voe+1,con,k+1,i);
			}else{ // ���� 
				solve(voe,con+1,k+1,i);
			}
	
	}
}


int main(){

	cin >> L >> C;
	for(int i=0;i<C;++i){
		cin >> arr[i];
	}
	sort(arr,arr+C);

	for(int i=0;i<C;++i){
		if(arr[i] == "a" || arr[i] == "e" || arr[i] == "i" || arr[i] == "o" || arr[i] == "u"){
			voewl[i] = 1;		
		}
	}
	
	solve(0,0,0,-1);
	
	return 0;
}
