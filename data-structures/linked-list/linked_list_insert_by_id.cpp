#include <iostream>
using namespace std;
class Node{
	public:
		int id;
		Node* next;
		Node(){
			this->next=NULL;
			this->id=0;
		}
		Node (int id){
			this->id = id;
			this->next = NULL;
		}
};

class ptr{
	public:
		Node* h;
		ptr(){
			h = new Node();
		}
		void before(int data,int id){
			Node* x = new Node(data);
			Node* p = h;
			if(p->id == id){
				x->next=p;
				h = x;
			}else{
			for(Node* head=h;head->next!=NULL;head=head->next){
				
				if(head->id==data){
					return;
				}
			}
			for(Node* head=h;head->next!=NULL;head=head->next){
				if(head->next->id==id){
					x->next = head->next;
					head->next =x;
					break;
				}else if(head->next->next == NULL && head->next->id!=id){
					x->next = head->next;
					head->next =x;
					break;
				}
			}				
			}
		}
		void print(){
			for(Node* head=h;head->next!=NULL;head=head->next){
				
				cout << head->id <<" ";
			}
			cout<< endl;
		}
		void del(int data){
			if(h->id==data){
				h=h->next;
			}else{
					for(Node* head=h;head->next!=NULL;head=head->next){
						if(head->next->id==data){
							cout<< "do"<< endl;
							head->next=head->next->next;
							break;
						}
					}	
			}
			
		}
		void after(int data,int id){
			Node* x = new Node(data);
			Node* p = h;
			if(p->id==0){
				x->next=p;
				h = x;
			}
			for(Node* head=h;head->next!=NULL;head=head->next){
				
				if(head->id==id){
					x->next=head->next;
					head->next= x;
					break;
				}else if(head->next->next == NULL && head->next->id!=id){
					x->next = head->next;
					head->next =x;
					break;
				}
			}
		}
		
};
int main(){
	ptr* exp = new ptr();
	char c;
	int id;
	int data;
	do{
		cin >> c;
		switch(c){
			case'I':{
				cin >>data;
				cin >>id;
				exp->before(data,id);
				exp->print();
				break;
			}
			case'A':{
				cin >>data;
				cin >>id;
				exp->after(data,id);
				exp->print();
				break;
			}
			case'D':{
				cin >>data;
				exp->del(data);
				exp->print();
				break;
			}
		}
		
	}while(c!='E');
	
	
}
