#include <iostream>
using namespace std;
class heap{
	public:
		int array[100];
		int i=0;
		void add(int data){
			if(i<100){
				array[i++] = data;
				upheap(i-1);
			}else{
				cout<< "full"<<endl;
			}
		}
		void upheap(int size){
			int parent = (size-1)/2;
			if(size>0 && array[size] > array[parent]){
				swap(array[size],array[parent]);
				upheap(parent);
			}
			
		}
		void downheap(int size){
			int left = 2*size+1;
			int right = 2* size+2;
			int max = size;
			if(left<i&&array[left]>array[max]){
				max=left;
			}
			if(right<i&&array[right]>array[max]){
				max=right;
			}
			if(size!=max){
				swap(array[size],array[max]);
				downheap(max);
			}
		}
		void deleteheap(){
			if(i==0){
				cout<< "empty"<<endl;
				return;
			}
			int show = array[0];
			cout << show <<endl;
			array[0] = array[i-1];
			i--;
			downheap(0);
		}
		void print(){
			for(int z=0;z<i;z++){
				cout << array[z] << " ";
			}
			cout << endl;
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
				test.deleteheap();
				break;
			}
		}
	}while(c !='e');
}
