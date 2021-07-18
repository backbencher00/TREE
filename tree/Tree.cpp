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
void preorder(node *root){
	if(root==NULL)return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void inorder(node *root){
	if(root==NULL)return ;
	inorder(root->left);
   cout<<root->data<<" ";
	inorder(root->right);
	
}
void postorder(node *root){
	if(root==NULL)return ;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
int height(node* root){
    if(root==NULL)return 0;
    return max(height(root->left), height(root->right))+1;
}
int diameter(node* root) {
  
    if(root==NULL)return 0;
    int h1=height(root->left);
    int h2=height(root->right);
    int lh =  diameter(root->left);
    int rh = diameter(root->right);
    return max(h1 + h2 + 1,max(lh, rh));
    
}

void printlevel(node * root, int level){
	if(root==NULL)return;
	if(level==0)cout<<root->data<<" ";
	printlevel(root->left, level-1);
	printlevel(root->right,level-1);
}
void levelOrder(node *root){
	int h=height(root);
	for(int i=0;i<h;i++){
		printlevel(root, i);
	}
}
void ReverselevelOrder(node *root){
	int h=height(root);
	for(int i=h-1;i>=0;i--){
		printlevel(root, i);
	}
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
 
void DiagonalTraverase(node*root, auto &mp, int d){
	if(root==NULL)return;
    mp[d].push_back(root->data);
	DiagonalTraverase(root->left, mp, d+1);
	DiagonalTraverase(root->right, mp, d);
}
void DiagonalPrint(node *root){
	unordered_map<int, std::vector<int>>mp;
	DiagonalTraverase(root,mp,0 );
	for(int i=0;i<mp.size();i++){
		for(auto it : mp[i]){
			cout<<it<<" ";
		}
		cout<<endl;
	}
}
void leftview(node *root, int curr, bool *level){
	if(root==NULL)return;
	if(level[curr]==false){
		cout<<root->data<<" ";
		level[curr]=true;
	}
	leftview(root->left, curr+1, level);
	leftview(root->right, curr+1, level);
}
void rightview(node *root, bool *level, int curr ){
        if(root==NULL)return;
        if(level[curr]==false){
            level[curr]=true;
            cout<<root->data<<" ";
             
        }
        rightview(root->right, level, curr+1);
        rightview(root->left, level, curr+1 );
}
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
void visitTop(node* root,int d,int l,map<int,pair<int,int>> &m){
    if(root==NULL) return;
 
    if(m.count(d)==0)m[d] = make_pair(root->data,l);
    else if(m[d].second>l)m[d] = make_pair(root->data,l);
 
    visitTop(root->left,d-1,l+1,m);
    visitTop(root->right,d+1,l+1,m);
}
void topView(struct node *root){  
    map<int,pair<int,int>> m;
    visitTop(root,0,0,m);
    for(auto i=m.begin();i!=m.end();i++)cout << i->second.first << " ";
     
}
node * createnode(int x){
	node *newnode=new node(x);
	return newnode;

}
void mirrorify(node *root, node **mirror ){
	if(root ==NULL){
		mirror=NULL;
		return ;
	}
	*mirror = createnode(root->data);
	mirrorify(root->left, &(*mirror)->right);
	mirrorify(root->right, &(*mirror)->left);

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
    preorder(root);cout<<endl;
    inorder(root);cout<<endl;
    postorder(root);cout<<endl;
    levelOrder(root);cout<<endl;
    ReverselevelOrder(root);cout<<endl;
    ZigZag(root);cout<<endl;
    DiagonalPrint(root);cout<<endl;
    topView(root);cout<<endl;
    bottomView(root);cout<<endl;
    bool level[10000]={false};
    rightview(root, level, 0);cout<<endl;
    bool level1[1000]={false};
    leftview(root,0,level1);cout<<endl;
    node* mirror; 
    mirrorify(root, &mirror);
    inorder(mirror);
}