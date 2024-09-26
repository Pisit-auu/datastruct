#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkList {
public:
    Node* head;
    LinkList() {
        head = new Node(0); // dummy head node
        head->next = NULL;
    }
    
    

};

int main() {
	LinkList* test = new LinkList();
	cout << test->head->data;


    return 0;
}

