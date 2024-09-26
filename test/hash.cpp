#include <iostream>
using namespace std;

class Node{
	public:
		Node* next;
		int data;
		Node(int data){
			this->next = NULL;
			this->data = data;
		}
};

class ptr{
	public:
	Node* head;
	ptr(){
		head = NULL;
	}
	void push(int data){
		Node* x = new Node(data);
		if(head == NULL){
			head = x;
			
		}else if(head!=NULL){
			for(Node* h = head;h!=NULL;h=h->next){
				if(h->next==NULL){
					h->next = x;
					break;
				}
			}
		}
	}
	void print(){
		if(head==NULL){
			cout << "-" <<endl;
		}else{
			for(Node* h = head;h!=NULL;h=h->next){
			cout << h->data <<" ";
		}
		}
		cout << endl;
	}
	
	
	
};
int main(){
	ptr* A[5];
	for(int i=0;i<5;i++){
		A[i] = new ptr();
	}
	A[1999%5]->push(1999);
	A[200%5]->push(200);
	A[100%5]->push(100);
	
	for(int i=0;i<5;i++){
		A[i]->print();
	}
}
