#include <iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
	Node(int data){
		this->data=data;
		this->next=NULL;
	}
};

class LinkList{
	public:
		Node* head;
	LinkList(){
		head = new Node(0);
		head->next = NULL;
	}
	void push(int data){
		Node *ptr = head;		
		Node *x = new Node(data);
		x->next = ptr;
		head = x;
	}
	void insert(int data,int id){
		Node *ptr = head;		
		if(id ==0 && ptr->next == NULL){
			push(data);
			
		}else if(ptr->next!=NULL&&ptr->data==id){
			push(data);
		}
		else {
			for(Node*ptr = head;ptr !=NULL;ptr=ptr->next){
				if(ptr->data==data){
					break;	
				}
				else if(ptr->next->data==id){
					Node *x = new Node(data);
					x->next = ptr->next;
					ptr->next = x;
					break;
				}else if(ptr->next->next == NULL && ptr->data!=id){
					Node *x = new Node(data);
					x->next = ptr->next;
					ptr->next = x;
					break;
				}
			}
		}
			
		}
	void insertafter(int data,int id){
				Node *ptr = head;		
		if(id ==0 && ptr->next == NULL){
			push(data);
			
		}else if(ptr->next!=NULL&&ptr->data==id){
			Node *x = new Node(data);
			x->next= ptr->next;
			ptr->next=x;
		}
		else {
			for(Node*ptr = head;ptr !=NULL;ptr=ptr->next){
				if(ptr->data==id){
					Node *x = new Node(data);
					x->next = ptr->next;
					ptr->next = x;
					break;
				}else if(ptr->next->next == NULL && ptr->data!=id){
					Node *x = new Node(data);
					x->next = ptr->next;
					ptr->next = x;
					break;
				}
			}
		}
			
	}
	void deletenode(int data){
		for(Node*ptr = head;ptr !=NULL;ptr=ptr->next){
				if(ptr->data == data){
					head= ptr->next;
					break;
				}	
				else if(ptr->next->data==data){
					ptr->next= ptr->next->next;
					break;
				}
	}
}
	void printList(){	
		for(Node*ptr = head;ptr!=NULL;ptr=ptr->next){
			if(ptr->data==0){
				
			}else{
				cout << ptr->data << " ";
			}
		}
		cout << endl;
	}
};
int main(){
    LinkList* test = new LinkList();	
	char c;
	int data,id;
	do{
		cin >> c;
		switch(c){
			case'I':{
				cin >> data;
				cin >> id;
				test->insert(data,id);
				test->printList();	
				break;
			}
			case'D':{
				cin >> data;
				test->deletenode(data);
				test->printList();	
				break;
			}
			case'A':{
				cin >> data;
				cin >> id;	
				test->insertafter(data,id);
				test->printList();	
				break;
		}
	
		}
	}	while(c!='E');
	
}

