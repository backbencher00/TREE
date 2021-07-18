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
int height(node* root){
    if(root==NULL)return 0;
    return max(height(root->left), height(root->right))+1;
}
void printlevel(node * root, int level){
	if(root==NULL)return;
	if(level==0)cout<<root->data<<" ";
	printlevel(root->left, level-1);
	printlevel(root->right,level-1);
}
void ReverselevelOrder(node *root){
	int h=height(root);
	for(int i=h-1;i>=0;i--){
		printlevel(root, i);
	}
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
    //preorder(root);
    ReverselevelOrder(root);
}