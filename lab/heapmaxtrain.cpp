#include <iostream>
using namespace std;

class heapmax{
	public:
		int* data;	
		int i;
		heapmax(int n){
			data =new int[n];
			i=0;
		}
		void heapadd(int data){
			if(i==0){
				this->data[i] = data;
				i++;
			}else{
				this->data[i] = data;
				heapcheck(i);
				i++;
			}
		}
		void heapcheck(int current){
			while(current!=0){
				if(this->data[(current-1)/2] <data[current]){
					swap(data[current],data[(current-1)/2]);
					current= (current-1)/2;
				}else{
					break;
				}
				
			}
		}
		void Delete(){
			cout << data[0]<<" "<<data[i-1] <<endl;
			swap(data[0],data[i-1]);
			i--;
			int current =0;
			while(true){
				int childleft = 2*current+1;
				int childright = 2*current+2;
				int larg = current;
				if(childleft < i && data[larg]<data[childleft]){
						larg = childleft;
				}
				if(childright < i &&data[larg]<data[childright]){	
					larg = childright;					
				}
				if(larg!=current){
					swap(data[larg],data[current]);
					current=larg;
				}else{
					break;
				}
		}
			}
		void print(){
			for(int z=0;z<i;z++){
				cout<< data[z] <<" " ;
			}
			cout << endl;
		}
		
		
};


int main(){
	heapmax m = heapmax(40);
	int data;
	char c;
	do{
		cin >> c;
		switch(c){
			case 'a':{
				cin >> data;
				m.heapadd(data);
				break;
			}
			case 'p':{
				m.print();
				break;
			}
			case 'd':{
				m.Delete();
				break;
			}
		}
		
	}while(c!='e');

}
