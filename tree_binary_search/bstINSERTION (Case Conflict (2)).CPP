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
    Node(int d){
    data=d;
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
    ll N,num;
    Node *root = NULL;
    cout<<"total N:";
    cin>>N;
    cout<<"enter numbers:";
    cin>>num;
    root = insert(root, num);
    for(ll i=1;i<N;i++){
        cin>>num;
        insert(root,num);
    }
    InOrder(root);
    return 0;
}
