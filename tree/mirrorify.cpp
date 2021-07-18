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
node * createnode(int x){
	node *newnode=new node(x);
	return newnode;

}
void mirrorify(node *root, node **mirror ){
	if(root ==NULL){
		mirror=NULL;
		return ;
	}
	*mirror = createnode(root->data);
	mirrorify(root->left, &(*mirror)->right);
	mirrorify(root->right, &(*mirror)->left);

}
void inorder(node*root){
	if(root==NULL)return;
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
    inorder(root);cout<<endl;
    node* mirror;
    //preorder(root);
    mirrorify(root, &mirror);
    inorder(mirror);
}