#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;
    int height;
    Node(int value) {
        this->left = NULL;
        this->right = NULL;
        this->value = value;
        this->height = -1; 
    }
};

class Tree {
public:
    Node* h;

    Tree() {
        h = NULL;
    }

    void push(int value) {
        Node* x = new Node(value);
        if (h == NULL) {
            h = x;
        } else {
            Node* head = h;
            while (true) {
                if (value < head->value) {
                    if (head->left == NULL) {
                        head->left = x;
                        break;
                    } else {
                        head = head->left;
                    }
                } else if (value > head->value) {
                    if (head->right == NULL) {
                        head->right = x;
                        break;
                    } else {
                        head = head->right;
                    }
                } else {
                    break;
                }
            }
        }
    }

void BreadthFirst() {
    if (h == NULL) {
        cout << "empty" << endl;
        return;
    }

    queue<Node*> q;
    q.push(h);
    q.push(NULL); 

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current != NULL) {
            cout << current->value;
            if (!q.empty() && q.front() != NULL) {
                cout << ",";
            }
            if (current->left != NULL) q.push(current->left);
            if (current->right != NULL) q.push(current->right);
        } else {
	            cout << "|";
	
	            if (!q.empty()) {
	                q.push(NULL);
	            }
        }
    }
    cout << endl;
}

    void inorder(Node* node) {
        if (node == NULL) return;
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }

    void inorder() {
        if (h == NULL) {
            cout << "empty" << endl;
        } else {
            inorder(h);
            cout << endl;
        }
    }

    void preorder(Node* node) {
        if (node == NULL) return;
        cout << node->value << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void preorder() {
        if (h == NULL) {
            cout << "empty" << endl;
        } else {
            preorder(h);
            cout << endl;
        }
    }

    void postorder(Node* node) {
        if (node == NULL) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->value << " ";
    }

    void postorder() {
        if (h == NULL) {
            cout << "empty" << endl;
        } else {
            postorder(h);
            cout << endl;
        }
    }

    void deleteNode(int value) {
        h = deleteNodeRec(h, value);
    }
    Node* deleteNodeRec(Node* root, int value) {
        if (root == NULL) return root;

        if (value < root->value) {
            root->left = deleteNodeRec(root->left, value);
        } else if (value > root->value) {
            root->right = deleteNodeRec(root->right, value);
        } else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->value = temp->value;
            root->right = deleteNodeRec(root->right, temp->value);
        }
        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }
};

int main() {
    Tree* test = new Tree();
    char c;
    int data;
    do {
        cin >> c;
        switch (c) {
            case 'a': {
                cin >> data;
                test->push(data);
                break;
            }
            case 'd': {
                cin >> data;
                test->deleteNode(data);
                break;
            }
            case 'b': {
                test->BreadthFirst();
                break;
            }
            case 'i': {
                test->inorder();
                break;
            }
            case 'p': {
                test->preorder();
                break;
            }
            case 't': {
                test->postorder();
                break;
            }
        }
    } while (c != 'x');

    return 0;
}

