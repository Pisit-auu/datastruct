#include <iostream>
using namespace std;

class Stack {

public:
	int array[50];
	int top = -1;

	void push(int data) {
		top++;
		array[top] = data;
		
		
	}
	int pop(char c) {
		int popp = array[top];
		if(c == 'O'){
			top--;
			return popp;
		}
		else if(c == 'T'){
			return popp;
		}
		
	}
	void showall(){
		for(int i=0;i<=top;i++){
				cout << array[i] << " ";
			}
		cout << endl;
	}

};

int main() {
	char c;
	int data;
	Stack w;
	do {
		cin >> c;
		switch (c) {
		case 'U': {
			cin >> data;
			w.push(data);
			break;
		}
		case 'O': {
			cout << w.pop(c)<<endl;
			break;
		}
		case 'T': {
			cout << w.pop(c) << endl;
			break;
		}
		case 'P': {
			w.showall();
			break;
		}
		case 'N':{
			cout << w.top+1<<endl;
			break;
		}
		}
	} while (c != 'X');

}

