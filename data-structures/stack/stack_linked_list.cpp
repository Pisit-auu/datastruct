#include <iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node(){
			this->next=NULL;
		}
		Node(int data){
			this->data=data;
			this->next=NULL;
		}
};
class ptr{
	public:
		Node* head;
		ptr(){
			head = new Node();
		}
		void push(int data){
			Node* p = head;
			Node* x = new Node(data);

			if(head==NULL){
				head->next = x;
			}else{
				x->next = p->next;
				head->next = x;
			}
	
		}
		void print(){
			if(head->next==NULL){
				cout << "empty" <<endl;
			}else{
				for(Node* h=head;h->next!=NULL;h=h->next){
				cout << h->next->data <<" ";
			}
			cout <<endl;
			}
		}
		void pop(){
			if(head->next==NULL){
				cout << "empty" <<endl;
			}else{
				cout << head->next->data <<endl;
				head=head->next;
			}
		}
};
int main(){
	ptr* st =new ptr();
	char c;
	int data;
	do{
		cin >> c;
		switch(c){
			case 'e':{
				cin >> data;
				st->push(data);
				break;
			}
			case 'p':{
				st->pop();
				break;
			}
			case 's':{
				st->print();
				break;
			}
		}
		
	}while(c!='x');
}
