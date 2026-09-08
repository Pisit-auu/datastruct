#include<iostream>
#include<math.h>
#include <iomanip>
using namespace std;
double fx(double t , double n,double x) {
    return pow(t,n) - x; 
}
int main() {
    cout << setprecision(6) << fixed;
    double x=38,n=3;
    // cin>>x;cin>>n;
    double xL = xL = 0, xR = 1000000, xM = 0, xM_new, xM_old, e=1;
    int i = 0;

    while (e != 0)
    {
        xM = ( xL*(fx(xR,n,x)) - xR*(fx(xL,n,x)) )/( fx(xR,n,x) - fx(xL,n,x));
        
        if ((fx(xR,n,x) * fx(xM,n,x) < 0)) {
            xL = xM;
            xM_new = xL;
        }
        else{
            xR = xM;
            xM_new = xR;
        }
        if (i > 1) {
            e = fabs((xM_new - xM_old) / xM_new);
            
        }
        xM_old = xM_new;
        i++;
    }cout<<xM;
    return 0;
}
