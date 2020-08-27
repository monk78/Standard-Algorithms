/**                    Author:Monk_
 *                     Topic:InorderPredecessorAndSuccessorBST                                                         **/
#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define _for(i,a,b) for(i=a;i<b;i++)

#define _rfor(i,a,b) for(i=a;i>=b;i--)

#define mp(a,b) make_pair(a,b)

void fast(){
 std::ios_base::sync_with_stdio(false);
 cout.tie(NULL);
}
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
Node *insert(Node *root,int key){
    if(root==NULL)return new Node(key);
    if(root->data>key)root->left=insert(root->left,key);
    else if(root->data<key)root->right=insert(root->right,key);
    return root;
}
void preStr(Node *root,Node *&pre,Node*&succ,int key){
  if(root==NULL)return;
  if(root->data==key){
    if(root->left!=NULL){
        Node *tmp=root->left;
        while(tmp->right)
            tmp=tmp->right;
       pre=tmp;
    }
    if(root->right!=NULL){
       Node *tmp=root->right;
       while(tmp->left){
        tmp=tmp->left;
       }
       succ=tmp;
    }
    return;
  }
  if(root->data>key){
    succ=root;
    preStr(root->left,pre,succ,key);
  }
  else{
    pre=root;
    preStr(root->right,pre,succ,key);
  }
}
int main(){
    fast();
    int key,N=7,i;
    Node *root=NULL;
    _for(i,0,N){
        cin>>key;
        insert(root,key);
    }
    Node *pre=NULL,*succ=NULL;
    cout<<"enter the key to be searched:"<<" ";
    cin>>key;
    preStr(root,pre,succ,key);
    cout<<pre->data<<" ";
    cout<<succ->data<<" ";
    return 0;
}
