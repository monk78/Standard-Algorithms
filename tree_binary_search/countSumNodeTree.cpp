/********
          Topic:Sum of all nodes(Tree);      Author:Monk_;
                                                         ***********/
#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
      int data;
      Node *left,*right;
      Node(int d){
        data=d;
        left=NULL;
        right=NULL;
      }
};
Node *buildTree(){
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
            if(f->left)
                q.push(f->left);
            if(f->right)
                q.push(f->right);

        }

    }
}
int countt(Node *root){
    if(root==NULL)
        return 0;
    return 1+countt(root->left)+countt(root->right);
}
int main(){
    Node *root=buildTree();
    cout<<"printing:";
    BFS(root);
    cout<<endl;
    cout<<countt(root)<<endl;
return 0;
}
