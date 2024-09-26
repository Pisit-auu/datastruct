#include <iostream>
using namespace std;

class Queue{
	public:
	int* arr;
	int checkfull;
	int size;
	int head;
	int tail;
	Queue(){
		checkfull=10;
		size=0;
		arr = new int[10];
		head=-1;
		tail=-1;
	}
	void push(int data){
		if(tail%10-head%10==10-1){
			cout << "Full" <<endl;
		}else{
			arr[++tail%10] = data;
		}
	}
	void pop(){
		if(head==tail){
			cout << "Empty" <<endl;
		}else{
			cout << arr[++head%10] <<endl;
		}
	}
};

int main(){
	Queue q;
	int n;
	char c;
	do{
		cin >> c;
			switch(c){
				case 'p':{
					cin >> n;
					q.push(n);
					break;
				}
				case 'o':{
					q.pop();
					break;
				}
					
			}
	}while(c !='x');
	
	
}
