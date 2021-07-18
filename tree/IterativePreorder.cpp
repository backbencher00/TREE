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
void Iterativepreorder(node *root){
	if(root==NULL)return ;
	stack<node*>s;
	s.push(root);

	while(!s.empty()){
       node* temp=s.top();
       s.pop();
       cout<<temp->data<<" ";
       if(temp->right)s.push(temp->right);
       if(temp->left)s.push(temp->left);
       
	}
}
void preorder(node *root){
	if(root==NULL)return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
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
    Iterativepreorder(root);
    cout<<endl;
    preorder(root);
}