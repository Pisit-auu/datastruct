#include <iostream>
using namespace std;

int main(){
	
	int arr[3][3] = {{-7, 3, 2}, {9, -5, 0}, {-2, 8, 5}};
	
	for(int i = 0; i<sizeof(arr)/sizeof(arr[0]); i++) {
    for(int j = 0; j<sizeof(arr[0])/sizeof(arr[0][0]); j++) {
        cout << arr[j][i] << "-";
    }
}
}
