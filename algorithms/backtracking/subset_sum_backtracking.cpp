#include <bits/stdc++.h>
using namespace std;
int A[] = {25,10,9,2,1};
int target = 12;
vector<bool> checkchoose(1000,false);
void subset(int l,int r,int sum){
		if(sum==target){
			for(int i=0;i<r;i++){
				if(checkchoose[i]){
					cout << A[i] <<" ";
				}	
			}
			cout << endl;
			return;
		}

	for(int i=l;i<r;i++){
		if(!checkchoose[i]){
			sum+= A[i];
			
			if(target-sum>=0){
				checkchoose[i]= true;
				subset(l+1,r,sum);
				checkchoose[i]= false;
				sum-= A[i];
			}else{
				sum-= A[i];
			}
		
			
		}
	}
}
int main(){
	subset(0,5,0);	
}
