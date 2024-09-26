#include <iostream>
using namespace std;
class Stack{
	public:
		int A[5];
		int n=-1;
		void push(int data){
			++n;
			if(n<5){	
				A[n] = data;
			}else{
				cout<<"stack full"<<endl;
				n--;
			}
			
		}
		bool check(){
			if(n== -1){
				return 0;
			}else{
				return 1;
			}
			
		}
		void pop(){
			if(check()){
				cout << A[n--] <<endl;
			}else{
				cout<<"stack empty"<<endl;
			}
		}
		
};
int main(){
	Stack s;
	s.push(2);
	s.push(2);

	
}
