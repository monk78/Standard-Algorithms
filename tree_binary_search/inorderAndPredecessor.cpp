/**                    Author:Monk_
 *                     Topic:inroder and predecessor                                                         **/
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
class Tree{
  public:
      int data;
      Tree *left,*right;
      Tree(int data){
        this->data=data;
        left=NULL;
        right=NULL;
      }
      Tree(){
        data=0;
        left=NULL;
        right=NULL;
      }
};
Tree *insert(Tree *root,int key){
    if(root==NULL)return new Tree(key);
    if(key<root->data)
        root->left=insert(root->left,key);
    else if(key>root->data)
        root->right=insert(root->right,key);
}
void bfs(Tree *root){
    queue<Tree*>q;
    q.push(root);
    while(!q.empty()){
        Tree *temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left)q.push(temp->left);
        if(temp->right)q.push(temp->right);
    }
}
void InOrdPred(Tree *root,Tree *&pre,Tree *&succ,int key){
   if(root==NULL)return;
   if(root->data==key){
     if(root->left!=NULL){
        Tree *temp=root->left;
        while(temp->right!=NULL)temp=temp->right;
        pre=temp;
     }

     if(root->right!=NULL){
        Tree *temp=root->right;
        while(temp->right!=NULL)temp=temp->right;
        succ=temp;
     }
       return;
   }
   if(key<root->data){
      succ=root;
      InOrdPred(root->left,pre,succ,key);
   }
   if(key > root->data){
    pre=root;
    InOrdPred(root->right,pre,succ,key);
   }
}

int main(){
    fast();
    int i,num;
    Tree *root=NULL;
    cin>>num;
    root=insert(root,num);
    _for(i,1,7){
        cin>>num;
        insert(root,num);
    }
    cout<<"bfs"<<"=>";
    bfs(root);
    cout<<"enter the value to be searched:"<<endl;
    cin>>num;
    Tree *pre,*succ;
    InOrdPred(root,pre,succ,num);
    cout<<pre->data<<" "<<succ->data<<endl;
    return 0;
}
