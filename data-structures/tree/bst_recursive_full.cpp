#include <iostream>
#include <queue>
using namespace std;

class Node{
	public:
		Node* left;
		Node* right;
		int data;
		Node(int data){
			this->left=NULL;
			this->right=NULL;
			this->data = data;
		}
};


Node* insert(Node* root,int val){
	if(root==NULL){
		return new Node(val);
	}
	if(val < root->data){
		root->left = insert(root->left,val);
	}else if(val > root->data){
		root->right = insert(root->right,val);
	}
	return root;
}
void inorder(Node* root){
	if(root !=NULL){
		inorder(root->left);
		cout << root->data <<",";
		inorder(root->right);
	}
	
}
void preorder(Node* root){
	if(root !=NULL){
		cout << root->data <<",";
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(Node* root){
	if(root !=NULL){	
		postorder(root->left);
		postorder(root->right);
		cout << root->data <<",";
	}
}

void Breadth(Node* root){
	queue<Node* > q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		
		Node* head = q.front();
		q.pop();
		
		if(head!=NULL){
			cout<< head->data <<",";
			if(head->left!=NULL){
				q.push(head->left);
			}
			if(head->right!=NULL){
				q.push(head->right);
			}
		
		}else{
			cout << "|";
			if(!q.empty()){
				q.push(NULL);
			}
		}
	}
	
	
}
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* deletenode(Node* root, int val){
	if(val < root->data){
		root->left = deletenode(root->left,val);
	}else if(val > root->data){
		root->right = deletenode(root->right,val);
	}else {
		if(root->left==NULL && root->right==NULL){
			delete root;
			return NULL;
		}
		else if(root->left==NULL){
			Node* temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right==NULL){
			Node* temp = root->left;
			delete root;
			return temp;
		}else{
			Node* temp = findMin(root->right);
			root->data = temp->data;
			root->right = deletenode(root->right, temp->data);
		}
	}
	
	
}

Node* findMinleft(Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}
Node* deletenodeleft(Node* root, int val){
	if(val < root->data){
		root->left = deletenodeleft(root->left,val);
	}else if(val > root->data){
		root->right = deletenodeleft(root->right,val);
	}else {
		if(root->left==NULL && root->right==NULL){
			delete root;
			return NULL;
		}
		else if(root->left==NULL){
			Node* temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right==NULL){
			Node* temp = root->left;
			delete root;
			return temp;
		}else{
			Node* temp = findMinleft(root->left);
			root->data = temp->data;
			root->left = deletenodeleft(root->left, temp->data);
		}
	}
	
	
}

int main(){
	Node* root =NULL;
	char c;
	int data;
	do{
		cin >> c;
		switch(c){
			case 'a':{
				cin >> data;
				root = insert(root,data);
				break;
			}
			case 'i':{
				inorder(root);
				cout << endl;
				break;
			}
			case 'p':{
				preorder(root);
				cout << endl;
				break;
			}
			case 't':{
				postorder(root);
				cout << endl;
				break;
			}
			case 'b':{
				Breadth(root);
				cout << endl;
				break;
			}
			case 'd':{
				cin >> data ;
				deletenode(root,data);
				break;
			}
			case 'l':{
				cin >> data ;
				deletenodeleft(root,data);
				break;
			}
		}
	}while(c!= 'x');
	
}
