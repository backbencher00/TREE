#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
	node(int val){
		data=val;;
		left=NULL;right=NULL;
	}

};

// recursive solution
int height(node* root){
    if(root==NULL)return 0;
    return max(height(root->left), height(root->right))+1;
}
void printZigZaglevel(node * root, int level, bool leftTOright){
	if(root==NULL)return;
	if(level==0)cout<<root->data<<" ";
	if(leftTOright){
        printZigZaglevel(root->left, level-1, leftTOright);
        printZigZaglevel(root->right,level-1, leftTOright);
    }else{
        printZigZaglevel(root->right, level-1, leftTOright);
        printZigZaglevel(root->left,level-1, leftTOright);
    }
}
void ZigZag(node *root){
	int h=height(root);
    bool leftTOright=true;
	for(int i=0;i<h;i++){
		printZigZaglevel(root, i, leftTOright);
        leftTOright=!leftTOright;
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
    ZigZag(root);
    cout<<endl;
    //levelOrderIter(root);

}