#include <iostream>
using namespace std;
class Node{
	public:
		Node* next;
		int id;
		int score;
		string name;
		Node(){
			this->next=NULL;
		}
		Node(int id,string name,int score){
			this->id=id;
			this->name=name;
			this->score=score;
			this->next=NULL;
		}
};

class Student{
	public:
		Node* h;
		Student(){
			h = NULL;
		}
		void push(int id,string name,int score){
			Node* x = new Node(id,name,score);
				if(h==NULL){			
					h = x;
				}else{
					x->next = h;
					h = x;
					
				}
			}
		
		void print(){
				cout<<"do"<<endl;
			for(Node* head=h;head!=NULL;head=head->next){
				cout<< head->id <<" " <<head->name<<" "<< head->score;
				cout<< endl;
			}
			
		}
		
};


int main(){
	char c;
	Student* A[100];
	for(int i=0;i<100;i++){
		A[i] = new Student();
	}
	do{
		cin >> c;
		switch(c){
			case 'p':{
				int idsub;
				string namesub;
				int fullscore;
				int id;
				string name;
				int score;
				cin >> idsub;
				cin >> namesub;
				cin >> fullscore;
				cin >> id;
				cin >> name;
				cin >> score;
				A[id%100]->push(id,namesub,score);
				cout<<"sucess"<<endl;
				break;
			}
			case 's':{
				int id;
				cin >> id ;
				A[id%100]->print();
				break;
			}
		}
		
	}while(c!='x');
}
