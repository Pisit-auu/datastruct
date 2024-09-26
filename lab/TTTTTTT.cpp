#include <iostream>
using namespace std;
class Node{
	public: 
	Node* left;
	Node* right;
	int value;
	Node(int value){
		this->left=NULL;
		this->right=NULL;
		this->value=value;
	}
};

class Tree{
	public:
		Node* root;
		Tree(){
			root =NULL;
		}
		Node* insert(Node* node,int value){
			if(node == NULL){
				return new Node(value);
				
			}
			if(value < node->value){
				node->left = insert(node->left,value);

			}else if(value > node->value){
				node->right = insert(node->right,value);
			}
			
			return node;
		}
		void inorderTraversal(Node* node) {
        if (node != NULL) {
            inorderTraversal(node->left);
            cout << node->value << " ";
            inorderTraversal(node->right);
        }
    }
};
int main(){
	Tree tree;
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    cout << "In-order Traversal: ";
    tree.inorderTraversal(tree.root);
    cout << endl;
}
