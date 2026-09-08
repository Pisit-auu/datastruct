#include <iostream>
using namespace std;
#include <vector>
#include <climits>
void merge(vector<int>& arr,int left,int mid,int right){
	int n1 = mid-left+1;
	int n2 = right-mid;
	vector<int> arrleft(n1);
	vector<int> arrright(n2);
	for(int i=0;i<n1;i++){
		arrleft[i] = arr[left+i];
	}
	for(int i=0;i<n2;i++){
		arrright[i] = arr[mid+1+i];
	}
	int i=0,j=0,k=left;
	while(i<n1&& j<n2){
		if(arrleft[i]<=arrright[j]){
			arr[k] = arrleft[i];
			i++;
		}else{
			arr[k] = arrright[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		arr[k] = arrleft[i];
		k++;i++;
	}
	while(j<n2){
		arr[k] = arrright[j];
		k++;j++;
	}
}
void mergesort(int l, int r, vector<int>& arr) {  
	if(l<r){
		int mid = l+(r-l)/2;
		mergesort(l,mid,arr);
		mergesort(mid+1,r,arr);
		merge(arr,l,mid,r);
	}
}
int main(){
	int n;
	cin >> n;
	vector<int> A(n);
	for(int i=0;i<n;i++){
		cin >> A[i];	
	}
	
	mergesort(0,n-1,A);
	
	
	vector <int> keep;
	int count=0;
	int max = INT_MIN;
	for(int i=0;i<n;i++){
		vector<int> C;
		while(A[i]>0){		
			C.push_back(A[i]%10);
			A[i]/=10;
		}
		for (int j = C.size()-1; j>=0;j--) {
			if(C[j]>max){
				max = C[j];
			}
		    keep.push_back(C[j]); 
		}
	}
	int temp=-999;
	int countnum =1;
	vector<int> array(max,0);
	for(int i=0;i<keep.size();i++){
		cout << keep[i];
		if(temp!= keep[i]){
			temp = keep[i];
			if(array[keep[i]] != countnum){
				array[keep[i]]=1;
			}
		}else{
			array[keep[i]]++;
		}
		if(array[keep[i]]>countnum){
			countnum = array[keep[i]];
			array[keep[i]] = countnum;
		}
	}
	  cout << endl;
		for(int i=0;i<=max;i++){
			if(array[i]==countnum){
				cout << i << " ";
			}
		}
		cout << endl;
		temp=-999;
		for(int i=0;i<keep.size();i++){
			if(temp!= keep[i]){
				temp = keep[i];
				cout << keep[i];
			}
		}
}
