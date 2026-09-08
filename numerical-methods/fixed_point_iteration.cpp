#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double fx(double x){
	return pow(7*x,1.0/3.0);
}
int main(){
	double x0=1;
	double x1=0;
	int count = 0;
	double error;
	while(true){
		x0= fx(x0);
		if(x1>0){
			error = abs((x0-x1)/x0);
			if(error ==0){
				cout << fixed << setprecision(6) << "x"<< count << " = "<< x0 <<endl;
				break;
			}
		}
	count++;
	x1=x0;
	}
	return 0;
}

