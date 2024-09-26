#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


double Fx(double x,double n){
  return pow(x,1.0/n);
}

double Fx2(double x,double n,double y){
    return pow(y,n)-x;
}

double bisection(double l,double r,double x,double n){
    double M = 0.0;
    double E ;

    do {
        double m = M;
        M = (l + r) / 2;

        E = fabs((M-m)/M);


        if (Fx2(x, n, l) * Fx2(x, n, M) < 0) {
            r = M;
        } else {
            l = M;
        }

   }while (E >1e-9);

    return M;
}

int main(){
    double L,X,n;
    double R;

    cout << "input X and n "<<endl;
    cin >> X;
    cin >> n;
    double result2 = Fx(X,n);
    cout << result2 <<endl;

    cout << "input L and R " <<endl;
    cin >> L ;
    cin >> R ;

    double result = bisection(L,R,X,n);
    cout << "y = "<< fixed << setprecision(6) << result <<endl;
return 0;
}
