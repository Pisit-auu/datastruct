#include <iostream>
#include <stack>
using namespace std;


int main(){
	stack <int> st;
	char c;
	int data;
	do{
		cin >> c;
		switch(c){
			case 'U':{
					cin >> data;
					st.push(data);
				break;
			}
			case 'O':{
				if(!st.empty()){
					cout << st.top() <<endl;
					st.pop();
				}
				break;
			}
			case 'T':{
				if(!st.empty()){
					cout << st.top() <<endl;
				}
				break;
			}
			case 'P':{
				int arr[st.size()];
				int size =st.size();
				int i=size-1;
				while(!st.empty()){
					arr[i] = st.top();
					i--;
					st.pop();
				}
				if(st.empty()){
					
					for(i=0;i<size;i++){
					cout << arr[i] <<" ";
				}
				cout << endl;
				}
				i=0;
				while( i <size){
					st.push(arr[i]);
					i++;
				}
				break;
			}
			case 'N':{
				cout << st.size() <<endl;
				break;
			}
		}
		
	}while( c!= 'X');
}
