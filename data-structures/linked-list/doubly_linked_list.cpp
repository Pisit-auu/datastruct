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
				// link x in front of head before overwriting head->prev,
				// otherwise x->prev ends up pointing at x itself
				x->next = head;
				x->prev = NULL;
				head->prev = x;
				head = x;

		}
		void print(){
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
