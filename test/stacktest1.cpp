#include <iostream>
#include <stack>
using namespace std;


class Stack{
	public:
	int* ar;
	int id;
	int A;
	int T;
	int *keep;
	int tail;
	int keepi;
	Stack(){
		ar = new int[10];
		tail=-1;
	}
	Stack(int n){
			keep = new int[n];
	}
	void push(int data,int A,int T){
		this->id=data;
		this->A = A;
		this->T=T;
	}
	void print(){
		cout << "ID: " << id <<" A "<< A <<" T " << T<<endl;
	}
	void fixA(int T){
		this->A = T;
	}
	
	void pushtemp(int data){
		ar[++tail] = data;
	}
	int poptemp(){
		return ar[tail--];
	}
};

int main(){
	stack<int> idtemp;
	stack<int> Ttemp;
	int n;
	cin >> n;
	int id;
	int T;
	int A;
	int at=0;
	Stack ar[n];
	for(int i=0;i<n;i++){
		cin >> id;
		cin >> A;
		cin >> T;
		ar[i].push(id,A,T);
	}

	int count=0;
	for(int i=0;i<100;i++){
		if(at == ar[i].A){
			for(int j=ar[i].T;j>0;j--){
				cout << ar[i].id<<":"<<j<<endl;
				at++;
			}
		}else{
			if(i<n){
				idtemp.push(ar[i].id);
				Ttemp.push(ar[i].T);
			}
		}
		
	}
			while(!idtemp.empty()){
			for(int i=Ttemp.top();i>0;i--){
				cout << idtemp.top()<< ":"<<i <<endl;
			}
			idtemp.pop();
			Ttemp.pop();
		}

}
