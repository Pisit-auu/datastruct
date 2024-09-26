#include <iostream>
using namespace std;

class Node{
	public:
		Node* next;
		Node* prev;
		int data;
		Node(){
			this->next= NULL;
			this->prev= NULL;			
		}
		Node(int data){
			this->next= NULL;
			this->prev= NULL;
			this->data= data;
		}
};

class ptr{
	public:
		Node* head;
		ptr(){
			head = new Node();
		}
		void push(int data){
			
				Node* x = new Node(data);
				Node* ptr = head;
				ptr->prev =x;
				x->next = ptr;
				x->prev = ptr->prev;
				head = x;
			
		}
		int print(){
			for(Node* h=head;h->next!=NULL;h=h->next){
				cout<< h->data <<":" ;
			}
			cout<<endl;
			
		}
};
int main(){
	Node* a = new Node(0);
	Node* b = new Node(1);
	Node* c = new Node(2);
	a->next =b;
	b->prev=a;
	b->next=c;
	c->prev=b;
	cout << a->next->next->prev->data <<endl;
	
	ptr* ax = new ptr();
	ax->push(989);
	ax->push(990);
	ax->push(991);
	ax->print();
}
