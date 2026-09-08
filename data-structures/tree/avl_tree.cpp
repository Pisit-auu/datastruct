#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        data = value;
        left = right = NULL;
        height = 1; // Leaf node starts with height 1
    }
};

// Function to get the height of a node
int height(Node* node) {
    return node ? node->height : 0;
}

// Function to get the balance factor of a node
int getBalance(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x; // New root
}

// Left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y; // New root
}

// Function to insert a node in the AVL tree
Node* insert(Node* node, int value) {
    if (!node) return new Node(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);
    else
        return node;

    node->height = max(height(node->left), height(node->right)) + 1;

    int balance = getBalance(node);

    if (balance > 1 && value < node->left->data)
        return rightRotate(node);

    if (balance < -1 && value > node->right->data)
        return leftRotate(node);

    if (balance > 1 && value > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && value < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node from the AVL tree
Node* deleteNode(Node* root, int value) {
    if (!root)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (!root)
        return root;

    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Pre-order traversal
void preOrderTraversal(Node* root) {
    if (root) {
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// In-order traversal
void inOrderTraversal(Node* root) {
    if (root) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

// Post-order traversal
void postOrderTraversal(Node* root) {
    if (root) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }
}

// Breadth-First (Level Order) traversal
void levelOrderTraversal(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        cout << node->data << " ";
        q.pop();

        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
}

// Main function to test the AVL tree implementation
int main() {
    Node* root = NULL;

    char command;
    int value;

    do {
        cin >> command;
        switch (command) {
            case 'a': // Add data to AVL Tree
                cin >> value;
                root = insert(root, value);
                break;
            case 'd': // Remove data from AVL Tree
                cin >> value;
                root = deleteNode(root, value);
                break;
            case 'b': // Breadth-First (Level Order) traversal
                levelOrderTraversal(root);
                cout << endl;
                break;
            case 'i': // In-order traversal
                inOrderTraversal(root);
                cout << endl;
                break;
            case 'p': // Pre-order traversal
                preOrderTraversal(root);
                cout << endl;
                break;
            case 't': // Post-order traversal
                postOrderTraversal(root);
                cout << endl;
                break;
        }
    } while (command != 'x'); // Exit loop when 'x' is entered

    return 0;
}

