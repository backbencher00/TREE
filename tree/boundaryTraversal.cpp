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
void leafs(node*root){
    if(!root)return;
    leafs(root->left);
    if(!(root->left) && !(root->right))cout<<root->data<<" ";
    leafs(root->right);
}
void lefttree(node*root ){
    if(!root)return;
    if(root->left){
       cout<<root->data<<" ";
       lefttree(root->left);
    }
    else if(root->right){
        cout<<root->data<<" ";
        lefttree(root->right);
    }
    
}
void righttree(node*root ){
    if(!root)return;
    if(root->right){
        righttree(root->right);
        cout<<root->data<<" ";
    }
    else if(root->left){
        righttree(root->left);
        cout<<root->data<<" ";    }
}
void printBoundary(node *root){ 
     cout<<root->data<<" ";
     lefttree(root->left);
     leafs(root);
     righttree(root->right);
      
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
    cout<<"d"<<endl;
    printBoundary(root);
}