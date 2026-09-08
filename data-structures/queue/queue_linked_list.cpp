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
			Node* x = new Node(data);
			if(head->next==NULL){	
				head->next=x;
			}else{
				
				for(Node* h=head;h->next!=NULL;h=h->next){
					if(h->next->next==NULL){
						h->next->next=x;
						break;
					}
				}
			}
		}
		void print(){
			if(head->next==NULL){
				cout<< "empty"<< endl;
			}else{
			for(Node* h=head;h->next!=NULL;h=h->next){
					cout << h->next->data <<" ";
				}
				cout << endl;	
			}
			
		}
		void pop(){
			if(head->next==NULL){
				cout<< "empty"<< endl;
			}else{
				cout << head->next->data <<endl;
				head=head->next;
			}
		}
};

int main(){
	ptr* q =new ptr();
	char c;
	int data;
	
	do{
		cin>>c;
		switch(c){
			case'e':{
				cin >> data;
				q->push(data);
				break;
			}
			case's':{
				q->print();
				break;
			}
			case'p':{
				q->pop();
				break;
			}
		}
		
	}while(c!='x');
}
