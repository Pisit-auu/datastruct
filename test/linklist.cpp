#include <iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
	Node(){
		this->data = 0;
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
			head=NULL;
		}
		void push(int data){
			Node* x = new Node(data);
				if(head==NULL){			
				head = x;
				}else{
					x->next = head;
					head = x;
					
				}
		
			
		}
		void Delete(){
			head = head->next;
		}
		void print(){
			for(Node* h = head;h!=NULL;h=h->next){			
				cout << h->data<< " " ;
			}
		}
};
int main(){
	ptr* a = new ptr();
	a->push(2);
	a->push(4);
	a->push(6);
	a->push(7);
	a->push(8);
	a->push(10);
	a->Delete();
	a->push(11);
	a->print();

	/*Node* x = new Node(2);
	Node* b = new Node(4);
	x->next= b;
	cout << x->data <<endl;
	cout << x->next->data <<endl;*/
}
