#include <iostream>
#include <algorithm> 
using namespace std;

int arr[510];

int main(){
	
	int H,W;
	cin >> H >> W;
	
	int cnt = 0;
	
	for(int i=0;i<W;++i){
		cin >> arr[i];  //arr[i]�� ���� ���� ��� ���� 
	}
	
	for(int i=1;i<W-1;++i){
		
		int currentH = arr[i];
		int leftH = currentH;
		int rightH = currentH;
		
		for(int l=i-1;l>=0;--l){	 // ���ʿ��� ���� ū ���� ã�� 
			if(arr[l]>currentH){
				leftH = max(leftH, arr[l]);	
			}
		}
		for(int r=i+1;r<W;++r){ 	 // �����ʿ��� ���� ū ���� ã�� 
			if(arr[r]>currentH){
				rightH = max(rightH, arr[r]);	
			}	
		} 
		
		int set = min(leftH,rightH);
		cnt += (set-currentH);
		
	}
	
	cout << cnt;
	
	return 0;
}
