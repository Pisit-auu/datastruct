#include <iostream>
using namespace std;
#define max 500
int arr[max];
int count=-1;

void print(){
	for(int i=0;i<=count;i++){
		cout << arr[i] << " ";
	}
	cout <<endl;
}
int findparent(int data){
	return (data-1)/2;
}
int findL(int data){
	return (2*data)+1;
}
int findR(int data){
	return (2*data)+2;
}
void insert(int data){
	arr[++count] = data;
	int temp = count;
	int parent = findparent(count);
	while(arr[parent]>arr[temp]){
		swap(arr[parent],arr[temp]);
		temp = parent;
		parent = findparent(parent);
	}
	print();
}
void deleteheap(){
	cout << arr[0] <<endl;
	swap(arr[count],arr[0]);
	count--;
	int start =0;
	while(start<=count){
		int L = findL(start);
		int R = findR(start);
		int large = start;
		if(L<=count && arr[L]<arr[large]){
			large = L;
		}
		if(R<=count&& arr[R]<arr[large]){
			large = R;
		}
		if(large!=start){
			swap(arr[large],arr[start]);
			start = large;
		}else{
			break;
		}
	}
	print();
}


int main(){
	
	char c;
	int data;
	do{
		cin >> c;
		switch(c){
			case 'i':{
				cin >> data;
				insert(data);
				break;
			}
			case 'd':{
				deleteheap();
				break;
			}
		}
		
	}while(c!= 'x');
	
}
