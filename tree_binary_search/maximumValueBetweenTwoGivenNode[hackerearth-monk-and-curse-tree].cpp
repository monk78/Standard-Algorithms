
/**                    Author:Monk_
 *                     Topic:BST insertion:                                                         **/
#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define _for(i,a,b) for(i=a;i<b;i++)

#define _rfor(i,a,b) for(i=a;i>=b;i--)

#define mp(a,b) make_pair(a,b)

void fast(){
 ios_base::sync_with_stdio(false);
 cout.tie(NULL);
}
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data){
    this->data=data;
    left=NULL;
    right=NULL;
 }
};
void InOrder(Node *root){
    if(root==NULL)return;
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}
Node *insert(Node *root,int key){
  if(root==NULL)return new Node(key);
  if(root->data>key)root->left=insert(root->left,key);
  else if(root->data<key)root->right=insert(root->right,key);
  return root;
}
int main(){
    fast();
    Node *root = NULL;
    ll N,i,key,X,Y,c;
    cin>>N;
    cin>>key;
    c=key;
    root=insert(root,key);
    _for(i,0,N){
        cin>>key;
        insert(root,key);
    }
    cin>>X>>Y;
    InOrder(root);
 //   if(X<c&&Y>c)
    return 0;
}
