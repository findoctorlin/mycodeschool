#include<iostream>
using namespace std;
#include<algorithm>
struct Node {
    int data;
    Node* left;
    Node* right;
};

int FindHeight(Node *root) {
    if (root == NULL)   return -1;
    return max(FindHeight(root->left), FindHeight(root->right))+1;
}

Node* Insert(Node *root,int data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else 
		root->right = Insert(root->right,data);
	return root;
}
 
int main() {
	/*Code To Test the logic
	  Creating an example tree
	             15
			   /    \
			  10    20
			 / \    /  \ 
		    8  12  17  25
           /   /   /     \
          6   11  16     27
    */
	Node* root = NULL;
	root = Insert(root,15); root = Insert(root,10);
	root = Insert(root,20); root = Insert(root,8); 
	root = Insert(root,12); root = Insert(root,17);
    root = Insert(root,25); root = Insert(root,6);
    root = Insert(root,11); root = Insert(root,16);
    root = Insert(root,27);
    cout << FindHeight(root);
}