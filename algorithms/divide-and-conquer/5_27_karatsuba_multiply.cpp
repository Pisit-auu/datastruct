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
    int power = 1;
    for (int i = 0; i < half; i++) {
        power *= 10;
    }
    int a1 = a / power;  
    int a2 = a % power;  
    int b1 = b / power;  
    int b2 = b % power; 
	int A = multiple(a1, b1); 
	int B = multiple(a1+a2, b1+b2);
	int C = multiple(a2, b2);  
    cout << A << "x" <<"10^"<<n<<"+("<< B<< "-" << A <<"-"<< C<< ")*10^"<<half<<"+" << C << endl;
	cout << A * power * power + (B - A - C) * power + C<<endl;
    return A * power * power + (B - A - C) * power + C;
}
int main() {
    int a, b;
    cin >> a;
    cin >> b;
    cout << multiple(a, b) ;
    return 0;
}

