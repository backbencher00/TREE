# TREE
### Tree Traversal
1. BFS(Level order Traversal)
2. DFS
 - preorder(Root-Left-right)
 - postorder(Left-Right-Root)
 - inorder(Left-Root-Right)
```cpp
#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
	node(int val){
		data=val;;
		left=NULL;
		right=NULL;
	}

};
void preorder(node *root){
	if(root==NULL)return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void postorder(node *root){
	if(root==NULL)return ;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
void inorder(node *root){
	if(root==NULL)return ;
	inorder(root->left);
 cout<<root->data<<" ";
	inorder(root->right);
	
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->left = new node(5);
    root->right->right = new node(6);
    root->right->left->left = new node(7);
    root->right->left->right = new node(8);
    preorder(root);
    postorder(root);
    inorder(root);
    
}
```
Some Other traversal
4. Reverse Level Order
5. Diagonal Traversal
6. Zig-Zag
7. Boundary Traversal
### Tree General question

1. Right View
2. Left View
3. Bottom View
4. Top View
5. Height of a tree
6. Diameter of a tree
7. Mirror of a tree


