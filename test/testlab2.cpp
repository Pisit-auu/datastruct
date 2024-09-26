#include <iostream>
using namespace std;

class Stack{
	public:
		char* A;
		int tail;
		Stack(){
			A = new char[100];
			tail=-1;
		}
		void push(char data){
			tail++;
			A[tail] = data;
		}
		char pop(){
			return A[tail--];
		}

};

int main(){
	char c;
	Stack ar;
	int l=0;
	int check=0;
	int countstack=0;
	int stop=0;
	int counthaha=2;
	int correct =0;
	do{
		c = cin.get();
		 if (c == '\n') {
            break;
        }
        if(stop==1){
        	break;
		}
		switch(c){
			case '(':
			case '[':
			case '<':
			case '{':
				ar.push(c);
				countstack++;
				l++;
				break;
			case '}':
				if(l==0){
					stop=1;
					break;
				}else if(ar.pop()=='{'){
					correct++;
					countstack--;
					break;
				}else{
					stop=1;
				break;	
				}
				
			case ']':
				if(l==0){
					stop=1;	
					break;
				}else if(ar.pop()=='['){
					correct++;
					countstack--;
					break;
				}else{
					stop=1;
				break;	
				}
			case '>':
				if(l==0){
					stop=1;	
					break;
				}else if(ar.pop()=='<'){
					correct++;
					counthaha--;
					countstack--;
					if(counthaha ==0){
						correct--;
						counthaha=2;
					}
					break;
				}else{
					stop=1;
				break;	
				}
			case ')':
				if(l==0){
					stop=1;		
					break;
				}else if(ar.pop()=='('){
					correct++;
					countstack--;;
					break;
				}else{
					
					stop=1;
				break;	
				}
			
		}	
	}while(true);	
	if(stop==1||countstack>0){
		cout << "Not matched"<<endl;
	}
	cout << correct <<" matched" <<endl;
	
	
}


