/******************
                   Author:Monk_     Topic:diameter of Tree

 Explanation:we will calculate it by searching recursively in both nodes left as well as right node;
 afterward we will optimize it;

                                                                  ****************/
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
class Pair{
 public:
     int height;
     int diameter;
};
Node *buildTree(){
 int d;
 cin>>d;
 if(d==-1)
    return NULL ;
 Node *newnode=new Node(d);
 newnode->left=buildTree();
 newnode->right=buildTree();
  return newnode;
}
int height(Node *root){
    if(root==NULL)
            return 0;
    return 1+max(height(root->left),height(root->right));
}
int diam(Node *root){
  if(root==NULL) return 0;
   int h1=height(root->left);
   int h2=height(root->right);
   int op1=h1+h2;
   int op2=diam(root->left);
   int op3=diam(root->right);
   return max(op1,max(op2,op3));
}
//optiized result:

int main(){
    Node *root=buildTree();
    cout<<"height is:"<<height(root);
    cout<<"diameter of Tree is:"<<diam(root)<<endl;
return 0;
}
