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
class List{
	public:
	Node* head;
	void push(int data){
		Node *h = new Node(data);
		h->next = head;
		head = h;
	}
	void insert(int data,int id){
		for(Node*h=head;h!=NULL;h=h->next){
			
		}
	}
	void printList(){
		for(Node*h=head;h!=NULL;h=h->next){
			cout << h->data << " ";
		}	
		cout << endl;	
	}
};
int main(){
	List test;
	test.push(0);
	
	void printList();
}
