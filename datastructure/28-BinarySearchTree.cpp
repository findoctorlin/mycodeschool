// Binary Search Tree - Implemenation in C++
// Simple program to create a BST of integers and search an element in it 
#include<iostream>
using namespace std;
//Definition of Node for Binary search tree
struct BstNode {
	int data; 
	BstNode* left;
	BstNode* right;
};

// Function to create a new Node in heap
BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
    delete newNode;
}

// To insert data in BST, returns address of root node 
BstNode* Insert(BstNode* root,int data) {       //注意返回值是指针（地址），这样就能返回在函数内部改变了的root值，
	if(root == NULL) { // empty tree            //否则局部变量回到主函数仍未改变
		root = GetNewNode(data);
	}
	// if data to be inserted is lesser, insert in left subtree. 
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	// else, insert in right subtree. 
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}
//To search an element in BST, returns true if element is found
bool Search(BstNode* root,int data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}

int FindMin(BstNode* root) {
	if(root == NULL) {
		cout << "ERROR: empty tree!" << endl;
		return -1;
	}
	BstNode* current = root;		//也可以不用current，直接用root
	while(current -> left != NULL) {
		current = current -> left;
	}
	return current -> data;
}

/*递归方法求最小值节点*/
int FindMin_recursive(BstNode* root) {
	if(root == NULL) {
		cout << "ERROR: empty tree!" << endl;
		return -1;
	}
	else if(root -> left == NULL) {
		return root -> data;
	}
	return FindMin_recursive(root -> left);
}

int main() {
	BstNode* root = NULL;  // Creating an empty tree
	/*Code to test the logic*/
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
	// Ask user to enter a number.  
	int number;
	cout<<"Enter number be searched\n";
	cin>>number;
	//If number is found, print "FOUND"
	if(Search(root,number) == true) cout<<"Found\n";
	else cout<<"Not Found\n";
}

//另一种实现改变insert函数内的root，主函数的root也能改变：形参是指针自身的地址
// void Insert(BstNode** root,int data) {
// 	if(*root == NULL) { // empty tree    
// 		*root = GetNewNode(data);
// 	}
// 	else if(data <= root->data) {
// 		*root->left = Insert(*root->left,data);
// 	}
// 	// else, insert in right subtree. 
// 	else {
// 		*root->right = Insert(*root->right,data);
// 	}
// }

// int main() {
// 	BstNode* root = NULL;
// 	Insert(&root,15);        //传入Insert函数的是root指针量自身的地址, 不是root指针存放的堆区的某一块的地址	