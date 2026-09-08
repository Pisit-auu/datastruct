#include <iostream>
#include <cmath>
using namespace std;

int getNumDigits(int num) {
    int digits = 0;
    while (num > 0) {
        digits++;
        num /= 10; 
    }
    return digits;
}

int multiple(int a, int b) {
    int n = max(getNumDigits(a), getNumDigits(b));  
    if (n <= 1) {
        return a * b;  
    }
    int half = n / 2;  
    int power = pow(10, half);  
    int a1 = a / power;  
    int a2 = a % power;  
    int b1 = b / power;  
    int b2 = b % power; 
	int A = multiple(a1, b1); 
	int B = multiple(a1, b2);
	int C = multiple(a2, b1);  
	int D = multiple(a2, b2);  
    cout << A << "x" <<"10^"<<n<<"+("<< C<< "+" << B<< ")*10^"<<half<<"+" << D << endl;

    return A * pow(10, n) + (B + C) * pow(10, half) + D;
}
int main() {
    int a, b;
    cin >> a;
    cin >> b;
    cout << multiple(a, b) ;
    return 0;
}

