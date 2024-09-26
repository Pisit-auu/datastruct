#include <iostream>
#include <stack>
using namespace std;

class Store{
	public:
		int ID;
		int A;
		int T;
	Store(int ID,int A,int T){
		this->ID = ID;
		this->A = A;
		this->T = T;
	}
};


int main(){
	stack<int> stID;
	stack<int> stT;
	char c;
	int ID;
	int A;
	int T;
	int n;
	cin >> n;
	Store* Arr[n];
	for(int i=0;i<n;i++){
		cin >> ID;
		cin >> A;
		cin >> T;
		Arr[i] = new Store(ID,A,T);

	}
	int count =0;
	for(int i=0;i<=100;i++){
		for(int j=0;j<n;j++){
			if(i == Arr[j]->A){
				for(int k=Arr[j]->T;k>0;k--){
					cout << Arr[j]->ID <<":"<<k <<endl;
					i++;
				}
				count++;
			}else{
				if(count < n){
				stID.push(Arr[j]->ID);
				stT.push(Arr[j]->T);
				count++;					
				}

			}
			
		}
	}	

	while(!stID.empty()){
		for(int k=stT.top();k>0;k--){
					cout << stID.top() <<":"<<k <<endl;
				}
				stID.pop();
				stT.pop();
	}

	
	
	
	
}
