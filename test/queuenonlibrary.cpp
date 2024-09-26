#include <iostream>
using namespace std;
class queue{
	public:
		int data;
		int tail;
		int head;
		int* arr;
		queue(int n){
			arr = new int[n];
			tail=-1;
			head=0;
		}
		void push(int data){
			tail++;
			arr[tail] = data;
		}
		int pop(){
			return arr[head++];
		}
		void print(){
			for(int i=head;i<=tail;i++){
				cout << arr[i] << " ";
			}
			cout << endl;
		}
		int gethead(){
			return arr[head];
		}
		int gettail(){
			return arr[tail];
		}
};

int main(){
		queue* q = new queue(100);
	char c;
	int data;
	do{
		cin >> c;
		switch(c){
			case 'e':{
				cin >> data;
				q->push(data);
				break;
			}
			case 'd':{
				cout << q->pop() <<endl;
				break;
			}
			case 'n':{
				cout << q->tail-q->head+1 <<endl;
				break;
			}
			case 's':{
				cout << q->gethead() << " " << q->gettail()<<endl;
				break;
			}
			case 'p':{
				q->print();
				break;
			}
		}
		
	}while(c!= 'x');
}
