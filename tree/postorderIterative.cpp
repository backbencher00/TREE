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
 void postOrderIterative(node *root){
   stack<node*>s;
    vector<int>v;
    s.push(root);
    while(!s.empty()){
         node*temp=s.top();
         s.pop();
         v.push_back(temp->data);
         if(temp->left)s.push(temp->left);
         if(temp->right)s.push(temp->right);
    }
     for(auto it=v.end()-1;it!=v.begin()-1;it--){
      cout<<*it<<" ";
     }
}
void postorder(node *root){
   if(root==NULL)return ;
   postorder(root->left);
   postorder(root->right);
   cout<<root->data<<" ";
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
    postOrderIterative(root);
    cout<<endl;
    postorder(root);
}