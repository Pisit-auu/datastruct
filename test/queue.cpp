#include <iostream>
using namespace std;
class Queue{
	public:
		int q[5];
		int h=-1;
		int t=-1;
		bool checkfull(){
			if(t<4){
				return 1;
			}else{
				return 0;
			}
		}
		bool checkempty(){
			if(t==-1){
				return 0;
			}else if(t-h==0){
				t=-1;
				h=-1;
				return 0;
			}else{
				return 1;
			}
		}
	void push(int data){
		if(checkfull()){
			t++;
			q[t]= data;
		}else{
			cout <<"queue full"<<endl;
		}

	}
	
	void pop(){
		if(checkempty()){
			h++;
			cout << q[h] <<endl;
		}else{
			cout <<"queue empty"<<endl;
		}
	}
};

int main(){
	Queue sq;
	sq.push(1);
	sq.push(2);
	sq.push(3);
	sq.pop();
	sq.pop();
	sq.pop();
	sq.pop();
	sq.push(4);
	sq.push(5);
	sq.push(6);
	sq.push(7);
	sq.push(8);
	sq.pop();	
	sq.pop();	
	sq.pop();	
	sq.pop();	
	sq.pop();
	sq.pop();
	sq.pop();
	sq.push(8);
	sq.push(8);
	sq.push(8);
	sq.pop();
	sq.pop();
	sq.push(7);
	sq.pop();
	sq.pop();
	sq.push(1);
	sq.push(2);
	sq.push(3);

				
				
				
	
}
