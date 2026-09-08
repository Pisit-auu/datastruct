#include <iostream>
using namespace std;

// ?????????? Node ??? Binary Search Tree
class Node {
public:
    int val;      // ?????????
    Node* left;   // ???????????????
    Node* right;  // ??????????????

    // ???????????????? Node
    Node(int value) {
        val = value;
        left = right = NULL;
    }
};

// ??????????????????? Binary Search Tree
class BST {
public:
    Node* root;


    BST() {
        root = NULL;
    }


    Node* insert(Node* node, int key) {
        if (node == NULL) {
            return new Node(key);
        }
        if (key < node->val) {
            node->left = insert(node->left, key);
        }
        else if (key > node->val) {
            node->right = insert(node->right, key);
        }
        return node;
    }

    Node* search(Node* node, int key) {
        if (node == NULL || node->val == key) {
            return node;
        }

        if (key < node->val) {
            return search(node->left, key);
        }

        return search(node->right, key);
    }

    void inorderTraversal(Node* node) {
        if (node != NULL) {
            inorderTraversal(node->left);
            cout << node->val << " ";
            inorderTraversal(node->right);
        }
    }


    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }


    Node* deleteNode(Node* root, int key) {

        if (root == NULL) {
            return root;
        }

   
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {

            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = minValueNode(root->right);

            root->val = temp->val;

            root->right = deleteNode(root->right, temp->val);
        }

        return root;
    }
};

int main() {
    BST tree;

    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    // ??????????????????????????? in-order
    cout << "In-order Traversal: ";
    tree.inorderTraversal(tree.root);
    cout << endl;

    // ????????????????? 40
    Node* result = tree.search(tree.root, 40);
    if (result != NULL) {
        cout << "Found 40" << endl;
    } else {
        cout << "40 Not Found" << endl;
    }

    // ?????????????? 20
    tree.root = tree.deleteNode(tree.root, 20);
    cout << "In-order Traversal after deleting 20: ";
    tree.inorderTraversal(tree.root);
    cout << endl;

    return 0;
}

