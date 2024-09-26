#include <iostream>
#include <stack>
using namespace std;

class keep{
	public:
	int ID;
	int A;
	int T;
	void set(int id,int a,int t){
		ID= id;
		A=a;
		T=t;
	}
};

int main(){
	stack<int> sid;
	stack<int> st;
	int n;
	int id;
	int a;
	int t;
	cin >> n;
	keep arr[n];
	for(int i=0;i<n;i++){
		keep arr[i];
	}
	for(int i=0;i<n;i++){
		cin >>id;
		cin >> a;
		cin >> t;
		arr[i].set(id,a,t);
	}
	int count=0;
	for(int i=0;i<=100;i++){
		for(int j=0;j<n;j++){
			if(i == arr[j].A){
				for(int k=arr[j].T;k>0;k--){
					cout << arr[j].ID <<":"<< k <<endl;
					i++;
				}
				count++;
			}else{
				if(count<n){
					sid.push(arr[j].ID);
					st.push(arr[j].T);
					count++;
				}
				
			}
		}
	}
	
		while(!sid.empty()){
			for(int k = st.top();k>0;k--){
				cout << sid.top() <<":"<< k <<endl;
			}
			st.pop();
			sid.pop();
		}
}
