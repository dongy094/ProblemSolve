#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int TestCase=10;

int number=1;
int result;

int main(){
	
	while(TestCase--){
		
		result = 1;
		vector<char> arr;
		int n;

		cin >> n;			
		
		for(int i=0 ; i<n ; i++){
			char a;
			cin >> a;
			if(a=='{' || a=='[' || a=='<' || a=='('){
				arr.push_back(a);				
			}else{ 
				if( arr.empty() ){
					result = 0;
				}else{
					char ch=arr.back();
					arr.pop_back();
					if(a=='}' && ch!='{'){
						result=0;
					}else if(a==']' && ch!='['){
						result=0;
					}else if(a=='>' && ch!='<'){
						result=0;
					}else if(a==')' && ch!='('){
						result=0;
					}
				}	
			}	
			
		}	
		if(!arr.empty()){
			result=0;
		}
		
		
		if(result){
			cout <<"#"<<number<<" "<<"1"<<endl;
		}else{
			cout <<"#"<<number<<" "<<"0"<<endl;
		}
	
		
		number++;
	}
	
	return 0;
}

