/**
 * @Author: monk
 * @Date:   2019-06-12T17:05:47+05:30
 * @Last modified by:   monk
 * @Last modified time: 2019-06-12T19:21:43+05:30
 * @License: free
 */
#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define mod 1000000009
#define MAX 100005
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%lld",&n)
#define pl(n) printf(" %lld  ",n)
#define ss(n) scanf("%s",n)
#define ps(n) printf("%s",n)
#define lt() printf("\n")
#define sp() printf(" ")
#define def(Node) (struct Node*)malloc(sizeof(struct Node))
typedef struct Node{
  ll data;
  struct Node *left,*right;
}Node;

Node *newnode(ll data){
  Node *temp=def(Node);
  temp->data=data;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}


Node *insert(Node *root,ll data){
   if(root==NULL)root=newnode(data);
   if(root->data > data){
     root->left=insert(root->left,data);
   }
   if(root->data < data)root->right=insert(root->right,data);
  return root;
}

void Inorder(Node *root){
  if(root==NULL)return;
 Inorder(root->left);
 pl(root->data);sp();
 Inorder(root->right);
}
void preorder(Node *root){
  if(root==NULL)return;
  pl(root->data);
  preorder(root->left);
  preorder(root->right);
}
void postorder(Node *root){
  if(root==NULL)return;
  postorder(root->left);
  postorder(root->right);
   pl(root->data);
}

ll InorderSucc(Node *root){
  Node *temp=root;
  while(temp->left!=NULL)temp=temp->left;
  return temp->data;
}

Node *dlx(Node *root,ll data){
  if(root==NULL)return NULL;
  if(root->data < data)root->right=dlx(root->right,data);
  else if(root->data>data)root->left=dlx(root->left,data);
  else{
    if(root->left==NULL){
       Node *temp=root;
       root=root->right;
       free(temp);
       return root;
    }
    else if(root->right==NULL){
     Node *temp=root;
     root=root->left;
     free(temp);
     return root;
    }
    else{
      ll insuc=InorderSucc(root);
      root->data=insuc;
      root->right=dlx(root->right,insuc);
    }
  }
  return root;
}


int main(){
  ll N,num;
  ps("numberss:");
  sl(N);
  Node *head=NULL;
  //Node *root=NULL;
  //Node *root=def(Node);
  //root=head;
  //sl(num);
  //root=insert(root,num);
  //N--;
  while(N--){
    sl(num);
    head=insert(head,num);
  }
  ps("inorder");
  Inorder(head);
  lt();
  ps("preorder");
  preorder(head);
  lt();
  postorder(head);
  lt();
  ps("enter number to be deleted:");
  sl(num);
  head=dlx(head,num);
  ps("inorder");
  Inorder(head);
  lt();
  ps("preorder");
  preorder(head);
  lt();
  postorder(head);
  lt();

  return 0;
}
