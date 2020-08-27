/**                    Author:Monk_
 *                     Topic:inorder traversal  without using recursion with the help of stack binary Tree                                                         **/
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
    if(d==-1)return NULL;
    Node *root=new Node(d);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
void printIn(Node *root){
  stack<Node*>st;
  Node *curr=root;
  while(curr!=NULL||(!st.empty())){
    while(curr!=NULL){
        st.push(curr);
        curr=curr->left;

    }
    curr=st.top();
    st.pop();
    cout<<curr->data<<" ";
    curr=curr->right;
  }
}
bool Ancestor(Node *root,int target){

 //Node *curr=root;
 if(root==NULL)return false;

 if(root->data==target)return true;

 if(Ancestor(root->left,target)||Ancestor(root->right,target)){
    cout<<root->data<<" ";
    return true;
 }
 return false;
}
int main(){
 fast();
 int t;
 Node *root=buildTree();
 cout<<"without Ancestor the program is:"<<endl;
 printIn(root);
 cout<<"\nenter target:";
 cin>>t;
 cout<<"with ancestors:"<<endl;
 Ancestor(root,t);
 return 0;
}
