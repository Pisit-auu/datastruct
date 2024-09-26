#include <iostream>
using namespace std;
class Stack{
	public:
		int id;
		int A;
		int T;
		int* keep;

		Stack(int id,int A,int T){
			this->id=id;
			this->A=A;
			this->T=T;
		}
};

int main(){
	int n;
	int id;
	int A;
	int T;
	cin >> n;
	Stack* array[n];
	for(int i=0;i<n;i++){
		cin >> id;
		cin >> A;
		cin >> T;
		array[i] = new Stack(id,A,T);
	}
	int temp[n];
	int ntemp =0;
	for(int i=0;i<=n;i++){
		for(int j=0 ;j<n ;j++){
			if(array[j]->A==i){
				for(int l=array[j]->T;l>0;l--){
					cout << array[j]->id << ":"<<l<<endl;
					i++;
				}
			}else{
				temp[ntemp] = j;
				ntemp++;
			}
		}
	}
	for(int i=0;i<ntemp;i++){
		for(int l=array[temp[i]]->T;l>0;l--){
					cout << array[temp[i]]->id << ":"<<l<<endl;
				}
	}

}


