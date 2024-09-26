 #include <iostream>
 #include <queue>
 using namespace std;
 int main() {
 queue <int> iqueue;
 iqueue.push( 13 );
 iqueue.push( 42 );
 cout << "Head: " << iqueue.front() << endl;
 iqueue.pop();                        
// no return value
 cout << "Head: " << iqueue.front() << endl;
 cout << "Size: " << iqueue.size() << endl;
 return 0;
 
 }

