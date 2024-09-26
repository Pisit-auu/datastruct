#include <iostream>
using namespace std;
class Node{
	public:
		int id;
		string name;
		Node* next;
		Node(){

			this->next=NULL;
		}
		Node(int id,string name){
			this->id = id;
			this->name = name;
			this->next = NULL;
		}
};

class ptr{
	public:
	Node* head;
	ptr(){
		head = new Node();
	}
	void push(int id,string name){
		Node* x = new Node(id,name);
		if(head->next==NULL){
			head->next = x;
		}else{
			for(Node* h = head;h->next!=NULL;h=h->next){
				if(h->next->next==NULL){
					h->next->next=x;
					break;
				}
			}
		}
	}
	void print(){
		if(head->next==NULL){	
			cout<<"(" << -1 <<","<< "-"<<")"<<endl;
		}else{
			for(Node* h = head;h->next!=NULL;h=h->next){
				cout<<"(" << h->next->id <<","<< h->next->name<<")" << " ";
			}
			cout << endl;
		}
		
	}
	void find(int id){
		bool check = false;
		string found ;
		for(Node* h = head;h->next!=NULL;h=h->next){
				if(h->next->id==id){
					found = h->next->name;
					check =true;
					break;
				}
			}
			if(check){
				cout << found <<endl;
			}else{
				cout << "-" <<endl;
			}
	}
};

int main(){
	int size=17;
	ptr* a[size];
	for(int i=0;i<size;i++){
		a[i] = new ptr();
	}
	char c;
	int id;
	
	string name;
	do{
		cin >> c;
		switch(c){
			case'a':{
				cin >>id;
				cin >> name;
				a[id%size]->push(id,name);
				break;
			}
			case'p':{
				for(int i=0;i<size;i++){
					a[i]->print();
				}
				break;
			}
			case's':{
				cin>>id;
				a[id%size]->find(id);
				break;
			}
		}
	}while(c!='e');
	
	
}
