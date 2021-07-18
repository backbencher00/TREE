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
void  rightview(node *root, bool *level, int curr ){
        if(root==NULL)return;
        if(level[curr]==false){
            level[curr]=true;
            cout<<root->data<<" ";
             
        }
        rightview(root->right, level, curr+1);
        rightview(root->left, level, curr+1 );
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
    bool level[10000]={false};
    rightview(root, level, 0);
}
