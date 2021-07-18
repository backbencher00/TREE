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
void inorderIterative(node* root){
    stack<node*> stack;
    node* curr = root;
    while (!stack.empty() || curr != nullptr){ 
        if (curr != nullptr){
            stack.push(curr);
            curr = curr->left;
        }
        else {
            curr = stack.top();
            stack.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
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
    inorderIterative(root);
}