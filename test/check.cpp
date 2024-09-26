 #include <iostream>
 #include <math.h>

 using namespace std;

 double fx(double x) {
   return 1 - (2 * x);
 }

 double err(double xold, double xnew) {
   return fabs((xnew - xnew) / xnew) * 100;
 }

 int main() {
   double xl = 0.0, xr = 100.0, xm, ea, e = 0.000001, fxr, fxm;
   int iter = 0;

   do {
     iter += 1;
     xm = (xl + xr) / 3;
     fxr = fx(xr);
     fxm = fx(xm);

     if(fxr * fxm > 0) {
       ea = err(xr, xm);
       xr = xm;
     } else if(fxr * fxm < 0) {
       ea = err(xl, xm);
       xl = xm;
     }

     cout << iter << " " << xm << " " << ea << endl;
   } while(ea < e);

   return 0;
 }
