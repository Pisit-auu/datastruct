#include <iostream>
using namespace std;

int main(){
	int size=6;
	int tail=0;
	int front=0;
	int queue[size];
	int data;
	int count=0;
	char c;
	do{
		cin >> c;
		switch(c){
			case 'e':{
				if(tail == size+count){
					cout<< "full"<<endl ;
				}else{
					cin >> data;
					queue[tail++] = data;	
				}
				break;
			}
			case 'd': {
				if(tail==0|| front == tail){
					cout<< "empty"<<endl ;
					count=0;
					front=0;
					tail=0;
				}else{
					if(front==size-1){
						front=0;
					}
					
				cout << queue[front++] <<endl;	
				count+=1;				
				}
				break;
			}
			case 'p': {
				for(int i=front;i<tail;i++){
					cout << queue[i] << " ";
				}
				cout << endl;
				break;
			}
			case 'n': {
				cout << tail << endl;
				break;
			}
			case 's':{
				cout << queue[front]<< " " << queue[tail-1]<< endl;
				break;
			}
		}
		}while(c != 'x');
	return 0;
	}


