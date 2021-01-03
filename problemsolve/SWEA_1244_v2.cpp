#include <iostream>
#include <cstring>
using namespace std;
int n_size,ret; // numũ�� 
int check[1000000][20]; 

void init(){
	
}

int swap(int num,int a,int b){
	
	int arr[10];
	int tmp=num;
	
	for(int i=0;i<n_size;i++){
		arr[i] = tmp % 10;
		tmp /= 10;
	} 	//123 �̸�  �迭���� 321 �̷��� ������ �Ųٷ� 
	
	if(arr[a] == arr[b]){
		return num;
	}
	
	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;  		//���õ� �ڸ� ���� 
	
	num = 0;
	for(int i = n_size-1 ; i>=0 ; i--){
		num = num*10 + arr[i];
	} 
	return num;
}

int solve(int num,int cnt){
	
	int& ret = check[num][cnt];
	if(ret != -1) return ret; 
	
	if(cnt==0) return ret=num;
	
	ret = 0; //�ش簪�� ���� ���� ������ ������ ó�� 
	for(int i=0;i<n_size-1;++i){
		for(int j=i+1;j<n_size;j++){
			int tmp = solve( swap(num,i,j), cnt-1 );
			if(tmp > ret){
				ret = tmp; // ret�� ����Ű�� ���� tmp�� ���� 
			}
		}
	}
	
	return ret;
}


int main(){

    int tc=0;
    cin >> tc;
    for(int i=1;i<=tc;++i){
    	
    	int num=0,cnt=0;
    	cin >> num >> cnt;
    	n_size=0;
    	int tmp = num;
    	while(tmp){
    		tmp /= 10;
    		++n_size;
		}
			
		for(int i=0;i<1000000;i++){
			for(int j=0 ; j<=n_size ; j++){
				check[i][j] = -1;
			}
		}
		
		cout << "#" << i << ' ' << solve(num,cnt) << endl;
		
	}
    return 0;
}


