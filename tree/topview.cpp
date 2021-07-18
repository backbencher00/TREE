#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
    node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }

};
void fill(node* root,int d,int l,map<int,pair<int,int>> &m){
    if(root==NULL) return;
 
    if(m.count(d)==0)m[d] = make_pair(root->data,l);
    else if(m[d].second>l)m[d] = make_pair(root->data,l);
 
    fill(root->left,d-1,l+1,m);
    fill(root->right,d+1,l+1,m);
}
void topView(struct node *root){  
    map<int,pair<int,int>> m;
    fill(root,0,0,m);
    for(auto i=m.begin();i!=m.end();i++)cout << i->second.first << " ";
     
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
   topView(root);

}