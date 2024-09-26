#include <iostream>
using namespace std;

class heap{
	public:
		int array[100];
		int i=0;
		
		void add(int data){
			if(i<5){
				array[i++] = data;
				upward(i-1);
			}else{
				cout<< "full" <<endl;
			}
		}
		void upward(int size){
			int parent = (size-1)/2;
			if(size>0&& array[size]>array[parent]){
				swap(array[size],array[parent]);
				upward(parent);
			}
		}
		void print(){
			if(i ==0){
				cout<< "empty" <<endl;
				return;
			}
			for(int z=0;z<i;z++){
				cout << array[z] << " " ;
			}
			cout << endl;
		}
		void downward(int index){
			int left = 2*index+1;
			int right = 2*index+2;
			int max = index;
			if(left < i && array[left] >array[max]){
				max = left;
			}
			if(right < i && array[right] >array[max]){
				max = right;
			}
			if(max != index){
				swap(array[index],array[max]);
				downward(max);
			}
		}
		void deletenode(){
			if(i ==0){
				cout<< "empty" <<endl;
				return;
			}
			int show = array[0];
			cout << show << endl;
			array[0] = array[i-1];
			i--;
			downward(0);
			
		}
		

};


int main(){
	int data;
	char c;
	heap test;
	do{
		cin >> c;
		switch(c){
			case 'a':{
				cin >> data;
				test.add(data);
				break;
			}
			case 'p':{
				test.print();
				break;
			}
			case 'd':{
				test.deletenode();
				break;
			}
		}
	}while(c !='e');
}
