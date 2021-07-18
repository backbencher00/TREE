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
 
void DiagonalTraverase(node*root, auto &mp, int d){
	if(root==NULL)return;
     mp[d].push_back(root->data);
	DiagonalTraverase(root->left, mp, d);
	DiagonalTraverase(root->right, mp, d+1);
}
void DiagonalPrint(auto mp){
	
	for(int i=0;i<mp.size();i++){
		for(auto it : mp[i]){
			cout<<it<<" ";
		}
		cout<<endl;
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
    //inorder(root);cout<<endl;
    //node* mirror;
    //preorder(root);
    unordered_map<int, std::vector<int>>mp;
    DiagonalTraverase(root, mp, 0);
    //inorder(mirror);
    DiagonalPrint(mp);
}