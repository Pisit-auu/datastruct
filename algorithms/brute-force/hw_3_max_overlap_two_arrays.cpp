#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> time(100001,0);
    int A[n];
    int B[n];
     for(int i=0;i<n;i++){
    	cin>> A[i]	;  	
		}
	 for(int i=0;i<n;i++){
    	cin>> B[i]	;  	
		}
    for(int i=0;i<n;i++){
    	time[A[i]]+=1;
    	time[B[i]+1]-=1;
    	
	}
	
	int max=0;
	int current=0;
	int start=0;
	int end=0;
	bool startset = false;
	
	for(int i=0;i<=100000;i++){
		current+=time[i];
		if(current > max){
			max = current;
			start=i;
			end=i;
			startset= true;
		}else if( current == max && startset){
			end = i;
		}else if ( current < max && startset){
			startset=false;
		}
	}
	
	cout << start <<" "<< end << " " << max ;

    return 0;
}

