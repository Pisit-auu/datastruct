#include <iostream>
using namespace std;

int main() {
    int size = 6; // ??????? queue
    int front = 0;
    int tail = 0;
    int count = 0;
    int queue[size];
    int data;
    char c;

    do {
        cin >> c;
        switch (c) {
            case 'e': { 
                if (count == size) {
                    cout << "full" << endl;
                } else {
                    cin >> data;
                    queue[tail] = data;
                    tail = (tail + 1) % size; 
                    count++;
                }
                break;
            }
            case 'd': { 
                if (count == 0) {
                    cout << "empty" << endl;
                } else {
                    cout << queue[front] << endl;
                    front = (front + 1) % size; 
                    count--;
                }
                break;
            }
            case 'p': {
                if (count == 0) {
                    cout << "empty" << endl;
                } else {
                    int i = front;
                    int printed = 0;
                    while (printed < count) {
                        cout << queue[i] << " ";
                        i = (i + 1) % size;
                        printed++;
                    }
                    cout << endl;
                }
                break;
            }
            case 'n': {
                cout << count << endl;
                break;
            }
            case 's': { 
                if (count == 0) {
                    cout << "empty" << endl;
                } else {
                    cout << queue[front] << " ";

                    cout << queue[(tail - 1 + size) % size] << endl;
                }
                break;
            }
        }
    } while (c != 'x');

    return 0;
}

