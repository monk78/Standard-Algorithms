/**                    Author:Monk_
 *                     Topic:Lowest Common Ancestor                                                         **/
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
class Tree{
public:
    ll data;
    Tree *left,*right;
    Tree(ll data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

Tree *insert(Tree *root,ll key){
 if(root==NULL)return new Tree(key);
 if(key<root->data) root->left=insert(root->left,key);
 if(key>root->data) root->right=insert(root->right,key);
 return root;
}

void bfs(Tree *root){
queue<Tree*>q;
q.push(root);
while(!q.empty()){
    Tree *temp=q.front();
    q.pop();
    cout<<temp->data<<" ";
    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);
 }
}

int LCA(Tree *root,ll num1,ll num2){
  if(root==NULL)return 0;
  if(root->data>num1&&root->data>num2)
        return LCA(root->left,num1,num2);
  if(root->data<num1&&root->data<num2)
        return LCA(root->right,num1,num2);
   return root->data;

}
/**
kth common Ancestor:

**/
int pthCommonAncestor(int x,int y,NODE *root,int p,vector<int> &vec){

  while(root){
      if(root==NULL);
      if(root->data>x && root->data>y){
          vec.push_back(root->data);
          root=root->left;
      }
      else if(root->data<x && root->data<y){
          vec.push_back(root->data);
          root=root->right;
      }
      else break;
  }
  vec.push_back(root->data);
  int i=vec.size();
  if(i-p>=0 && vec[i-p]!=0)return vec[i-p];
  else return -1;
}

int main(){
    fast();
    Tree *root=NULL;
    ll i,num,one,two;
    cin>>num;
    root=insert(root,num);
    _for(i,1,7){
        cin>>num;
        insert(root,num);
    }
    cout<<"BFS:-";
    bfs(root);
    cout<<"\n enter the number whose lowest common  \ancestor u want to know:";
    cin>>one>>two;
    //Tree *ans=LCA(root,one,two);
   // cout<<ans->data<<" ";
   cout<<LCA(root,one,two)<<endl;
    return 0;
}
