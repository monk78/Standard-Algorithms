/***********************************************************************
    topic: Tree-BFS                Author : Monk_
*****************************************************************************/

/****

1.complexity of programm to make level order traversal via breadth-first-search is:O(n)

2.we use queue of type queue < Node* > qu1;type to implement our programme:

3.if we want to change the line after every level then there is basically two methods:
    (i)implement it by using queue< pair < Node*,int> > qu2;
    (ii)insert NULL char in qu1 after every level and traverse then whole tree,then as we will procced
    a new line will form after every node

*****/

#include<iostream>
#include<queue>
using namespace std;
class Node{
 public:
     int data;
     Node *left;
     Node *right;
     Node(int d){
       data=d;
       left=NULL;
       right=NULL;
     }
};
Node *buildTree(){
    int d=0;
    cin>>d;
    if(d==-1)
        return NULL;
    Node *root=new Node(d);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
int height(Node *root){
    if(root==NULL)
            return 0;
    return 1+max(height(root->left),height(root->right));
}
//applying BFS
void BFS1(Node *root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node *f=q.front();
        cout<<f->data<<" ";
        q.pop();
        if(f->left)
            q.push(f->left);
        if(f->right)
            q.push(f->right);
    }
}
void BFS2(Node *root){
    queue<Node*>q2;
    q2.push(root);
    q2.push(NULL);
    while(!q2.empty()){
        Node *f=q2.front();
        if(f==NULL){
            cout<<endl;
            q2.pop();
            if(!q2.empty())
                q2.push(NULL);
        }
        else{
        cout<<f->data<<" ";
        q2.pop();
        if(f->left)
                q2.push(f->left);
        if(f->right)
                q2.push(f->right);
       }
  }
}
int main(){
    Node *root=buildTree();
    cout<<"depth of tree:"<<height(root);
    cout<<"\nprinting All Node:";
    BFS1(root);cout<<endl;
    BFS2(root);cout<<endl;
return 0;
}
