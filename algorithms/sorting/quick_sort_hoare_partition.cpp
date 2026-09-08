#include <iostream>
using namespace std;
int Partition(int* Arr,int l,int r){
	int p = Arr[l];
	int i = l;
	int j = r+1;
	
	do{
		 do { 
            i++;
        }while(Arr[i] < p);
        do{ 
            j--;
        }while(Arr[j] > p);
        swap(Arr[i],Arr[j]);
		}while(i<j);
		swap(Arr[i],Arr[j]);
		swap(Arr[l], Arr[j]);
		return j;
}
void quicksort(int* Arr,int l,int r){
	if(l<r){
		int s = Partition(Arr,l,r);
		quicksort(Arr,l,s-1);
		quicksort(Arr,s+1,r);
	}
}

int main(){
	int arr[] = {16,25,2,54,36,9,12,66};
	quicksort(arr,0,8-1);

}

/*
			for(int k=0;k<8;k++){
				cout << Arr[k] <<" ";
			}
			cout << endl;
			
			swap(Arr[j],Arr[l]);
				for(int i=0;i<8;i++){
				cout << Arr[i] <<" ";
			}
			cout << endl;
	*/
