//this is first method of building tree recursively:
////below is in_order,pr_order,post_order traversal for printing the particular tree:
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
        root->left = buildTree();
        root->right = buildTree();
        return root;
     }
     //pr-order:-root,left,right;
     void printpre(Node *root){
        if(root==NULL)
            return;
        //print trees followed by subtrees:
        cout<<root->data<<" ";
        printpre(root->left);
        printpre(root->right);
     }
     //In-order:-left,root,right;
     void printIn(Node *root){
        if(root==NULL)
                return;
        printIn(root->left);
        cout<<root->data<<" ";
        printIn(root->right);
     }
     //post-order:-left,right,root
     void printpost(Node *root){
      if(root==NULL)
            return;
        printpost(root->left);
        printpost(root->right);
        cout<<root->data<<" ";
     }
int main(){
    Node* root=buildTree();
    cout<<"pr_order traversal:";
    printpre(root);
    cout<<"\nIn_order traversal:";
    printIn(root);
    cout<<"\npost_order traversal:";
    printpost(root);
return 0;
}

