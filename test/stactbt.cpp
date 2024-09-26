#include <iostream>
#include <stack>
using namespace std;


int main(){
	stack <char> st;
	char c;
	bool check = true;
	while(cin.get(c)){
		if(c=='\n'){
			break;
		}
		switch(c){
			case'(':{
				st.push(c);
				break;
			}
			case')':{
				if(!st.empty()){
					if( st.top() == '('){
					st.pop();
					check = true;
				}else{
					check = false;
					break;
				}
				}else{
						check = false;
					break;
				}
				break;
			}
		}
	}
	if(check && st.empty()){
		cout << "pass" <<endl;
	}else{
		cout << "Error" <<endl;
	}
}
