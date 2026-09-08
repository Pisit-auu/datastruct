#include <iostream>
using namespace std;
#include <stack>

int main(){
	stack <char> s;
	char c;
	int i=0;
	bool check=true;
	bool checkmatch=false;
	int match=0;
	int count=0;
	while(cin.get(c)){
		
		if(c == '\n'){
			break;
		}
		switch(c){
			case'(':
			case'[':
			case'{':
			case'<':
				s.push(c);
				break;
			case')':{
				if(s.empty()){
					check=false;
					if(i==0){
						checkmatch=true;
					}
				}
				else if(s.top() == '('){
					s.pop();
					match++;
					i++;
					count=0;
				}
				break;
			}
				
			case'}':{
				if(s.empty()){
					check=false;
					if(i==0){
						checkmatch=true;
					}
				}
				else if(s.top() == '{'){
					s.pop();
					match++;
					i++;
					count=0;
				}
				break;
			}
			case']':{
				if(s.empty()){
					check=false;
					if(i==0){
						checkmatch=true;
					}
				}
				else if(s.top() == '['){
					s.pop();
					match++;
					i++;
					count=0;
				}
				break;
			}
			case'>':{
				if(s.empty()){
					check=false;
					if(i==0){
						checkmatch=true;
					}
				}
				else if(s.top() == '<'){
					s.pop();
					match++;
					i++;
					count++;
					if(count==2){
						match--;
						count=0;
					}
				}
				break;
			}
		}
		
	}
	if(checkmatch){
		match=0;
	}
	if(s.empty()&&check){
		cout<< match <<" matched"<<endl; 
	}else{
		cout<< "Not matched"<<endl; 
		cout<< match <<" matched"<<endl; 
	}


	
}
