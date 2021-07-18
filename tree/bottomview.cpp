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
void visitbottom(node *node, int dist, int level, map<int ,pair<int,int>> &mp)
{ 
    if(node == nullptr)return;
    if(level >=mp[dist].second)mp[dist]={node->data,level};
    
    visitbottom(node->left, dist - 1, level + 1, mp);
    visitbottom(node->right, dist + 1, level + 1, mp);
}
 
  
void bottomView(node *root){
     
    map<int, pair<int,int>> mp;
    visitbottom(root, 0, 0, mp);
    for(auto it =mp.begin();it!=mp.end();it++)cout << it->second.first << " ";
      
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
   bottomView(root);

}