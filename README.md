# TREE
### Tree Traversal
1. BFS(Level order Traversal)
```cpp
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
//Iterative solution
void levelOrderIter(node* root){ 
    queue<node *>q;
    q.push(root);
    while(!q.empty()){
        node *temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left)q.push(temp->left);
        if(temp->right)q.push(temp->right);
    }
}
// recursive solution
int height(node* root){
    if(root==NULL)return 0;
    return max(height(root->left), height(root->right))+1;
}
void printlevel(node * root, int level){
	if(root==NULL)return;
	if(level==0)cout<<root->data<<" ";
	printlevel(root->left, level-1);
	printlevel(root->right,level-1);
}
void levelOrderRec(node *root){
	int h=height(root);
	for(int i=0;i<h;i++){
		printlevel(root, i);
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
    levelOrderRec(root);
    cout<<endl;
    levelOrderIter(root);

}
}
```
3. DFS
 - preorder(Root-Left-right)
 - postorder(Left-Right-Root)
 - inorder(Left-Root-Right)
```cpp
#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left;node *right;
	node(int val){
		data=val;;
		left=NULL;
		right=NULL;
	}
};
void preorder(node *root){
	if(root==NULL)return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void postorder(node *root){
	if(root==NULL)return ;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
void inorder(node *root){
	if(root==NULL)return ;
	inorder(root->left);
        cout<<root->data<<" ";
	inorder(root->right);
	
}
void preorderIterative(node *root){
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
     for(auto it=v.end()-1;it!=v.begin()-1;it--)cout<<*it<<" ";   
}
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
    preorder(root);
    cout<<endl;
    preorderIterative(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    postOrderIterative(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    inorderIterative(root);
    
}
```
Some Other traversal
4. Reverse Level Order
5. Diagonal Traversal
6. Zig-Zag
7. Boundary Traversal
### Tree General question

1. Right View
2. Left View
3. Bottom View
4. Top View
5. Height of a tree
6. Diameter of a tree
7. Mirror of a tree


