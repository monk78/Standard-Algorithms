/****
    Author:Monk_       Topic:Height Balanced Tree
    Logic/involved :(|left height-right height|>=1)

                                                                                                                                                                                                                                        ***/
#include<bits/stdc++.h>
using namespace std;
class Node{

    public:
        int data;
        Node *left,*right;
        Node(int d){
        left=NULL;
        right=NULL;
        data=d;
        }
};
Node *buildTree(){
    int d;
    cin>>d;
    if(d==-1) return NULL;
    Node *root=new Node(d);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
void BFS(Node *root){
queue<Node*>q;
q.push(root);
q.push(NULL);
while(!q.empty()){
    Node *f=q.front();
    if(f==NULL){
        cout<<endl;
        q.pop();
        if(!q.empty())
            q.push(NULL);
    }
    else{
        cout<<f->data<<" ";
        q.pop();
        if(f->left)q.push(f->left);
        if(f->right)q.push(f->right);
    }
}

}
int height(Node *root){
    if(root==NULL)
        return 0;
    return 1+max(height(root->left), height(root->right));
}
bool Isbalance(Node *root){
    if(root==NULL)
        return true;
    int l=abs(height(root->left)-height(root->right));
    if(l<=1)
        return true;
    else
        return false;
}
int main(){
     Node *root=buildTree();
     cout<<"printing Tree:"<<endl;
     BFS(root);cout<<endl<<
     height(root);
 return 0;
}
