#include <iostream>
#define size 10
using namespace std;
class Stack{
	public:
	int* num;
	int tail;
	Stack(){
		num = new int[size];
		tail=-1;
	}
	void push(int data){
		tail++;
		num[tail] = data;
	}
	int pop(){
		return num[tail--];
	}
};
int main(){
	Stack s;
	while(true){
	char c = cin.get();
	if(c == '\n'){
		break;
	}
	else{
		if( static_cast<int>(c) >= 48 && static_cast<int>(c) <=57){
			s.push(static_cast<int>(c)-48);
		}
		else{
			switch(c){
				case '+':{
					int x = s.pop()+s.pop();
					s.push(x);
					break;
				}

				case '-':{
					int x1= s.pop();
					int x2 = s.pop();
					s.push(x2-x1);
					break;
				}

				case 'x':{
					int x = s.pop()*s.pop();
					s.push(x);	
					break;
				}
		
			}
		}
		
	}
	}
	cout << s.pop()<<endl;
}
