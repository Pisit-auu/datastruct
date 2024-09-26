#include <iostream>
using namespace std;
class stack{
	public:
		int size;
		int head;
		int* data;
		stack(int size){
			this->size = size;
			this->head = -1;
			this->data = new int [size];
		}
		void push(int value){

			if(head+1 ==size){
				cout << " full " <<endl;
			}else{
				data[++head] = value;
			}
		}
		int pop(){
			if(head == -1){
				cout << "stack empty" << endl;
			}else {
				return data[head--];
			}
		}
		int show(){
			if(head == -1){
				cout << "stack empty" << endl;
			}else{
				return data[head];
			}
		}
		void showall(){
			if(head == -1){
				cout << "stack empty" << endl;
			}else{
				for(int i=0;i<=head;i++){
					cout << data[i] << " ";
				}
				cout<< endl;
			}
		}
};
int main(){
	stack* test = new stack(20);
	char c;
	int data;
	do{
		cin>> c;
		switch(c){
			case 'U':{
				cin >> data;
				test->push(data);
				break;
			}
			case 'P':{
				test->showall();				
				break;
			}
			case 'T':{
				cout << test->show() <<endl;	
				break;
			}
			case 'N':{
				cout << test->head+1  <<endl;
				break;
			}
			case 'O':{
				cout << test->pop()<<endl;
				break;
			}
		}
	}while(c != 'X');
	
	return 0;
}
