#include <iostream>
using namespace std;
#define size 17

class Node{
	public:
	string data;
	int id;
	Node *next;
	Node(){
		this->next = NULL;
	}
	Node(int id,string data){
		this->data = data;
		this->id = id;
		this->next = NULL;
	}
};

class Linklist{
	public:
	Node* head;
	Linklist(){
		head = NULL;
	}
	void pushfirst(int id ,string data){
		Node * x = new Node(id,data);
		x->next = head;
		head = x;
	}
	void insert(int id,string data){
		
		if(head == NULL){
			pushfirst(id,data);
		}else{
			Node *ptr = head;
			while (ptr->next != NULL) {
                ptr = ptr->next;
            }
			Node *x = new Node(id,data);
			ptr->next = x;
		}
	}
    void print() {
        if (head == NULL) {
            cout << "(-1,-)" << endl;
        } else {
            for (Node* ptr = head; ptr != NULL; ptr = ptr->next) {
                cout << "(" << ptr->id << "," << ptr->data << ") ";
            }
            cout << endl;
        }
    }  	
    
    bool checkid(int id){
            for (Node* ptr = head; ptr != NULL; ptr = ptr->next) {
                if(ptr->id==id){
                	cout << ptr->data;
                	return true;
				}
            }
			return false;	
	}
		
	void printdata(int id) {
        if (head == NULL) {
            cout << "-" << endl;
        } else {
            
                if(checkid(id)){
                	
				}else {
					cout << "-" ;
				}
            
            cout << endl;
        }
    }  	
};

	int Hash(int id){
		int hash = id%size;
		return hash;
	}


int main(){
	
	Linklist* array[size];
	for (int i = 0; i < size; ++i) {
    array[i] = new Linklist();
	}

	char c;
	int id;
	string data;
	do{
		cin >> c;
		switch(c){
			case 'a':{
				cin >>  id;
				cin >> data;
				array[Hash(id)]->insert(id,data);
				break;
			}
			case 'p':{
				for(int i=0;i<size;i++){
					array[i]->print();
				}
				break;
			}
			case 's':{
				cin>> id;
				array[Hash(id)]->printdata(id);
				break;
			}
		}
	}while(c!= 'e');

	
	
	
}
