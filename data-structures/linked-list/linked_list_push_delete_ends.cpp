#include <iostream>
using namespace std;

class Node{
	public: 
	int data;
	Node* next=NULL;
	Node(){
		this->next=NULL;
	}
	Node(int data){
		this->data=data;
		this->next=NULL;
	}
};
class linklist{
	public: 
	Node* h;
	linklist(){
		h = new Node();
	}
	void pushbefore(int data){
		Node* x=new Node(data);
		Node* head =h;
		if(h->next==NULL){
			h->next = x;
		}else{
			x->next = head->next;
			h->next = x;
		}
	}
	void pushafter(int data){
		Node* x=new Node(data);
		if(h->next==NULL){
			h->next = x;
		}else
		for(Node* head = h ;head!=NULL;head=head->next){
				if(head->next==NULL){
					head->next =x;
					break;
					
				}
			}	
		}
	
	void print(){
		if(h->next==NULL){
			cout<<"empty"<<endl;
		}else{
				for(Node* head = h ;head!=NULL;head=head->next){
				cout << head->next->data << " ";
			}
			cout << endl;
		}
	}
	void deletebefore(){
		h=h->next;
	}
	void deleteafter(){
		for(Node* head = h ;head!=NULL;head=head->next){
				if(head->next->next==NULL){
					head->next=NULL;
					break;
					
				}
			}
	}
};

int main(){
	linklist* ll = new linklist();
	ll->pushafter(1);
	ll->pushafter(2);
	ll->deleteafter();

	ll->print();
}
