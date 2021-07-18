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
void leftview(node *root, int curr, bool *level){
	if(root==NULL)return;
	if(level[curr]==false){
		cout<<root->data<<" ";
		level[curr]=true;
	}
	leftview(root->left, curr+1, level);
	leftview(root->right, curr+1, level);
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
    bool level[1000]={false};
    leftview(root,0,level);
}
