/**                    Author:Monk_
 *                     Topic:With minimum Value B.S.T                                                         **/
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
    Node *left;
    Node *right;
    Node(int d){
     data=d;
     left=NULL;
     right=NULL;
    }
};
Node *insert(Node *root,int key){
  if(root==NULL)return new Node(key);
  if(key<root->data)root->left=insert(root->left,key);
  else if(key>root->data)root->right=insert(root->right,key);
  return root;
}
int  minV(Node *root){
Node *curr=root;
while(curr->left!=NULL){
    curr=curr->left;
}
return curr->data;
}
int main(){
    //fast();
    int i,key;
    Node *root=NULL;
    root=insert(root,4);
    _for(i,0,5){
      cin>>key;
      insert(root,key);
    }
    cout<<minV(root)<<endl;
    return 0;
}
