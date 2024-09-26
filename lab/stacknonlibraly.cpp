#include <iostream>
using namespace std;
class Stack{
	public:
	int id;
	int*arr;
	int tail;
	Stack(int n){
		tail=-1;
		arr = new int[n];
	}
	void push(int data){
		tail++;
		arr[tail] = data;
	}
	int pop(){
		return arr[tail--];
	}
	void print(){
		for(int i=0;i<=tail;i++){
			cout << arr[i] <<" ";
		}
		cout <<endl;
	}
	int size(){
		return tail;
	}
	int top(){
		return arr[tail];
	}
};


int main(){
	Stack* st = new Stack(100);
	char c;
	int data;
	do{
		cin >> c;
		switch(c){
			case 'U':{
					cin >> data;
					st->push(data);
				break;
			}
			case 'O':{
				cout << st->pop() <<endl;
				break;
			}
			case 'T':{
				cout << st->top() <<endl;
				break;
			}
			case 'P':{
				st->print();
				break;
			}
			case 'N':{
				cout << st->size()+1 <<endl;
				break;
			}
		}
		
	}while( c!= 'X');
}
