#include <iostream>
using namespace std;

class heapmax{
	public:
		int* data;
		int i;
		heapmax(int n){
			data = new int[n];
			i =0;
		}
		void push(int value){
			if(i==0){
				data[i++]=value;			
			}else{
				data[i]=value;
				check(i++);
			}
		}
		void check(int p){
			while(p>0){
				int root = (p-1)/2;
				if(data[root]<data[p]){
					swap(data[root],data[p]);
					p=root;
				}else{
					break;
				}
				
			}
		}
		void deleteh(){
			cout << data[0] <<endl;
			swap(data[0],data[i-1]);
			i--;	
			int start=0;
			while(true){
				int left = 2*start+1;
				int right = 2*start+2;
				int large = start;
				if(left<i&&data[large]<data[left]){
					large=left;
				}if(right<i&&data[large]<data[right]){
					large=right;		
				}
				
				if(large != start){
					swap(data[start],data[large]);
					start=large;
				}else{
					break;
				}
			}
		}
		void print(){
			for(int j=0;j<i;j++){
				cout << data[j] <<" ";
			}
			cout << endl ;
		}
};


int main(){
	char c;
	int data;
	heapmax* h = new heapmax(50);
	do{
		cin >> c;
		switch(c){
			case 'a':{
				cin >> data;
				h->push(data);
				break;
			}
			case 'p':{
				h->print();
				break;
			}
			case 'd':{
				h->deleteh();
				break;
			}
		}
		
	}while(c!='x');
}
