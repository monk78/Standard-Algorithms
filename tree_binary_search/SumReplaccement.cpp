/**
    Author:Monk_ Topic:Sum Replacement of all leafs;

    Logic:we used recursion as a part to do question;

    this is a programme for counting sum of all leaf nodes:
                                                            **/

#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        Node *left,*right;
        int data;
        Node(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
};
Node *buildTree()
{
    int d;
    cin>>d;
    if(d==-1)
        return NULL;
    Node *root=new Node(d);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
void BFS(Node *root){
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
int countt(Node *root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL)
        return root->data;
    int leftsum=countt(root->left);
    int rightsum=countt(root->right);
    int temp=root->data;
    root->data=leftsum+rightsum;
    return temp+root->data;

}
int main(){
    Node *root=buildTree();
    cout<<"printing the tree:"<<endl;
    BFS(root);
    cout<<"Sum Replacement:"<<endl;
    countt(root);
    BFS(root);
return 0;
}
