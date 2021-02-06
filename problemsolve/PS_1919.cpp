#include <iostream>

using namespace std;
string str1,str2;

int arr1[1010]={0,};
int arr2[1010]={0,};
int cnt = 0;

int main(){
	
	cin >> str1 >> str2;

	int str1_size = str1.size();
	for(int i=0;i<str1_size;++i){
		arr1[ str1[i]-97 ]++;		// 0-a  1-b  2-c  3-d ...
	}
	

	int str2_size = str2.size();
	for(int i=0;i<str2_size;++i){
		arr2[ str2[i]-97 ]++;		
	}
		
	for(int i=0;i<26;++i){
		if(arr1[i]==arr2[i]) continue;
		else if(arr1[i]>arr2[i]){
			while(arr1[i]!=arr2[i]){
				arr1[i]--;
				cnt++;
			}
		}else if(arr1[i]<arr2[i]){
			while(arr1[i]!=arr2[i]){
				arr2[i]--;
				cnt++;
			}
		}
			
	}	
		
	cout << cnt;
		
	return 0;
}
