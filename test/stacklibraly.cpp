#include <iostream>
#include <stack>
using namespace std;

int main(){
	stack<char> stack;
	int count =0;
	int coutdoubly=0;
	bool check=true;
	bool notmatch=false;
 	while(true){
 		char c = cin.get();
 		if(c=='\n'){
 			break;
		 }else{
		 	if(check){
		 		switch(c){
		 		case '<':
		 		case '{':
		 		case '[':
		 		case '(':
		 			stack.push(c);
		 			break;
		 		case ')':
		 			if(stack.empty()&&count==0){
		 				check=false;
		 				break;
					 }else if(stack.empty() || stack.top() !='('){
					 	notmatch=true;
					 	break;
					 }else if( stack.top() == '('){
		 				stack.pop();
		 				coutdoubly=0;
		 				count++;
		 				break;
					 }
		 		case '>':
		 			if(stack.empty()&&count==0){
		 				check=false;
		 				break;
					 }else if(stack.empty() || stack.top() !='<'){
					 	notmatch=true;
					 	break;
					 }else if( stack.top() == '<'){
		 				stack.pop();
		 				count++;
		 				coutdoubly++;
		 				if(coutdoubly==2){
		 					count--;
		 					coutdoubly=0;
		 					
						 }
		 				break;
					 }
		 		case '}':
		 			if(stack.empty()&&count==0){
		 				check=false;
		 				break;
					 }else if(stack.empty() || stack.top() !='{'){
					 	notmatch=true;
					 	break;
					 }else if( stack.top() == '{'){
		 				stack.pop();
		 				count++;
		 				coutdoubly=0;
		 				break;
					 }
		 		case ']':
		 			if(stack.empty()&&count==0){
		 				check=false;
		 				break;
					 }else if(stack.empty() || stack.top() !='['){
					 	notmatch=true;
					 	break;
					 }else if( stack.top() == '['){
		 				stack.pop();
		 				count++;
		 				coutdoubly=0;
		 				break;
					 }
					break;
			 }
			 }
		 }
	 } 
	 if(check== false){
	 	cout << "Not matched" <<endl;
	 	cout << "0 matched" <<endl;
	 }else if(notmatch||!stack.empty()){
	 	cout << "Not matched" <<endl;
	 	cout << count << " matched" <<endl;
	 }else{
	 	cout << count << " matched" <<endl;
	 }
}
