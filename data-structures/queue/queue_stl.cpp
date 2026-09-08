#include <iostream>
#include <queue>
using namespace std;


int main(){
	queue <int> q;
	char c;
	int data;
	do{
		cin >> c;
		switch(c){
			case 'e':{
				cin >> data;
				q.push(data);
				break;
			}
			case 'd':{
				cout << q.front() <<endl;
				q.pop();
				break;
			}
			case 'n':{
				cout << q.size() <<endl;
				break;
			}
			case 's':{
				cout << q.front()<<" " << q.back() <<endl;
				break;
			}
			case 'p':{
				int arr[q.size()];
				int size = q.size();
				for( int i=0;i<size;i++){
						arr[i] = q.front();
						cout << q.front()<<" ";
						q.pop();
				}
				cout << endl;
				for(int i=0;i<size;i++){
					q.push(arr[i]);
				}
				break;
			}
		}
		
	}while(c!= 'x');
}
